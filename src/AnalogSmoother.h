#ifndef AnalogSmoother_h
#define AnalogSmoother_h

#include "Arduino.h"

class AnalogSmoother {
	public:
		AnalogSmoother(int pin, unsigned int size);
		~AnalogSmoother();
		void fill();
		float read();
	private:
		int mPin;
		unsigned int mSize;
		unsigned int mI;
		int mTotal;
		int *mReadings;
};

#endif
