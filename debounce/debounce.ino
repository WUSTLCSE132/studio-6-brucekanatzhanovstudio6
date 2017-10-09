const int buttonPin = 2;
volatile int buttonState;
volatile int lastButtonState = LOW;

volatile int totalPress = 0;

volatile unsigned long lastDebounceTime = 0;
volatile unsigned long debounceDelay = 50;
volatile unsigned long nowTime = 0;

void setup(){
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, CHANGE);
}

void loop(){
  delay(1000);
  Serial.println(totalPress);
}

void buttonPressed(){
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState){
    lastDebounceTime = millis();
  }

  //if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW){
        nowTime=millis();
      }
      if(buttonState == HIGH){
        if(millis()-nowTime>40)
        {
          totalPress++;
        }
      }
    }
  //}
  lastButtonState = reading;
}

