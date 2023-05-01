#include <LiquidCrystal.h>
#include <Thread.h>
#include <stdlib.h>


#define PIN_TRIG 13
#define PIN_ECHO 11


const int LED = 9;
const int sampleWindow = 50;
const int tonePin = 6;
const int speakerPin = 6;

const int rs = 12, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long duration, cm;
unsigned int sample;


Thread brainThread = Thread();
Thread onClickButtonThread = Thread();

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


bool lastButton = false;
bool currentButton = false;


bool debounce(bool last) {

    bool current = digitalRead(8);

    if(last != current) {

        delay(5);
        current = digitalRead(8);

        return current;
    }
}


void signal() {

  while(true) {

      tone(tonePin, 391, 173.07675);
      delay(500);

      if(digitalRead(8) == 0) {

          delay(5);
          if(digitalRead(8) == 0)
              return;
      }
  }
}


void brain() {

  //tone(tonePin, 1000);

  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);

  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2) / 29.1;

  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.");

  // Задержка между измерениями для корректной работы скеча
  delay(250);

  digitalWrite(LED, LOW);
   // Cохраняем текущие значение millis в startMillis
   unsigned long startMillis= millis();         
   // Создаем переменною peakToPeak, где храним разницу между минимальным и максимальным сигналом
   unsigned int peakToPeak = 0;                

   // signalMax максимальным значением
   unsigned int signalMax = 0; 
   // signalMin минимальным значением                 
   unsigned int signalMin = 1024;              

   // Пока в startMillis содержащиеся больше заданного sampleWindow, выполняется код в цикле while
   while (millis() - startMillis < sampleWindow) 
   {
      // Сохраняем значение переменной sample считанное с аналогового входе 0
      sample = analogRead(0);    
      // Если значение sample меньше 1024, то есть максимальное значение, читаемое на аналоговом порту                
      if (sample < 1024)                         
      {
         // Если значение sample больше максимального значения, найденного в signalMax
         if (sample > signalMax)                
         {
            // Обновление значения signalMax, содержащимся в sample
            signalMax = sample; 
         }
         //  В противном случае, если значение sample меньше, чем signalMin
         else if (sample < signalMin) 
         {
            // Обновление значения signalMin, содержащимся в sample
            signalMin = sample;  
         }
      }
   }
   //  В переменной peakToPeak будет хранится разницу между максимальным значением и минимальным значением.
   peakToPeak = signalMax - signalMin; 
   // Значение peakToPeak умножается на 5 - это напряжение, с которым работает Arduino, а затем делим на 1024, поскольку на аналоговом порту от 0 до 1024.
   double volts = (peakToPeak * 5.0) / 1024;  
   // Отправляем переменную в вольте.
   Serial.println(volts);

   if(cm > 2000) {

     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("                ");
   } 
  
  if(volts > 2 || (cm < 10 && cm >= 3)) {

        lcd.setCursor(0, 0);
        
        digitalWrite(LED, HIGH);

      if(cm < 1000) {

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

  if (digitalRead(8) == 0)
      exit(0);
}

void setup() {

  // Инициализируем взаимодействие по последовательному порту
  
  lcd.begin(16, 2);

  Serial.begin (9600);
  //music();

  //Определяем вводы и выводы
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(8, INPUT_PULLUP);

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
