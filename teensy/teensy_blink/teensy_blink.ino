//
//    Copyright 2013 Christopher D. McMurrough
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

/***********************************************************************************************************************
* @FILE teensy_blink.ino
* @BRIEF An example Arduino sketch that blinks the onboard LED on the Teensy 3.1/3.2 microcontroller.
* @AUTHOR Christopher D. McMurrough
**********************************************************************************************************************/

// define GPIO pins
const int LED_PIN = 13;
const int LED_ON = HIGH;
const int LED_OFF = LOW;


/***********************************************************************************************************************
* @BRIEF perform initial setup of the microcontroller
* @AUTHOR Christoper D. McMurrough
**********************************************************************************************************************/
void setup()
{
    // initialize the IO pins
    pinMode(LED_PIN, OUTPUT);
}

/***********************************************************************************************************************
* @BRIEF main program loop
* @AUTHOR Christoper D. McMurrough
**********************************************************************************************************************/
void loop()
{
    // turn the LED on and off
    digitalWrite(LED_PIN, LED_ON);
    delay(50);
    digitalWrite(LED_PIN, LED_OFF);
    delay(50);
}
