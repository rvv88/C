/******************************************************************************

Considere os seguintes vetores paralelos que descrevem os locais de realização dos 10 cursos ministrados em um
congresso:
- vCurso: cada posição armazena o número identificador de um curso (um número qualquer).
- vLocal: cada posição armazena o número da sala onde o evento foi realizado (um número entre 101 e 105)
Obs: Pode haver mais de um curso na mesma sala
E os participantes dos cursos do congresso, descritos pelos vetores paralelos
vMatricula: matrícula do participante no congresso
- vCurso: contém o número do curso que o participante está inscrito
Construa um programa ( modularizado) que mnostre para cada participante, a sala em que seu curso será
ministrado; Ao finla, seu programa deve exibir a quantidade de pessoas por sala ( independente do curso) que
receba esses vetores e mostre, para cada local, o total de participantes nos eventos realizados nele.
Obs: Os vetores só podem ser percorridos uma vez.

Teste com os seguintes vetores:

void zera(float v[], int n){
int i;
for (i=0;i<n;i++)
v[i]=0;
}

int busca(int v[], int n, int chv){
int i;
for (i=0;i<n;i++){
if( v[i]==chv)
return i;
}
return -1;
}

int main() {
// Vetores de cursos e salas (10 cursos, 5 salas)
int vCurso[10] = {211, 202, 213, 204, 205, 206, 207, 218, 209, 214};
int vLocal[10] = {101, 102, 103, 104, 105, 101, 102, 103, 104, 105};
// Vetores de participantes e cursos inscritos (15 participantes)
int vMatricula[20] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019,
1020};
int vCursoParticipante[20] = {211, 202, 203, 204, 205, 206, 207, 218, 209, 214, 211, 218, 201, 202, 203, 204, 205, 206, 207, 218};

SAÍDA para os vet. Testes:

Participantes e suas salas:
Matrícula: 1001, Sala: 101
Matrícula: 1002, Sala: 102
Matrícula: 1004, Sala: 104
Matrícula: 1005, Sala: 105
Matrícula: 1006, Sala: 101
Matrícula: 1007, Sala: 102
Matrícula: 1008, Sala: 103
Matrícula: 1009, Sala: 104
Matrícula: 1010, Sala: 105
Matrícula: 1011, Sala: 101
Matrícula: 1012, Sala: 103
Matrícula: 1014, Sala: 102
Matrícula: 1016, Sala: 104
Matrícula: 1017, Sala: 105
Matrícula: 1018, Sala: 101
Matrícula: 1019, Sala: 102
Matrícula: 1020, Sala: 103

Quantidade de participantes por sala:
Sala 101: 4 participante(s)
Sala 102: 4 participante(s)
Sala 103: 3 participante(s)
Sala 104: 3 participante(s)
Sala 105: 3 participante(s)
*******************************************************************************/

#include <stdio.h>

int busca(int v[], int n, int chv){
	int i;
	for (i=0;i<n;i++){
        if( v[i]==chv) 
        return i;
	}
	return -1;
}

void zera(int v[], int qt) {
    for (int i = 0; i < qt; i++) {
        v[i]=0;
    }
}

int main()
{
    int v_curso[10] = {211, 202, 213, 204, 205, 206, 207, 218, 209, 214};
    int v_local[10] = {101, 102, 103, 104, 105, 101, 102, 103, 104, 105};
    int v_matricula[20]          = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020};
    int v_curso_participante[20] = {211,  202,  203,  204,  205,  206,  207,  218,  209,  214,  211,  218,  201,  202,  203,  204,  205,  206,  207,  218};
    int v_cont_aluno_sala[5];    
    int i;
    
    zera(v_cont_aluno_sala, 5);
    
    printf("Participantes e suas salas:"); 
    for (i = 0; i < 20; i++) { 
        int acha_curso = v_curso_participante[i];
        int curso = busca(v_curso, 10, acha_curso); //varre os elementos em v_curso_participante e encontra pares em v_curso. Se encontra, grava a posicao para exibir a matricula.
        if (curso != -1){
            printf("\nMatrícula: %d. Sala: %d", v_matricula[i], v_local[curso]); 
            
            int acha_local = v_local[curso];
            int local = busca(v_local, 10, acha_local);
            if (local != -1){
                v_cont_aluno_sala[local]++; //vetor soma em cada posicao o numero de alunos por sala. posicao 0-sala101;posicao1-sala102...
            }
        }
    }
    
    printf("\n\nQuantidade de participantes por sala:");
    for (i=0; i<5; i++){
        printf("\nSala %d: %d participantes.", v_local[i], v_cont_aluno_sala[i]);
    }

    return 0;
}