#include <DS3231.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "DHT.h"
DHT dht;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 2, 3, 4, 5 };
byte colPins[COLS] = { 6, 7, 8, 9 };
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
DS3231  rtc(A4, A5);
Servo servo_test;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int t1, t2, t3, t4, t5, t6;
char j; 
boolean feed = true; // condition for alarm
char key;
int r[6];
const int PIR_SENSOR_OUTPUT_PIN = 11; 
int warm_up;
void setup(){ 
  servo_test.attach(10);
  rtc.begin();
  lcd.begin();
  servo_test.write(0); 
  Serial.begin(9600);
  pinMode(A2, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Serial.println();
  Serial.println(" Status \t Humidity(%)\t Temperature(C)\t AktivitasKucing ");
  dht.setup(12);
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
  Serial.begin(9600);
 } 
void loop(){ 
  lcd.setCursor(0,0);
  int buttonPress;
  buttonPress = digitalRead(A2);
  if (buttonPress==1)
  setFeedingTime();
  j=0;
  lcd.print("Time:  ");
  String t = "";
  t = rtc.getTimeStr(); 
  t1 = t.charAt(0)-48;
  t2 = t.charAt(1)-48;
  t3 = t.charAt(3)-48;
  t4 = t.charAt(4)-48;
  t5 = t.charAt(6)-48;
  t6 = t.charAt(7)-48;
 lcd.print(rtc.getTimeStr());
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(rtc.getDateStr());
 if (t1==r[0] && t2==r[1] && t3==r[2] && t4==r[3]&& t5<1 && t6<3 && feed==true){ 
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print(r[0]);
  lcd.print(r[1]);
  lcd.print(":");
  lcd.print(r[2]);
  lcd.print(r[3]);
  lcd.print(" WIB");
  lcd.setCursor(2,1);
  lcd.print("Selamat Makan");
  Serial.print("Waktu Makan");
  Serial.print(r[0]);
  Serial.print(r[1]);
  Serial.print(":");
  Serial.print(r[2]);
  Serial.print(r[3]);
  Serial.println();
  servo_test.write(0); 
  delay (3000);
  tone(13, 1000, 2000);
  servo_test.write(90);
  delay (2000);
  servo_test.write(0);
  feed = false;
 } 
  delay(200);
  float humidity = dht.getHumidity(); 
  float temperature = dht.getTemperature();
  int sensor_output;
  sensor_output = digitalRead(PIR_SENSOR_OUTPUT_PIN);
  Serial.print(dht.getStatusString()); 
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t");
  Serial.print(temperature, 1);
  Serial.print("\t");
    if( sensor_output == LOW ){
    if( warm_up == 1 ){
      warm_up = 0;}
    Serial.print("0\n");
    delay(200);}
    else{
    Serial.print("1\n");    
    warm_up = 1;
    delay(200);} }       
void setFeedingTime(){
  feed = true;
  int i=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Set feeding Time");
  lcd.clear();
  lcd.print("HH:MM");
  lcd.setCursor(0,1);
  while(1){
    key = kpd.getKey();
    if(key!=NO_KEY){
      lcd.setCursor(j,1);
      lcd.print(key);
    r[i] = key-48;
    i++;
    j++;
    if (j==2)
    {
      lcd.print(":"); j++;
    }
    delay(500);
  }
  if (key == 'D')
  {key=0; break; }
  }
}
