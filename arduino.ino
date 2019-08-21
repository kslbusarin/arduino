#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Config Firebase
#define FIREBASE_HOST "parkingdb-215c7.firebaseapp.com"
#define FIREBASE_AUTH "ePLbewj6DeaW8QTXBe4AmbzYAYi4T5rYALtljnm8"

// Config connect WiFi
#define WIFI_SSID "iot"
#define WIFI_PASSWORD "C0mputinG"

//int i = 0;

int trigPin1=D1;
int echoPin1=D2;
int trigPin2=D3;
int echoPin2=D4;
int trigPin3=D5;
int echoPin3=D6;
int trigPin4=D7;
int echoPin4=D8;;
long duration1,distance1,duration2,distance2,duration3,distance3,duration4,distance4;

void setup() {
  Serial.begin(115200);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
   /*if (distance1 >= 500 || distance1 <= 0){
    Serial.println("Out of range 1");
  }*/
  if (distance1 < 7) {
    Serial.print("building_b ");
    Serial.println(distance1);
    Firebase.setString("building_b/b01", "False");
    if (Firebase.failed()) {
      Serial.print("set building_b/b01 failed: ");
      Serial.println(Firebase.error());
      return;
    }
  } else {
    Serial.print("building_b ");
    Serial.println(distance1);
    Firebase.setString("building_b/b01", "True");
    if (Firebase.failed()) {
      Serial.print("set building_b/b01 failed: ");
      Serial.println(Firebase.error());
      return;
    }
  }
  delay(2);

  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;
   /*if (distance2 >= 500 || distance2 <= 0){
    Serial.println("Out of range 2");
  }*/
   if (distance2 < 7) {
    Serial.print("building_b ");
    Serial.println(distance2);
    Firebase.setString("building_b/b02", "False");
    if (Firebase.failed()) {
      Serial.print("set building_b/b02 failed: ");
      Serial.println(Firebase.error());
      return;}
  } else {
    Serial.print("building_b ");
    Serial.println(distance2);
    Firebase.setString("building_b/b02", "True");
    if (Firebase.failed()) {
      Serial.print("set building_b/b02 failed: ");
      Serial.println(Firebase.error());
      return;}
  }
  delay(2);


  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= (duration3/2) / 29.1;
  /* if (distance3 >= 500 || distance3 <= 0){
    Serial.println("Out of range3");
  }*/
   if (distance3 < 7) {
    Serial.print("building_b ");
    Serial.println(distance3);
    Firebase.setString("building_b/b03", "False");
    if (Firebase.failed()) {
      Serial.print("set building_b/b03 failed: ");
      Serial.println(Firebase.error());
      return;}
  } else {
    Serial.print("building_b ");
    Serial.println(distance3);
    Firebase.setString("building_b/b03", "True");
    if (Firebase.failed()) {
      Serial.print("set building_b/b03 failed: ");
      Serial.println(Firebase.error());
      return;}
  }
  delay(2);

  digitalWrite(trigPin4, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4= (duration4/2) / 29.1;
   /*if (distance4 >= 500 || distance4 <= 0){
    Serial.println("Out of range4");
  }*/
   if (distance4 < 7) {
    Serial.print("building_b ");
    Serial.println(distance4);
    Firebase.setString("building_b/b04", "False");
    if (Firebase.failed()) {
      Serial.print("set building_b/b04 failed: ");
      Serial.println(Firebase.error());
      return;}
  } else {
    Serial.print("building_b ");
    Serial.println(distance4);
    Firebase.setString("building_b/b04", "True");
    if (Firebase.failed()) {
      Serial.print("set building_b/b04 failed: ");
      Serial.println(Firebase.error());
      return;}
   }
  delay(2);
  /*
  Serial.print("building_b");
  Serial.println("parking: ");
  Serial.print("a01: ");
  Serial.println(Firebase.getString("building_b/parking/b01"));
  Serial.print("a02: ");
  Serial.println(Firebase.getString("building_b/parking/b02"));
  Serial.print("a03: ");
  Serial.println(Firebase.getString("building_b/parking/b03"));
  Serial.print("a04: ");
  Serial.println(Firebase.getString("building_b/parking/b04"));
  //Serial.print("Available: ");
 // Serial.println(Firebase.getBool("building_b/available"));*/
 // Serial.println("----------");


}
