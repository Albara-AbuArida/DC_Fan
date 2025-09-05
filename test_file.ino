// Pin Definitions
const int button0 = 2;
const int button1 = 3;
const int button2 = 4;
const int button3 = 5;

const int pwmPin = 9;  // Corresponds to RC2 with PWM

// seven-segment pins using pins 6 to 13
const int seg_pins[7] = {6, 7, 8, 10, 11, 12, 13};

const int in1 = 14;
const int in2 = 15;


void setup() {
  // Set up inputs
  pinMode(button0, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  // Set up PWM output
  pinMode(pwmPin, OUTPUT);

  // Set up 7-SEG pins as output
  for (int i = 0; i < 7; i++) {
    pinMode(seg_pins[i], OUTPUT);
  }

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Set the direction of the motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  //The motor runs in one direction only

  analogWrite(pwmPin, 0);  // Initially off
  write7SEG(0B00111111);// Initially 0 on seven-segment
}

void write7SEG(byte value) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(seg_pins[i], (value >> i) & 1);
  }
}

void loop() {
  if (digitalRead(button0) == HIGH) {
    analogWrite(pwmPin, 0); // PWM off
    write7SEG(0B00111111);
  }
  else if (digitalRead(button1) == HIGH) {
    analogWrite(pwmPin, 64); // ~25% duty cycle
    write7SEG(0B00000110);
  }
  else if (digitalRead(button2) == HIGH) {
    analogWrite(pwmPin, 127); // ~50% duty cycle
    write7SEG(0B01011011);
  }
  else if (digitalRead(button3) == HIGH) {
    analogWrite(pwmPin, 191); // ~75% duty cycle
    write7SEG(0B01001111);
  }
  

  delay(100);  // debounce delay
}
