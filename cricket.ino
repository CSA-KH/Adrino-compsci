const int sensorPin = 2;
const int sensorPin2 = 3;
const int ledPin = 12;
const int ledPin2 = 13;

const int highChirp = 20;
const int lowChirp = 14;

const int chirpCycle = 70;
const int chirpPause = 8;
const int numChirps = 10;
const int midChirp = 150;
const int skittish = 5000;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin2, INPUT);
}

void Chirp1(){  //does the blink pattern for the first LED
    for (int i=1; i<=numChirps; i++){
      
        for (int j=1; j<=numChirps; j++){
          digitalWrite(ledPin,HIGH);
          delayMicroseconds(chirpCycle*10);
          digitalWrite(ledPin, LOW);
          delayMicroseconds(1000-(chirpCycle*10));
        }
      digitalWrite(ledPin, LOW);
      
      if (i == numChirps/2) delay(midChirp);
      else delay(lowChirp);
    }
}

void Chirp2(){  //Does the seecond pattern
    for (int i=1; i<=numChirps; i++){
      
      for (int j=1; j<=numChirps; j++){
        digitalWrite(ledPin2,HIGH);
        delayMicroseconds(chirpCycle*15);
        digitalWrite(ledPin2, LOW);
        delayMicroseconds(800-(chirpCycle*7));
      }
      digitalWrite(ledPin2, LOW);
      
      if (i == numChirps/2) delay(midChirp);
      else delay(lowChirp);
    }
}

void Chirp3(){  //Does the third pattern when both of the switches are HIGH
      for (int i=1; i<=numChirps; i++){
      
        for (int j=1; j<=numChirps; j++){
          digitalWrite(ledPin2,HIGH);
          digitalWrite(ledPin, HIGH);
          delayMicroseconds(chirpCycle*100);
          digitalWrite(ledPin2, LOW);
          digitalWrite(ledPin, LOW);
          delayMicroseconds(1100-(chirpCycle*15));
        }
      digitalWrite(ledPin, LOW);
      digitalWrite(ledPin2, LOW);
      
      if (i == numChirps/2) delay(midChirp);
      else delay(lowChirp);
    }
}
void loop(){
  while ((digitalRead(sensorPin) == LOW) or (digitalRead(sensorPin2) == LOW)){  //Only one of the sensor pins are going to be high because it is impossible to get both clicked at the same tims
      delay(1);
    while (digitalRead(sensorPin) == HIGH){  //While sensor 1 is HIGH, does the pattern for the first LED
    Chirp1();
    }
    while(digitalRead(sensorPin2) == HIGH){  //While sensor 2 is HIGH, does the pattern for the seccond LED
    Chirp2();
    }
    digitalRead(sensorPin);  //checks if the two things are switched HIGH
    delay(50);
    digitalRead(sensorPin2);
    while ((digitalRead(sensorPin) == HIGH) and (digitalRead(sensorPin2) == HIGH)){  //Uses the delay on the top so one can press both of the buttons to high, than does the pattern for both the LED
    Chirp3();
    }
  }
}
