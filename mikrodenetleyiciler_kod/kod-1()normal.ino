int ledpin1 =2; 
int ledpin2 =3;
int ledpin3 =4;
int ledpin4 =5;

int buton = 6;

int hafiza =0;
int hafiza2 = 0;

unsigned long eski_zaman1 = 0;
unsigned long eski_zaman2 = 0;
unsigned long eski_zaman3 = 0;
unsigned long eski_zaman4 = 0;


unsigned long degerim;

int hesap1;
int hesap2;
int hesap3;
int hesap4;

void setup()
{
  
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT);
  pinMode(ledpin4,OUTPUT);
  
  pinMode(buton,INPUT);
  Serial.begin(9600);

}

void loop()
{  
  int buton_degeri1 = digitalRead(buton);
  
  if(buton_degeri1 == 1){
    degerim =millis(); 
    hafiza = buton_degeri1;
    Serial.println(hafiza);
    Serial.println(degerim);
    
    hesap1 = (degerim + 3000);
    hesap2 = (degerim + 5000);
    hesap3 = (degerim + 10000);
    hesap4 = (degerim + 10000);
    
    Serial.print("HESAPLANAN DEGERLER: ");
    Serial.print("LED1: ");Serial.print(hesap1);Serial.print(",");Serial.print("LED2: ");Serial.print(hesap2);Serial.print(",");Serial.print("LED3: ");Serial.print(hesap3);Serial.print(",");Serial.print("LED4: ");Serial.print(hesap4);}
  
   if (hafiza ==1){
     int buton_degeri2 =digitalRead(buton); 
     
     
     hafiza2 = buton_degeri2;
 
     if(millis()- eski_zaman1 >=hesap1){
      eski_zaman1 = millis();
      digitalWrite(ledpin1,HIGH);
      //Serial.println(hafiza);
      
      if (hafiza2 == 0){
      digitalWrite(ledpin1,LOW);}
      }
     
     if ((millis()-eski_zaman2 >=0) && (millis()-eski_zaman2 <=hesap2)){
        digitalWrite(ledpin2,HIGH);

        eski_zaman2 = millis();

         if((hafiza2 ==0)&&(millis()>hesap2)){
          digitalWrite(ledpin2,LOW);}
        }
     
     if ((millis()-eski_zaman3 >=0) && (millis()-eski_zaman3 <hesap3)){
       digitalWrite(ledpin3,HIGH);
       eski_zaman3 = millis();

       if ((hafiza2 ==0)&&(millis()>hesap3)){
          digitalWrite(ledpin3,LOW);} 
       }
    if ((millis()-eski_zaman4 >=0) && (millis()-eski_zaman4 <hesap4)){
       digitalWrite(ledpin4,HIGH);
       eski_zaman4 = millis();

       
       if(millis() > hesap4){
       digitalWrite(ledpin4,LOW);}
       } 
   delay(1000);
}}