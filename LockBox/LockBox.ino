  
const int button3 = 6; //pin outs
const int button2 = 5; 
const int button1 = 4;

const int buzzer = 3;
const int led = 2;
const int lock = 7;


const int pin1 = 2; //choose a password
const int pin2 = 1;
const int pin3 = 1;

int curVal1 = 0; //current times respective buttons are pressed.
int curVal2 = 0;
int curVal3 = 0;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;


void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(lock, OUTPUT);
}

void loop() { 
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  
  if(buttonState1 == HIGH){
    curVal1++;
    delay(200);
    Check();
    Serial.print(curVal1);
  	if(curVal1 == 9){//resets the pin value if gone too high.
      curVal1 = 0;                      
    }
    tone(buzzer, 440, 200);
    digitalWrite(led, HIGH);    
  }  
  else if(buttonState2 == HIGH){                   
    curVal2++;
    delay(200);
    Check();
    Serial.print(curVal2);
    if(curVal2 == 9){
      curVal2 = 0;                      
    }
    tone(buzzer, 440, 200);
    digitalWrite(led, HIGH); 
  }
  else if(buttonState3 == HIGH){
    curVal3++;
    delay(200);
    Check();
    Serial.print(curVal3);
    if(curVal3 == 9){
      curVal3 = 0;                      
    }
    tone(buzzer, 440, 200);
    digitalWrite(led, HIGH);
  }  
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }
  
  Check();
  
 }

void Check(){//Check if password is correct.
  if ((curVal1 == pin1) && (curVal2 == pin2) && (curVal3 == pin3)){
    digitalWrite(lock, HIGH);    
    tone(buzzer, 330, 500);
    delay(5000);
    curVal1 = curVal2 = curVal3 = 0;
  }
  else{
    digitalWrite(lock, LOW);
    digitalWrite(buzzer, LOW);
  }
}
