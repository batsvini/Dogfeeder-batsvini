#include <Servo.h>

Servo myservo;
int hourscounter = 14;
int minutescounter = 51;
int secondscounter = 0;

int mosturePin1 = A3;
int sensorState1 = 0;

int valve1 = 10;
int valvedelay = 2000;

int distp = A2;
int dist = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(mosturePin1, INPUT);
pinMode(distp,INPUT);
pinMode(valve1, OUTPUT);
digitalWrite(valve1, HIGH);
myservo.attach(9);
givefood();
}

void loop() {
  // put your main code here, to run repeatedly:
sensorState1 = analogRead(mosturePin1);
delay (1000);
secondscounter++;
clockk();
Serial.print("hours: ");
Serial.println(hourscounter);
Serial.print("mins: ");
Serial.println(minutescounter);
Serial.print("sec: ");
Serial.println(secondscounter);
Serial.println(sensorState1);


}

void clockk(){
  if (secondscounter == 60){
  minutescounter++;
  
 //water();
  secondscounter = 0;
} if (minutescounter == 59){
  hourscounter++;
  minutescounter = 0;
  food();  
} if (hourscounter == 24){
  hourscounter = 0;
  minutescounter = 15; //////////////////////////////////
  secondscounter = 0;


}
} 
void water(){
  if (sensorState1 > 700){
    digitalWrite(valve1, LOW);
    while(sensorState1 > 600){
  sensorState1 = analogRead(mosturePin1);
  Serial.println(sensorState1);
}
 digitalWrite(valve1, HIGH);   
  } 
    secondscounter = secondscounter + valvedelay;
    digitalWrite(valve1, HIGH);   
}
void food(){
  if (hourscounter == 7){
    givefood();
    
  }if (hourscounter == 13){
    givefood();
    
  }if (hourscounter == 19){
    givefood();
    
  }if (hourscounter == 21){
    givefood();
    
  }
}
void givefood(){
  myservo.attach(9);
  myservo.write(150);
delay(990);
dist = analogRead(distp);
while(dist > 500){
  dist = analogRead(distp);
  Serial.println("yes");
  myservo.write(30);
}
myservo.write(90);
secondscounter = secondscounter + 2;
}
