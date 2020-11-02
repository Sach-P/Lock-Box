  
const int button3 = 6; //pin outs
const int button2 = 5; 
const int button1 = 4;

const int buzzer = 3;
const int led = 2;
const int lock = 7;


const int pin1 = 5; //choose a password
const int pin2 = 7;
const int pin3 = 8;

int curVal1 = 0; //current times respective buttons are pressed.
int curVal2 = 0;
int curVal3 = 0;


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
 
  if(digitalRead(button1) == HIGH){                  
    curVal1++;
    if(curVal1 == 9){//resets the pin value if gone too high.
      curVal1 = 0;                      
    }
    tone(buzzer, 440, 200);
  }  
  else if(digitalRead(button2) == HIGH){                   
    curVal2++;
    if(curVal2 == 9){
      curVal2 = 0;                      
    }
    tone(buzzer, 440, 200);
  }
  else if(digitalRead(button3) == HIGH){
    curVal3++;
    if(curVal3 == 9){
      curVal3 = 0;                      
    }
    tone(buzzer, 440, 200);
  }
  
  delay(200);
  
  if ((curVal1 == pin1) && (curVal2 == pin2) && (curVal3 == pin3)){//open 
    digitalWrite(lock, HIGH);    
    tone(buzzer, 330, 1000);                    
    digitalWrite(led, HIGH);
  }
 }
