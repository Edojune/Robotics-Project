#include <SharpIR.h>

#define model 1080

// H-Bridge Pins
int EN_A = 10; // Enable pin for first motor
int IN1 = 9;   // Control pin for first motor(for direction)
int IN2 = 8;   // Control pin for first motor(for direction)
int IN3 = 7;   // Control pin for second motor
int IN4 = 6;   // Control pin for second motor
int EN_B = 5;  // Enable pin for second motor

// Variables for motors
// Motors WILL NOT respond to speeds higher than 235!
int motor_speed1 = 150;
int motor_speed2 = 0;

int IR_PIN_1 = A0;
int IR_PIN_2 = A1;

const int LED = 13;

int sensor1Val = 0;
int sensor2Val = 0;

int sensor1Dig = 0;
int sensor2Dig = 0;

int distance1 = 0;
int distance2 = 0;

int MIN_DISTANCE = 15;

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

void stopMovement()
{
    digitalWrite(EN_A, LOW);
    digitalWrite(EN_B, LOW);
    Serial.println("Stop!");
}

SharpIR sensor1 = SharpIR(IR_PIN_1, model);
SharpIR sensor2 = SharpIR(IR_PIN_2, model);

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
    // Initializing infrared sensor pins
    pinMode(IR_PIN_1, INPUT);
    pinMode(IR_PIN_2, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    // Debug messages.
    sensor1Dig = digitalRead(IR_PIN_1);
    sensor2Dig = digitalRead(IR_PIN_2);
    distance1 = sensor1.distance();
    distance2 = sensor2.distance();
    Serial.println("digital for s1: ");
    Serial.println(distance1);
    Serial.println("digital for s2: ");
    Serial.println(distance2);
    // if (distance1 <= MIN_DISTANCE && distance2 <= MIN_DISTANCE)
    if (sensor1Dig == HIGH && sensor2Dig == HIGH)
    {
        delay(100);
        digitalWrite(LED, HIGH);
        moveForward();
    }
    // Movement direction opposite of active sensor
    // else if (distance1 <= MIN_DISTANCE && distance2 > MIN_DISTANCE)
    else if (sensor1Dig == HIGH && sensor2Dig == LOW)
    {
        delay(100);
        digitalWrite(LED, HIGH);
        moveLeft();
    }
    // else if (distance1 > MIN_DISTANCE && distance2 <= MIN_DISTANCE)
    else if (sensor1Dig == LOW && sensor2Dig == HIGH)
    {
        delay(100);
        digitalWrite(LED, HIGH);
        moveRight();
    }
    else
    {
        digitalWrite(LED, LOW);
        stopMovement();
    }
}
