#include "grupp6.c"
//#include <stdlib.h> finns i Grupp6
//#include <string.h> finns i Grupp6
//#include <stdio.h>   finns i Grupp6 // för sprintf
#include <nrfx.h>
#include <nrf5340_application.h>
#include <nrfx_config.h>
#include <nrf.h>
#include <nrfx_uarte.h>
//#include <nrf_gpio.h>  //finns i Grupp6
#include <nrfx_systick.h>
#include <nrfx_rtc.h>



#define PIN_TXD 20
#define PIN_RXD 22

#define LED1 28
#define LED2 29
#define LED3 30
#define LED4 31
#define BUTTON1 23
#define BUTTON2 24
#define BUTTON3 8
#define BUTTON4 9

#define LED_OFF 1
#define LED_ON 0

#define SIZE 10

#define LIST_SIZE 25
#define TREE_SIZE 255
#define MIN_VALUE 0
#define MAX_VALUE 1000

nrfx_uarte_t instance = NRFX_UARTE_INSTANCE(0);
nrfx_rtc_t rtc_instance = NRFX_RTC_INSTANCE(0);


//Starten av uppgift 1 lab 2
/*
List head;


// UART write
void uarte_write(char* data, int length)
{
    nrfx_uarte_tx(&instance, data, length, 0);
}

// Skicka sträng via UART
void uart_send_string(const char* str)
{
    uarte_write((char*)str, strlen(str));
}

// Läs in text via UART
void read_string(char *buffer, int max_len)
{
    uint8_t ch;
    int i = 0;

    while (i < max_len - 1)
    {
        nrfx_uarte_rx(&instance, &ch, 1);
        if (ch == '\r' || ch == 13) break;  // Enter
        buffer[i++] = (char)ch;
    }

    buffer[i] = '\0';
}

// Läs ett heltal från UART
int read_int()
{
    char buffer[50];
    read_string(buffer, sizeof(buffer));
    return atoi(buffer);
}

int main(void)
{
    head = create_empty_list();
    char buffer[10];
    char input;

    uart_send_string("Välkommen till länkad lista!\n");

    while (1)
    {
        uart_send_string("\n--- Meny ---\n");
        uart_send_string("1: Lägg till först (10)\n");
        uart_send_string("2: Lägg till sist (20)\n");
        uart_send_string("3: Ta bort första\n");
        uart_send_string("4: Ta bort sista\n");
        uart_send_string("5: Töm listan\n");
        uart_send_string("6: Skriv ut listan\n");
        uart_send_string("Val: ");

        read_string(buffer, sizeof(buffer));  // Läs input
        input = buffer[0];  // Första tecknet som val

        switch (input)
        {
            case '1':
                add_first(&head, 10);
                uart_send_string("Lade till 10 först\n");
                break;

            case '2':
                add_last(&head, 20);
                uart_send_string("Lade till 20 sist\n");
                break;

            case '3':
                remove_first(&head);
                uart_send_string("Tog bort första\n");
                break;

            case '4':
                remove_last(&head);
                uart_send_string("Tog bort sista\n");
                break;

            case '5':
                clear_list(&head);
                uart_send_string("Listan rensad\n");
                break;

            case '6':
                uart_send_string("Listans innehåll: ");
                print_list(head);
                uart_send_string("\n");
                break;

            default:
                uart_send_string("Ogiltigt val, försök igen\n");
                break;
        }
    }
}
*/ //Slutet av uppgift 1 lab 2


//Aktivera klocka
//Starta tid
//Vänta på knapptryckning
//När knapp trycks använd värde på klocka som srand(Värde klocka)
//displaya en rand() och kolla att ni får olika värden
/*
void int_gpio(void){
    const nrfx_uarte_config_t config = NRFX_UARTE_DEFAULT_CONFIG(PIN_TXD, PIN_RXD);
    nrfx_err_t errr = nrfx_uarte_init(&instance, &config, NULL);
    if (errr != 0) {
        // Hantera ev. fel
    }

    //  LED-pinnar som output
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_cfg_output(LED2);
    nrf_gpio_cfg_output(LED3);
    nrf_gpio_cfg_output(LED4);

    // Släck alla från början
    nrf_gpio_pin_write(LED1, LED_OFF);
    nrf_gpio_pin_write(LED2, LED_OFF);
    nrf_gpio_pin_write(LED3, LED_OFF);
    nrf_gpio_pin_write(LED4, LED_OFF);

    nrf_gpio_cfg_input(BUTTON1, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON2, NRF_GPIO_PIN_PULLUP);
}

uint8_t button_status(uint8_t button_pin){
    if(nrf_gpio_pin_read(button_pin) == 0){
        return 0;
    }
    else{
        return 1;
    }
}
*/


