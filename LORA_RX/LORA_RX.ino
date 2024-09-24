#include <SPI.h>
#include <LoRa.h>
#include <Servo.h>

const int ledPin1 = 7;
const int ledPin2 = 4;
const int ledPin3 = 5;
const int ledPin4 = 6;

Servo ESC;     // create servo object to control the ESC
int potValue;  // variable to store received potentiometer value

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");
//  pinMode(LED,OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
ESC.attach(3, 1000, 2000); // (pin, min pulse width, max pulse width in microseconds)
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
void loop(){
  
  LED_one(); 
  LED_two(); 
  LED_tree();
  LED_four();
  bldc_out();
  }
void LED_one() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String receivedData = LoRa.readString();

    if (receivedData.equals("LED_ONE_ON")) {
      digitalWrite(ledPin1, HIGH);
      Serial.println("LED ONE turned ON");
    } else if (receivedData.equals("LED_ONE_OFF")) {
      digitalWrite(ledPin1, LOW);
      Serial.println("LED ONE turned OFF");
    }
  }
}
void LED_two() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String receivedData = LoRa.readString();

    if (receivedData.equals("LED_TWO_ON")) {
      digitalWrite(ledPin2, HIGH);
      Serial.println("LED TWO turned ON");
    } else if (receivedData.equals("LED_TWO_OFF")) {
      digitalWrite(ledPin2, LOW);
      Serial.println("LED TWO turned OFF");
    }
  }
}

void LED_tree() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String receivedData = LoRa.readString();

    if (receivedData.equals("LED_TREE_ON")) {
      digitalWrite(ledPin3, HIGH);
      Serial.println("LED TREE turned ON");
    } else if (receivedData.equals("LED_TREE_OFF")) {
      digitalWrite(ledPin3, LOW);
      Serial.println("LED TREE turned OFF");
    }
  }
}
void LED_four() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String receivedData = LoRa.readString();

    if (receivedData.equals("LED_FOUR_ON")) {
      digitalWrite(ledPin4, HIGH);
      Serial.println("LED FOUR turned ON");
    } else if (receivedData.equals("LED_FOUR_OFF")) {
      digitalWrite(ledPin4, LOW);
      Serial.println("LED FOUR turned OFF");
    }
  }
}


void bldc_out() {
  
  // Check if a LoRa packet is available
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Read the potentiometer value from the received packet
    String receivedData = "";
    while (LoRa.available()) {
      receivedData += (char)LoRa.read();
    }
    potValue = receivedData.toInt();

    // Print the received potentiometer value
    Serial.print("Received Potentiometer Value: ");
    Serial.println(potValue);

    // Control the ESC with the received potentiometer value
    ESC.write(potValue);
  }   
  }
       
