// H-Bridge Pins
int EN_A = 10; // Enable pin for first motor
int IN1 = 9; // Control pin for first motor(for direction)
int IN2 = 8; // Control pin for first motor(for direction)
int IN3 = 7; // Control pin for second motor 
int IN4 = 6; // Control pin for second motor 
int EN_B = 5; // Enable pin for second motor

// Variables for motors
int motor_speed1 = 255;
int motor_speed2 = 0;

void setup()
{
    Serial.begin(9600); //Starting the serial communication at 9600 baud rate
    //Initializing the motor pins as output
    pinMode(EN_A, OUTPUT);
    pinMode(IN1, OUTPUT);  
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);  
    pinMode(IN4, OUTPUT);
    pinMode(EN_B, OUTPUT);
}

void loop()
{
    //
    int IR_SENSOR1 = analogRead(A0);
    //int IR_SENSOR2 = analogRead(A1);
    Serial.println(IR_SENSOR1);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(25);
    analogWrite(EN_A, motor_speed1);
    //delay(3000);
    //analogWrite(EN_A, 0);
    delay(3000);
}
