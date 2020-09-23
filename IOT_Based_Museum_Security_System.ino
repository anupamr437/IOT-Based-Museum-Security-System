#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> // It provides ESP8266 specific Wi-Fi routines that we are calling to connect to the network.
#include <BlynkSimpleEsp8266.h> // It handles all the connection routines and data exchange between hardware, Blynk Cloud, and app.
#include<Servo.h> //It provides commands to control servo motors.
char auth[] = "1c777027bb32498c92ffbaca882f5688"; // Device Authentication Token to get the hardware online and connect it to Blynk Cloud
const int pirsensor=04; //D2
const int ldr=00; // connect to pin D3 of NodeMCU development board, which connects to GPIO 00 of ESP8266 microcontroller.
const int buzzerPin=02; //D4
const int servo1=14; //D5
const int servo2=12; //D6
const int servo3=13; //D7
int pirValue;
int ldrValue;
Servo servoA;
Servo servoD;
Servo servoE;
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, "XOLO", "88888888");
pinMode(pirsensor, INPUT);
pinMode(ldr, INPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(servo1, OUTPUT);
pinMode(servo2, OUTPUT);
pinMode(servo3, OUTPUT);
servoA.attach(servo1);
servoD.attach(servo2);
servoE.attach(servo3);
}
void loop()
{  
servoA.write(0);
servoD.write(0);
servoE.write(180);
digitalWrite(buzzerPin,LOW);
Blynk.run();
pirValue = digitalRead(04); // read the digital signal from PIR sensor
ldrValue = digitalRead(00); // read the digital signal from LDR Sensor Module
Serial.print("pirvalue=");
Serial.print(pirValue);
Serial.print("    and    ldrvalue=");
Serial.println(ldrValue);
if ((pirValue == 1 ) || (ldrValue==1)) // movement detected
{
Blynk.notify("Security Breach");
digitalWrite(buzzerPin,HIGH);
servoA.write(90);
servoD.write(90);
servoE.write(0);
delay(1000);
}
}
