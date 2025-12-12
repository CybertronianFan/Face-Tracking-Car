// Declares the motor shield pins that decide the speed and direction
int M1_Sp = 3;
int M1_Di = 4;
int M2_Sp = 11;
int M2_Di = 12;
int M3_Sp = 5;
int M3_Di = 8;
int M4_Sp = 6;
int M4_Di = 7;

// The function that makes the car move forward
void forward() {
  // Motor 1
  digitalWrite(M1_Di, LOW);
  analogWrite(M1_Sp, 200);

  // Motor 2
  digitalWrite(M2_Di, LOW);
  analogWrite(M2_Sp, 200);

  // Motor 3
  digitalWrite(M3_Di, LOW);
  analogWrite(M3_Sp, 200);

  // Motor 4
  digitalWrite(M4_Di, LOW);
  analogWrite(M4_Sp, 200);
}

void left(){
   // Motor 1
  digitalWrite(M1_Di, HIGH);
  analogWrite(M1_Sp, 200);

  // Motor 2
  digitalWrite(M2_Di, LOW);
  analogWrite(M2_Sp, 200);

  // Motor 3
  digitalWrite(M3_Di, HIGH);
  analogWrite(M3_Sp, 200);

  // Motor 4
  digitalWrite(M4_Di, LOW);
  analogWrite(M4_Sp, 200);
}

void right(){
   // Motor 1
  digitalWrite(M1_Di, LOW);
  analogWrite(M1_Sp, 200);

  // Motor 2
  digitalWrite(M2_Di, HIGH);
  analogWrite(M2_Sp, 200);

  // Motor 3
  digitalWrite(M3_Di, LOW);
  analogWrite(M3_Sp, 200);

  // Motor 4
  digitalWrite(M4_Di, HIGH);
  analogWrite(M4_Sp, 200);
}

void stopMotors() {
  analogWrite(M1_Sp, 0);
  analogWrite(M2_Sp, 0);
  analogWrite(M3_Sp, 0);
  analogWrite(M4_Sp, 0);
}

void setup() {
  Serial.begin(9600); // Begin serial communication

  // Set all direction pins as OUTPUT
  pinMode(M1_Di, OUTPUT);
  pinMode(M2_Di, OUTPUT);
  pinMode(M3_Di, OUTPUT);
  pinMode(M4_Di, OUTPUT);

  // Optional: initialize PWM pins (Arduino does not require pinMode for PWM)
}

void loop() {
  if (Serial.available() > 0){ // Check if any data is sent from Raspberry Pi
    char cmd = Serial.read(); // Read one character
    
    if (cmd == 'f') { // It detects that the serial is 'f' so the function 'forward' begins
      forward();
    }

    if (cmd == 'l') { // It detects that the serial is 'l' so the function 'left' begins
      left();
    }
    if (cmd == 'r') { // It detects that the serial is 'r' so the function 'right' begins
      right(); 
    }
    else if (cmd == 's') { // It detects the 's' serial to stop all of the motors 
      stopMotors(); // Stops all motors
    }
  } 
}
