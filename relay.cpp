#include "relay.h"

// =========================
// Status Relay
// =========================
bool relayState[6] = {
    false,
    false,
    false,
    false,
    false,
    false
};

// =========================
// Daftar Pin Relay
// =========================
const uint8_t relayPin[6] = {
    RELAY1_PIN,
    RELAY2_PIN,
    RELAY3_PIN,
    RELAY4_PIN,
    RELAY5_PIN,
    RELAY6_PIN
};

// =========================
// Menulis Output Relay
// =========================
void relayWrite(uint8_t relay, bool state) {

    if (relay < 1 || relay > 6) return;

    relayState[relay - 1] = state;

    digitalWrite(
        relayPin[relay - 1],
        state ? RELAY_ON : RELAY_OFF
    );

}

// =========================
// Inisialisasi Relay
// =========================
void relayBegin() {

    for (int i = 0; i < 6; i++) {

        pinMode(relayPin[i], OUTPUT);

        digitalWrite(relayPin[i], RELAY_OFF);

        relayState[i] = false;

    }

}

// =========================
// Relay ON
// =========================
void relayOn(uint8_t relay) {

    relayWrite(relay, true);

}

// =========================
// Relay OFF
// =========================
void relayOff(uint8_t relay) {

    relayWrite(relay, false);

}

// =========================
// Toggle Relay
// =========================
void relayToggle(uint8_t relay) {

    if (relay < 1 || relay > 6) return;

    relayWrite(relay, !relayState[relay - 1]);

}

// =========================
// Semua ON
// =========================
void relayAllOn() {

    for (int i = 1; i <= 6; i++) {

        relayOn(i);

    }

}

// =========================
// Semua OFF
// =========================
void relayAllOff() {

    for (int i = 1; i <= 6; i++) {

        relayOff(i);

    }

}

// =========================
// Status Relay
// =========================
bool relayStatus(uint8_t relay) {

    if (relay < 1 || relay > 6) return false;

    return relayState[relay - 1];

}
