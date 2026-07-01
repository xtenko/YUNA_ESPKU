#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <FastBot.h>

// Inisialisasi bot
void telegramBegin(FastBot &bot);

// Callback pesan Telegram
void telegramHandler(FB_msg &msg);

// Mengirim menu utama
void sendMainMenu(FastBot &bot, int64_t chatID);

// Mengirim status relay
void sendRelayStatus(FastBot &bot, int64_t chatID);

#endif
