%{
#include <stdio.h>
#include <stdlib.h>
%}
%option noyywrap  

ziffer [0-9]
letter [a-zA-Z]
sign [+-]
zeichen [_]
%%
while {printf("Schlüsselwort gefunden! Name=%s \n",yytext); }
{letter}({letter}|{ziffer}|{zeichen})* {printf("Bezeichner gefunden! Name=%s \n",yytext); }
{sign}?{ziffer}+ {printf("Ganzzahl gefunden! Name=%s \n",yytext); }
{sign}?{ziffer}+([.,]){ziffer}+ {printf("Gleitkommazahl gefunden! Name=%s \n",yytext); }
%%
