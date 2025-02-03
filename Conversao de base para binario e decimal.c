/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

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