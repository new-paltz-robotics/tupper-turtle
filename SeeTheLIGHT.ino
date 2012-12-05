int analogPin = 1;     // potentiometer wiper (middle terminal) connected to analog pin 3
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
