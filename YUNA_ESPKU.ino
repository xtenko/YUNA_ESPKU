#include <WiFi.h>
#include <FastBot.h>

#include "config.h"
#include "relay.h"
#include "telegram.h"

// TODO: WiFiManager module will replace connectWiFi() in a future commit.
// TODO: Telegram manager will encapsulate FastBot.

FastBot bot(BOT_TOKEN);

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  if (WiFi.status() == WL_CONNECTED) return;
  Serial.print("Menghubungkan WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("WiFi Terhubung");
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  connectWiFi();
  relayBegin();
  bot.setChatID(CHAT_ID);
  telegramBegin(bot);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) connectWiFi();
  bot.tick();
}
