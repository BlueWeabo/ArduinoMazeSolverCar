
#define LEFT_T 2
#define LEFT_E 3
#define FRONT_T 8
#define FRONT_E 9
#define MOTOR_L_F 4
#define MOTOR_L_B 5
#define MOTOR_R_F 7
#define MOTOR_R_B 6
#define MOTOR_SPEED_L 10
#define MOTOR_SPEED_R 11
#define SENSOR_CALC 340 / 1000 / 2

void setup() {
  pinMode(MOTOR_L_F, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
  pinMode(MOTOR_R_F, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);
  pinMode(MOTOR_SPEED_L, OUTPUT);
  pinMode(MOTOR_SPEED_R, OUTPUT);
  pinMode(LEFT_T, OUTPUT);
  pinMode(LEFT_E, INPUT);
  pinMode(FRONT_T, OUTPUT);
  pinMode(FRONT_E, INPUT);
}

void loop() {
  float leftSensor = checkLeftSensor();
  float frontSensor = checkFrontSensor();
  if (leftSensor > 3.6f) {
    goLeft();
  } else if (frontSensor < 4.5f) {
    goRight();
  } else if (frontSensor < 2.5f) {
    goBackwards();
  } else {
    goForwards();
  }
}

float checkLeftSensor() {
  digitalWrite(LEFT_T, LOW);
  delayMicroseconds(2);
  digitalWrite(LEFT_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(LEFT_T, LOW);
  return float(pulseIn(LEFT_E, HIGH)) * SENSOR_CALC;
}

float checkFrontSensor() {
  digitalWrite(FRONT_T, LOW);
  delayMicroseconds(2);
  digitalWrite(FRONT_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(FRONT_T, LOW);
  return float(pulseIn(FRONT_E, HIGH)) * SENSOR_CALC;
}

void goForwards() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, 180);
  analogWrite(MOTOR_SPEED_R, 180);
}

void goBackwards() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTOR_SPEED_L, 180);
  analogWrite(MOTOR_SPEED_R, 180);
}

void goLeft() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, 100);
  analogWrite(MOTOR_SPEED_R, 230);
}

void goRight() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTOR_SPEED_L, 180);
  analogWrite(MOTOR_SPEED_R, 180);
}
