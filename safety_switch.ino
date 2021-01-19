
#define ledPin 2
#define buttonPin 4
#define down 0
#define up 1

int currentState;
int event ;

void setup() {
currentState = 0 ;
pinMode(ledPin,OUTPUT);
pinMode(buttonPin,INPUT);
Serial.begin(9600);


}

void loop() {
  event = detectEvent();
  Serial.println(currentState);
  
  if (currentState== 0)
  {
    if (event == down){
    currentState= 1;
    }
  }
  
  if(currentState==1)
  { 
    if (event == up){
      currentState= 2;
    }
    }


  if (currentState==2)
  {
    if (event == down){
    currentState= 3;
    }
  }
  
  if(currentState==3)
  {  
    if(event ==up){
    currentState= 4;
    digitalWrite(ledPin,HIGH);
    }
  }
  
  if (currentState== 4)
  {
    if (event == down){
    currentState= 5;
    }
  }
  
  if(currentState==5){  
    if(event ==up){
    currentState= 6;
    digitalWrite(ledPin,LOW);
    }
  }

  if (currentState== 6)
  {
    currentState= 0;
    }
  }
 
  
 

int detectEvent(){
  if(digitalRead(buttonPin)==HIGH){
      return 0;
  }
  if(digitalRead(buttonPin)==LOW){
    return 1;
  }
  }
