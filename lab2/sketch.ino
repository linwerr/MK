#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h> 
#include <DHT.h>
#include <Adafruit_BMP085.h>

LiquidCrystal_I2C display(0x27, 16, 2);
DHT sensor(2, DHT22);
RTC_DS1307 clock;
Adafruit_BMP085 barometer;

void setup() {
  //дисплей
  display.init();
  display.backlight();
  clock.begin();
  sensor.begin();
  barometer.begin();
}

void loop() {
  //время
  DateTime currentTime = clock.now();

  display.setCursor(0, 0);
  int hours = currentTime.hour();
  int minutes = currentTime.minute();
  int seconds = currentTime.second();

  if (hours <= 9) {
    display.print("0");
  }
  display.print(hours);
  display.print(":");

  if (minutes <= 9) {
    display.print("0");
  }
  display.print(minutes);
  display.print(":");

  if (seconds <= 9) {
    display.print("0");
  }
  display.print(seconds);
  
  display.print(" ");

  //температура
  float temperature = sensor.readTemperature();
  display.print(temperature);
  display.print("*C");

  //давление
  display.setCursor(0, 1);
  long pressure = barometer.readPressure();
  display.print("P");
  display.print(pressure);

  display.print(" ");

  //влажность
  float humidity = sensor.readHumidity();
  display.print("H");
  display.print(humidity);

  delay(1000);
  display.clear();
}
