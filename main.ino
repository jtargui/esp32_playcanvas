// Include the Libraries
#include <WiFi.h>
#include <HTTPClient.h>
#include <SocketIoClient.h>

// Wifi Credentials
const char* ssid = "QWERTY";
const char* password =  "h6y50k93";

// Teleclaw Login
const char* apiUsername = "Please Contact Teleclaw";
const char* apiPassword =  "Please Contact Teleclaw";

// Variables and Tokens
String userToken;
String userId;
String appId;
String did;
String token;

// Define Pin
const int blinkPin = 16;
const int switchPin = 32;
const int button1Pin = 25;
const int xPin = 33;
const int yPin = 34;

// Define Pin Readings
int buttonState;
int button1State;
int xVal;
int yVal;

// Client to connect server
SocketIoClient webSocket;

void event(const char * payload, size_t length) {
  Serial.println("got message");
}

void setup() {
  pinMode(blinkPin,switchPin,xPin,yPin,button1Pin);
  Serial.begin(115200);
  Serial.println("Run!");  
  wifi();
  if(WiFi.status() == WL_CONNECTED){
    //login();
    Serial.println("\nConnect!"); 
    Serial.println("\nCreate event");
    webSocket.on("playerData", event);
    webSocket.on("playerJoined", event);
    Serial.println("\nStarting connection to server...");
    webSocket.begin("lilac-seal.glitch.me");
    webSocket.emit("initialize");
  } else {
    Serial.println("No connect!");  
  }
}

void loop() { 
  webSocket.loop();
  
  // Readings from the Pin
  buttonState = digitalRead(switchPin);
  button1State = digitalRead(button1Pin);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);

  if(WiFi.status() == WL_CONNECTED){    
    //switchState(buttonState);
    //joyStickControl(xVal,yVal);
    //catchGift(button1State);
  }
} 
