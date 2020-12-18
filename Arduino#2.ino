#define BUZZ 4
#define LED 5

void setup() {

 //setting pinmodes for buzzer and led
  pinMode(BUZZ, OUTPUT);
  pinMode(LED, OUTPUT);

  //setting up the baud rate
  Serial.begin(9600);

}

void loop() {

   if(Serial.available() > 0){
      String status = Serial.readStringUntil('\n');

       
       if(status == "1"){

       digitalWrite(LED, HIGH);
       digitalWrite(BUZZ, HIGH);
      
        }
     else if(status == "0"){

        digitalWrite(LED, LOW);
        digitalWrite(BUZZ, LOW);
     
       
       }
   }

}