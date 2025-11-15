#include "profissional.h"
#include <stdio.h>    // Para printf
#include <string.h>   // Para strncpy, strcmp
#include <stdlib.h>   // Para qsort

// --- Implementações ---

void adicionar_skill(Profissional* p, const char* nome, int nivel) {
    if (p->num_skills < 5) {
        // Usando strncpy para segurança (evita buffer overflow)
        strncpy(p->skills[p->num_skills].nome, nome, 49);
        p->skills[p->num_skills].nome[49] = '\0'; // Garante terminação nula
        
        p->skills[p->num_skills].nivel = nivel;
        p->num_skills++;
    }
    // (O ideal seria um 'else' para tratar o erro, mas mantendo simples)
}

int get_nivel_skill(Profissional* p, const char* skill_nome) {
    for (int i = 0; i < p->num_skills; i++) {
        if (strcmp(p->skills[i].nome, skill_nome) == 0) {
            return p->skills[i].nivel;
        }
    }
    return 0; // Nível 0 se não encontrar
}

// --- Lógica de Comparação para o qsort ---

// Variável global estática para qsort.
// É a forma padrão em C de passar um "contexto" para a função de comparação.
static const char* skill_foco_global;

/**
 * Função de comparação que o qsort usará.
 */
int compare_profissionais(const void* a, const void* b) {
    // Converte ponteiros void* de volta para Profissional*
    Profissional* p1 = (Profissional*)a;
    Profissional* p2 = (Profissional*)b;

    // Usa a variável global para saber qual skill comparar
    int nivel1 = get_nivel_skill(p1, skill_foco_global);
    int nivel2 = get_nivel_skill(p2, skill_foco_global);

    // Queremos ordem DECRESCENTE (maior para o menor)
    // Se (nivel2 > nivel1), retorna positivo (troca)
    // Se (nivel2 < nivel1), retorna negativo (mantém)
    return nivel2 - nivel1;
}

/**
 * Função principal de ordenação (Otimizada).
 */
void ordenar_por_skill_qsort(Profissional* lista, int n, const char* skill_nome) {
    // Configura a variável global ANTES de chamar o qsort
    skill_foco_global = skill_nome;
    
    // Chama o qsort padrão do C
    qsort(lista, n, sizeof(Profissional), compare_profissionais);
}


/**
 * Função de impressão.
 */
void imprimir_profissionais(Profissional* lista, int n, const char* skill_foco) {
    printf("--- Lista de Profissionais (Foco: %s) ---\n", skill_foco);
    for (int i = 0; i < n; i++) {
        int nivel = get_nivel_skill(&lista[i], skill_foco);
        printf("Pos. %d: %s (Nivel %s: %d)\n", 
               i + 1, 
               lista[i].nome, 
               skill_foco, 
               nivel);
    }
}