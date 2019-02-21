#pragma once

#include "eventbus/Event.h"

namespace eventbus::test {
  struct CreateEvent : public eventbus::Event {

  };

  struct QuitEvent : public eventbus::Event {

  };

  struct PauseEvent : public eventbus::Event {
      PauseEvent(bool isPaused) : isPaused(isPaused) {};
      bool isPaused;
  };
}
