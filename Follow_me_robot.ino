#include <NewPing.h>

// Define motor pins
#define MOTOR_A_EN 5
#define MOTOR_B_EN 6
#define MOTOR_A_DIR1 7
#define MOTOR_A_DIR2 8
#define MOTOR_B_DIR1 9
#define MOTOR_B_DIR2 10


#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
 
  pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(MOTOR_B_EN, OUTPUT);
  pinMode(MOTOR_A_DIR1, OUTPUT);
  pinMode(MOTOR_A_DIR2, OUTPUT);
  pinMode(MOTOR_B_DIR1, OUTPUT);
  pinMode(MOTOR_B_DIR2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
 
  unsigned int distance = sonar.ping_cm();

 
  Serial.print("Distance: ");
  Serial.println(distance);

  
  if (distance > 0 && distance < 30) { 
    stopMotors();
  } else if (distance >= 30) { 
    moveForward();
  }

  delay(100); 
}
void stopMotors() {
  digitalWrite(MOTOR_A_EN, LOW);
  digitalWrite(MOTOR_B_EN, LOW);
}
void moveForward() {
  digitalWrite(MOTOR_A_EN, HIGH);
  digitalWrite(MOTOR_B_EN, HIGH);
  digitalWrite(MOTOR_A_DIR1, HIGH);
  digitalWrite(MOTOR_A_DIR2, LOW);
  digitalWrite(MOTOR_B_DIR1, HIGH);
  digitalWrite(MOTOR_B_DIR2, LOW);
}