/*
int main(void)
{
    nrfx_systick_init();

    // LED som OUTPUT
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_cfg_output(LED2);
    nrf_gpio_cfg_output(LED3);
    nrf_gpio_cfg_output(LED4);

    // Nollar LEDs (kom ihåg att det är omvänt här)
    nrf_gpio_pin_write(LED1, LED_OFF);
    nrf_gpio_pin_write(LED2, LED_OFF);
    nrf_gpio_pin_write(LED3, LED_OFF);
    nrf_gpio_pin_write(LED4, LED_OFF);

    /*
        Pin 23 och 24 som input.
        NRF_GPIO_PIN_PULLUP aktiverar pull-up resistor
        som ser till att pin 23/24 inte hamnar i ett okänt
        läge där det är oklart om den är hög eller låg.
        I praktiken så kopplas en resistor mellan matning och output.

        Det innebär att pinnen är HIGH som default så
        knapptryckning innebär att pinnen blir LOW.

        Så ett förslag är att fixa
        #define PIN_HIGH 0
        #define PIN_LOW 1
        Förutsatt att ni använder NRF_GPIO_PIN_PULLUP.
    */

    /*
    nrf_gpio_cfg_input(BUTTON1, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON2, NRF_GPIO_PIN_PULLUP);

    nrfx_rtc_config_t config = NRFX_RTC_DEFAULT_CONFIG;
    nrfx_err_t errr = nrfx_rtc_init(&rtc_instance, &config, NULL);
    nrfx_rtc_enable(&rtc_instance);
    while(1)
    {
        nrfx_systick_delay_ms(50); // Onödigt att loopa för snabbt.

        if (nrf_gpio_pin_read(BUTTON1) == 0){
            nrf_gpio_pin_write(LED1, LED_ON);
        } else {
            nrf_gpio_pin_write(LED1, LED_OFF);
        }

        if (nrf_gpio_pin_read(BUTTON2) == 0 ){
            nrf_gpio_pin_write(LED2, LED_ON);
            nrfx_systick_delay_ms(3000);
        }

        nrf_gpio_pin_write(LED2, LED_OFF);
    }
} 
*/ // Slut på 3.3

/**/

//List head;

//ÄLDRE KOD
// UART write

List tree;  //Själva trädet

void uarte_write(char* data, int length)
{
    nrfx_uarte_tx(&instance, data, length, 0);
}

// Skicka sträng via UART
void uart_send_string(const char* str)
{
    char msg[400];
    sprintf(msg, "%s", str);
    uarte_write(msg, strlen(msg));
}

// Läs in text via UART
void read_string(char *buffer, int max_len)
{
    uint8_t ch;
    int i = 0;

    while (i < max_len - 1)
    {
        nrfx_uarte_rx(&instance, &ch, 1);
        if (ch == '\r' || ch == 13) break;  // Enter
        buffer[i++] = (char)ch;
    }

    buffer[i] = '\0';
}

