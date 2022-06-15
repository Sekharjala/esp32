#include <Arduino.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);//arduino pins connected to LCD
#include <Wire.h>
void dataRcv(int numBytes);
int i2c_rcv;               // data received from I2C bus
int R2;

void setup(){
	Wire.begin(0x09);           // join I2C bus as Slave with address 0x09
	Wire.onReceive(dataRcv);    // register an event handler for received data
	lcd.begin(16,2);
	lcd.setCursor(0,0);
	lcd.print("---- OHM METER ---");
}

void loop(){
	delay(1000);
}

//received data handler function
void dataRcv(int numBytes)
{
		while( Wire.available()) 
		{	
			i2c_rcv = Wire.read();
			int y = map(i2c_rcv,0,127,0,2000);
			lcd.setCursor(0,1);
			lcd.print("R = ");
			lcd.print(y);
			lcd.setCursor(8,1);
			lcd.print(" Ohm");
			Serial.println(y);
		}
}

