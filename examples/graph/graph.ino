#include "AnalogSmoother.h"

AnalogSmoother analog(A0);

void setup() {
	Serial.begin(115200);
	analog.fill();
}

void loop() {
	Serial.print(analogRead(A0));
	Serial.print(" ");
	Serial.println(analog.read());
	delay(10); // Slow down the serial output
}
