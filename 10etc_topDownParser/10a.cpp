#include <stdio.h>
#include <iostream>

char token;
void S(); void A(); void B(); //m�ssen implementiert werden!

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
    std::cout << "Regel S->AB \n";
    A();
    B();
} 
void A() {
    if (token == 'a')
    {
        std::cout << "Regel A->aaB \n";
        check('a');
        check('a');
        B();
    } else {
        std::cout << "Regel A->B \n";
        B();
    }
} 

void B() {
    if (token == 'b')
    {
        std::cout << "Regel B->b \n";
        check('b');
    }
    else
    {
        std::cout << "Fehler \n";
    }
    
} 


int main()
{
	while (!feof(stdin)) parser();
    return 1;
}