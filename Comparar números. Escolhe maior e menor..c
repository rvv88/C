/******************************************************************************
Q1 Ponteiros e Operações de Endereçamento
a) (2.0) Escreva uma função chamada atualizaMinMax que receba três números (num1, num2 e num3) e dois ponteiros adicionais (min e max).
A função deve comparar os três números e atualizar as variáveis min e max com os valores mínimo e máximo, respectivamente.

b) (1.0) Faça um programa que leia três números inteiros de vários conjuntos e utilize obrigatoriamente a função atualizaMinMax 
para encontrar o menor e o maior número em cada conjunto.
O programa deve:
Exibir os números lidos, o menor e o maior valor de cada conjunto.
Mostrar o percentual de conjuntos com maior valor par juntos processados.
Encerrar a entrada quando o primeiro valor do  conjunto for zero

*******************************************************************************/
#include <stdio.h>

//compara os números e estabelece maior e menor
void atualiza_min_max(int num1, int num2, int num3, int *min, int *max) {
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