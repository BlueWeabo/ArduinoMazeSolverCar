
#define LEFT_T 3
#define LEFT_E 4
#define FRONT_T 11
#define FRONT_E 12
#define MOTOR_L_F 8
#define MOTOR_L_B 7
#define MOTOR_R_F 6
#define MOTOR_R_B 5
#define MOTOR_SPEED_L 10
#define MOTOR_SPEED_R 9
#define SPEED 50
const float SENSOR_CALC = 29.0 * 2.0;

void setup() {
  Serial.begin(9600);
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
  Serial.println(leftSensor);
  Serial.println(frontSensor);
  if (leftSensor > 5.8f) {
    goLeft();
  } else if (frontSensor > 200.00f) {
    goBackwards();
  } else if (frontSensor < 3.00f) {
    goBackwards();
  } else if (frontSensor < 4.50f) {
    goRight();
    delay(5 00);
  } else if (leftSensor < 3.00f) {
    goSmallRight();
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
  return float(pulseIn(LEFT_E, HIGH)) / SENSOR_CALC;
}

float checkFrontSensor() {
  digitalWrite(FRONT_T, LOW);
  delayMicroseconds(2);
  digitalWrite(FRONT_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(FRONT_T, LOW);
  return float(pulseIn(FRONT_E, HIGH)) / SENSOR_CALC;
}

void goForwards() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, SPEED);
  analogWrite(MOTOR_SPEED_R, SPEED);
}

void goBackwards() {
  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTOR_SPEED_L, SPEED);
  analogWrite(MOTOR_SPEED_R, SPEED);
}

void goLeft() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, SPEED/2);
  analogWrite(MOTOR_SPEED_R, SPEED*7/4);
}

void goRight() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);
  analogWrite(MOTOR_SPEED_L, SPEED*3/2);
  analogWrite(MOTOR_SPEED_R, SPEED*3/2);
}

void goSmallRight() {
  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);
  analogWrite(MOTOR_SPEED_L, SPEED*5/4);
  analogWrite(MOTOR_SPEED_R, SPEED*3/4);
}
