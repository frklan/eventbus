#pragma once

#include "Event.h"

class EventCallback {
  public:
    EventCallback() = default;
    virtual ~EventCallback() = default;

    void execute(Event& e) {
      call(e);
    }
  private:
    virtual void call(Event& e) = 0;
};