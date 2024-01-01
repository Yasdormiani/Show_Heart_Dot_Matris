#include <MaxMatrix.h>
#include <LedControl.h>
int DIN = 12;
int CLK = 11;
int CS = 10;
int MAXINUSE = 1;
MaxMatrix m(DIN, CS, CLK, MAXINUSE);


LedControl lc = LedControl(DIN, CLK, CS, 0);
void setup() {
  lc.shutdown(0, false);   //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0, 15);  // Set the brightness to maximum value
  lc.clearDisplay(0);      // and clear the display
}
void loop() {
  byte f[8] = {
    0x00,
    0x66,
    0xFF,
    0xFF,
    0x7E,
    0x3C,
    0x18,
    0x00,
  };

  printByte(f);
  delay(1000);

}
void printByte(byte character[]) {
  int i = 0;
  for (i = 0; i < 8; i++) {
    lc.setRow(0, i, character[i]);
  }
}

int enA = 10;  
int in1 = 9; 
int in2 = 8; 
int pot = A0;

void setup()
{
  pinMode(enA, OUTPUT);  
  pinMode(in1, OUTPUT);   
  pinMode(in2, OUTPUT); 
  pinMode(pot, INPUT);  
}
void loop()
{
  int potValue = analogRead(pot);
  int motorSpeed = map(potValue, 0, 1023, 0, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, motorSpeed);
}
