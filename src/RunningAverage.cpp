#include "RunningAverage.h"

RunningAverage::RunningAverage(unsigned int size) {
	mI = 0;
	mSize = size;
	mTotal = 0;
	mValues = new int[size];

	for (unsigned int i=0; i<mSize; i++) {
		mValues[i] = 0;
	}
}

RunningAverage::~RunningAverage() {
	delete mValues;
}

void RunningAverage::fill(int value) {
	for (unsigned int i=0; i<mSize; i++) {
		append(value);
	}
}

float RunningAverage::append(int value) {
	mTotal     -= mValues[mI]; // Subtract old value
	mTotal     += value;       // Add new value
	mValues[mI] = value;       // Save new value

	mI++; // Increment buffer index
	if (mI >= mSize) {
		mI = 0;
	}

	return (float)mTotal / (float)mSize;
}
