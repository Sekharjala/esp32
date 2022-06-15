#include <Arduino.h>
#include <Wire.h>

byte i2c_rcv;               // data received from I2C bus
byte val;             // potentiometer position
byte pot_value;
//Declarations
int V_out_q=0;
//V_out_q is the quantized voltage
float V_in =5;
float V_out;
//V_in = V_cc
float R1=220;
int R2; 
//R1 is known resistance
//R2 is unknown resistance

// requests data handler function
void dataRqst(){
	V_out_q=analogRead(A0);//reading from A0
	//V_out is the actual voltage at the junction of R1 and R2
	V_out = V_in*V_out_q/1023;
	R2 = (R1/((V_in / V_out)-1));
	int y = map(R2,0,2000,0,127);
	Wire.write(y); // send resistance value
  	
}

void setup(){
	Wire.begin(0x08);           // join I2C bus as Slave with address 0x08
	Wire.onRequest(dataRqst);   // register an event handler for data requests
	Serial.begin(9600);
}

void loop(){
delay(1000);
}


