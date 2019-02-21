#include <iostream>

#include "eventbus/EventBus.h"
#include "events.h"

#include "player.h"
#include "mob.h"

int main() {
  std::clog << "--- EventBus ---\n";
  
  std::clog << "Creating eventbus\n";
  EventBus eventbus;

  std::clog << "Creating Player\n";
  Player p(eventbus);

  std::clog << "Creating Mob\n";
  Mob m(eventbus);

  std::clog << "Sending messages to player\n";
  
  eventbus.publish(CreateEvent{});
  eventbus.publish(PauseEvent{true});
  eventbus.publish(PauseEvent{false});
  
  return 0;
}

