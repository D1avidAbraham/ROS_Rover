#include <Encoder.h>
#include <PID_v1.h>

// Pin definitions
const int encPinA = 2;
const int encPinB = 3;
const int pwmPin  = 9;
const int dirPin  = 8;

// Encoder object
Encoder motorEnc(encPinA, encPinB);

// PID variables
double  Setpoint;   // desired speed (counts/sec)
double  Input;      // measured speed
double  Output;     // PWM output (0–255)

// PID tuning parameters
double Kp = 2.0;
double Ki = 5.0;
double Kd = 1.0;

// Initialize PID
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// Timing
unsigned long lastTime = 0;
long         lastCount = 0;

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Start serial for debugging
  Serial.begin(9600);

  // Set desired speed (e.g., 1000 counts/sec)
  Setpoint = 1000;

  // Configure PID
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-255, 255);  // allow reverse
}

void loop() {
  unsigned long now = millis();
  unsigned long dt  = now - lastTime;

  if (dt >= 100) {  // update at 10 Hz
    long count = motorEnc.read();

    // Calculate speed in counts/sec
    Input = (double)(count - lastCount) * (1000.0 / dt);

    // Compute new PID output
    myPID.Compute();

    // Drive motor
    if (Output >= 0) {
      digitalWrite(dirPin, HIGH);
      analogWrite(pwmPin, (int)Output);
    } else {
      digitalWrite(dirPin, LOW);
      analogWrite(pwmPin, (int)(-Output));
    }

    // Debug
    Serial.print("Speed: "); Serial.print(Input);
    Serial.print("  PWM: ");   Serial.println(Output);

    // Prepare next iteration
    lastCount = count;
    lastTime  = now;
  }
}
