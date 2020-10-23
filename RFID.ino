#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 5 //Pin Led Hijau
#define LED_R 4 //Pin Led Merah
#define BUZZER 2 //Pin Buzzer
MFRC522 mfrc522(SS_PIN, RST_PIN);   // deklarasi RFID
Servo myServo; //Nama Servo
LiquidCrystal_I2C lcd(0x3F ,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup() 
{
  myServo.write(0);

  delay(5000); //jangka waktu
=======
  delay(1000);

  Serial.begin(9600);   //Komunikasi baud rate
  SPI.begin();
  mfrc522.PCD_Init();
  myServo.attach(3); //pemanggilan servo
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  lcd.begin(16,2); //lcd start
  lcd.setCursor(4,0);
  lcd.print("DEKAT");
  lcd.setCursor(5,1);
  lcd.print("CARD");

}
void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) //pembacaan nilai pada kartu RFID
  {
    return;
     //Menampilkan UID TAG Di Serial Monitor
     Serial.print("UID tag :"); //pembacaan tag
     String content= "";
     byte letter;
   for (byte i = 0; i < mfrc522.uid.size; i++) 
  }
  {
     #Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     #Serial.print(mfrc522.uid.uidByte[i], HEX);
     #content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     #content.concat(String(mfrc522.uid.uidByte[i], HEX));

  if (content.substring(1) == "04 16 62 9A EF 2C 80" || content.substring(1) == "7D 8F 63 D3" || content.substring(1) == "04 5C 8C 2A 59 28 80") //Ganti UID TAG DENGAN PUNYA MAS-NYA
  {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("AKSES");
    lcd.setCursor(4, 1);
    lcd.print("DI TERIMA");
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    tone(BUZZER, 400);
    delay(300); //delay 300 milisecond
    tone(BUZZER, 300);
    delay(300);
    noTone(BUZZER);
    digitalWrite(LED_G, LOW);
    myServo.write(0);
    delay(5000); //delay 5 second
    myServo.write(70);
  }
 
 else   {//akses ditolak karena id tidak sesuai
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("AKSES");
    lcd.setCursor(4, 1);
    lcd.print("DI TOLAK");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("DEKATKAN");
  lcd.setCursor(5,1);
  lcd.print("KARTU");
} 
