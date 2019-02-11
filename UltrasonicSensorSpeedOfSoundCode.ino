int trigPin=13; //Sensor trig pin is connected to 13
int echoPin=11; //Sensor echo pin is connected to 11
float pingTime; //Time for ping to hit and return
float speedOfSound; //We will calculate the speed of sound
float targetDistance=4;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //Turn on serial port
  pinMode(trigPin, OUTPUT); //Set trig pin as an output
  pinMode(echoPin, INPUT); //Set echo pin as an input


}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Pause to let signal settle
  digitalWrite(trigPin, HIGH); //Set trigger pin high
  delayMicroseconds(10); //Pasue with trigger pin HIGH
  digitalWrite(trigPin,LOW); //Finish trigger pulse by bringing it low

  pingTime = pulseIn(echoPin,HIGH); //Measure ping travel time in microseconds

  speedOfSound = 2*targetDistance/pingTime;  //Give us speed in inches per microseconds
  speedOfSound = speedOfSound/63360*1000000*3600;  //Gives us speed in miles per hour

  Serial.print("The speed of sound is: ");
  Serial.print(speedOfSound);
  Serial.println("miles per hour");
  delay(3000);
}