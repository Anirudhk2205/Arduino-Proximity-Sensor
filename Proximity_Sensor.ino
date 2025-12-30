
const int SensorPin = 8;
const int GreenLED = 13;
const int YellowLED = 12;
const int RedLED = 11;

const long interval = 2000;
unsigned long prevmillis = 0;

const long LEDinterval = 100;
unsigned long LEDprevmillis = 0;
bool LEDstate = LOW;

void blinkLED(int LEDPin, long interval, unsigned long &LEDprevmillis, unsigned long currentmillis, bool &LEDstate) {
  if (currentmillis - LEDprevmillis >= interval) {
    LEDprevmillis = currentmillis;
    LEDstate = !LEDstate;
  }
  digitalWrite(LEDPin, LEDstate);
}

void setup() {
  pinMode(SensorPin, INPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(RedLED, OUTPUT);



  Serial.begin(9600);
}

void loop() {
  bool ult = digitalRead(SensorPin);
  if (ult == HIGH) {
    Serial.println("No object in path");
    digitalWrite(GreenLED, HIGH);
    digitalWrite(RedLED, LOW);
    digitalWrite(YellowLED, LOW);

    prevmillis = millis();
  } else if (ult == LOW) {
    Serial.print("Object in path, ");
    unsigned long currentmillis = millis();
    if (currentmillis - prevmillis < interval) {
      digitalWrite(GreenLED, LOW);
      digitalWrite(RedLED, LOW);
      unsigned long LEDcurrentmillis = millis();
      blinkLED(YellowLED, LEDinterval, LEDprevmillis, LEDcurrentmillis, LEDstate);
      Serial.println("Warning");
    } else {
      digitalWrite(GreenLED, LOW);
      digitalWrite(RedLED, HIGH);
      digitalWrite(YellowLED, LOW);
      Serial.println("Danger");
    }
  } else {
    Serial.println("ERROR");
  }
}
