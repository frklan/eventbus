#pragma once

#include "eventbus/EventBus.h"
#include "events.h"

class Player {
  public:
    Player() = delete;
    Player(EventBus& eb);
    ~Player() = default;

  private:
    void onCreateEvent(CreateEvent& e);
    void onCreateEvent2(CreateEvent& e);

    void onPauseEvent(PauseEvent& e);
};