//
//    Copyright 2016 Christopher D. McMurrough
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
* @FILE multicolor_led.ino
* @BRIEF An example Arduino sketch showing dimmer control of a multicolor LED
* @AUTHOR Christopher D. McMurrough
**********************************************************************************************************************/

// define onobard LED pins
const int LED_PIN = 13;
const int LED_ON = HIGH;
const int LED_OFF = LOW;

// define RGB LED pins
const int RED_PIN = 21;
const int GREEN_PIN = 22;
const int BLUE_PIN = 23;
const int RGB_ON = LOW;
const int RGB_OFF = HIGH;

// define potentiometer pins
const int POT_PIN = 14;

/***********************************************************************************************************************
* @BRIEF perform initial setup of the microcontroller
* @AUTHOR Christoper D. McMurrough
**********************************************************************************************************************/
void setup()
{
    // initialize the IO pins
    pinMode(LED_PIN, OUTPUT);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    // turn off the RGB LED by pulling the pins hig
    digitalWrite(RED_PIN, RGB_OFF);
    digitalWrite(GREEN_PIN, RGB_OFF);
    digitalWrite(BLUE_PIN, RGB_OFF);
    
    // flash the onboard LED state
    for(int i = 0; i < 25; i++)
    {
        digitalWrite(LED_PIN, LED_ON);
        delay(50);
        digitalWrite(LED_PIN, LED_OFF);
        delay(50);
    }

    // start serial communication at 9600 bps
    Serial.begin(9600);
}

/***********************************************************************************************************************
* @BRIEF main program loop
* @AUTHOR Christoper D. McMurrough
**********************************************************************************************************************/
void loop()
{
    int potValue = analogRead(POT_PIN);
    Serial.println(potValue);

    // if the potentiometer value is over half of the range, enable the RGB LED
    if(potValue > 512)
    {
        // steadily increase LED brightness
        for(int i = 0; i < 256; i++)
        {
            analogWrite(RED_PIN, 255 - i);
            delay(10);
        }
      
        // steadily decrease LED brightness
        for(int i = 0; i < 256; i++)
        {
            analogWrite(RED_PIN, i);
            delay(10);
        }
      
        // steadily increase LED brightness
        for(int i = 0; i < 256; i++)
        {
            analogWrite(GREEN_PIN, 255 - i);
            delay(10);
        }
      
        // steadily decrease LED brightness
        for(int i = 0; i < 256; i++)
        {
            analogWrite(GREEN_PIN, i);
            delay(10);
        }
      
        // steadily increase LED brightness
        for(int i = 0; i < 256; i++)
        {
            analogWrite(BLUE_PIN, 255 - i);
            delay(10);
        }
      
        // steadily decrease LED brightness
        for(int i = 0; i < 256; i++)
        {
            analogWrite(BLUE_PIN, i);
            delay(10);
        }
    }
}
