#include <stdio.h>
#include <ctype.h>
#define MAX_ESTUDANTES 20
#define MAX_DISCIPLINA 50
#define MAX_NOTAS 4

struct Disciplina {
    char nome[MAX_DISCIPLINA];
    int carga_horaria;
    float notas[MAX_NOTAS];
};

struct Estudante {
    char nome[MAX_DISCIPLINA];
    int matricula;
    int idade;
    struct Disciplina disciplina;
};

void cadastrarEstudante(struct Estudante estudantes[], int indice) {
    printf("\n=== Cadastro de Estudante ===\n");
    printf("Nome: ");
    scanf("%s", estudantes[indice].nome);
    printf("Matrícula: ");
    scanf("%d", &estudantes[indice].matricula);
    printf("Idade: ");
    scanf("%d", &estudantes[indice].idade);
    printf("=== Cadastro de Disciplina ===\n");
    printf("Nome da disciplina: ");
    scanf("%s", estudantes[indice].disciplina.nome);
    printf("Carga horária: ");
    scanf("%d", &estudantes[indice].disciplina.carga_horaria);
    for (int i = 0; i < MAX_NOTAS; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &estudantes[indice].disciplina.notas[i]);
    }
    printf("=============================\n");
}

void exibirEstudantes(struct Estudante estudantes[], int numEstudantes) {
    printf("\n=== Lista de Estudantes ===\n");
    for (int i = 0; i < numEstudantes; i++) {
        printf("Estudante %d\n", i + 1);
        printf("Nome: %s\n", estudantes[i].nome);
        printf("Matrícula: %d\n", estudantes[i].matricula);
        printf("Idade: %d\n", estudantes[i].idade);
        printf("Disciplina: %s\n", estudantes[i].disciplina.nome);
        printf("Carga horária: %d\n", estudantes[i].disciplina.carga_horaria);
        printf("Notas: ");
        for (int j = 0; j < MAX_NOTAS; j++) {
            printf("%.2f ", estudantes[i].disciplina.notas[j]);
        }
        printf("\n");
    }
    printf("==========================\n");
}

int main() {
    struct Estudante estudantes[MAX_ESTUDANTES];
    int numEstudantes = 0;
    char continuar = 'S';

    while (continuar == 'S' && numEstudantes < MAX_ESTUDANTES) {
        cadastrarEstudante(estudantes, numEstudantes);
        numEstudantes++;

        printf("Deseja cadastrar outro estudante? (S/N): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);
    }

    exibirEstudantes(estudantes, numEstudantes);

    return 0;
}
