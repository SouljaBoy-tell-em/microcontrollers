#include <LiquidCrystal.h>
#include <Thread.h>
#include <stdlib.h>


//--------
// MACROS:
//--------

#define CONVERTTOCM(cm, duration) (cm) = ((duration) / 2) / 29.1


//---------------------------------
// PARALLEL PROGRAMMING PROCESSESS:
//---------------------------------

// Thread brainThread = Thread();
// Thread onClickButtonThread = Thread();


//-----
// LED:
//-----

const int LED = 9;


//-------------
// DYNAMIC PIN:
//-------------

const int tonePin = 6;
#define FREQUENCY 391
#define DURATION 173.07675
#define PERIOD 500


//---------------------------------
// CONFIGURATE LIQUID CRYSTAL PINS:
//---------------------------------

const int rs = 12, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//-----------------------
// ANTI-DEBOUNCER CONSTS:
//-----------------------

// bool lastButton = false;
// bool currentButton = false;
#define ANTIDEBOUNCETIME 5


//------------
// BUTTON PIN:
//------------

const int buttonPin = 8;


//--------------
// RANGE SENSOR:
//--------------

#define LIMITLENGTH 2000
long duration, cm;
unsigned int sample;


//---------------------------
// DISPLAY 16 * 2 PARAMETERS:
//---------------------------

#define LENGTH 16
#define WIDTH   2


//-----------------------------
// OTHER OUTPUT AND INPUT PINS:
//-----------------------------

#define PIN_TRIG 13
#define PIN_ECHO 11
const int sampleWindow = 50;


//--------------
// OTHER CONSTS:
//--------------

#define TRANSMISSIONSPEED 9600


void music();
bool debounce(bool last);
void signal();
void brain();
int clickButton();


void music() {

  tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 195, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 146, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 146, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 783, 692.307);
    delay(769.23);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 174, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 195, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 146, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 146, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 195, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 195, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 346.1535);
    delay(384.615);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 346.1535);
    delay(384.615);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 220, 173.07675);
    delay(192.3075);
    tone(tonePin, 195, 346.1535);
    delay(384.615);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 86.538375);
    delay(96.15375);
    tone(tonePin, 293, 86.538375);
    delay(96.15375);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 783, 692.307);
    delay(769.23);
    tone(tonePin, 523, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 346.1535);
    delay(384.615);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 587, 173.07675);
    delay(192.3075);
    tone(tonePin, 523, 346.1535);
    delay(384.615);
    tone(tonePin, 466, 346.1535);
    delay(384.615);
    tone(tonePin, 440, 346.1535);
    delay(384.615);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 523, 346.1535);
    delay(384.615);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 86.538375);
    delay(96.15375);
    tone(tonePin, 293, 86.538375);
    delay(96.15375);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 346.1535);
    delay(384.615);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 587, 173.07675);
    delay(192.3075);
    tone(tonePin, 523, 346.1535);
    delay(384.615);
    tone(tonePin, 466, 346.1535);
    delay(384.615);
    tone(tonePin, 440, 346.1535);
    delay(384.615);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 523, 346.1535);
    delay(384.615);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 86.538375);
    delay(96.15375);
    tone(tonePin, 293, 86.538375);
    delay(96.15375);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 346.1535);
    delay(384.615);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 587, 173.07675);
    delay(192.3075);
    tone(tonePin, 523, 346.1535);
    delay(384.615);
    tone(tonePin, 466, 346.1535);
    delay(384.615);
    tone(tonePin, 440, 346.1535);
    delay(384.615);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 523, 346.1535);
    delay(384.615);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 86.538375);
    delay(96.15375);
    tone(tonePin, 293, 86.538375);
    delay(96.15375);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 97, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 440, 173.07675);
    delay(192.3075);
    tone(tonePin, 466, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 233, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 293, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 261, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 349, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 391, 173.07675);
    delay(192.3075);
    tone(tonePin, 783, 1384.614);
    delay(1538.46);
}


bool debounce(bool last) {

    bool current = digitalRead(buttonPin);

    if(last != current) {

        delay(ANTIDEBOUNCETIME);
        current = digitalRead(buttonPin);

        return current;
    }
}


void signal() {

  while(true) {

      tone(tonePin, FREQUENCY, DURATION);
      delay(PERIOD);

      if (!digitalRead(buttonPin)) {

          delay(ANTIDEBOUNCETIME);
          if (!digitalRead(buttonPin))
              return;
      }
  }
}


void clearDisplay() {

    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
}


void brain() {

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);

  CONVERTTOCM(cm, duration);

  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.");

  delay(250);

  digitalWrite(LED, LOW);
  unsigned long startMillis= millis();         
  unsigned int peakToPeak = 0;                

  unsigned int signalMax = 0; 
  unsigned int signalMin = 1024;              

   while(millis() - startMillis < sampleWindow) {

      sample = analogRead(0);    
      if (sample < 1024) {

         if (sample > signalMax)
            signalMax = sample; 

         else if (sample < signalMin) 
            signalMin = sample;  
      }
   }

   peakToPeak = signalMax - signalMin; 
   double volts = (peakToPeak * 5.0) / 1024;  
   Serial.println(volts);

   if (cm > LIMITLENGTH)
     clearDisplay();
  
  if(volts > 2 || (cm < 10 && cm >= 3)) {

    lcd.setCursor(0, 0);
    digitalWrite(LED, HIGH);

    if (cm < 1000) {

      lcd.print("length: ");  
      lcd.print(cm);
    }

    lcd.setCursor(0, 1);
    lcd.print("volume: ");
    lcd.print(volts);
    signal(); 
  }

  analogWrite(LED, 103 * volts);
  delay(10);
}


int clickButton() {

  if(digitalRead(buttonPin) == 0)
      exit(EXIT_SUCCESS);
}

void setup() {

  lcd.begin(LENGTH, WIDTH);
  Serial.begin (TRANSMISSIONSPEED);
  //music();

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  //brainThread.onRun(brain);
  //onClickButtonThread.onRun(clickButton);
}

void loop() {

  // if(brainThread.shouldRun())
  //     brainThread.run();
  
  // if(onClickButtonThread.shouldRun())
  //     onClickButtonThread.run();

    brain();
}

