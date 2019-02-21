#include <iostream>

#include "eventbus/EventBus.h"
#include "events.h"

#include "player.h"

Player::Player(EventBus& bus)
{
  std::clog << "Player created, subscribing to CreateEvent twice and PauseEvent once \n";
  bus.subscribe(this, &Player::onCreateEvent); 
  bus.subscribe(this, &Player::onCreateEvent2);
  bus.subscribe(this, &Player::onPauseEvent);
}

void Player::onCreateEvent(CreateEvent&) {
  std::clog << "\t--> Player received CreateEvent (first time)\n";
}

void Player::onCreateEvent2(CreateEvent&) { 
  std::clog << "\t--> Player received CreateEvent (second time)\n";
}

void Player::onPauseEvent(PauseEvent& e){
   std::clog << "\t--> Player received PauseEvent, isPaused = " << e.isPaused << '\n';
}