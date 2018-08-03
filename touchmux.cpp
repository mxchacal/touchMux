#include <Arduino.h>
#include "touchMux.h"

touchMux::touchMux(int sig0, int sig1, int sig2, int sig3, int readpin) {
  sig0_ = sig0;
  sig1_ = sig1;
  sig2_ = sig2;
  sig3_ = sig3;
  readpin_ = readpin;

  pinMode(sig0_, OUTPUT); // set up output pins for multiplexer address bus
  pinMode(sig1_, OUTPUT);
  pinMode(sig2_, OUTPUT);
  pinMode(sig3_, OUTPUT);
}

int touchMux::read(int channel) {
  digitalWriteFast(sig0_, bitRead(channel, 0)); // set the output pins for multiplexer address bus for the current address
  digitalWriteFast(sig1_, bitRead(channel, 1));
  digitalWriteFast(sig2_, bitRead(channel, 2));
  digitalWriteFast(sig3_, bitRead(channel, 3));

  return map(touchRead(readpin_), 0, 5000, 0, 127); // adjust these bounds for a particular setup, capacitance
}

bool touchMux::touched(int channel) {
  return read(channel) > treshold_ ? 1 : 0;
}

void touchMux::setTreshold(int treshold) {}

void touchMux::autoTreshold() {}
