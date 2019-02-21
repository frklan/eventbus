#pragma once

#include "eventbus/EventBus.h"
#include "events.h"

namespace eventbus::test {
  class Mob {
    public:
      Mob() = delete;
      Mob(eventbus::EventBus& eb);
      ~Mob() = default;

    private:
      void onCreateEvent(eventbus::test::CreateEvent& e);
  };
}