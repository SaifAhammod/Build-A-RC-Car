// Motor 1
#define ENA 10  // Enable pin for Motor 1
#define IN1 9  // Motor 1 control pin 1
#define IN2 8  // Motor 1 control pin 2

// Motor 2
#define IN3 7  // Motor 2 control pin 1
#define IN4 6  // Motor 2 control pin 2
#define ENB 5 // Enable pin for Motor 2

char command;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600); // Default TX (1) & RX (0)
  Serial.println("Bluetooth RC Car Initialized...");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.print("Received Command: ");
    Serial.println(command);
    
    Stop(); // Stop before executing new command
    
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      default:
        Serial.println("Invalid Command Received");
    }
  }
}

void forward() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Moving Forward...");
}

void back() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Moving Backward...");
}

void left() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Turning Left...");
}

void right() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Turning Right...");
}

void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stopped");
}