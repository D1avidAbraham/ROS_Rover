#include <Encoder.h>
#include <PID_v1.h>

// Motor driver pins
const int dirPin1 = 7;
const int dirPin2 = 8;
const int pwmPin  = 9;

// Encoder pins
const int encPinA = 2;
const int encPinB = 3;

// PID variables
double Setpoint, Input, Output;
double Kp = 2.0, Ki = 0.5, Kd = 1.0;

// Instantiate encoder and PID controller
Encoder motorEnc(encPinA, encPinB);
PID motorPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// Target position in encoder ticks
long targetTicks = 2000;

void setup() {
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);

  Serial.begin(9600);

  // Initialize PID for position control
  Setpoint = targetTicks;
  motorPID.SetMode(AUTOMATIC);
  motorPID.SetOutputLimits(-255, 255);
}

void loop() {
  // 1) Read current encoder position
  Input = motorEnc.read();

  // 2) Compute PID output (signed PWM command)
  motorPID.Compute();

  // 3) Drive motor direction & speed
  if (fabs(Setpoint - Input) > 1) {  // deadband of 1 tick
    if (Output >= 0) {
      digitalWrite(dirPin1, HIGH);
      digitalWrite(dirPin2, LOW);
      analogWrite(pwmPin, Output);
    } else {
      digitalWrite(dirPin1, LOW);
      digitalWrite(dirPin2, HIGH);
      analogWrite(pwmPin, -Output);
    }
  } else {
    // Stop motor when within deadband
    analogWrite(pwmPin, 0);
  }

  // 4) Debugging output
  Serial.print("Position: "); Serial.print(Input);
  Serial.print("  Output: ");  Serial.println(Output);

  delay(50);
}
