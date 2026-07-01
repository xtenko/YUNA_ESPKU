#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>
#include "config.h"

// Status relay
extern bool relayState[6];

// Inisialisasi
void relayBegin();

// Kontrol relay
void relayOn(uint8_t relay);
void relayOff(uint8_t relay);
void relayToggle(uint8_t relay);

// Kontrol semua relay
void relayAllOn();
void relayAllOff();

// Membaca status relay
bool relayStatus(uint8_t relay);

// Mengubah output relay
void relayWrite(uint8_t relay, bool state);

#endif
