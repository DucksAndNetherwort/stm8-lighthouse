int led = 5; // pin = c3
int inputOne = 10; // pin = d1
int inputTwo = 11; // pin = d2

void setup() {
  pinMode(led, OUTPUT);
  pinMode(inputOne, INPUT);
  pinMode(inputTwo, INPUT);

}

void loop() {
  if(digitalRead(inputOne) == true) {
    analogWrite(led, 256);
    delay(200);
    analogWrite(led, 0);
  };
  if(digitalRead(inputTwo) == true) {
    analogWrite(led, 256);
    delay(200);
    analogWrite(led, 0);
  };
  analogWrite(led, 0);
}
