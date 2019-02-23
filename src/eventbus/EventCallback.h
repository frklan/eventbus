#pragma once

#include "Event.h"

namespace eventbus {
  class EventCallback {
    public:
      virtual ~EventCallback() = default;

      void execute(eventbus::Event& e) {
        call(e);
      }

    private:
      virtual void call(eventbus::Event& e) = 0;
  };
}
