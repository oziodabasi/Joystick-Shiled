#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>
// ALICI
#define CE_PIN 9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio (CE_PIN, CSN_PIN);
char data [20];
void setup() {
    Serial.begin(9600);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(14,OUTPUT);
    pinMode(15,OUTPUT);
    pinMode(16,OUTPUT);
    pinMode(17,OUTPUT);
    Serial.begin(9600);
    radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
}

void loop() {
 
String msg="";
if (radio.available() )
{
radio.read(data, sizeof(data) );
Serial.println(data);
msg=data;

 if(msg=="up"){
 digitalWrite(2,1);
 digitalWrite(3,0);
 digitalWrite(4,0);
 digitalWrite(5,0);

 }
if(msg=="right"){
 digitalWrite(2,0);
 digitalWrite(3,1);
 digitalWrite(4,0);
 digitalWrite(5,0);

 }
if(msg=="down"){
 digitalWrite(2,0);
 digitalWrite(3,0);
 digitalWrite(4,1);
 digitalWrite(5,0);

 }
if(msg=="left"){
 digitalWrite(2,0);
 digitalWrite(3,0);
 digitalWrite(4,0);
 digitalWrite(5,1);

 }

        //joyistick


 if(msg=="up_y"){

 digitalWrite(14,1);
 digitalWrite(15,0);
 digitalWrite(16,0);
 digitalWrite(17,0);
 }
if(msg=="right_x"){

 digitalWrite(14,0);
 digitalWrite(15,1);
 digitalWrite(16,0);
 digitalWrite(17,0);
 }
if(msg=="down_y"){

digitalWrite(14,0);
 digitalWrite(15,0);
 digitalWrite(16,1);
 digitalWrite(17,0);
 }
if(msg=="left_x"){

 digitalWrite(14,0);
 digitalWrite(15,0);
 digitalWrite(16,0);
 digitalWrite(17,1);
 }


}

}
