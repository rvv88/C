/******************************************************************************
Questão 2: Vetores Operações com Números Binários
Um número na base binária está armazenado em um vetor de forma que o dígito menos significativo está na
posição 0, e assim sucessivamente até que o dígito mais significativo está na última posição do vetor.
Por exemplo:
0 1 1 0 1 -> 10110 Transformando em decimal : 0*2 0 + 1* 2 1 + 1 * 2 2 + 0 * 2 3 + 1 * 2 4  22
0 1 2 3 4
a) Exibir um número binário
Construa uma função que receba um vetor com um número binário (representado conforme descrito) e a
quantidade de elementos. A função deve exibi-lo corretamente, da posição mais significativa para a menos
significativa.
b) Converter um número binário para decimal
Construa uma função que receba um vetor com um número binário e a quantidade de elementos. A função deve
calcular e retornar o número decimal correspondente.
c) Operação XOR entre dois números binários
Construa uma função que receba três vetores com a mesma quantidade de elementos. Os dois primeiros vetores
armazenam dois números binários, e o terceiro vetor, inicialmente vazio, deve ser preenchido com o resultado da
operação XOR. Isto é: O resultado de uma posição será 0 se os dígitos forem iguais e será 1, se forem diferentes. Por
exemplo, se a função receber os dois vetores com os valores {1,0,0,1} e {1,0,1,0}, o terceiro vetor ficará com
{0,0,1,1,}:
1001
1010
------
0011 -> resultado
d) Crie uma função main para testar as funções anteriores. Exiba os números binários e seus equivalentes em
decimal. Exiba também o resultado da operação XOR em ambas as bases.
*******************************************************************************/
#include <stdio.h>
#include <math.h>

void exibir_binario(int v[], int qt) {
    for (int i = qt-1 ; i >= 0; i--) {
        printf(" %d", v[i]);
    }
}

int conv_bin_dec(int v[], int qt) {
    int decimal = 0;
    for (int i = 0; i < qt; i++){
        decimal += v[i] * pow(2 , i);    
    }
    return decimal;
}

void operacao_xor(int v1[], int v2[], int v3[]){
    for (int i = 0; i < 4; i++){
        if (v1[i] == v2[i]){
            v3[i] = 0;
        }
        else {
            v3[i] = 1;
        }
    }
}


void zera(int v[], int qt) {
    for (int i = 0; i<qt; i++){
        v[i] = 0;
    }
}

int main()
{
    int v1[4]={1,0,0,1};
    int v2[4]={1,0,1,0};
    int v3[4];
    
    zera(v3,4); //zera elementos em v3
    
    //Dadosv1
    printf("Binário nº1:");
    exibir_binario(v1,4);
    int decimal1 = conv_bin_dec(v1,4);
    printf("\nConvertido para decimal: %d.", decimal1);
    
    //Dados v2
    printf("\n\nBinário nº2:");
    exibir_binario(v2,4);
    int decimal2 = conv_bin_dec(v2,4);
    printf("\nConvertido para decimal: %d",decimal2);
    
    //exibe resultado xor entre bases v1 e v2 -> exibe dados v3
    operacao_xor(v1,v2,v3);//atualiza valores em v3
    printf("\nResultado operação xor: ");
    for (int i=0; i<4; i++) {
        printf(" %d", v3[i]);
    }

    return 0;
}
