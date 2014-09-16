/*Programa para convertir grados
centigrados, este programa utiliza
la formula C=(5/9)(F-32) */
#include <stdio.h>

/*Imprime la tabla Fahrenheit-Celcius
para fahr=0,20 ....,300*/

main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower=0; /*Limite Inferior de la Tabla*/
    upper=0; /*Limite Superior*/
    step=20; /*Tamanio del incremento*/

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5*(fahr-32)/9;
        printf("   %d\n",fahr); /*Especificadores de Formato   */
        printf("   %d\n",celsius);
        fahr= fahr+step;
    }
}
/*
int a=8;
char* n="Juan";

Si quieres imprimir en la pantalla algo como:
"Soy Juan y tengo 8 años" pero usando esas variables,
entonces puedes usar el printf:

printf("Soy %s y tengo %d años", n, a);

%c : caracter
%d : entero decimal
%f : flotante
%g : flotante (uno de los 2 usa notación científica, no recuerdo cuál)
%x: entero hexadecimal
%X: entero hexadecimal
%s: char*
%S: wchar_t* (cadena usando caracteres "wide")
%%: %
%lld: long long decimal (long long es un entero de 64 bits)
*/
