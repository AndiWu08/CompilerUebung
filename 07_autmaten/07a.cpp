#include <iostream>

int scannerA() 
{ 
    int zustand = 0;
    int ch;
    std::cout <<  "a*[a|b] \n";

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        char zeichen = (char)ch;
        switch (zustand)
        {
            case 0:
                if (zeichen == 'a' || zeichen == 'b')
                    zustand = (zeichen == 'a') ? 1 : 2; 
                else
                    zustand = 99;
                break;
            case 1:
                if (zeichen == 'a' || zeichen == 'b')
                    zustand = (zeichen == 'a') ? 1 : 2; 
                else
                    zustand = 99;
                break;
            case 2:
                if (zeichen != '\n')
                {
                    zustand = 99;
                }
                break;
            default:
                zustand = 99;
                break;
        }  
    }
    std::cout << "Endzustand:" << zustand << "\n";
    if ((zustand == 1) | (zustand == 2))
    {
        return 1;
    }
    else if (zustand == 99)
    {
        return 99;
    }
    else
    {
        return 0;
    }
}

int main() 
{ 
    std::cout << "Eingabe: " << (scannerA() == 1 ? "Akzeptiert" : "Abgelehnt") << std::endl;
    return 0; 
}