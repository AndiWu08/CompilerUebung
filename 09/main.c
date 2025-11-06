// main.c
#include <stdio.h> // <--- DIESE ZEILE WURDE ERGÄNZT!

extern int yylex(void); // Deklariert die von Flex generierte Funktion

int main() {
    printf("Geben Sie Text ein (mit Strg+Z und Enter beenden):\n");
    yylex(); // Startet den Scanner, der Eingaben von stdin liest
    return 0;
}