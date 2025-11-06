%{
#include <stdio.h>
#include <stdlib.h>

int bintodez (char* binary) {
    int i = 0;
    int dez = 0;
    int sign = 1;
    
    while (binary[i] != '\0') {
        switch (binary[i++])
        {
            case 'I':
                dez = dez*2+1;
                break;
            case 'O':
                dez = dez*2;
                break;
            case '-':
                sign = -1;
                break;
        }
    }
    return sign * dez;
}
%}



ziffer [0-9]
bin [IO]
sign [+-]
zeichen [_]



%%
{sign}?{ziffer}+ {printf("Dezimalzahl gefunden! Name=%s \n",yytext); }
{sign}?{bin}+ {printf("Binäzahl gefunden! Name=%s = %d \n",yytext, bintodez(yytext)); }
%%