// Läs ett heltal från UART
int read_int()
{
    char buffer[50];
    read_string(buffer, sizeof(buffer));
    return atoi(buffer);
}
void initstuff(void) { // För att aktivera kretskortet
    // UART
    const nrfx_uarte_config_t config = NRFX_UARTE_DEFAULT_CONFIG(20, 22); // PIN_TXD, PIN_RXD
    nrfx_uarte_init(&instance, &config, NULL);

    // RTC
    nrfx_rtc_config_t rtc_config = NRFX_RTC_DEFAULT_CONFIG;
    nrfx_err_t err = nrfx_rtc_init(&rtc_instance, &rtc_config, NULL);
    nrfx_rtc_init(&rtc_instance, &rtc_config, NULL);
    nrfx_rtc_enable(&rtc_instance); //Vi lade till rtc bakom instance

    // Systick
    nrfx_systick_init();
    while (nrf_gpio_pin_read(BUTTON1) == 1);
    srand(nrf_systick_val_get()); 

    nrf_systick_val_clear();
    uint32_t pretime = nrf_systick_val_get();
    // LED
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_pin_write(LED1, LED_OFF);  // Släck LED

    // Aktivera Knappar 
    //aktivera BUTTONS 1, 2, 3 och 4 fast vi inte använder 4
    nrf_gpio_cfg_input(BUTTON1, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON2, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON3, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON4, NRF_GPIO_PIN_PULLUP);
}






void test_merge_sort() {
    char msg[100];  // Buffer för att lagra textmeddelanden som skickas via UART

    // Skapa en array med heltal
    int* arr = malloc(sizeof(int) * SIZE);

    // Fyll arrayen med slumpmässiga tal
    fill_random_array(arr, SIZE, MIN_VALUE, MAX_VALUE);

    // Skriv ut arrayen före sortering
    uart_send_string("Merge Sort - Före sortering:\r\n");
    for (int i = 0; i < SIZE; i++) {
        sprintf(msg, "%d ", arr[i]);      // Omvandla tal till text
        uart_send_string(msg);            // Skicka texten via UART
    }
    uart_send_string("\r\n");             // Radbrytning i terminalen

    // Starta tidtagning
    nrf_systick_val_clear();              // Nollställ timern
    uint32_t pre = nrf_systick_val_get(); // Läs starttid
    merge_sort(arr, 0, SIZE - 1);         // Kör Merge Sort
    uint32_t post = nrf_systick_val_get();// Läs sluttid

    // Skriv ut arrayen efter sortering
    uart_send_string("Efter sortering:\r\n");
    for (int i = 0; i < SIZE; i++) {
        sprintf(msg, "%d ", arr[i]);
        uart_send_string(msg);
    }
    uart_send_string("\r\n");

    // Beräkna hur lång tid det tog (i ticks)
    uint32_t ticks = pre - post;

    // Kontrollera om arrayen är sorterad rätt
    int sorted = is_sorted_array(arr, SIZE);

    // Skicka resultat via UART
    sprintf(msg, "Merge Sort, size=%d, ticks=%lu", SIZE, ticks, sorted ? "YES" : "NO");
    uart_send_string(msg);

    // Rensa minnet
    free(arr);
}



void test_quick_sort() {
    char msg[100];  // Buffer för att lagra textmeddelanden som ska skickas via UART

    // Skapa en dynamisk array med heltal
    int* arr = malloc(sizeof(int) * SIZE);

    // Fyll arrayen med slumpmässiga heltal mellan MIN_VALUE och MAX_VALUE
    fill_random_array(arr, SIZE, MIN_VALUE, MAX_VALUE);

    // Skriv ut arrayen före sortering
    uart_send_string("Quick Sort - Före sortering:\r\n");
    for (int i = 0; i < SIZE; i++) {
        sprintf(msg, "%d ", arr[i]);      // Konvertera varje tal till text
        uart_send_string(msg);            // Skicka texten via UART
    }
    uart_send_string("\r\n");             // Radbrytning

    // Starta tidtagning
    nrf_systick_val_clear();              // Nollställ timern
    uint32_t pre = nrf_systick_val_get(); // Läs av tiden före sorteringen
    quick_sort(arr, 0, SIZE - 1);         // Kör själva sorteringen
    uint32_t post = nrf_systick_val_get();// Läs av tiden efter sorteringen

    // Skriv ut arrayen efter sortering
    uart_send_string("Efter sortering:\r\n");
    for (int i = 0; i < SIZE; i++) {
        sprintf(msg, "%d ", arr[i]);      // Konvertera varje tal till text
        uart_send_string(msg);            // Skicka via UART
    }
    uart_send_string("\r\n");             // Radbrytning

    // Beräkna hur många ticks sorteringen tog
    uint32_t ticks = pre - post;

    // Kontrollera om arrayen verkligen blev sorterad
    int sorted = is_sorted_array(arr, SIZE);

    // Skicka resultat via UART
    sprintf(msg, "Quick Sort, size=%d, ticks=%lu \r\n", SIZE, ticks);
    uart_send_string(msg);

    // Frigör minnet som användes för arrayen
    free(arr);
}

