#include <stdio.h>
#define LOWER 0		/*Define el limite inferior*/
#define UPPER 300	/*Define el limite superior*/
#define STEP  20	/*Define el incremento*/

main()
{
int fhar;

for (fhar=LOWER; fhar<=UPPER; fhar=fhar+STEP)
printf("%3d %6.1f\n",fhar,(5.0/9.0)*(fhar-32));


}
