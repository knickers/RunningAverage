#include "AnalogSmoother.h"

AnalogSmoother sensor(A0, 10); // Buffer size of 10 readings

void setup() {
	Serial.begin(115200);

	// Optional, fill the buffer with actual readings from the sensor
	sensor.fill();
}

void loop() {
	// Draw 2 lines in the serial plotter
	Serial.print(analogRead(A0));
	Serial.print(" ");
	Serial.println(sensor.read());

	// Slow down the serial output
	delay(10);
}