void test_bubble_sort() {
    char msg[100];

    // Skapa en länkad lista med slumpmässiga värden
    List list = create_random_list(SIZE, MIN_VALUE, MAX_VALUE);

    // Skriv ut listan före sortering
    uart_send_string("Bubble Sort (Linked List) - Före sortering:\r\n");
    print_list(list);     // Visar listan i ordning via UART
    uart_send_string("\r\n");

    // Starta tidtagning
    nrf_systick_val_clear();
    uint32_t pre = nrf_systick_val_get();
    bubble_sort(&list);      // Kör bubble sort på listan
    uint32_t post = nrf_systick_val_get();

    // Skriv ut listan efter sortering
    uart_send_string("Efter sortering:\r\n");
    print_list(list);
    uart_send_string("\r\n");

    // Räkna ut hur många ticks det tog
    uint32_t ticks = pre - post;

    // Kontrollera om listan är sorterad
    //int sorted = is_sorted(list);

    // Skicka resultat via UART
    sprintf(msg, "Bubble Sort, size=%d, ticks=%lu\r\n", SIZE, ticks);
    uart_send_string(msg);

    // Rensa minnet
    free_tree(&list);
}
/*

int main(void)
{
    const nrfx_uarte_config_t config = NRFX_UARTE_DEFAULT_CONFIG(20, 22); // PIN_TXD, PIN_RXD
    nrfx_uarte_init(&instance, &config, NULL);

    // RTC
    nrfx_rtc_config_t rtc_config = NRFX_RTC_DEFAULT_CONFIG;
    nrfx_err_t errr = nrfx_rtc_init(&rtc_instance, &rtc_config, NULL);
    nrfx_rtc_enable(&rtc_instance);

    // Systick
    nrfx_systick_init();

    // LED
    nrf_gpio_cfg_output(LED1);
    nrf_gpio_pin_write(LED1, LED_OFF);  // Släck LED

    // Knapp
    nrf_gpio_cfg_input(BUTTON1, NRF_GPIO_PIN_PULLUP);


    initstuff();  // Initierar alla moduler

    char str[64];
    uint32_t ms;
    uint32_t s;

    while (1)
    {
        // Hämta antal ticks från RTC och omvandla till millisekunder
        
        ms = nrfx_rtc_counter_get(&rtc_instance) / 33;  // ≈ 32.768 Hz → ms
        s = ms / 1000;

        // Formatera sträng
        sprintf(str, "%d s, eller %d ms\r\n", s, ms);
        uarte_write(str, strlen(str));

        // Vänta 1000 ms
        nrfx_systick_delay_ms(1000);
        
        if (nrf_gpio_pin_read(BUTTON1) == 0)
    {
        // Läs RTC-counter-värde (antal tick från start)
        uint32_t rtc_val = nrfx_rtc_counter_get(&rtc_instance);

        // Dela ner till millisekunder (≈32.768 Hz → dela med 33)
        uint32_t seed = rtc_val / 33;

        // Använd seed till slumptalsgenerator
        srand(seed);

        // Bekräfta vilket seed som användes
        sprintf(str, "Seed: %lu\r\n", seed);
        uarte_write(str, strlen(str));

        // Skriv ut 5 slumpmässiga tal
        for (int i = 0; i < 2; i++) {
            int tal = rand();
            sprintf(str, "Rand: %d\r\n", tal);
            uarte_write(str, strlen(str));
            nrfx_systick_delay_ms(300);  // Paus mellan varje tal
        }

        // Vänta tills knappen släpps (för att undvika dubbla triggers)
        while (nrf_gpio_pin_read(BUTTON1) == 0);

        // Liten extra väntetid för debounce
        nrfx_systick_delay_ms(300);
        }
    }
}
*/
/*


//Starten av lab 2

int main(void) {

    
    initstuff();  // Startar UART, RTC, från funktionen ovan

    // Här kan vi testa UART manuellt innan programmet fortsätter (valfritt, tillfälligt)
    /*
    char test_msg[] = "\r\nTestmeddelande via UART\r\n";
    uart_send_string(test_msg);
    

    // Vi skapar två separata listor:
    List stack = create_empty_list();   
    List queue = create_empty_list();   

    char str[64];  // Textbuffer för meddelanden till Putty

    while (1) {  // Programmet kör i en oändlig loop

        
        // Vänta på att någon av knapparna 1, 2 eller 3 trycks ned
        //Så länge knapparna inte är nedtryckta så fungerar det inte.
        while (!button_status(BUTTON1) && !button_status(BUTTON2) && !button_status(BUTTON3));

        // KNAPP 1: Slumpa ett tal och lägg till i stack eller kö ---
        if (button_status(BUTTON1)) {
            uint32_t seed = nrfx_rtc_counter_get(&rtc_instance) / 33;  // Hämtar värde från klockan
            srand(seed);  // Använder värdet som "seed" för att slumpa
            //Från 4.1 RTC övning

            int n = rand() % 100;  // Skapar ett slumptal mellan 0 och 99

            sprintf(str, "Random: %d\r\n", n);  // Gör om talet till text
            uart_send_string(str);  // Skicka till Putty

            if (n % 2 == 0) {  // Om talet är jämnt
                add_first(&stack, n);  // Lägg det i stacken
                uart_send_string("Push till stack brorsan!\r\n");
            } else {  // Om talet är udda
                add_last(&queue, n);  // Lägg det i kön
                uart_send_string("Enqueue till Kön och respektera den!\r\n");
            }

            while (button_status(BUTTON1));  // Vänta tills knappen släpps
            nrfx_systick_delay_ms(500);  // Liten paus en halv sekund
        }

        // KNAPP 2: Ta bort översta från stacken (pop)
        else if (button_status(BUTTON2)) {
            if (!is_empty(stack)) {  // Om stacken inte är tom
                int val = get_first_element(stack);  // Hämta värdet
                remove_first(&stack);  // Ta bort det från stacken
                sprintf(str, "POP från stack: %d\r\n", val);
                uart_send_string(str);
            } else {
                uart_send_string("Stacken är tom\r\n");
            }

            while (button_status(BUTTON2));  // Vänta tills knappen släpps
            nrfx_systick_delay_ms(500);
        }

        // KNAPP 3: Ta bort första från kön (dequeue) 
        else if (button_status(BUTTON3)) {
            if (!is_empty(queue)) {  // Om kön inte är tom
                int val = get_first_element(queue);  // Hämta värdet
                remove_first(&queue);  // Ta bort det från kön
                sprintf(str, "DEQUEUE från kö HEJDÅÅÅÅ: %d\r\n", val);
                uart_send_string(str);
            } else {
                uart_send_string("Kön är tom :)\r\n");
            }

            while (button_status(BUTTON3));  // Vänta tills knappen släpps
            nrfx_systick_delay_ms(500);
        }

        // Visa vad som ligger överst i stacken (peek) 
        if (!is_empty(stack)) {
            int top = get_first_element(stack);
            sprintf(str, "Top (STACK): %d\r\n", top);
            uart_send_string(str);
        } else {
            uart_send_string("Stacken är tom\r\n");
        }

        // Visa första i kön (front)
        if (!is_empty(queue)) {
            int front = get_first_element(queue);
            sprintf(str, "Front (QUEUE): %d\r\n", front);
            uart_send_string(str);
        } else {
            uart_send_string("Kön är tom\r\n");
        }

        // Väntar 1 sekund innan nästa varv
        nrfx_systick_delay_ms(1000);
    }
}
*/

