int led = PC3; // pin = c3
int inputOne = PD1; // pin = d1
int inputTwo = PD2; // pin = d2

void setup() {
  pinMode(led, OUTPUT);
  pinMode(inputOne, INPUT_PULLUP);
  pinMode(inputTwo, INPUT_PULLUP);

}

void loop() {
  if(!digitalRead(inputOne)) {
    analogWrite(led, 256);
    delay(200);
    analogWrite(led, 0);
  };
  if(!digitalRead(inputTwo)) {
    analogWrite(led, 256);
    delay(200);
    analogWrite(led, 0);
  };
  analogWrite(led, 0);
}
