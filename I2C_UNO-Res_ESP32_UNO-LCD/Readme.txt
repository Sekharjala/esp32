This Project is to measure resistance from an Arduino Uno and Display the results in Another Arduino Using I2C Protocol.

I2C master  Folder consists of code assosiated to Define ESP32 As a Master. This Code recieves data From Slave1 And Transmit the data to Slave2 using I2c Bus.
I2C pins of Esp32 are (SDA-21,SCL-22) 


Slave 1 Folder is assosiated to Resistance measuring Arduino Code and the Address of the UNO is Defined as 0x08. Flash this Code On one of the arduino Boards.
Use Analog Pin A0 to Measure the unknown Resistance. Connected I2C pins (SDA-A4,SCL-A5) to I2C Bus.
 
 
Now,

Slave 2 is associated to a Displaying the Measured Resistance on LCD (16x2). As in the discription Below

Arduino Pins	LCD Pins	  LCD Pin     LCD Pin Description
GND	          1	          GND	
5V	          2	          Vcc	
GND	          3	          Vee	        Contrast
D12	          4	          RS	        Register Select
GND	          5	          R/W	        Read/Write
D11	          6	          EN	        Enable
D5	          11	        DB4	        Serial Connection
D4	          12	        DB5	        Serial Connection
D3	          13	        DB6	        Serial Connection
D2	          14	        DB7	        Serial Connection
5V	          15	        LED+	      Backlight
GND	          16	        LED-	      Backlight

Conncet to I2C bus using I2C pins (SDA-A4,SCL-A5).This is connected to I2c Using the address 0x09.