//Slut av lab 2

/* Laboration 3 uppgift 2
int main(void)
{
    nrfx_systick_init();
    initstuff();  // Initiera UART, RTC, knappar osv

    tree = create_empty_tree();  // Starta med tomt träd

    // Meny för interaktion efter inmatning
    char buffer[64];
    int val;

    while (1)
    {
        uart_send_string("\r\n--- MENY ---\r\n");
        uart_send_string("1: Skriv ut trädet (inorder)\r\n");
        uart_send_string("2: Ta bort ett värde\r\n");
        uart_send_string("3: Sök efter ett värde\r\n");
        uart_send_string("4: Visa djup\r\n");
        uart_send_string("5: Visa minsta djup\r\n");
        uart_send_string("6: Balansera trädet\r\n");
        uart_send_string("7: Rensa trädet\r\n");
        uart_send_string("8: Lägg till nytt värde\r\n");
        uart_send_string("9: Skriv ut trädet (preorder)\r\n");
        uart_send_string("Val: ");

        read_string(buffer, sizeof(buffer));
        char input = buffer[0];

        switch (input)
        {
            case '1':
                uart_send_string("Trädet (inorder): ");
                print_inorder(tree);
                uart_send_string("\r\n");
                break;

            case '2':
                uart_send_string("Ange heltal att ta bort: ");
                val = read_int();
                remove_element(&tree, val);
                uart_send_string("Försöker ta bort värdet\r\n");
                break;

            case '3':
                uart_send_string("Ange heltal att söka efter: ");
                val = read_int();
                if (find(tree, val))
                    uart_send_string("Värdet finns i trädet\r\n");
                else
                    uart_send_string("Värdet hittades EJ\r\n");
                break;

            case '4':
                val = depth(tree);
                sprintf(buffer, "Djup: %d\r\n", val);
                uart_send_string(buffer);
                break;

            case '5':
                val = min_depth(tree);
                sprintf(buffer, "Minsta möjliga djup: %d\r\n", val);
                uart_send_string(buffer);
                break;

            case '6':
                balance_tree(&tree);
                uart_send_string("Trädet är balanserat!\r\n");
                break;

            case '7':
                free_tree(&tree);
                uart_send_string("Trädet är rensat.\r\n");
                break;

            case '8':
                uart_send_string("Ange heltal att lägga till: ");
                val = read_int();
                insert_sorted(&tree, val);
                uart_send_string("Värdet är tillagt\r\n");
                break;

            case '9':
                uart_send_string("Trädet (preorder): ");
                print_preorder(tree);
                uart_send_string("\r\n");
                break;

            default:
                uart_send_string("Ogiltigt val, försök igen.\r\n");
                break;
        }

        nrfx_systick_delay_ms(500);  // Liten paus
    }
} 
*/

