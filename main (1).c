/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

//compara os números e estabelece maior e menor
void atualiza_min_max(int num1, int num2, int num3, int *min, int *max){
    if (num1 < num2) {  
        (*min) = num1;
        (*max) = num2;
    }
    else {
        (*min) = num2;
        (*max) = num1;
    }
    if (num3 < *min) {
        (*min) = num3;
    }
    else if (num3 > *max) {
        (*max) = num3;
    }
}    
int main()
{
    int num1, num2, num3, min, max;
    int cont_par = 0, cont_total = 0; //contadores
    
    printf("Insira 3 números: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    
    while (num1 != 0){ //inicia o loop. Interrompe qd num1=0.
        atualiza_min_max(num1, num2, num3, &min, &max);
        printf("\nOs números inseridos são: %d, %d e %d.", num1, num2, num3);
        printf("\nO menor número foi: %d. O maior número foi: %d.", min, max);
        cont_total++;
        if (max % 2 == 0){
            cont_par++;
        }
        printf("\n\nInsira 3 números: ");
        scanf("%d%d%d", &num1, &num2, &num3);
    }
    
    float percent_par = (float)cont_par / cont_total * 100;
    printf("\nO percentual de conjuntos com maior número par foi de: %.2f$$", percent_par);
    return 0;
}