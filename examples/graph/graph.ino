#include "RunningAverage.h"

RunningAverage average(10); // Buffer size of 10 readings

void setup() {
	Serial.begin(115200);

	// Optional, fill the buffer with a starting value
	average.fill(random(15));
}

void loop() {
	long int n = random(15);

	// Draw 2 lines in the serial plotter
	Serial.print(n);
	Serial.print(" ");
	Serial.println(average.append(n));

	// Slow down the serial output
	delay(10);
}