//Start av laboration 3 del 1
/*
int main(void)
{
    nrfx_systick_init();

    initstuff();  // Initiera UART, RTC, knappar, osv

    BSTree tree = create_empty_tree();

    // Skapa ett obalanserat träd genom att lägga in 1 till TREE_SIZE sorterat
    for (int i = 1; i <= TREE_SIZE; i++) {
        insert_sorted(&tree, i);
    }

    //balance_tree(&tree);  // Balansera trädet före sökningen
    // Balanserar trädet så att sökningen blir snabbare (logaritmisk tid) 

    // Tidtagning börjar
    nrf_systick_val_clear();                      // Nollställ räknaren
    uint32_t pre = nrf_systick_val_get();         // Spara startvärde
    find(tree, TREE_SIZE);                        // Sök efter största värdet
    uint32_t post = nrf_systick_val_get();        // Spara slutvärde
    uint32_t ticks = pre - post;                  // Tiden det tog 

    // Skriv ut resultat via UART
    char buffer[64];  // Skapar en textbuffert för att lagra meddelandet som ska skickas via UART

sprintf(buffer, "TREE_SIZE = %d, Ticks = %lu\r\n", TREE_SIZE, ticks);
// Skickar ett meddelande med trädstorlek och antal SysTick ticks, och sparar det i bufferten

uart_send_string(buffer);  // Skickar meddelandet till Putty via UART

    while (1); // Stanna här
}
*/ //Slutet av laboration 3 del 1



