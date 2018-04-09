#include "ESP8266.h"

ESP8266::ESP8266()
{
//nothing to do in default constructor
}

//parameterized constructor
//Purpose: to set software serial pins to be used by the wifi module and set the ssid, password, API keys, and channel ID
//parameters:4 Strings, 2 integers
//return value(s): none
ESP8266::ESP8266(String _SSID, String _password, String _API_key, String _Channel_ID, int _RX, int _TX)
{
//set variables
SSID = _SSID;
password = _password;

RX = _RX;
TX = _TX;

API_key = _API_key;
channel_ID = _Channel_ID;

//start softwareSerial 
uart = new SoftwareSerial(RX, TX);
uart->begin(9600);
}

//SetWifiMode
//Purpose: To change the wifi mode of the esp8266
//parameters:integer
//return value(s): String
String ESP8266::SetWifiMode(int _mode)
{
String changeMode = "AT+CWMODE_DEF=";
char response;
String returnString;

//add the mode number to the header string;
changeMode += _mode;

//send the wifi mode to the module
uart->println(changeMode);

//wait for a response
while(uart->available() == 0)
{}

//listen for the response and return it
while(uart->available() > 0)
{
	if(uart->available())
	{
		returnString += char(uart->read());
	}
}

return returnString;
}

































