//int BTN_1 = 2;
//int BTN_2 = 3;
//int LED_1 = 4;
//int LED_2 = 5;

//int BTN_HAFIZA;

//unsigned long buton_basma_sure;
//unsigned long Eski_zaman_2;

//unsigned long Eski_sure=0;
//int hesapla = buton_basma_sure + 3000;

//void setup()
//{
  //  pinMode(BTN_1, INPUT);
   // pinMode(BTN_2, INPUT);
  //  pinMode(LED_1, OUTPUT);
  //  pinMode(LED_2, OUTPUT);

 // Serial.begin(9600);
//}

//void loop()
//{
   // int buton_1 = digitalRead(BTN_1);
   // int buton_2 = digitalRead(BTN_2);
   // Serial.println(buton_1);
  
    //unsigned long surem = millis();
    
  
  

//  if ((buton_1 == HIGH)&&(millis() - Eski_sure < 150000)){
    //	buton_basma_sure = millis();
      	//digitalWrite(LED_1,HIGH);
   	 	//BTN_HAFIZA = digitalRead(BTN_1);}

  //else if(buton_1 == LOW)

  //  if ((millis() - Eski_sure >=15000)&& (millis() - Eski_sure <17000)){
  //      digitalWrite(LED_1,LOW);
  //      delay(1000);
  //      digitalWrite(LED_1,HIGH);


 //   }
   // else if (millis() - Eski_sure >20000){
    //	digitalWrite(LED_1,LOW);
 //     	Eski_sure = millis();
//}

 // delay(1000);
//}


int OUT_1= 4;
int OUT_2 = 5;

int IN_1 = 2;
int IN_2 = 3;

int OUT_1zaman = 0;
int OUT_2zaman = 0;

void setup() 
{
  pinMode(IN_1, INPUT);
  pinMode(IN_2, INPUT);
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);

}

void loop() {

 if (digitalRead(IN_1)==HIGH){
      digitalWrite(OUT_1,HIGH);
      OUT_1zaman = millis();
  }
  else if (millis() -OUT_1zaman>=15000 && millis() -OUT_1zaman <=17000)
  {
          	digitalWrite(OUT_1,LOW);
        	delay(1000);
        	digitalWrite(OUT_1,HIGH);
  }
  else if(millis() -OUT_1zaman >20000)
  {
      digitalWrite(OUT_1,LOW);
  }
 

  if(millis()- OUT_2zaman <=3000 && digitalRead(IN_1)==HIGH)
  {
     	digitalWrite(OUT_2,HIGH);
    	OUT_2zaman = millis();
  }
  if (millis() - OUT_2zaman >= 15000 && millis() -OUT_2zaman <= 17000)
  {
        digitalWrite(OUT_2,LOW);
        delay(1000);
        digitalWrite(OUT_2,HIGH);
  }
  else if(millis() - OUT_2zaman >20000)
  {
      digitalWrite(OUT_2,LOW);
  }
  else if(OUT_2zaman>=3000){
    if (digitalRead(IN_2)==HIGH){
        digitalWrite(OUT_2,LOW);
    }
  }
}