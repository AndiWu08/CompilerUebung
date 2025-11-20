#include <stdio.h>
#include <iostream>

char token;
void S(); void A(); // Vorwärtsdeklaration

int zahl;

char scanner()
{
	return getchar();
}

void check(char e_token)
{
	if (token==e_token)
		token=scanner();
	else
	{
		printf("Syntaxfehler: %c erwartet",e_token);
		while (token!='\n') token=scanner(); // Lesen bis Eingabeende
	}
}

void parser()
{
	token=scanner();
	S();
	while (token!='\n')
	{
		printf("Syntaxfehler am Eingabeende\n");
		token=scanner();
	}
}

void S() {
    if (token == '1')
    {
        std::cout << "S->1A \n";
        check('1');
        zahl = 1;
        A();
    }
    else
    {
        std::cout << "Falsche Eingabe \n";
    }
    
} 


void A() {
    if (token == '1')
    {
        std::cout << "A->1A \n";
        check('1');
        zahl++;
        A();
    }
    else if (token == '\n')
    {
        std::cout << "A->Epsilon \n";
        std::cout << "Zahl erkannt " << zahl << "\n";
    }
    else
    {
        std::cout << "falsche Eingabe \n";
    }
    
} 

int main()
{
	while (!feof(stdin)) parser();
    return 1;
}