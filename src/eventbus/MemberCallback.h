#pragma once

#include "EventCallback.h"
#include "Event.h"

namespace eventbus {
  template<typename T, typename EventType>
  class MemberCallback : public EventCallback {
    public:
      typedef void (T::*Callback)(EventType&);
      
      MemberCallback(T* instance, Callback callback) :
      instance(instance),
      callback(callback)
      {
      }

    private:
      virtual void call(eventbus::Event& e) override {
        std::invoke(callback, instance, static_cast<EventType&>(e));
      }

    private:
      T* instance;
      Callback callback;
  };
}