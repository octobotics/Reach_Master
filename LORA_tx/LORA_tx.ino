#include <SPI.h>
#include <LoRa.h>
#include <Servo.h>


Servo ESC;     // create servo object to control the ESC

int potValue;  // value from the analog pin
int butt_Pin1 = A3; // Pin connected to the push button
int butt_Pin2 = A4;
int butt_Pin3 = A2;
int butt_Pin4 = A1;
void setup() {
  Serial.begin(9600);
  pinMode(butt_Pin1, INPUT);
  pinMode(butt_Pin2, INPUT);
  pinMode(butt_Pin3, INPUT);
  pinMode(butt_Pin4, INPUT);
//  pinMode(pot_pin,   INPUT);
  while (!Serial);
  Serial.println("LoRa Sender");

  
  
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
void loop(){
  
  butt_one();
  butt_two();
  butt_tree();
  butt_four();
  pot_value();  
  //LoRa.endPacket();
  
  }
void butt_one() {
  int buttonState = digitalRead(butt_Pin1);

  if (buttonState == LOW) {
    Serial.println("Sending command: LED ONE ON ");
    LoRa.beginPacket();
    LoRa.print("LED_ONE_ON");
    LoRa.endPacket();
    //delay(1000);
  } else {
    Serial.println("Sending command: LED ONE OFF ");
    LoRa.beginPacket();
    LoRa.print("LED_ONE_OFF");
    LoRa.endPacket();
    //delay(1000);
  }
}

void butt_two() {
  int buttonState = digitalRead(butt_Pin2);

  if (buttonState == LOW) {
    Serial.println("Sending command: LED TWO ON ");
    LoRa.beginPacket();
    LoRa.print("LED_TWO_ON");
    LoRa.endPacket();
    //delay(1000);
  } else {
    Serial.println("Sending command: LED TWO OFF ");
    LoRa.beginPacket();
    LoRa.print("LED_TWO_OFF");
    LoRa.endPacket();
    //delay(1000);
  }
}
void butt_tree() {
  int buttonState = digitalRead(butt_Pin3);

  if (buttonState == LOW) {
    Serial.println("Sending command: LED TREE ON");
    LoRa.beginPacket();
    LoRa.print("LED_TREE_ON");
    LoRa.endPacket();
    //delay(1000);
  } else {
    Serial.println("Sending command: LED TREE OFF");
    LoRa.beginPacket();
    LoRa.print("LED_TREE_OFF");
    LoRa.endPacket();
    //delay(1000);
  }
}

void butt_four() {
  int buttonState = digitalRead(butt_Pin4);

  if (buttonState == LOW) {
    Serial.println("Sending command: LED FOUR ON");
    LoRa.beginPacket();
    LoRa.print("LED_FOUR_ON");
    LoRa.endPacket();
    //delay(1000);
  } else {
    Serial.println("Sending command: LED FOUR OFF");
    LoRa.beginPacket();
    LoRa.print("LED_FOUR_OFF");
    LoRa.endPacket();
    //delay(1000);
  }
}
void pot_value(){
  
       potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  ESC.write(potValue);    // Send the signal to the ESC

  // Send potentiometer value over LoRa
  String message = String(potValue);
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  //delay(500);  // Add a delay to avoid sending data too frequently
  
  }
