#include "profissional.h" // Inclui nosso header
#include <stdio.h>        // Para printf
#include <string.h>       // Para strcpy

int main() {
    Profissional time[3];
    
    // Inicializando o número de skills (Obrigatório!)
    time[0].num_skills = 0;
    time[1].num_skills = 0;
    time[2].num_skills = 0;

    // --- DADOS CORRIGIDOS (FORA DE ORDEM) ---

    // Configurando Profissional 1 (Carla Dias) - Comunicacao Nível 0
    strcpy(time[0].nome, "Carla Dias");
    adicionar_skill(&time[0], "Python", 10);
    adicionar_skill(&time[0], "Lideranca", 7);

    // Configurando Profissional 2 (Bruno Costa) - Comunicacao Nível 6
    strcpy(time[1].nome, "Bruno Costa");
    adicionar_skill(&time[1], "Comunicacao", 6);
    adicionar_skill(&time[1], "Java", 9);
    adicionar_skill(&time[1], "Lideranca", 8);
    
    // Configurando Profissional 3 (Ana Silva) - Comunicacao Nível 9
    strcpy(time[2].nome, "Ana Silva");
    adicionar_skill(&time[2], "Comunicacao", 9);
    adicionar_skill(&time[2], "Python", 7);

    // --- FIM DOS DADOS ---

    const int num_profissionais = 3;
    const char* skill_vaga = "Comunicacao";

    printf("--- ANTES DA ORDENACAO (qsort) ---\n");
    imprimir_profissionais(time, num_profissionais, skill_vaga);

    // Chama a nova função otimizada
    ordenar_por_skill_qsort(time, num_profissionais, skill_vaga);

    printf("\n--- DEPOIS DA ORDENACAO POR '%s' (qsort) ---\n", skill_vaga);
    imprimir_profissionais(time, num_profissionais, skill_vaga);

    return 0;
}