# EventBus

A simple event system made in C++, inspired by [Niko Savas](https://medium.com/@savas/nomad-game-engine-part-7-the-event-system-45a809ccb68f) article on Medium. I did not want the naked pointers so I rolled my own version (and as a plus I avoided a couple of memory leaks.. :grin: ).

## Usage

Events are defined as subclasses to Events, like so

````c++
struct CreateEvent : public eventbus::Event {
};

struct QuitEvent : public eventbus::Event {
};

struct PauseEvent : public eventbus::Event {
    PauseEvent(bool isPaused) : isPaused(isPaused) {};
    bool isPaused;
};
````

The shared EventBus object is created, like so

````c++
eventbus::EventBus eventbus;
````

An object can now register itself as a subscriber by calling ````EventBus.subscribe()```` passing in a pointer to the object and the callback method

````c++
Mob::RegisterEvents(eventbus::EventBus& bus) {
  bus.subscribe(this, &Mob::onCreateEvent);  
}

void Mob::onCreateEvent(CreateEvent&) {
  std::clog << "\t--> Mob received CreateEvent\n";
}

````

## Compiling

To compile the demo code, clone the repo and do

````bash
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON ..
$ make -j4
$ ./ebus
````

## TODO

I'm quite happy how this came out, there are however a couple of things that should be addressed. Most important is to add a method to unsubscripe and to check if a subscriber is alive invoking the callback.

- [ ] Make it possible to unsubscribe from an event
- [ ] Check that the subscriber still exists before calling the callback
- [ ] Remove the need for pointer-to-member-functions, e.g. take a wrapper lambda as the callback argument
- [ ] Proper exception handling

## Contributing

Contributions are always welcome!

When contributing to this repository, please first discuss the change you wish to make via the issue tracker, email, or any other method with the owner of this repository before making a change.

Please note that we have a code of conduct, you are required to follow it in all your interactions with the project.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/frklan/eventbus/tags).

## Authors

* **Fredrik Andersson** - *Initial work* - [frklan](https://github.com/frklan)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
