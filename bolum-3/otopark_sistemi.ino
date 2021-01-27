#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 10, 11, 12, 13, 15);


int giris_btn = 3;
int cikis_btn =4;
int acil_btn =2;

int Led_pin1 = 5;
int Led_pin2 = 6;
int Led_pin3 = 7;


int Buzz =8;
int DHT11 =A0;



int giris_sayac= 0;
int cikis_sayac =0;

int kapasite = 20;
int kalan_yer=0;

float gerilim;

void setup()
{
  pinMode(giris_btn,INPUT);
  pinMode(cikis_btn, INPUT);
  pinMode(acil_btn,INPUT);
  
  pinMode(Led_pin1,OUTPUT);
  pinMode(Led_pin2,OUTPUT);
  pinMode(Led_pin3,OUTPUT);
  
  pinMode(Buzz,OUTPUT);
  
  lcd.begin(16, 2);
  Serial.begin(9600);
  attachInterrupt(0,Acil,RISING);
}

void loop()
  
{  lcd.clear();
   lcd.setCursor(0, 0);
  lcd.print("Kalan yer:");
  lcd.print(kalan_yer);
  lcd.setCursor(2, 1);
  
  float sicaklik = analogRead(DHT11);
  float gerilim = (sicaklik * 5.0);
  gerilim = (gerilim/ 1024.0);
  Sicaklik();
  
  int btn_drm_giris = digitalRead(giris_btn);
  int btn_drm_cikis = digitalRead(cikis_btn);
  int btn_drm_acil = digitalRead(acil_btn);

  if (btn_drm_giris ==1){
    digitalWrite(Buzz,HIGH);
    delay(1000);  
    digitalWrite(Buzz,LOW);
    
    Giris();}
  
  else if (btn_drm_cikis ==1){
    digitalWrite(Buzz,HIGH);
    delay(1000);
    digitalWrite(Buzz,LOW);
    Cikis();}
  else if(btn_drm_acil ==1){
    Acil();}
    delay(500);
}

void Giris(){
    Serial.println("ARABA GIRIS YAPTI");
  	giris_sayac +=1;
    Serial.print("KALAN YER: ");
    
    kalan_yer = kapasite - 1;
    kapasite = kapasite -1;
    Serial.println(kalan_yer);
    
  if ((kalan_yer >=6) && (kalan_yer <=20)){
    digitalWrite(Led_pin1,HIGH);
    Serial.println("OTOPARK BOS");}
  
  else if ((kalan_yer > 0) && (kalan_yer<=5)){
    digitalWrite(Led_pin1,LOW);
    digitalWrite(Led_pin2,HIGH);
    Serial.println("OTOPARK SIKISIK..");}
  
  else if (kalan_yer ==0){
    digitalWrite(Led_pin2,LOW);
    digitalWrite(Led_pin3,HIGH);
    Serial.println("OTOPARK DOLU!");}
}

void Cikis(){
   Serial.println("ARABA CIKIS YAPIYOR");
   cikis_sayac +=1; 
   kalan_yer = kalan_yer+1;
   Serial.print("KALAN YER: ");
   Serial.println(kalan_yer);
  
  if(kalan_yer ==0){
  	Serial.println("OTOPARK DOLU");
    digitalWrite(Led_pin3,HIGH);}
  
   else if ((kalan_yer >0) && (kalan_yer <=5)){
   	Serial.println("OTOPARK SIKISIK");
   	digitalWrite(Led_pin3,LOW);
    digitalWrite(Led_pin2,HIGH);}
  
  else if ((kalan_yer >=6) && (kalan_yer <=20)){
  	Serial.println("OTOPARK BOS");
    digitalWrite(Led_pin2,LOW);
    digitalWrite(Led_pin1,HIGH);
  }      
    
}
void Acil(){
  	digitalWrite(Led_pin1,LOW);
  	digitalWrite(Led_pin2,LOW);
	digitalWrite(Led_pin3,HIGH);
  	digitalWrite(Buzz,HIGH);
  	delay(15000);
  	digitalWrite(Led_pin3,LOW);
  	digitalWrite(Buzz,LOW);}

void Sicaklik(){
  Serial.print("DERECE DONUSUMU");
  float derece = (gerilim - 0.5) * -100 ;                                            
  Serial.print(derece); 
  Serial.println(" Derece C ");
  lcd.setCursor(0, 1);
  lcd.print("Sicaklik: ");
  lcd.print(derece);
  lcd.print("c");}