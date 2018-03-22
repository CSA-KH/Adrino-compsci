const int rgb[] = {9, 10};
const int time = 250;
const int switchPin = 2;

void setup() {
  for (int i=0; i<2; i++) pinMode(rgb[i], OUTPUT);
  pinMode(switchPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  int RPin = 0;
  int BPin = 1;
  int bounce1 = digitalRead(switchPin);
  delay(25);
  int bounce2 = digitalRead(switchPin);

  while ((bounce1 == bounce2) && (bounce1 == LOW)){  //Checks if the thing is true
    digitalWrite(rgb[BPin], LOW);  //Does the blinking light thing for sos
    digitalWrite(rgb[RPin], HIGH);
    delay (time);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time*3);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time*3);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time*3);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time);
    digitalWrite(rgb[RPin], LOW);
    delay (time);
    digitalWrite(rgb[RPin], HIGH);
    delay (time);
    digitalWrite(rgb[RPin], LOW);
    delay (time*6);
    if (switchPin == true) {  //Checks if the switch pin is on or off
      for (int i=0; i<3; i++) digitalWrite(rgb[i], HIGH);
      delay(time);
      for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);
    }
    bounce1 = digitalRead(switchPin);  //Reavaluates if the switch is flipped or not
    delay(25);
    bounce2 = digitalRead(switchPin);
  }
  for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);  //If switch pin is off, than it wilkl turn the light only blue
  digitalWrite(rgb[BPin], HIGH);
  
  // put your main code here, to run repeatedly:

}
