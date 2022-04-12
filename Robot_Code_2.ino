const int in1 = 6; // Right Motor Pin 1 (Arduino Pin 6 to L298N IN1)
const int in2 = 5; // Right Motor Pin 2 (Arduino Pin 5 to L298N IN2)
const int in3 = 10; // Left Motor Pin 1 (Arduino Pin 10 to L298N IN3)
const int in4 = 11; // Left Motor Pin 2 (Arduino Pin 11 to L298N IN4)
const int IR1 = A0; // Left IR Sensor (Arduino Analog Pin A0 to Left IR Sensor OUT)
const int IR2 = A1; // Right IR Sensor (Arduino Analog Pin A1 to Right IR Sensor OUT)
const int speed1 = 125; // Speed of Motors
const int val = 1000; // Sets the limit for IR Sensor Detection
void setup() { // Start of Setup
  pinMode(in1,OUTPUT); // Specifies Right Motor Pin 1 as OUTPUT
  pinMode(in2,OUTPUT); // Specifies Right Motor Pin 1 as OUTPUT
  pinMode(in3,OUTPUT); // Specifies Left Motor Pin 1 as OUTPUT
  pinMode(in4,OUTPUT); // Specifies Left Motor Pin 1 as OUTPUT
  pinMode(IR1,INPUT); // Specifies Left IR Sensor as INPUT
  pinMode(IR2,INPUT); // Specifies Right IR Sensor as INPUT
} // End of Setup
void loop() { // Start of loop
  int IRS1 = analogRead(IR1); // Left IR Sensor Status (reads darker/black colors at higher values generally above 1000 and lighter/white colors at lower values generally under 50)
  int IRS2 = analogRead(IR2); // Right IR Sensor Status (reads darker/black colors at higher values generally above 1000 and lighter/white colors at lower values generally under 50)
  if (IRS1 > val && IRS2 > val){ // Forward Motion Condition (if both sensors read values above 1000 then move forward)
    digitalWrite(in1,LOW); // Set Right Motor Pin 1 to LOW 
    analogWrite(in2,speed1); // Set Right Motor Pin 2 to 'speed1' variable for set speed
    digitalWrite(in3,LOW); // Set Left Motor Pin 1 to LOW
    analogWrite(in4,speed1); // Set Left Motor Pin 2 to 'speed1' variable for set speed
  } // End of Forward Motion Condition
  else if (IRS1 < val && IRS2 < val){ // Stop Condition (if both sensors read values below 1000 then stop moving)
    digitalWrite(in1,LOW); // Set Right Motor Pin 1 to LOW
    digitalWrite(in2,LOW); // Set Right Motor Pin 2 to LOW
    digitalWrite(in3,LOW); // Set Left Motor Pin 1 to LOW
    digitalWrite(in4,LOW); // Set Left Motor Pin 2 to LOW
  } // End of Stop Condition
  else if (IRS1 > val && IRS2 < val){ // Right-Turning Condition (if the Left IR Sensor reads over 1000 and the Right IR Sensor reads under 1000 then turn right)
    digitalWrite(in1,LOW); // Set Right Motor Pin 1 to LOW
    analogWrite(in2,speed1); // Set Right Motor Pin 2 to 'speed1' variable for set speed
    analogWrite(in3,speed1); // Set Left Motor Pin 1 to 'speed1' variable for set speed
    digitalWrite(in4,LOW); // Set Left Motor Pin 2 to LOW
  } // End of Right=Turning Condition
  else if (IRS1 < val && IRS2 > val){ // Left-Turning Condition (if the Left IR Sensor reads under 1000 and the Right IR Sensor reads over 1000 then turn left)
    analogWrite(in1,speed1); // Set Right Motor Pin 1 to 'speed1' variable for set speed
    digitalWrite(in2,LOW); // Set Right Motor Pin 2 to LOW
    digitalWrite(in3,LOW); // Set Left Motor Pin 1 to LOW
    analogWrite(in4,speed1); // Set Left Motor Pin 2 to 'speed1' variable for set speed
  } // End of Left-Turning Condition
} // End of Loop/Program
