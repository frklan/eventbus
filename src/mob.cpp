#include <iostream>

#include "eventbus/EventBus.h"
#include "events.h"

#include "mob.h"


Mob::Mob(EventBus& bus)
{
  std::clog << "Mob created, subscribing to CreateEvent \n";
  bus.subscribe(this, &Mob::onCreateEvent);  
}

void Mob::onCreateEvent(CreateEvent&) {
  std::clog << "\t--> Mob received CreateEvent\n";
}