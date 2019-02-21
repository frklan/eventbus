#pragma once

#include "eventbus/Event.h"

struct CreateEvent : public Event {

};

struct QuitEvent : public Event {

};

struct PauseEvent : public Event {
    PauseEvent(bool isPaused) : isPaused(isPaused) {};
    bool isPaused;
};

