int pattern[50];
int player_pattern[50];
int level = 1;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

}

void loop() {
  if (level == 1){
    make();
  }
  
  if(digitalRead(A4) == LOW || level != 1){
    show();
    check();
    delay(200);
  }

}

void show(){
  for(int i=0;i<level;i++){
    digitalWrite(pattern[i],HIGH);
    delay(300);
    digitalWrite(pattern[i],LOW);
  }
}

void check(){
  int yn = 0;

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


void make(){
randomSeed(millis());

for (int i = 0; i < 50; i++){
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

