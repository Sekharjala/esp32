#include <Arduino.h>
#include <Wire.h>

int i2c_rcv;               // data received from I2C bus

void setup(){
	Serial.begin(9600);
  	Wire.begin(); // join I2C bus as the master


}

void loop(){
		
		Wire.requestFrom(0x08,01);    // request potentiometer position from slave 0x08
	      // read response from slave 0x08
		while (Wire.available()) {  // slave may send less than requested
      	i2c_rcv = Wire.read(); 
		delay(200);  
		}
// send recieved to Slave device 0x09
	
	Wire.beginTransmission(0x09); // informs the bus that we will be sending data to slave device 9 (0x09)
	Wire.write(i2c_rcv); 
	Serial.print("TX loop ");
	delay(1000);
	Serial.print(i2c_rcv);       // send value_pot
	Wire.endTransmission();       // informs the bus and the slave device that we have finished sending data
  Serial.println(" sent");	
}
