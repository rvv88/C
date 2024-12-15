//Questão 2) (3.0 pontos) percurso e acesso a elementos de vetores
//a) 1.3 Escreva a função encontraMenor() que:
//●recebe o número de empregados de uma empresa, um vetor de float com os salários dos empregados dessa empresa e retorna o menor valor de salário
//b) 1.2 Escreva a função exibeDifMenorRetornaSoma() que:
//●recebe o valor do menor salário, o número de empregados de uma empresa, um vetor de inteiros com os números
//de inscrição dos empregados dessa empresa, um vetor de float com os salários dos empregados dessa empresa
//(vSal[k] é o salário do empregado de inscrição vInsc[k])
//●exibe, para cada empregado, a inscrição e a diferença de seu salário em relação ao menor salário
//●A função retorna a soma das diferenças exibidas
//c) 0.5 Complete a função main, utilizando as funções anteriores, para exibir, para cada empregado, sua inscrição e
//a diferença de seu salário em relação ao menor salário. No final, seu programa deve exibir a soma das diferenças.
//int main(void){
//int vInsc[6]={1010,1020,1030,1040,1050,1060};
//float vSal[6]={1000.00,4020.00,900.00,10400.00,20000.00,1000.00};
//return 0;
//}
//------------------------------------------------------------

#include <stdio.h>

float encontra_menor(int qt_empregado, float v_sal[])
{
    float m_salario = v_sal[1];
    for (int i=0; i<qt_empregado; i++)  
    {
        if (v_sal[i] < m_salario)
        {
            m_salario = v_sal[i];
        }
    }
return m_salario;
}

void exibe_dif_menor_retorna_soma(float m_salario, int qt_empregado, int v_insc[], float v_sal[])
{
    float dif_salario, soma_dif_salario;
    
    for (int i=0; i < qt_empregado; i++)
    {
        dif_salario = v_sal[i] - m_salario;
        soma_dif_salario += dif_salario;
        printf("Funcionário: - Inscrição nº: %d.  - Salário: %.2f.\n", v_insc[i], v_sal[i]);
        printf("A diferença entre seu salário e o menor salário é de R$ %.2f.\n\n", dif_salario);
    }
    printf("\nA soma das diferenças salarias é de %.2f.\n", soma_dif_salario);
}

int main()
{
    int qt_empregado = 6;
    int v_insc[6] = {1010,1020,1030,1040,1050,1060};
    float v_sal[6] = {1000.00,4020.00,900.00,10400.00,20000.00,1000.00};
    float m_salario = encontra_menor(qt_empregado, v_sal);
    exibe_dif_menor_retorna_soma(m_salario, qt_empregado, v_insc, v_sal);
    

    return 0;
}