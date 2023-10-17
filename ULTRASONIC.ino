int trig1=2;
int trig2=4;
int echo1=3;
int echo2=5;
int ml1 = 6;
int ml2 = 7;
int mr1 = 8;
int mr2 = 9;
float duration1,duration2;
float distance1,distance2;
void setup() {
  // put your setup code here, to run once:
 pinMode(trig1,OUTPUT);
 pinMode(trig2,OUTPUT);
 pinMode(echo1,INPUT);
 pinMode(echo2,INPUT);
 pinMode(ml1,OUTPUT);
  pinMode(ml2,OUTPUT);
  pinMode(mr1,OUTPUT);
  pinMode(mr2,OUTPUT);
  Serial.begin(9600);
  
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  duration1=pulseIn(echo1,HIGH);
 distance1=duration1*0.017;
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  duration2=pulseIn(echo2,HIGH);
 distance2=duration2*0.017;
  Serial.println("DISTLEFT");
  Serial.println(distance1);
  Serial.println("DISTright");
  Serial.println(distance2);
  if(distance1>=10&&distance2>=10){
   digitalWrite(ml1,HIGH);
      digitalWrite(ml2,LOW);  
        digitalWrite(mr1,HIGH);   
        digitalWrite(mr2,LOW);
    Serial.println("forward"); 
    }
   else if(distance1>=10&&distance2<10){
   digitalWrite(ml1,LOW);
      digitalWrite(ml2,LOW);  
        digitalWrite(mr1,HIGH);   
        digitalWrite(mr2,LOW);
    Serial.println("LEFT"); 
    }
    else if(distance1<10&&distance2>=10){
   digitalWrite(ml1,HIGH);
      digitalWrite(ml2,LOW);  
        digitalWrite(mr1,HIGH);   
        digitalWrite(mr2,HIGH);
    Serial.println("RIGHT"); 
    }
    else{
   digitalWrite(ml1,LOW);
      digitalWrite(ml2,LOW);  
        digitalWrite(mr1,LOW);   
        digitalWrite(mr2,LOW);
    Serial.println("stop"); 
    }
    
}
