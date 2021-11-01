/*
  Program: 3 LM393 Soil Hygrometers with ESP8266 NodeMCU and telegram notification
  Author: Rennan Cockles
  Dependencies: CTBot: https://www.arduino.cc/reference/en/libraries/ctbot/
*/

#include <CTBot.h>
#include <HygroSensor.h>

int DELAY = 1000 * 60 * 60 * 12;  // 12 hours

String WIFI_SSID  = "";
String WIFI_PASSWORD  = "";
String BOT_TOKEN = "";
int64_t CHAT_ID = 0;

bool connected = false;

CTBot bot;
HygroSensor s0(D5);
HygroSensor s1(D6);
HygroSensor s2(D7);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  bot.wifiConnect(WIFI_SSID, WIFI_PASSWORD);
  bot.setTelegramToken(BOT_TOKEN);

  connected = bot.testConnection();

  if (connected) {
    String success = "Connected on the '" + WIFI_SSID + "' Wi-Fi";
    Serial.println(success);
    bot.sendMessage(CHAT_ID, success);
  } else {
    Serial.println("Error connecting on Wi-Fi");
  }
}

void loop()
{
  s0.update();
  s1.update();
  s2.update();

  if (connected && s0.changedDry()) {
    bot.sendMessage(CHAT_ID, "Dry soil at sensor 0");
    Serial.println("Dry soil at sensor 0");
  }
  if (connected && s1.changedDry()) {
    bot.sendMessage(CHAT_ID, "Dry soil at sensor 1");
    Serial.println("Dry soil at sensor 1");
  }
  if (connected && s2.changedDry()) {
    bot.sendMessage(CHAT_ID, "Dry soil at sensor 2");
    Serial.println("Dry soil at sensor 2");
  }

  Serial.print("Sensor 0: ");
  Serial.println(s0.getValue());
  Serial.print("Sensor 1: ");
  Serial.println(s1.getValue());
  Serial.print("Sensor 2: ");
  Serial.println(s2.getValue());

  delay(DELAY);
}
