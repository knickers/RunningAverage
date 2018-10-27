#include "AnalogSmoother.h"

AnalogSmoother::AnalogSmoother(int pin) {
	init(pin, 20);
}

AnalogSmoother::AnalogSmoother(int pin, unsigned int size) {
	init(pin, size);
}

AnalogSmoother::~AnalogSmoother() {
	delete mReadings;
}

void AnalogSmoother::init(int pin, unsigned int size) {
	mI = 0;
	mPin = pin;
	mSize = size;
	mTotal = 0;
	mReadings = new int[size];

	for (int i=0; i<size; i++) {
		mReadings[i] = 0;
	}
}

float AnalogSmoother::read() {
	mTotal       -= mReadings[mI];    // Subtract old reading
	mReadings[mI] = analogRead(mPin); // Read new value
	mTotal       += mReadings[mI];    // Add new reading

	mI++; // Increment readings index
	if (mI >= mSize) {
		mI = 0;
	}

	return (float)mTotal / (float)mSize;
}
