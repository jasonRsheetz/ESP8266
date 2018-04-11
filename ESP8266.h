#include <WString.h>
#include <SoftwareSerial.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

class ESP8266
{
public:
ESP8266();
ESP8266(String, String, int, int);
void Sleep(int);
String Transmit(int, String);
String SetWifiMode(int);
String JoinNetwork(String, String);
void Sleep(int);

private:
//pointer to a software serial object
SoftwareSerial *uart;

//wifi varibles
String SSID;
String password;

//softwareSerial pins
int RX;
int TX;

//thingspeak variables
String API_key;
String channel_ID;
};


