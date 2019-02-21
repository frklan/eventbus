#pragma once

#include "eventbus/EventBus.h"
#include "events.h"

class Mob {
  public:
    Mob() = delete;
    Mob(EventBus& eb);
    ~Mob() = default;

  private:
    void onCreateEvent(CreateEvent& e);
};