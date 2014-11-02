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
float inputs[1000];
float inputRef = 2.5;

//sets up LCD output and analog input
void setup(){
//  lcd.begin(16, 2);
//  lcd.print("hello, world!");
  delay(3000);
  Serial.begin(9600);
  Serial.print("hello");
}

void loop(){
  input(inputs);
//  lcd.setCursor(0,1);
//  lcd.print("voltage = ");
  int ones = (int)average(inputs)%10;
  int decimals = (int)(average(inputs)*100)%100;
//  lcd.print(ones);
//  lcd.print(".");
//  lcd.print(decimals);  
Serial.print(ones);
Serial.print(".");
Serial.print(decimals);
Serial.print("hello");
}

void input(float voltages[]){
//  lcd.setCursor(0,0);
//  lcd.print("recordning...");
  Serial.print("recording...\n");
  int i = 0;
  for (i = 0; i < 1000; i++){
    voltages[i] = abs((analogRead(A0)*(5.0 / 1023.0))-inputRef) ;
    delay(3);
  }
}

float average(float voltages[]){
  int i = 0;   //counting varible
  float averageValue;

  for(i=0; i<1000; ++i)   //loop to iterate through array
{
    averageValue = voltages[i]+voltages[i+1];
}
  averageValue = averageValue/1000;    //takes the total voltage and divides by number of inputs
  
  return averageValue;
}