//övning 3.1
/*
int main(void)
{
    nrfx_systick_init();         // Initierar SysTick för tidtagning (används i vissa labbar)
    initstuff();                 // Initierar UART, RTC, LED, knappar m.m.

    srand(time(NULL));           // Startar slumptalsgeneratorn med en unik seed (baserat på tid)

    int array[LIST_SIZE];        // Skapar en array av storlek LIST_SIZE (definieras med #define)
    fill_random_array(array, LIST_SIZE, 1, 1000);  // Fyller arrayen med slumptal mellan 1 och 1000

    int sorted = is_sorted_array(array, LIST_SIZE); // Kollar om arrayen är sorterad

    char msg[100];               // Skapar en textbuffert för att lagra utskrift

    sprintf(msg, "Array är %s\r\n", sorted ? "sorterad" : "inte sorterad"); // Skriver meddelandet i bufferten
    uart_send_string(msg);       // Skickar meddelandet via UART till terminal (t.ex. Putty)

    BSTree tree = create_random_tree(LIST_SIZE, 1, 1000); // Skapar ett binärt träd med slumptal
    sorted = is_sorted(tree);    // Kollar om trädet är sorterat

    sprintf(msg, "Binära trädet är %s\r\n", sorted ? "sorterad" : "inte sorterad");  // Skriv nytt meddelande i bufferten
    uart_send_string(msg);       // Skickar det via UART

    while (1);                   // Programmet stannar här – loopar för alltid
}
*/


//Övning 3.2
/*
int main(void)
{
    nrfx_systick_init();     // Initiera SysTick
    initstuff();             // Initiera UART, RTC, knappar, LED etc.
    srand(time(NULL));       // Starta slumptalsgeneratorn

    // Skapa en enkel länkad lista manuellt
    BSTree list = create_empty_tree(); // Vi använder treeNode som lista

    // Fyll listan med slumpmässiga tal (bara högerpekare används)
    for (int i = 0; i < LIST_SIZE; i++) {
        int val = rand() % 100;  // Tal mellan 0–99
        struct treeNode* new_node = malloc(sizeof(struct treeNode));
        new_node->data = val;
        new_node->left = NULL;    // Ignoreras
        new_node->right = NULL;

        // Lägg till i slutet av listan
        if (list == NULL) {
            list = new_node;
        } else {
            struct treeNode* temp = list;
            while (temp->right != NULL)
                temp = temp->right;
            temp->right = new_node;
        }
    }

    uart_send_string("Lista före sortering:\r\n");
    struct treeNode* temp = list;
    char buffer[20];
    while (temp != NULL) {
        sprintf(buffer, "%d ", temp->data);
        uart_send_string(buffer);
        temp = temp->right;
    }
    uart_send_string("\r\n");

    // Sortera listan
    bubble_sort(&list);

    // Skriv ut listan efter sortering
    uart_send_string("Lista efter sortering:\r\n");
    temp = list;
    while (temp != NULL) {
        sprintf(buffer, "%d ", temp->data);
        uart_send_string(buffer);
        temp = temp->right;
    }
    uart_send_string("\r\n");

    while (1);  // Stoppa här
}
*/

/*  ÖVNING 3.3/3.4
int main(void)
{
    nrfx_systick_init();      // Initiera SysTick (om du vill mäta tid)
    initstuff();              // Initiera UART, RTC, LED, knappar m.m.
    srand(time(NULL));        // Starta slumptalsgeneratorn

    int array[LIST_SIZE];     // Skapa array av storlek LIST_SIZE
    fill_random_array(array, LIST_SIZE, 1, 30);  // Fyll arrayen med slumpmässiga tal mellan 1 och 1000

    // Skriv ut arrayen före sortering
    uart_send_string("Array före Merge Sort:\r\n");
    char buffer[20];
    for (int i = 0; i < LIST_SIZE; i++) {
        sprintf(buffer, "%d ", array[i]);
        uart_send_string(buffer);
    }
    uart_send_string("\r\n");

    //  Sortera arrayen med Quick Sort
    quick_sort(array, 0, LIST_SIZE - 1);

    //  Skriv ut arrayen efter sortering
    uart_send_string("Array efter Quick Sort:\r\n");
    for (int i = 0; i < LIST_SIZE; i++) {
        sprintf(buffer, "%d ", array[i]);
        uart_send_string(buffer);
    }
    uart_send_string("\r\n");

    while (1);  // Stanna här
} */

int main(void) 
{
    nrfx_systick_init();
    initstuff();

    test_merge_sort();
    test_quick_sort();
    test_bubble_sort();

    while (1);
}