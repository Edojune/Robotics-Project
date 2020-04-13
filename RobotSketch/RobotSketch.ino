// H-Bridge Pins
int EN_A = 10; // Enable pin for first motor
int IN1 = 9;   // Control pin for first motor(for direction)
int IN2 = 8;   // Control pin for first motor(for direction)
int IN3 = 7;   // Control pin for second motor
int IN4 = 6;   // Control pin for second motor
int EN_B = 5;  // Enable pin for second motor

// Variables for motors
int motor_speed1 = 200;
int motor_speed2 = 0;

int IR_PIN_1 = A0;
int IR_PIN_2 = A1;

int sensor1Val = 0;
int sensor2Val = 0;

void moveForward()
{
    analogWrite(EN_A, motor_speed1);
    analogWrite(EN_B, motor_speed1);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("forward");
}

void moveBackward()
{
    analogWrite(EN_A, motor_speed1);
    analogWrite(EN_B, motor_speed1);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("backward");
}

void moveRight()
{
    analogWrite(EN_A, motor_speed1);
    analogWrite(EN_B, motor_speed1);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("right");
}

void moveLeft()
{
    analogWrite(EN_A, motor_speed1);
    analogWrite(EN_B, motor_speed1);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Left");
}

void stop()
{
    digitalWrite(EN_A, LOW);
    digitalWrite(EN_B, LOW);
    Serial.println("Stop!");
}

// TODO calculate distance with ir sensors

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
    sensor1Val = analogRead(IR_PIN_1);
    sensor2Val = analogRead(IR_PIN_2);
    //int IR_SENSOR2 = analogRead(A1);
    Serial.println(sensor1Val);
    Serial.println(sensor2Val);
    if (sensor1Val > 0 && sensor2Val > 0)
    {
        moveForward();
    }
    else if (sensor1Val > 0 && sensor2Val == 0)
    {
        moveRight();
    }
    else if (sensor1Val == 0 && sensor2Val > 0)
    {
        moveLeft();
    }
    else
    {
        stop();
        moveLeft();
        moveLeft();
    }

    // moveForward();
    // moveForward();
    // moveBackward();
}
