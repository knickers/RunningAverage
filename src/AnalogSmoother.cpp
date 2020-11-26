#include "AnalogSmoother.h"

AnalogSmoother::AnalogSmoother(int pin, unsigned int size) {
	mI = 0;
	mPin = pin;
	mSize = size;
	mTotal = 0;
	mReadings = new int[size];

	for (unsigned int i=0; i<mSize; i++) {
		mReadings[i] = 0;
	}
}

AnalogSmoother::~AnalogSmoother() {
	delete mReadings;
}

void AnalogSmoother::fill() {
	for (unsigned int i=0; i<mSize; i++) {
		read();
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
