#include <iostream>

int scannerA() 
{ 
    int zustand = 0;
    int ch;
    std::cout <<  "(01)*1*0 \n";

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        char zeichen = (char)ch;
        switch (zustand)
        {
            case 0:
                if (zeichen == '0' || zeichen == '1')
                    zustand = (zeichen == '0') ? 1 : 2; 
                else
                    zustand = 99;
                break;
            case 1:
                if (zeichen == '1')
                    zustand = 0; 
                else
                    zustand = 99;
                break;
            case 2:
                if (zeichen == '0' || zeichen == '1')
                    zustand = (zeichen == '0') ? 3 : 2; 
                else
                    zustand = 99;
                break;
            case 3:
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
    if ((zustand == 1) | (zustand == 3))
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