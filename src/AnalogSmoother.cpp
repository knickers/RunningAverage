#include "AnalogSmoother.h"

AnalogSmoother::AnalogSmoother(int pin) {
	AnalogSmoother(pin, 20);
}

AnalogSmoother::AnalogSmoother(int pin, unsigned int size) {
	if (size < 1) {
		throw "AnalogSmoother buffer must be larger than 0";
	}

	_i = 0;
	_pin = pin;
	_size = size;
	_total = 0;
	_readings = new int[_size];
	assert(_readings);
	_lastReading = 0;

	for (int i=0; i<_size; i++) {
		_readings[i] = 0;
	}
}

AnalogSmoother::~AnalogSmoother() {
	delete _readings;
}

AnalogSmoother::read() {
	unsigned long now = millis();

	if (now - _lastReading < 5) {
		return _total / _size;
	}

	_lastReading  = now;
	_total       -= _readings[_i];    // Subtract old reading
	_readings[_i] = analogRead(_pin); // Read new value
	_total       += _readings[_i];    // Add new reading

	_i++; // Increment readings index
	if (_i >= _size) {
		_i = 0;
	}

	return (double)_total / (double)_size;
}
