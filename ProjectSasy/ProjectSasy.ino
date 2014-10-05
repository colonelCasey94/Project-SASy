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

void input(float voltages[]);
float average(float voltages[]);

float averages[1000];

//sets up LCD output and analog input
void setup(){
  
}

void loop(){
  
}

void input(float voltages[]){
  
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
