#include <stdio.h>
#include <iostream>

char token;
void S(); void A(); void B(); void C(); //m�ssen implementiert werden!

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
    std::cout << "Regel S->ABC \n";
    A();
    B();
    C();
} 
void A() {
    if (token == 'a')
    {
        std::cout << "Regel A->aB \n";
        check('a');
        B();
    } else {
        std::cout << "Regel A->b \n";
        check('b');
    }
} 

void B() {
    if (token == 'b')
    {
        std::cout << "Regel B->bb \n";
        check('b');
        check('b');
    }
    else
    {
        std::cout << "Regel B->C \n";
        C();
    }
} 

void C() {
    if (token == 'c')
    {
        std::cout << "Regel C->c \n"; 
        check('c');
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