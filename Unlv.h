/* This header file will hold the motorCtrl's register value
 * & a few necessary functions
 *Author:Julio B. Figueroa
 *University of Nevada, Las Vegas
 *Department of Mechanical Engineering
 */
#include <stdio.h>
#include <stdlib.h>
#define ADDRESS 0x61    //address of the SD21
// Below are the registers used for the SD21 in hex values
// for more information look at register chart in report
//      NAME    HEX      DEC    PIN-VALUE
#define Y1P0    0x3F  // 63     S1      note: bottom yaw
#define Y1P1    0x40  // 64     S2      note: femur
#define Y1P2    0x41  // 65     S3      note: tribia

#define Y2P0    0x42  // 66     S4
#define Y2P1    0x43  // 67     S5
#define Y2P2    0x44  // 68     S6

#define Y3P0    0x45  // 69     S7
#define Y3P1    0x46  // 70     S8
#define Y3P2    0x47  // 71     S9

#define Y4P0    0x48  // 72     S10
#define Y4P1    0x49  // 73     S11
#define Y4P2    0x4a  // 74     S12

#define Y5P0    0x4b  // 75     S13
#define Y5P1    0x4c  // 76     S14
#define Y5P2    0x4d  // 77     S15

#define Y6P0    0x4e  // 78     S16
#define Y6P1    0x4f  // 79     S17
#define Y6P2    0x50  // 80     S18

#define Y7P0    0x51  // 81     S19     note: mount yaw
#define Y7P1    0x52  // 82     S20     note: mount pitch

#define delayVal 5000

/* for low resource MCs eq. is Y = X*6+732,
 * so the Y range goes from 730@X=0 to 2267@X=225
 * Let's try to avoid the extremes, 1500 = center
 * The Y values represent PWM pulse widths in micro-sec
*/
void oneServoTest()
{
    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);
        Wire.write(255);
    Wire.endTransmission();
    delay(delayVal);

    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);
        Wire.write(128);
    Wire.endTransmission(ADDRESS);
    delay(delayVal);

    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);
        Wire.write((byte)0);
    Wire.endTransmission(ADDRESS);
    delay(delayVal);

    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);
        Wire.write(128);
    Wire.endTransmission();
    delay(delayVal);
    return;
}

void compactOneServoTest(int servoNum, int pos, int delayAmt)
{
//    int servoNum, pos, delayAmt;
    Wire.beginTransmission(ADDRESS);
        Wire.write(servoNum);
        Wire.write(pos);
    Wire.endTransmission();
    delay(delayAmt);
    return;
}

void doubleCompactOneServoTest()
{
    compactOneServoTest(Y1P0, 255, 1000);
    compactOneServoTest(Y1P0, 128, 1000);
    compactOneServoTest(Y1P0, (byte)0, 1000); //byte 0's, err o.w.
    compactOneServoTest(Y1P0, 128, 1000);     //should reset pos
}

//void dance()
