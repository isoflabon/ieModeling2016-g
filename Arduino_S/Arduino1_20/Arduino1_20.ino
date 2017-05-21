#include <ESP8266WiFi.h>
#include <Milkcocoa.h>
#include <IRremoteESP8266.h>

#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "XXXXXXXXX"
#define WLAN_PASS       "XXXXXXXXX"
IRsend irsend(13);
int RECV_PIN = 14; 
IRrecv irrecv(RECV_PIN);


/************************* Your Milkcocoa Setup *********************************/

#define MILKCOCOA_APP_ID      "woodixitlj8v"
#define DATASTORE_LED   "remote"
#define DATASTORE_Tv    "tvpush"


/************* Milkcocoa Setup (you don't need to change this!) ******************/

#define MILKCOCOA_SERVERPORT  1883


// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

const char MQTT_SERVER[] PROGMEM    = MILKCOCOA_APP_ID ".mlkcca.com";
const char MQTT_CLIENTID[] PROGMEM  = __TIME__ MILKCOCOA_APP_ID;


Milkcocoa milkcocoa = Milkcocoa(&client, MQTT_SERVER, MILKCOCOA_SERVERPORT, MILKCOCOA_APP_ID, MQTT_CLIENTID);


void onpush1(DataElement *elem) {
  Serial.println("onLEDpush");
  Serial.println(elem->getInt("sw"));
  if(elem->getInt("sw")==1){
    digitalWrite(12,HIGH);
  }else if(elem->getInt("sw")==0){
    digitalWrite(12,LOW);
  }
};

void onpush2(DataElement *elem) {
  Serial.println("TV_REMOTE");
  Serial.println(elem->getString("mem"));
  switch(atoi(elem->getString("mem"))){
    case(1):
      Serial.println("TV_ON・OFF");
      irsend.sendPanasonic(0x555A,0xF148688B);
      break;
    case(2):
      Serial.println("Volumeup");
     irsend.sendPanasonic(0x555A,0xF148288F);
     break;
    case(3):
      Serial.println("Volumedown");
     irsend.sendPanasonic(0x555A,0xF148A887);
     break;
     case(4):
      Serial.println("ch_change1");
     irsend.sendPanasonic(0x555A,0xF1488885);
     break;
     case(5):
      Serial.println("ch_change2");
     irsend.sendPanasonic(0x555A,0xF1484889);
     break;
  }
   
};


void setupWiFi() {
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}




decode_results results;

void setup() {
  
    pinMode(12,OUTPUT);
    irsend.begin();
  Serial.begin(115200);
   irsend.begin();
   irrecv.enableIRIn(); // Start the receiver
  delay(10);
  Serial.println(F("Milkcocoa SDK demo"));

  setupWiFi();
  
  WiFiManager wifiManager;

  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("connected...yeey :)");

  Serial.println( milkcocoa.on(DATASTORE_LED, "push", onpush1) );
  Serial.println( milkcocoa.on(DATASTORE_Tv, "push", onpush2) );
}


void dump(decode_results *results) {
  // Dumps out the decode_results structure.
  // Call this after IRrecv::decode()
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");

  }
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->panasonicAddress, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
    Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("Decoded AIWA RC T501: ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Decoded Whynter: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.write('-');
      Serial.print((unsigned long) results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {
   milkcocoa.loop();
   if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    dump(&results);
    irrecv.resume(); // Receive the next value
  }
  // put your main code here, to run repeatedly:
  delay(7000);
}
