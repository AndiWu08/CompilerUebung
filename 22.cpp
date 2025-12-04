#include <stdio.h>
#include <iostream>

char token;
void S(); void A(); void A_(); void B(); void B_(); void C(); void C_(); // Vorwärtsdeklaration

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
    std::cout << "Regel S->ABbC \n";
    A();
    B();
    check('b');
    C();
} 
void A() {
    if (token == 'b')
    {
        std::cout << "Regel A->bbA_ \n";
        check('b');
        check('b');
        A_();
    } else {
        std::cout << "Fehler \n";
    }
} 

void A_() {
    if (token == 'a')
    {
        std::cout << "Regel A_ -> B \n";
        B();
    } else if (token == 'b')
    {
        std::cout << "Regel A_ -> A_ -> A \n";
        A();
    } else {
        std::cout << "Fehler \n";
    }
    
}

void B() {
    if (token == 'a')
    {
        std::cout << "Regel B->aB_ \n";
        check('a');
        B_();
    }
    else
    {
        std::cout << "Fehler \n";
    }
} 

void B_() {
    if (token == 'c')
    {
        std::cout << "Regel B_-> cC \n";
        check('c');
        C();
    }
    else
    {
        std::cout << "Regel B_ -> Epsilon \n";
    }
} 

void C() {
    std::cout << "Regel C-> C_\n"; 
    C_();
}

void C_() {
    if (token == 'c')
    {
        std::cout << "Regel C_-> cC_ \n";
        check('c');
        C_();
    }
    else
    {
        std::cout << "Regel C_ -> Epsilon \n";
    }
} 

int main()
{
	while (!feof(stdin)) parser();
    return 1;
}