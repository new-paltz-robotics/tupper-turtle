int analogPin = 5;     // potentiometer wiper (middle terminal) connected to analog pin 3
int rDirPin = 12; //12
int rBreakPin = 9; //9
int rSpeedPin = 3; //3

int lDirPin = 13; //13
int lBreakPin = 8; //8
int lSpeedPin = 11; //11
                       // outside leads to ground and +5V           // variable to store the value read

void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  int variance = sensorMethod();    // read the input pin
  Serial.println(variance);    // debug value
  if (variance >0)
    Serial.print("right");
  else
    Serial.print("left");
}


int sensorMethod(){
 //returns between +/-512 
 
  int val = analogRead(analogPin);  
  int turnAmount = 512 - val;
  return turnAmount;
  
}
