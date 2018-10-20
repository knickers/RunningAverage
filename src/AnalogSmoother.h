#ifndef AnalogSmoother_h
#define AnalogSmoother_h

#include "Arduino.h"

class AnalogSmoother {
	public:
		AnalogSmoother(int pin);
		AnalogSmoother(int pin, unsigned int size);
		~AnalogSmoother();
		double read();
	private:
		int _pin;
		unsigned int _size;
		unsigned int _i;
		int _total;
		int *_readings;
		unsigned long _lastReading;
};

#endif
