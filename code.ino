#include "DHT.h"                //Library DHT
#include <LiquidCrystal_I2C.h>  //Library LCD I2C

#define DHTPIN 5                //DHT pada pin D5
#define DHTTYPE DHT11           //Type DHT 11
DHT dht(DHTPIN, DHTTYPE);       //Masukkan pin dan type DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2); //Alamat I2C

#define lampu1 8                 //Lampu1 pada pin D8
#define lampu2 9                 //Lampu2 pada pin D9

void setup() {
  dht.begin();      //Mulai DHT
  lcd.init();       //Mulai LCD
  lcd.backlight();  //Nyalakan backlight
  pinMode(lampu1, OUTPUT); //Setting I/O
  pinMode(lampu2, OUTPUT);
  digitalWrite(lampu1, HIGH);
  digitalWrite(lampu2, HIGH);
}

void loop() {
  float t = dht.readTemperature();    //Baca suhu
  
  lcd.setCursor(0,0);     //Koordinat text
  lcd.print("Suhu: "); 
  lcd.print(t);           //Tampilkan suhu
  lcd.print("*C");
  
  if(t > 38){                   //Jika suhu > 38*C
    digitalWrite(lampu1, HIGH);
    digitalWrite(lampu2, HIGH);
  }
  else if(t > 35){
    digitalWrite(lampu1, LOW);
    digitalWrite(lampu2, HIGH);
  }
  else{
    digitalWrite(lampu1, LOW);
    digitalWrite(lampu2, LOW);
  }
  
  delay(1000);            //Jeda pembacaan 1000ms
  lcd.clear();            //Hapus tampilan LCD
}
