#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower=0; /*Limite Inferior de la Tabla*/
    upper=300; /*Limite Superior*/
    step=20; /*Tamanio del incremento*/

    fahr = lower;
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3df %6.1f\n",fahr, celsius); /*Especificadores de Formato*/
        fahr= fahr+step;
    }
}
