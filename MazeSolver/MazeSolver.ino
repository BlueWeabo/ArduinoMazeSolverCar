
#define LEFT 2
#define FRONT 3
#define MOTOR_FRONT_L_F 4
#define MOTOR_FRONT_L_B 5
#define MOTOR_FRONT_R_F 7
#define MOTOR_FRONT_R_B 6
#define MOTOR_BACK_L_F 8
#define MOTOR_BACK_L_B 9
#define MOTOR_BACK_R_F 13
#define MOTOR_BACK_R_B 12
#define MOTOR_SPEED_L 10
#define MOTOR_SPEED_R 11
#define SENSOR_CALC 340 / 1000 / 2

void setup() {
  pinMode(MOTOR_FRONT_L_F, OUTPUT);
  pinMode(MOTOR_FRONT_L_B, OUTPUT);
  pinMode(MOTOR_FRONT_R_F, OUTPUT);
  pinMode(MOTOR_FRONT_R_B, OUTPUT);
  pinMode(MOTOR_BACK_L_F, OUTPUT);
  pinMode(MOTOR_BACK_L_B, OUTPUT);
  pinMode(MOTOR_BACK_R_F, OUTPUT);
  pinMode(MOTOR_BACK_R_B, OUTPUT);
  pinMode(MOTOR_SPEED_L, OUTPUT);
  pinMode(MOTOR_SPEED_R, OUTPUT);
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
  pinMode(LEFT, OUTPUT);
  digitalWrite(LEFT, LOW);
  delayMicroseconds(2);
  digitalWrite(LEFT, HIGH);
  delayMicroseconds(10);
  digitalWrite(LEFT, LOW);
  pinMode(LEFT, INPUT);
  return float(pulseIn(LEFT, HIGH)) * SENSOR_CALC;
}

float checkFrontSensor() {
  pinMode(FRONT, OUTPUT);
  digitalWrite(FRONT, LOW);
  delayMicroseconds(2);
  digitalWrite(FRONT, HIGH);
  delayMicroseconds(10);
  digitalWrite(FRONT, LOW);
  pinMode(FRONT, INPUT);
  return float(pulseIn(FRONT, HIGH)) * SENSOR_CALC;
}

void goForwards() {
  digitalWrite(MOTOR_FRONT_L_F, HIGH);
  digitalWrite(MOTOR_FRONT_L_B, LOW);
  digitalWrite(MOTOR_FRONT_R_F, HIGH);
  digitalWrite(MOTOR_FRONT_R_B, LOW);
  digitalWrite(MOTOR_BACK_L_F, HIGH);
  digitalWrite(MOTOR_BACK_L_B, LOW);
  digitalWrite(MOTOR_BACK_R_F, HIGH);
  digitalWrite(MOTOR_BACK_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, 180);
  analogWrite(MOTOR_SPEED_R, 180);
}

void goBackwards() {
  digitalWrite(MOTOR_FRONT_L_F, LOW);
  digitalWrite(MOTOR_FRONT_L_B, HIGH);
  digitalWrite(MOTOR_FRONT_R_F, LOW);
  digitalWrite(MOTOR_FRONT_R_B, HIGH);
  digitalWrite(MOTOR_BACK_L_F, LOW);
  digitalWrite(MOTOR_BACK_L_B, HIGH);
  digitalWrite(MOTOR_BACK_R_F, LOW);
  digitalWrite(MOTOR_BACK_R_B, HIGH);
  analogWrite(MOTOR_SPEED_L, 180);
  analogWrite(MOTOR_SPEED_R, 180);
}

void goLeft() {
  digitalWrite(MOTOR_FRONT_L_F, HIGH);
  digitalWrite(MOTOR_FRONT_L_B, LOW);
  digitalWrite(MOTOR_FRONT_R_F, HIGH);
  digitalWrite(MOTOR_FRONT_R_B, LOW);
  digitalWrite(MOTOR_BACK_L_F, HIGH);
  digitalWrite(MOTOR_BACK_L_B, LOW);
  digitalWrite(MOTOR_BACK_R_F, HIGH);
  digitalWrite(MOTOR_BACK_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, 100);
  analogWrite(MOTOR_SPEED_R, 230);
}

void goRight() {
  digitalWrite(MOTOR_FRONT_L_F, LOW);
  digitalWrite(MOTOR_FRONT_L_B, HIGH);
  digitalWrite(MOTOR_FRONT_R_F, HIGH);
  digitalWrite(MOTOR_FRONT_R_B, LOW);
  digitalWrite(MOTOR_BACK_L_F, LOW);
  digitalWrite(MOTOR_BACK_L_B, HIGH);
  digitalWrite(MOTOR_BACK_R_F, HIGH);
  digitalWrite(MOTOR_BACK_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, 180);
  analogWrite(MOTOR_SPEED_R, 180);
}
