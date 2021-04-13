#include <SoftwareSerial.h>
 // arduino Rx (pin 2) ---- ESP8266 Tx
 // arduino Tx (pin 3) ---- ESP8266 Rx
SoftwareSerial esp8266(3,2); 

void setup()
{
 pinMode(13,OUTPUT);
 Serial.begin(9600);  // monitor serial del arduino
 esp8266.begin(9600); // baud rate del ESP8255
 
 //sendData("AT+CWMODE=3\r\n",1000); // configurar como MIXTO
 //endData("AT+CWJAP=\"FAMILIA BARRETO SANCHEZ\",\"GERMAN2018BARRETO\"\r\n",8000); //SSID y contraseña para unirse a red 
 //sendData("AT+CIFSR\r\n",1000);    // obtener dirección IP
 esp8266.print("AT+RST\r\n");
 delay(2000);
 //esp8266.print("AT+CWMODE=3\r\n");
 //delay(1000);
 //esp8266.print("AT+CWJAP=\"FAMILIA BARRETO SANCHEZ\",\"GERMAN2018BARRETO\"\r\n");
 //delay(8000);
 esp8266.print("AT+CIFSR\r\n");
 delay(1000);
 esp8266.print("AT+CIPMUX=1\r\n");
 delay(1000);
 esp8266.print("AT+CIPSERVER=1,1234\r\n");
 delay(1000);
 digitalWrite(13, HIGH);
 //sendData("AT+CIPMUX=1\r\n",1000); // configurar para multiples conexiones
 //sendData("AT+CIPSERVER=1,80\r\n",1000);         // servidor en el puerto 80
}

void loop()
{ 
  if (esp8266.available())
 
  { char c = esp8266.read();
    Serial.print(c);
    
  }
  if (Serial.available())
  { char c = Serial.read();
    esp8266.print(c);
  }
}
