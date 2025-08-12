// Left Motor Pin outs 
const int motorPin1 = 4;  // IN1 on motor driver
const int motorPin2 = 5;  // IN2 on motor driver
const int pwmPin = 3;  


const float radius = .047625; // raduis on wheel in m 
const float length = .1397 ; // distance between the two wheels in m 
const float W_max = 200; 

float V_x = 0; 
float W = 0; 
float pwmLeft = 0;

void setup() {
  // Set motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);
}

float leftDDR(int V_x, int W){
  return abs(V_x/radius) - ((length/2)*(W/radius));
}

float rightDDR(int V_x, int W){
  return  abs(V_x/radius) + ((length/2)*(W/radius));
}


void loop() {
  if (Serial.available()) {

    String input = Serial.readString();
    int commaIndex = input.indexOf(',');
    String part1 = input.substring(0, commaIndex);
    String part2 = input.substring(commaIndex + 1);

    // Convert to float
    V_x = part1.toFloat();
    W = part2.toFloat();
    // Move motor forward
    if (V_x > 0 ){ 
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
    }else{
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, HIGH);
    }

    pwmLeft = leftDDR(V_x, W)/W_max* 255.0;
   
    Serial.print("V_x: ");
    Serial.println(V_x);
    Serial.print("W: ");
    Serial.println(W);
    Serial.print("pwmLeft: ");
    Serial.println(abs(pwmLeft));
    



  }

  analogWrite(pwmPin, abs(pwmLeft));
  
  
  
 
  
}

