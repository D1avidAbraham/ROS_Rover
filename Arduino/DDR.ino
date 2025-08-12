class DriveTrain{
    public:
        // Radius, Length, Max_W_rpm, MotorAPin1, MotorAPin2, MotorAPwm, MotorBPin1, MotorBPin2, MotorBPwm
        DriveTrain(float radius, float length, float W_max, int motorAPin1, int motorAPin2, int motorAPwm, int motorBPin1, int motorBPin2, int motorBPwm);
        void ddrSetup();
        void move(int V_x, int W);
        float leftDDR(int V_x, int W);
        float rightDDR(int V_x, int W);

    private:
        float _radius;
        float _length;
        float _W_max;
        int _motorAPin1;
        int _motorAPin2;
        int _motorAPwm;
        int _motorBPin1;
        int _motorBPin2;
        int _motorBPwm;
};

DriveTrain::DriveTrain(float radius, float length, float W_max, int motorAPin1, int motorAPin2, int motorAPwm, int motorBPin1, int motorBPin2, int motorBPwm){
    _radius = radius;
    _length = length;
    _W_max = W_max;
    _motorAPin1 = motorAPin1;
    _motorAPin2 = motorAPin2;
    _motorAPwm = motorAPwm;
    _motorBPin1 = motorBPin1;
    _motorBPin2 = motorBPin2;
    _motorBPwm = motorBPwm;
}

void DriveTrain::ddrSetup(){
    pinMode(_motorAPin1, OUTPUT);
    pinMode(_motorAPin2, OUTPUT);
    pinMode(_motorAPwm, OUTPUT);
    pinMode(_motorBPin1, OUTPUT);
    pinMode(_motorBPin2, OUTPUT);
    pinMode(_motorBPwm, OUTPUT);
}

void DriveTrain::move(int V_x, int W){
    if (V_x > 0 ){ 
        digitalWrite(_motorAPin1, HIGH);
        digitalWrite(_motorAPin2, LOW);
        digitalWrite(_motorBPin1, LOW);
        digitalWrite(_motorBPin2, HIGH);
    }else{
        digitalWrite(_motorAPin1, LOW);
        digitalWrite(_motorAPin2, HIGH);
        digitalWrite(_motorBPin1, HIGH);
        digitalWrite(_motorBPin2, LOW);
    }
    analogWrite(_motorAPwm, leftDDR( V_x, W));
    analogWrite(_motorBPwm, rightDDR( V_x, W));
}

float DriveTrain::leftDDR(int V_x, int W){
  return abs(V_x/_radius) - ((_length/2)*(W/_radius));
}

float DriveTrain::rightDDR(int V_x, int W){
  return  abs(V_x/_radius) + ((_length/2)*(W/_radius));
}


const float radius = .047625;
const float length = .1397;
const float W_max = 200; 
const int motorAPin1 = 4;
const int motorAPin2 = 5;
const int motorAPwm = 3; 
const int motorBPin1 = 7;
const int motorBPin2 = 8;
const int motorBPwm = 6;

int V_x = 0;
int W = 0;
DriveTrain Drive(radius, length, W_max, motorAPin1, motorAPin2, motorAPwm, motorBPin1, motorBPin2, motorBPwm);

void setup(){
    Serial.begin(115200);
    Serial.setTimeout(50);
    Drive.ddrSetup();

}

void loop(){
    if (Serial.available()>= 1) {
        /*
        String input = Serial.readString();
        int commaIndex = input.indexOf(',');
        String part1 = input.substring(0, commaIndex);
        String part2 = input.substring(commaIndex + 1);

        // Convert to float
        V_x = part1.toFloat();
        W = part2.toFloat();
        */
        V_x = Serial.parseFloat(); 
        W = Serial.parseFloat(); 
        Drive.move(V_x, W);
    }
     //Drive.move(V_x, W);

}