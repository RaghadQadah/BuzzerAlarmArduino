#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define TempSensor A0
#define DCmotor  6
int j = 0;
float sum;
unsigned int prevMillis = 0;
float temp[4];

void setup() {
  pinMode(TempSensor, INPUT);
  pinMode(DCmotor, OUTPUT);

  lcd.begin(16, 4);
  lcd.setCursor(0, 0);
  
  Serial.begin(9600);
  prevMillis = millis(); //to implement delay without using delay()function 
}

void loop() {
  //calcualte  every 1.5 seconds 
  if(millis() - prevMillis >= 1500){
   prevMillis = millis();
    
    if(j < 4){
    temp[j] = (((analogRead(TempSensor)/1023.0) * 5)-0.5)*100;    //temperature in degree celsius
    }else{
    readAndshift(temp);    
    }

  // every 1.5 seconds find Tavg
   if(j >= 3){
    //calculating Tavg
    sum=0;
    for(int i = 0; i < 4; i++)
    sum=sum+temp[i];
    float Tavg =sum/4;    
    lcd.clear();
    lcd.print("Tavg= " + String(Tavg) + " C");   

      if(Tavg>= 35){
      Serial.print("1\n");//activate the alarm
      
      } else if(Tavg < 35){
      Serial.print("0\n");//deactivate the alarm
      }
   
      if(Tavg > 29){
      int base = 0.2*255;
      int op = (Tavg - 29)/2;
      int increment = 0.1*(255)*op;
      base += increment;
      analogWrite(DCmotor, base);
       }

     else if(Tavg < 27){
     analogWrite(DCmotor, 0); //turn off the  DC motor   
       
     }         
   }
      if(j >= 3)
        j = 5; //if first 6 sec past 
      else 
        j++;
   }
}

void readAndshift(float temp[]){
float x =(((analogRead(TempSensor)/1023.0) * 5)-0.5)*100;
for(int i = 1; i < 4; i++)
 temp[i] = temp[i+1];
temp[3] = x;
 
 }
 