#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>

#define CE_PIN 9
#define CSN_PIN 10
int up_button = 2; 
int down_button = 4;
int left_button  =5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int analog_button = 8;
int x_axis = A0;
int y_axis = A1;
int buttons[] = {up_button, down_button, left_button, right_button, start_button, select_button, analog_button};

//vericiii
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio (CE_PIN, CSN_PIN);
char msg [20]= "";

void setup() {

for (int i; i<7; i++)
{
pinMode(buttons[i], INPUT); 
digitalWrite(buttons[i], HIGH);
}

radio.begin();
radio.openWritingPipe(pipe);
  Serial.begin(9600);
}

void loop() {

if (digitalRead(up_button) ==LOW)
{

char msg[]="up";
radio.write(msg, sizeof(msg)); 
delay(300);
Serial.println("UP Button Pressed");
}


if (digitalRead(down_button)==LOW)
{
char msg[]="down";
radio.write(msg, sizeof(msg));
delay(300);
Serial.println("Down Button Pressed");
}
if (digitalRead(left_button) ==LOW)
{

char msg[]="left";
radio.write(msg, sizeof(msg)); 
delay(300);
Serial.println("Left Button Pressed");
}


if (digitalRead(right_button)==LOW)
{
char msg[]="right";
radio.write(msg, sizeof(msg));
delay(300);
Serial.println("Right Button Pressed");
}

if (analogRead(x_axis)>0 && analogRead(x_axis)<250)
{
char msg[]="left_x";
radio.write(msg, sizeof(msg));
delay(300);
Serial.println("left_x Pressed");
}
if (analogRead(x_axis)>750 && analogRead(x_axis)<1023)
{
char msg[]="right_x";
radio.write(msg, sizeof(msg));
delay(300);
Serial.println("right_x Pressed");
}

if (analogRead(y_axis)>0 && analogRead(y_axis)<250)
{
char msg[]="down_y";
radio.write(msg, sizeof(msg));
delay(300);
Serial.println("down_y Pressed");
}
if (analogRead(y_axis)>750 && analogRead(y_axis)<1023)
{
char msg[]="up_y";
radio.write(msg, sizeof(msg));
delay(300);
Serial.println("up_y Pressed");
}
}
