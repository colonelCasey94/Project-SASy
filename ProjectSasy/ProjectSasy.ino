/*
  Project SASy
  Reads an analog input from a microphone and uses that input over time to calculate if a group of students
  is being too lound in which case the ATMEGA will flash a stobe.
  
  Code:
  Jacob Dorer
  Hannah Ingle
  
  Hardware:
  John "Jack" Gentery
  Rachel Powers
  (unknown)
*/

#include <LiquidCrystal.h>
#include <math.h>

//LCD creation
//LCD_RS pint to digital pin 12
//LCD_E pin to digital pin 11
//LCD_D(4:7) pins to digital pins (5:2)
//LiquidCrystal lcd (12,11,5,4,3,2);

//creates input array
void input(float voltages[]);
//calculates average of voltages
float average(float voltages[]);

//stores the voltage input 
#define arraySize 200
float inputs[arraySize];  //1000 floats exceeds the memory of the audrino so we downgraded to 200
float inputRef = 2.5;

//sets up LCD output and analog input
void setup(){
//  lcd.begin(16, 2);
//  lcd.print("hello, world!");
  delay(3000);
  Serial.begin(9600);
  Serial.print("hello initialize");
  pinMode(13, OUTPUT);
}

void loop(){
  delay(10);
  int i = 0;
  float temp = 0;
  input(inputs);

//  lcd.setCursor(0,1);
//  lcd.print("voltage = ");
 temp = average(inputs);
 
 Serial.print(temp,6);
 
 if(temp>0.1)
 {
   digitalWrite(13,HIGH);
   delay(500);
 }
 digitalWrite(13,LOW);
 //int ones = ((int)(temp))%10;
//int decimals = ((int)((temp)*100.0))%100;
//  lcd.print(ones);
//  lcd.print(".");
//  lcd.print(decimals);  
//Serial.print(ones);
//Serial.print(".");
//Serial.print(decimals);
Serial.print("end\n\n");
}

void input(float voltages[]){
//  lcd.setCursor(0,0);
//  lcd.print("recordning...");
  Serial.print("recording...\n");
  int i = 0;
  float temp = 0;
  for (i = 0; i < arraySize; i++){
    temp = analogRead(A0)*(5.0 / 1023.0)-inputRef;
    voltages[i] = abs(temp) ;
    delay(3);
  //int ones = (int)voltages[i]%10;
  //int decimals = (int)(voltages[i]*100)%100;
  //Serial.print(ones);
  //Serial.print(".");
  //Serial.print(decimals);
  //Serial.print("\n");

  }
 
}

float average(float voltages[]){
  int i = 0;   //counting varible
  float averageValue;
  Serial.print("In Average\n");
  //Serial.print(voltages[i]);
  //Serial.print("\n");

  for(i=0; i<arraySize-1; ++i)   //loop to iterate through array
{
    averageValue = voltages[i]+voltages[i+1];
}
  averageValue = averageValue/arraySize;    //takes the total voltage and divides by number of inputs
  //Serial.print(averageValue,6);
  //Serial.print("\n");
  return averageValue;
}
