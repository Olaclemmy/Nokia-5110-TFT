#include "Arduino.h"
#include <PCD8544.h>

#define LCDLED 8

// Smiley face (of sorts)
static const byte smiley[] = { 
	B00010000, 
	B00110100, 
	B00110000, 
	B00110100, 
	B00010000 };

// Create the LCD object (using a library class)
static PCD8544 lcd;

// =============================================================================
// SETUP     SETUP     SETUP     SETUP     SETUP     SETUP     SETUP     SETUP
// =============================================================================
void setup() {
	Serial.begin(9600);

	// Nokia 5110 has 84W x 48H pixels
	lcd.begin(84, 48);
	lcd.clear();

	// LED control (backlight)
	pinMode(LCDLED, OUTPUT);
	digitalWrite(LCDLED, HIGH);

	// Add the smiley to position "0" of the ASCII table...
	lcd.createChar(0, smiley);
	Serial.println("Setup Completed");
}

// =============================================================================
// LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP
// =============================================================================
void loop() {
	// Speed demo counter
	static unsigned long counter = 0;

	// Position is COL, ROW
	lcd.setCursor(0, 0);

	// For PRINT statement it works out the actual pixel start point
	lcd.print("Hi Arduinites!");

	// Print more stuff on the 2nd ROW (not second pixel!)
	lcd.setCursor(0, 2); // col, row
	lcd.print("You can use a");

	// Keep printing stuff
	lcd.setCursor(0, 3); // col, row
	lcd.print("Nokia 5110 TFT");

	// Because we WRITE the smiley you must work out the exact pixel position
	lcd.setCursor(78,5);
	lcd.write(0);  // write the smiley from stored character zero

	while (1) {
		// Use a potentiometer to set the LCD contrast...
		short level = map(analogRead(A0), 0, 1023, 0, 127);
		lcd.setContrast(level);

		// Write out the counter
		lcd.setCursor(0, 5);
		lcd.print(counter, DEC);

		// Increment counter and run again as fast as we can
		counter++;

		// Turn the LED light ON/OFF every two hundred counts
		if (counter % 200 == 0) {

			// This means: read the current value of LCDLED state (HIGH or LOW)
			// Then turn the pin state to what ever that value is NOT
			digitalWrite(LCDLED, !digitalRead(LCDLED));
		}
	}	
}