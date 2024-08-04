#define btnPin D5
#define pinLed_R D1
#define pinLed_G D2
#define pinLed_B D3

int lastVal;
unsigned long pressStartTime;
unsigned long pressTime;
bool buttonPressed = false;
unsigned long shortestPressTime = 500;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(pinLed_R, OUTPUT);
  pinMode(pinLed_G, OUTPUT);
  pinMode(pinLed_B, OUTPUT);
}

void loop() {
  int val = digitalRead(btnPin);
  if ((val == LOW) && (lastVal == HIGH) && !buttonPressed && (millis() - pressStartTime > debounceDelay)) {
    pressStartTime = millis();
    buttonPressed = true;
    Serial.println("Button Press Started");
  }

  if ((val == HIGH) && (lastVal == LOW) && buttonPressed) {
    pressTime = millis() - pressStartTime;
    buttonPressed = false;
    Serial.print("Press Time: ");
    Serial.println(pressTime);

    if (pressTime < shortestPressTime) {
      shortestPressTime = pressTime;

      digitalWrite(pinLed_R, HIGH);
      digitalWrite(pinLed_G, HIGH);
      digitalWrite(pinLed_B, HIGH);
      Serial.println("LED Color: Turquoise");
    } else {

      digitalWrite(pinLed_R, HIGH);
      digitalWrite(pinLed_G,HIGH);
      digitalWrite(pinLed_B, LOW);
      Serial.println("LED Color: Orange");
    }
    Serial.println("Button Press Ended");
  }
Serial.println(shortestPressTime);
  lastVal = val;
}