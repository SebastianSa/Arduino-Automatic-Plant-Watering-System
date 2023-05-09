/*
Plant-Watering-x4_advanced-LCD

Sketch
https://github.com/WayinTop/Automatic-Plant-Watering-System-Tutorial/blob/master/4%20Channel%20Relay%20Plant%20Watering%20System%20and%20code/arduino_Watering4/arduino_Watering4.ino

Bauplan
https://github.com/WayinTop/Automatic-Plant-Watering-System-Tutorial/blob/master/4%20Channel%20Relay%20Plant%20Watering%20System%20and%20code/Pflanzen%20Bew%C3%A4sserungssystem%20Tutorial-Deutsch.pdf

Display (4x20)
https://funduino.de/anleitung-4x20-i%C2%B2c-lcd-modul


Bewässerung anhand der % Bodenfeuchte
gießwert_ entsprechend anpassen
gegossen wird pro Durchlauf für 2 Sec. pro pumpe/Pflanze

Changelog:
  Version 0.22
    09.05.2023        + Channels can be disabled when "giesswert is set to 0"
  
  Version 0.21
    04.05.2023        * float to int to use and display % as integer values

  Version 0.2
    28.04.2023        + LCD Display
    26.04.2023 20:23  + added 4th watering loop
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 4);
//in “20, 4” ändern wenn 20x04 benutzt wird

char version[] = "0.22";
char UpDate[] = "09.05.2023";

//Default Values wet: 250; dry: 610 

int wet1 = 262; //Wert wenn der Feuchtesensor im Wasser steht
int dry1 = 614; //Wert wenn der Feuchtesensor an der Luft, im Trockenen steht

int wet2 = 246;
int dry2 = 607;

int wet3 = 250;
int dry3 = 610;

int wet4 = 250;
int dry4 = 610;

// gießt, wenn Bodenfeuchte kleiner als giesswert
int giesswert1 = 50; //maximale Bodenfeuchte, ab der gegossen wird, 0 to disable channel
int giesswert2 = 50; //maximale Bodenfeuchte, ab der gegossen wird, 0 to disable channel
int giesswert3 = 80; //maximale Bodenfeuchte, ab der gegossen wird, 0 to disable channel
int giesswert4 = 0; //maximale Bodenfeuchte, ab der gegossen wird, 0 to disable channel


  ///////////////////////////////////////////
 // Don't change anything below this line //
///////////////////////////////////////////

//Umrechnung von Sensorwerten in 5 feuchtewerte
int feuchtewert1 = (dry1 - wet1) / 100;
int feuchtewert2 = (dry2 - wet2) / 100;
int feuchtewert3 = (dry3 - wet3) / 100;
int feuchtewert4 = (dry4 - wet4) / 100;

//Pin Inits
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

int Pin1 = A0; //
int Pin2 = A1;
int Pin3 = A2;
int Pin4 = A3;

int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

int wet = 280; //in Water
int dry = 614; //in air
int feuchtewert = (dry - wet) / 100;

char buf[100];


void setup() {
  
  Serial.begin(9600);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin4, INPUT);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);


//LCD Setup
    lcd.init();
    lcd.backlight();
    delay(100);
    lcd.noBacklight();
    delay(100);
    lcd.backlight();


// LCD Welcome Screen
//  position, line
  delay(500);

  lcd.setCursor(0, 0); lcd.print("-- PLANT WATERING --");
  lcd.setCursor(0, 1);lcd.print("====================");
  lcd.setCursor(0, 2);lcd.print("Version: ");
  lcd.setCursor(9, 2);lcd.print(version);
  lcd.setCursor(0, 3);lcd.print("Updated: ");
  lcd.setCursor(9, 3);lcd.print(UpDate);
delay(5000);

lcd.clear();

}
void loop() {
  
//Serial.println(feuchtewert);

if (giesswert1>0) //just executed if not 0 (0 is used to disable channel)
{ 
  //// PLANT 1 /////////////////////////////
    Serial.print("MOISTURE LEVEL 1:  ");
    value1 = analogRead(Pin1);
    Serial.print(value1);
    int bodenfeuchte1 = 100 - ((value1 - wet1) / feuchtewert1);
    Serial.print("  "); 
    Serial.print(bodenfeuchte1);
    Serial.println("%");

  //LCD print
      lcd.setCursor(0, 0);lcd.print("Plant 1:");
      lcd.setCursor(10, 0);lcd.print(bodenfeuchte1);
      lcd.setCursor(13, 0); lcd.print("%");
      lcd.setCursor(16, 0);lcd.print(giesswert1);
      lcd.setCursor(19, 0); lcd.print("%");

    if(bodenfeuchte1<giesswert1)
    {    //WATERING
        Serial.print("Watering PLANT 1\n");
        digitalWrite(IN1, LOW);
        delay(2000);
        digitalWrite(IN1, HIGH);
    }
    else
    { 
      digitalWrite(IN1, HIGH);
      }
  }  

if (giesswert2>0) //just executed if not 0 (0 is used to disable channel)
{ 
////PLANT 2 /////////////////////////////
  Serial.print("MOISTURE LEVEL 2:  ");
  value2 = analogRead(Pin2);
  Serial.print(value2);
  int bodenfeuchte2 = 100 - ((value2 - wet2) / feuchtewert2);
  Serial.print("  "); 
  Serial.print(bodenfeuchte2);
  Serial.println("%");

  //LCD print
    lcd.setCursor(0, 1);lcd.print("Plant 2:");
    lcd.setCursor(10, 1);lcd.print(bodenfeuchte2);
    lcd.setCursor(13, 1); lcd.print("%");
    lcd.setCursor(16, 1);lcd.print(giesswert2);
    lcd.setCursor(19, 1); lcd.print("%");

  if(bodenfeuchte2<giesswert2)
  {    //WATERING
      Serial.print("Watering PLANT 2\n");
      digitalWrite(IN2, LOW);
      delay(2000);
      digitalWrite(IN2, HIGH);
  }
  else
  { 
    digitalWrite(IN2, HIGH);
    }
}

if (giesswert3>0) //just executed if not 0 (0 is used to disable channel)
{
////PLANT 3 /////////////////////////////
  Serial.print("MOISTURE LEVEL 3:  ");
  value3 = analogRead(Pin3);
  Serial.print(value3);
  int bodenfeuchte3 = 100 - ((value3 - wet3) / feuchtewert3);
  Serial.print("  "); 
  Serial.print(bodenfeuchte3);
  Serial.println("%");

  //LCD print
    lcd.setCursor(0, 2);lcd.print("Plant 3:");
    lcd.setCursor(10, 2);lcd.print(bodenfeuchte3);
    lcd.setCursor(13, 2); lcd.print("%");
    lcd.setCursor(16, 2);lcd.print(giesswert3);
    lcd.setCursor(19, 2); lcd.print("%");

  if(bodenfeuchte3<giesswert3)
  {    //WATERING
      Serial.print("Watering PLANT 3\n");
      digitalWrite(IN3, LOW);
      delay(2000);
      digitalWrite(IN3, HIGH);
  }
  else
  { 
    digitalWrite(IN3, HIGH);
    }
}


if (giesswert4>0) //just executed if not 0 (0 is used to disable channel)
{ 
////PLANT 4 /////////////////////////////
Serial.print("MOISTURE LEVEL 4:  ");
  value4 = analogRead(Pin4);
  Serial.print(value4);
  int bodenfeuchte4 = 100 - ((value4 - wet4) / feuchtewert4);
  Serial.print("  "); 
  Serial.print(bodenfeuchte4);
  Serial.println("%");

  //LCD print
    lcd.setCursor(0, 3);lcd.print("Plant 4:");
    lcd.setCursor(10, 3);lcd.print(bodenfeuchte4);
    lcd.setCursor(13, 3); lcd.print("%");
    lcd.setCursor(16, 3);lcd.print(giesswert4);
    lcd.setCursor(19, 3); lcd.print("%");

  if(bodenfeuchte4<giesswert4)
  {    //WATERING
      Serial.print("Watering PLANT 4\n");
      digitalWrite(IN3, LOW);
      delay(2000);
      digitalWrite(IN4, HIGH);
  }
  else
  { 
    digitalWrite(IN4, HIGH);
    }
}
else{
      lcd.setCursor(0, 3);lcd.print("channel disabled    ");
}
///////////////////////////////////////
  delay(5000);
  Serial.println("");
}
