#include <WString.h>
#include <SoftwareSerial.h>

class ESP8266
{
public:
ESP8266();
ESP8266(String, String, String, String, int, int);
void Sleep(int);
String Transmit(String);
String SetWifiMode(int);

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
