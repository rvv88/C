/******************************************************************************
Construa um programa, utilizando a função OrgLargada, para mostrar a hora e a fileira de largada de cada um
dos ciclistas inscritos na Corrida do Século a partir do seu peso e de sua idade. Término da entrada de dados:
peso <= 0
Idade Peso Hora Fileira
<18 - 8 sequencial (nSeq)
Até 100 9 dezena da idade
18 a 65 Acima de 100 10 unidade da idade
>65 - 11 unidade da idade

Função OrgLargada: recebe a idade, o peso e o endereço de três variáveis inteiras (nSeq, hora, fileira) que
devem ser preenchidas/atualizadas de acordo com a tabela acima.
Obs: nSeq armazena a quantidade de menores de idade que já foram processados até o momento.
*******************************************************************************/

#include <stdio.h> 

void org_largada(int idade, int peso, int *n_seq, int *hora, int *fileira)
{
    if (idade < 18)
    {
        (*n_seq) ++;
        (*hora) = 8;
        (*fileira) = *n_seq;
        
    }
    else if (peso <= 100)
    {
        (*hora) = 9;
        (*fileira) = idade - idade % 10;
    }
    else if (idade > 18 && idade <=65 && peso > 100)
    {
        (*hora) = 10;
        (*fileira) = idade % 10;
    }
    else if (idade > 65)
    {
        (*hora) = 11;
        (*fileira) = idade % 10;
    }
}

int main()
{
    int idade, peso, n_seq, hora, fileira;
    n_seq = 0;
    fileira = 0;
    printf("Informe a idade e peso do ciclista: (idade, peso)\n");
    printf("Para sair digite um peso menor do que 0.\n");
    scanf("%d, %d", &idade, &peso);
    while (peso >= 0)
    {
        org_largada(idade, peso, &n_seq, &hora, &fileira);
        printf("Hora de largada: %d. Fileira: %d\n", hora, fileira);
        printf("Total de ciclistas menores de idade: %d.\n\n", n_seq);
        printf("Informe a idade e peso do ciclista: (idade, peso)\n");
        printf("Para sair digite um peso menor do que 0.\n");
        scanf("%d, %d", &idade, &peso);
    }
    
    return 0;
    
}
