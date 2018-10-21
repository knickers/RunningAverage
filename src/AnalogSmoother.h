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
		void init(int pin, unsigned int size);
		int mPin;
		unsigned int mSize;
		unsigned int mI;
		int mTotal;
		int *mReadings;
};

#endif
