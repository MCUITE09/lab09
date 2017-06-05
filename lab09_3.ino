#include <Ultrasonic.h>
#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 11, 5, 4, 3, 6); // initialize interface pins
#define TRIGGER_PIN 8
#define ECHO_PIN 7
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
const byte intPin=2; //interrupt pin
const byte ledPin=13; //built-in LED
volatile boolean state=1; //initial value of switch pin
void setup() { 
pinMode(ledPin, OUTPUT); 
pinMode(intPin, INPUT_PULLUP);
digitalWrite(ledPin, LOW); 
attachInterrupt(0, int0, LOW);
lcd.begin(20, 2); // set up the LCD's number of columns and rows:
Serial.begin(9600);
}
void loop() { 
}

void int0() {  
  if (state) 
 {digitalWrite(ledPin, HIGH);
 }
else 
{digitalWrite(ledPin, LOW);
} 
float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
Serial.print("MS: "); 
Serial.print(microsec);
Serial.print(", CM: "); 
Serial.print(cmMsec);
Serial.print(", IN: "); 
Serial.println(inMsec);
lcd.print("CM:");
lcd.print(cmMsec);
//lcd.print(ultrasonic.convert(microsec, Ultrasonic::CM));
delay(100000);
lcd.clear();

state=!state;
}
