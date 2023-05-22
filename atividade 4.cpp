#include <stdio.h>

float le_valida_n1() {
    float n1;
    while (1) {
        printf("Digite o primeiro valor: ");
        if (scanf("%f", &n1) == 1) {
            return n1;
        } else {
            printf("Valor inválido. Digite um número válido.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n');
        }
    }
}

float le_valida_n2() {
    float n2;
    while (1) {
        printf("Digite o segundo valor: ");
        if (scanf("%f", &n2) == 1) {
            return n2;
        } else {
            printf("Valor inválido. Digite um número válido.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n');
        }
    }
}

char le_valida_operador() {
    char operador;
    while (1) {
        printf("Digite a operação (+, -, *, /): ");
        scanf(" %c", &operador);
        if (operador == '+' || operador == '-' || operador == '*' || operador == '/') {
            return operador;
        } else {
            printf("Operação inválida. Digite uma operação válida.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n');
        }
    }
}

float soma(float n1, float n2) {
    return n1 + n2;
}

float subtracao(float n1, float n2) {
    return n1 - n2;
}

float multiplicacao(float n1, float n2) {
    return n1 * n2;
}

float divisao(float n1, float n2) {
    if (n2 != 0) {
        return n1 / n2;
    } else {
        printf("Erro: divisão por zero.\n");
        return 0;
    }
}

void cabecalho() {
    printf("+-----------------------------------+\n");
    printf("|            SUPER CALC             |\n");
    printf("+-----------------------------------+\n");
}

void rodape() {
    printf("+-----------------------------------+\n");
    printf("|          Copyright 2023           |\n");
    printf("+-----------------------------------+\n");
}

int main() {
    char continuar = 'S';
    
    while (continuar == 'S') {
        // Limpa a tela
        
        
        cabecalho();
        
        float n1 = le_valida_n1();
        float n2 = le_valida_n2();
        char operador = le_valida_operador();
        
        float resultado;
        if (operador == '+') {
            resultado = soma(n1, n2);
        } else if (operador == '-') {
            resultado = subtracao(n1, n2);
        } else if (operador == '*') {
            resultado = multiplicacao(n1, n2);
        } else if (operador == '/') {
            resultado = divisao(n1, n2);
        }
        
        printf("|          O resultado da           |\n");
        printf("|          %g %c %g eh             |\n", n1, operador, n2);
        printf("|          %g                      |\n", resultado);
        
        rodape();
        
        printf("|      Deseja continuar? (S/N):     |\n");
        printf("+-----------------------------------+\n");
        scanf(" %c", &continuar);
        
    }
    
    return 0;
}

