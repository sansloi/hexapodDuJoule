/* Hexy Script, this is the logic that makes a robot dance */
/* Uiversity of Nevada, Las Vegas Spring 2016 */
#include <Wire.h>
#include "Unlv.h"       //E.nice, sugar, spice
#include "Menu.h"      //menu
int input, switchVar;
long temps;  //milliseconds
char junk = ' ';

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  menuStart();
}

void loop()
{
    menuOne();
    while(Serial.available() == 0)
  {  //wait  until input buffer has a char
      // by default -1 if no serial data is available
    input = Serial.parseFloat();   //input value, int

    while (Serial.available() > 0)
    {//paraseFloat() can leave non-numberic char
        junk = Serial.read();       //clear the keyboard buffer
    }
        if (input == 1)
        {
            response1();
        }
        else if (input == 2)
        {
            response2();
            oneServoTest();
        }
        else if (input == 3)
        {
            response3();
        }
        else if (input == 4)    //This is a test for a compact function
        {
            doubleCompactOneServoTest();
        }
  }
}
