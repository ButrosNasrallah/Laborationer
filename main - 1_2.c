#include <nrfx.h>
#include <nrf5340_application.h>
#include <nrfx_config.h>
#include <nrf.h>
#include <nrfx_uarte.h>
#include <stdio.h>     // För sprintf om det ska skriva ut text
#include <string.h>    // För strlen()
#include <stdlib.h>    // För atoi()

//definierar vilka pinnar som ska användas för att skicka och ta emot data:
#define PIN_TXD 20
#define PIN_RXD 22

//Skapar en driver instance för UARTE:
nrfx_uarte_t instance = NRFX_UARTE_INSTANCE(0);

//skapar en buffer att ta emot tecken vi läser över UARTE
char uarte_buffer;

//en funktion för att skicka strängen data av storlek length, över UARTE
void uarte_write(char* data, int length)
{
    nrfx_uarte_tx(&instance, data, length, 0);
}

// Funktion som läser en sträng tills Enter trycks
void read_string(char *buffer, int max_len) {
    uint8_t ch;
    int i = 0;

    while (i < max_len - 1) { // Lämna plats för '\0'
        nrfx_uarte_rx(&instance, &ch, 1); // Läs ett tecken

        if (ch == '\r' || ch == 13) { // Enter (carriage return)
            break;
        }

        buffer[i++] = (char)ch; // Lägg till tecknet i strängen
    }

    buffer[i] = '\0'; // Null-terminera strängen
}

// Funktion som läser en sträng och omvandlar till heltal
int read_int() {
    char buffer[50];
    read_string(buffer, sizeof(buffer));  // Läs in text från användaren
    return atoi(buffer);                  // Konvertera till int
}

int main(void)
{
    // Standardkonfiguration för UART
    const nrfx_uarte_config_t config = NRFX_UARTE_DEFAULT_CONFIG(PIN_TXD, PIN_RXD);
    nrfx_err_t errr = nrfx_uarte_init(&instance, &config, NULL);

    //TEST
    if (errr != 0){
        // Här kan man lägga till felhantering om man vill
    }

    // Info-meddelande till PuTTY så användaren vet vad som ska göras , TEST
    char msg[] = "\n\rSkriv ett heltal och tryck Enter:\n\r";
    uarte_write(msg, strlen(msg));

    while (1)
    {
        int tal = read_int();  // Läs heltal från användaren via UART
        char TEST[50];
        //TEST
        sprintf(TEST, "\n\rDu skrev talet: %d\n\r", tal);
        uarte_write(TEST, strlen(TEST));
    }
}