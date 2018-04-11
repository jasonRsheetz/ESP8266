#include "ESP8266.h"

ESP8266::ESP8266()
{
//nothing to do in default constructor
}

//parameterized constructor
//Purpose: to set software serial pins to be used by the wifi module and set the ssid, password, API keys, and channel ID
//parameters:4 Strings, 2 integers
//return value(s): none
ESP8266::ESP8266(String _API_key, String _Channel_ID, int _RX, int _TX)
{

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

String ESP8266::JoinNetwork(String _SSID, String _password)
{
//set variables
SSID = _SSID;
password = _password;
String returnString;

String StringToSend = "AT+CWJAP_DEF=";
StringToSend += SSID;
StringToSend += ",";
StringToSend += password;


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


String ESP8266::Transmit(int _data, String field)
{
String responseString;

//establish connection with thingspeak.com
uart->println("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80");
_delay_ms(3000);

//the length of the web address for thingspeak 40 characters, plus to for the newline and carriage return characters
uint8_t webAddressLength = 42;

//find the length of the datafor O3
String dataToString = String(_data);


uint8_t dataLength =dataToString.length()+webAddressLength;

//send the number of characters to be updated
String dataLengthToString = String(dataLength);
String dataLengthcmd = "AT+CIPSEND=";
dataLengthcmd += dataLengthToString;

//send the data length
uart->println(dataLengthcmd);
_delay_ms(3000);

//piece the data together
String dataToSend = "GET /update?key=E2TKCCBA49LSZK2Q&field" + field + "=" + dataToString;


//close communications
uart->println(dataToSend);
_delay_ms(500);
uart->println("AT+CIPCLOSE");

return responseString;
}

void ESP8266::Sleep(int _sleepTime)
{
//transmit the sleep time
uart->println(String(_sleepTime);
}




























