// H-Bridge Pins
int EN_A = 10; // Enable pin for first motor
int IN1 = 9;   // Control pin for first motor(for direction)
int IN2 = 8;   // Control pin for first motor(for direction)
int IN3 = 7;   // Control pin for second motor
int IN4 = 6;   // Control pin for second motor
int EN_B = 5;  // Enable pin for second motor

// Variables for motors
int motor_speed1 = 235;
;
int motor_speed2 = 0;

int IR_PIN_1 = A0;
int IR_PIN_2 = A1;

const int LED = 13;

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

void stopMovement()
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
    // Initializing infrared sensor pins
    pinMode(IR_PIN_1, INPUT);
    pinMode(IR_PIN_2, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    //
    sensor1Val = analogRead(IR_PIN_1);
    sensor2Val = analogRead(IR_PIN_2);
    //int IR_SENSOR2 = analogRead(A1);
    Serial.println(sensor1Val);
    Serial.println(sensor2Val);
    if  (digitalRead(IR_PIN_1) == HIGH && digitalRead(IR_PIN_2) == HIGH)
    {
        digitalWrite(LED, HIGH);
        moveForward();
    }
    else if (digitalRead(IR_PIN_1) == LOW && digitalRead(IR_PIN_2) == HIGH)
    {
        digitalWrite(LED, HIGH);
        moveRight();
    }
    else if (digitalRead(IR_PIN_1) == HIGH && digitalRead(IR_PIN_2) == LOW)
    {
        digitalWrite(LED, HIGH);
        moveLeft();
    }
    else
    {
        digitalWrite(LED, LOW);
        stopMovement();
//        moveLeft();
//        moveLeft();
    }

    // moveForward();
    // moveForward();
    // moveBackward();
}
