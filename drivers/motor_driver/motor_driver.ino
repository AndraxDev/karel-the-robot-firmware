#include <AFMotor.h> 

AF_DCMotor motor_left(4);
AF_DCMotor motor_right(3);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial initialized");
  motor_left.setSpeed(255);
  motor_left.run(RELEASE);
  motor_right.setSpeed(255);
  motor_right.run(RELEASE);
  
  pinMode(A0, INPUT); // CTRL PORT

  // MOTOR PORTS
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop() {
  // Wait until raspberry is not initialized
  if (analogRead(A4) > 500) {
    if (analogRead(A0) < 60 && analogRead(A1) < 60) {
      motor_left.run(RELEASE);
    } else if (analogRead(A0) > 500 && analogRead(A1) < 60) {
      motor_left.run(FORWARD);
    } else if (analogRead(A0) < 60 && analogRead(A1) > 500) {
      motor_left.run(BACKWARD);
    } else if (analogRead(A0) > 500 && analogRead(A1) > 500) {
      motor_left.run(RELEASE);
    }
  
    if (analogRead(A2) < 60 && analogRead(A3) < 60) {
      motor_right.run(RELEASE);
    } else if (analogRead(A2) > 500 && analogRead(A3) < 60) {
      motor_right.run(FORWARD);
    } else if (analogRead(A2) < 60 && analogRead(A3) > 500) {
      motor_right.run(BACKWARD);
    } else if (analogRead(A2) > 500 && analogRead(A3) > 500) {
      motor_right.run(RELEASE);
    }
  
    Serial.print(analogRead(A0));
    Serial.print(" ");
    Serial.print(analogRead(A1));
    Serial.print(" ");
    Serial.print(analogRead(A2));
    Serial.print(" ");
    Serial.println(analogRead(A3));
    delay(10);
  } else {
    Serial.println(analogRead(A4));
    delay(10);
  }
}
