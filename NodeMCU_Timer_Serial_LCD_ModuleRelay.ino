//NodeMCU_Timer_Serial_LCD_ModuleRelay.ino

#include <LiquidCrystal.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin13 = 13; //D7
int var = 0;
int x=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
    pinMode(ledPin13, OUTPUT);  
    
  //Wire.begin (SDA, SCL);
  Wire.begin (D2, D1);
  lcd.begin();    
}

void loop() {
  // put your main code here, to run repeatedly:

  for(var=x; var<=15; var++)
{
Serial.println(var);
digitalWrite(ledPin13, LOW); //LED ON
//Do something here......
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Start counter=");
  lcd.println(var);
  lcd.setCursor(0,1);
  lcd.print("Stop counter=15");

delay(1000);
}
digitalWrite(ledPin13, HIGH);  //LED OFF
x=var;

  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println("Count 15,LED OFF");
  lcd.setCursor(0,1);
  lcd.print("Thanks,4watching"); 
}
