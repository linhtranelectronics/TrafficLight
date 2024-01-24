//used 1903 led with 5 led in a colum

#include "Adafruit_NeoPixel.h"
#define PIN1        8
#define PIN2         7
#define NUMPIXELS 6
Adafruit_NeoPixel colum1(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel colum2(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
auto red = colum1.Color(255, 0, 0);
auto green = colum1.Color(0, 255, 0);
auto yellow = colum1.Color(255, 255, 0);
auto off = colum1.Color(0, 0, 0);
uint8_t countTime;
const uint8_t maxTime = 30;
const uint8_t timeYellow = 2;
const uint8_t timeGreen = 13;
const uint8_t timeRed = 15;

uint8_t ledRed = 4;
uint8_t ledYellow = 3;
uint8_t ledGreen = 2;
uint8_t peLedRed = 1;
uint8_t peLedGreen = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
colum1.begin();
colum1.clear();
colum2.begin();
colum2.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
updateTime();

lane1();
lane2();
}

void updateTime()
{
static uint8_t maxTimeCount = maxTime;
static uint32_t lastTimeCount;
if (lastTimeCount+1000 <= millis())
{
  lastTimeCount = millis();
  countTime++;
  countTime = countTime>maxTime?0:countTime;
  Serial.println(countTime);
}
}
void lane1()
{
  // xanh - vàng - đỏ
  if (countTime < timeGreen)
  {
    colum1.setPixelColor(ledGreen, green);
    colum1.setPixelColor(ledYellow, off);
    colum1.setPixelColor(ledRed, off);

    colum1.setPixelColor(peLedGreen, off);
    colum1.setPixelColor(peLedRed, red);
    colum1.show();
  }
  else if (countTime >= timeGreen && countTime < timeGreen + timeYellow)
  {
    colum1.setPixelColor(ledGreen, off);
    colum1.setPixelColor(ledYellow, yellow);
    colum1.setPixelColor(ledRed, off);

    colum1.setPixelColor(peLedGreen, off);
    colum1.setPixelColor(peLedRed, red);
    colum1.show();
  }
  else
  {
    colum1.setPixelColor(ledGreen, off);
    colum1.setPixelColor(ledYellow, off);
    colum1.setPixelColor(ledRed, red);

    colum1.setPixelColor(peLedGreen, green);
    colum1.setPixelColor(peLedRed, off);
    colum1.show();
  }


}
void lane2()
{
  //  đỏ - xanh - vàng
  if (countTime < timeRed)
  {
    colum2.setPixelColor(ledGreen, off);
    colum2.setPixelColor(ledYellow, off);
    colum2.setPixelColor(ledRed, red);

    colum2.setPixelColor(peLedGreen, green);
    colum2.setPixelColor(peLedRed, off);
    colum2.show();
  }
  else if (countTime >= timeRed && countTime < timeRed + timeGreen)
  {
    colum2.setPixelColor(ledGreen, green);
    colum2.setPixelColor(ledYellow, off);
    colum2.setPixelColor(ledRed, off);
    
    colum2.setPixelColor(peLedGreen, off);
    colum2.setPixelColor(peLedRed, red);
    colum2.show();
  }
  else
  {
    colum2.setPixelColor(ledGreen, off);
    colum2.setPixelColor(ledYellow, yellow);
    colum2.setPixelColor(ledRed, off);
    
    colum2.setPixelColor(peLedGreen, off);
    colum2.setPixelColor(peLedRed, red);
    colum2.show();
  }
}
