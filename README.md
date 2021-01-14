# RunningAverage

This library employs a running average to smooth a series of values.

```cpp
#include "RunningAverage.h"

RunningAverage smooth(10); // Buffer size of 10 values

void setup() {
	Serial.begin(115200);

	// Optional, fill the buffer with a starting value
	smooth.fill(random(15));
}

void loop() {
	long int n = random(15);

	// Draw 2 lines in the serial plotter
	Serial.print(n);
	Serial.print(" ");
	Serial.println(sensor.append(n));

	// Slow down the serial output
	delay(10);
}
```
