#pragma once

#include "EventCallback.h"
#include "Event.h"

namespace eventbus {
  template<typename T, typename EventType>
  class MemberCallback : public EventCallback {
    public:
      typedef void (T::*Callback)(EventType&);
      
      MemberCallback(T* instance, Callback callback) :
      handlerInstance(instance),
      eventCallback(callback)
      {
      }

      virtual ~MemberCallback() override = default;

    private:
      virtual void call(eventbus::Event& e) override {
        std::invoke(eventCallback, handlerInstance, static_cast<EventType&>(e));
      }

    private:
      T* handlerInstance;
      Callback eventCallback;
  };
}
