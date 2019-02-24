#pragma once
#include <map>
#include <list>
#include <typeindex>

#include "EventCallback.h"
#include "MemberCallback.h"
#include "Event.h"

namespace eventbus {
  typedef std::list<std::unique_ptr<EventCallback>> HandlerList;

  class EventBus {
    public:
      template<typename T, typename EventType> 
      void subscribe(T* instance, void (T::*callback)(EventType&));

      template<typename Event>
      void publish(Event& event);

      template<typename Event>
      void publish(Event&& event);

      void reset() { subscribers.clear(); }

    private:
      std::map<std::type_index, std::unique_ptr<HandlerList>> subscribers;
  };

  template<typename T, typename EventType> 
  void EventBus::subscribe(T* instance, void (T::*callback)(EventType&) ){ 
    if(subscribers[typeid(EventType)].get() == nullptr) {
      subscribers[typeid(EventType)] = std::make_unique<HandlerList>(); 
    }
    auto sub = std::make_unique<MemberCallback<T, EventType>>(instance, callback);
    subscribers[typeid(EventType)]->push_back(std::move(sub));
  };

  template<typename EvenType>
  void EventBus::publish(EvenType& event) {
    auto handlers = subscribers[typeid(EvenType)].get();

    if(handlers == nullptr) {
      return;
    }

    for(auto iter = handlers->begin(); iter != handlers->end(); iter++){
      auto handler = iter->get();
      if(handler != nullptr) {
        handler->execute(event);
      }
    }
  }

  template<typename Event>
  void EventBus::publish(Event&& event) {
    publish(event);
  };
}
