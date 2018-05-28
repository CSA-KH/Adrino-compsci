int pattern[50];  //you can always make the max value higher
int player_pattern[50];
int level = 1;
int yn = 0;

void setup() {
  pinMode(2,OUTPUT);  //these are the led lights, this one is red
  pinMode(3,OUTPUT);  //green
  pinMode(4,OUTPUT);  //blue
  pinMode(5,OUTPUT);  //yellow
  
  pinMode(A0,INPUT);  //output pins to check the button inputs, this one is for the red
  pinMode(A1,INPUT);  //for green
  pinMode(A2,INPUT);  //for blue
  pinMode(A3,INPUT);  //for yellow

}

void loop() {
  if (level == 1){  //makes a new pattern once the player gets the pattern wrong
    make();
  }
  
  if(digitalRead(A4) == LOW || level != 1){
    show();
    check();
    delay(200);
  }

}

void show(){  //goes through the pattern untill it reaches the 'level' the player is on
  for(int i=0;i<level;i++){
    digitalWrite(pattern[i],HIGH);
    delay(300);
    digitalWrite(pattern[i],LOW);
  }
}

void check(){

  for (int i=0; i<level; i++){
    yn = 0;
    while (yn == 0){
      
    if (digitalRead(A0) == LOW){  //checks the inputed value.
      digitalWrite(5,HIGH);  //When the player puches the button, turns the led on
      player_pattern[i] = 5;
      yn = 1;
      delay(150);
      if (player_pattern[i] != pattern[i]){  //sees if the inputed switch is not the same as the one thet was in the pattern
        wrong();
        return;
      }
      digitalWrite(5,LOW);  //turns the led off
      }

    if (digitalRead(A1) == LOW){  //the rest is the same as the top
      digitalWrite(4,HIGH);
      player_pattern[i] = 4;
      yn = 1;
      delay(150);
      if (player_pattern[i] != pattern[i]){
        wrong();
        return;
      }
      digitalWrite(4,LOW);
      }

    if (digitalRead(A2) == LOW){
      digitalWrite(3,HIGH);
      player_pattern[i] = 3;
      yn = 1;
      delay(150);
      if (player_pattern[i] != pattern[i]){
        wrong();
        return;
      }
      digitalWrite(3,LOW);
      }

    if (digitalRead(A3) == LOW){
      digitalWrite(2,HIGH);
      player_pattern[i] = 2;
      yn = 1;
      delay(150);
      if (player_pattern[i] != pattern[i]){
        wrong();
        return;
      }
      digitalWrite(2,LOW);
      }

    }
  }
  if (level <= 50){
  level ++;   
  }    
}


void make(){  //makes a random list of 50 numbers
randomSeed(millis());

for (int i=0; i<50; i++){
  pattern[i] = random(2,6);
  }
}

void wrong(){  //shows the wrong sequence
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  level = 1;
}

void checkbutton(){  //test to make the code up there in the check button simpler. Not sure if it would work
  for(int i=0;i<4;i++){
    if (i == 1){
      whichB = A0;
      whichLED = 2;
    }
    if (i == 2){
      whichB = A1;
      whichLED = 3;
    }
    if (i == 3){
      whichB = A2;
      whichLED = 4;
    }
    if (i == 4){
      whichB = A3;
      whichLED = 5;
    }
    if (digitalRead(whichB) == LOW){
          digitalWrite(whichLED,HIGH);
          player_pattern[i] = whichLed;
          yn = 1;
          delay(150);
          if (player_pattern[i] != pattern[i]){
            wrong();
            return;
          }
          digitalWrite(whichLED,LOW);
          }
    if(i == 4){
      i = 0;
    }
    }
  }
