#pragma once

#include "eventbus/EventBus.h"
#include "events.h"

namespace eventbus::test {
  class Player {
    public:
      Player() = delete;
      Player(eventbus::EventBus& eb);
      ~Player() = default;

    private:
      void onCreateEvent(eventbus::test::CreateEvent& e);
      void onCreateEvent2(eventbus::test::CreateEvent& e);

      void onPauseEvent(eventbus::test::PauseEvent& e);
  };
}
