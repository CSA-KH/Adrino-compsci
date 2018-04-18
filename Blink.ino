const int kPinLed = 2;
const int qPinLed = 3;
const int wPinLed = 4;
const int ePinLed = 5;
const int rPinLed = 6;
const int tPinLed = 7;
const int yPinLed = 8;
const int uPinLed = 9;
const int num = 100;

void setup() {
  pinMode(kPinLed, OUTPUT);
  pinMode(qPinLed, OUTPUT);
  pinMode(wPinLed, OUTPUT);
  pinMode(ePinLed, OUTPUT);
  pinMode(rPinLed, OUTPUT);
  pinMode(tPinLed, OUTPUT);
  pinMode(yPinLed, OUTPUT);
  pinMode(uPinLed, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  delay(num);
  digitalWrite(uPinLed, HIGH);
  delay(num);
  digitalWrite(kPinLed, LOW);
  delay(num);
  digitalWrite(qPinLed, LOW);
  delay(num);
  digitalWrite(kPinLed, HIGH);
  delay(num);
  digitalWrite(wPinLed, LOW);
  delay(num);
  digitalWrite(qPinLed, HIGH);
  delay(num);
  digitalWrite(ePinLed, LOW);
  delay(num);
  digitalWrite(wPinLed, HIGH);
  delay(num);
  digitalWrite(rPinLed, LOW);
  delay(num);
  digitalWrite(ePinLed, HIGH);
  delay(num);
  digitalWrite(tPinLed, LOW);
  delay(num);
  digitalWrite(rPinLed, HIGH);
  delay(num);
  digitalWrite(yPinLed, LOW);
  delay(num);
  digitalWrite(tPinLed, HIGH);
  delay(num);
  digitalWrite(uPinLed, LOW);
  delay(num);

  digitalWrite(yPinLed, HIGH);
  delay(num);
  
  // put your main code here, to run repeatedly:

}
