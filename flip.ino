const int rgb[] = {9, 10};
const int time = 250;
const int switchPin = 2;

void setup() {
  for (int i=0; i<2; i++) pinMode(rgb[i], OUTPUT);
  pinMode(switchPin, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  int oldPin = 1;
  int newPin = 0;
  int bounce1 = digitalRead(switchPin);
  delay(25);
  int bounce2 = digitalRead(switchPin);

  while ((bounce1 == bounce2) && (bounce1 == LOW)){


    digitalWrite(rgb[oldPin], HIGH);
    delay(time);

    
    if (newPin == 0) {
      for (int i=0; i<3; i++) digitalWrite(rgb[i], HIGH);
      delay(time);
      for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);
    }
    bounce1 = digitalRead(switchPin);
    delay(25);
    bounce2 = digitalRead(switchPin);
  }
  for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);
  digitalWrite(rgb[oldPin], LOW);
  // put your main code here, to run repeatedly:

}
