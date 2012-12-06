int analogPin = 5;     // potentiometer wiper (middle terminal) connected to analog pin 3
int rDirPin = 12; //12
int rBreakPin = 9; //9
int rSpeedPin = 3; //3

int RIGHT = 1;
int LEFT = 0;

int lDirPin = 13; //13
int lBreakPin = 8; //8
int lSpeedPin = 11; //11
                       // outside leads to ground and +5V           // variable to store the value read

void setup()
{
  Serial.begin(9600);          //  setup serial
  
  pinMode(rDirPin, OUTPUT); //Initiates Motor Channel A pin
  pinMode(rBreakPin, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(lDirPin, OUTPUT); //Initiates Motor Channel A pin
  pinMode(lBreakPin, OUTPUT);  //Initiates Brake Channel A pin
  
}

void loop()
{
  int variance = sensorMethod();    // read the input pin
  Serial.println(variance);    // debug value
  if (variance >0){
    Serial.print("right");
    turn(RIGHT, variance);
  }
  else{
    turn(LEFT, (-1* variance));
    Serial.print("left");
  }
}


void turn(int dir, int magnitude){
 if (dir == LEFT) {
   digitalWrite(rDirPin, HIGH);
   digitalWrite(rBreakPin, LOW);
   analogWrite(rSpeedPin, magnitude);
   
   digitalWrite(lDirPin, HIGH); 
   digitalWrite(lBreakPin, LOW); //Disengage the Brake for Channel B
   analogWrite(lSpeedPin, magnitude); 
 }
 if (dir == RIGHT){
   digitalWrite(rDirPin, LOW);
   digitalWrite(rBreakPin, LOW);
   analogWrite(rSpeedPin, magnitude);
   
   digitalWrite(lDirPin, LOW); 
   digitalWrite(lBreakPin, LOW); //Disengage the Brake for Channel B
   analogWrite(lSpeedPin, magnitude); 
 }
 
 
}

int sensorMethod(){
 //returns between +/-512 
 
  int val = analogRead(analogPin);  
  int turnAmount = 512 - val;
  return turnAmount;
  
}
