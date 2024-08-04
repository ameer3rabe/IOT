#define btnPin D5

int lastVal;
unsigned long pressStartTime;
unsigned long pressTime;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(btnPin, INPUT_PULLUP);
  lastVal = digitalRead(btnPin);
}

void loop() {
  int val = digitalRead(btnPin);


  if ((val == LOW) && (lastVal == HIGH) && !buttonPressed) {
    pressStartTime = millis();
    buttonPressed = true;
  }

  if ((val == HIGH) && (lastVal == LOW) && buttonPressed) {
    pressTime = millis() - pressStartTime;
    buttonPressed = false;
    Serial.print("Press Time: ");
    Serial.println(pressTime);
  }

  lastVal = val;
}
