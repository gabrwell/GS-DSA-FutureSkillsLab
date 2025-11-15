#include "profissional.h"
#include <stdio.h>    // Para printf
#include <string.h>   // Para strncpy, strcmp
#include <stdlib.h>   // Para qsort

// --- Implementações ---

void adicionar_skill(Profissional* p, const char* nome, int nivel) {
    if (p->num_skills < 5) {
        strncpy(p->skills[p->num_skills].nome, nome, 49);
        p->skills[p->num_skills].nome[49] = '\0'; 
        
        p->skills[p->num_skills].nivel = nivel;
        p->num_skills++;
    }
}

int get_nivel_skill(Profissional* p, const char* skill_nome) {
    for (int i = 0; i < p->num_skills; i++) {
        if (strcmp(p->skills[i].nome, skill_nome) == 0) {
            return p->skills[i].nivel;
        }
    }
    return 0; 
}

// --- Lógica de Comparação para o qsort ---

static const char* skill_foco_global;

int compare_profissionais(const void* a, const void* b) {
    Profissional* p1 = (Profissional*)a;
    Profissional* p2 = (Profissional*)b;

    int nivel1 = get_nivel_skill(p1, skill_foco_global);
    int nivel2 = get_nivel_skill(p2, skill_foco_global);

    return nivel2 - nivel1;
}

void ordenar_por_skill_qsort(Profissional* lista, int n, const char* skill_nome) {
    skill_foco_global = skill_nome;
    qsort(lista, n, sizeof(Profissional), compare_profissionais);
}


// --- FUNÇÃO MODIFICADA ---
void imprimir_profissionais(Profissional* lista, int n, const char* skill_foco) {
    printf("--- Lista de Profissionais (Foco: %s) ---\n", skill_foco);
    
    for (int i = 0; i < n; i++) {
        
        // Imprime a linha principal (a que foi usada para ordenar)
        int nivel = get_nivel_skill(&lista[i], skill_foco);
        printf("Pos. %d: %s (Nivel %s: %d)\n", 
               i + 1, 
               lista[i].nome, 
               skill_foco, 
               nivel);

        // --- INÍCIO DA MUDANÇA ---
        // Loop aninhado para imprimir TODAS as skills daquele profissional
        printf("    Skills: "); // <-- NOVO
        for (int j = 0; j < lista[i].num_skills; j++) { // <-- NOVO
            printf("%s (%d); ", 
                   lista[i].skills[j].nome, 
                   lista[i].skills[j].nivel); // <-- NOVO
        }
        printf("\n\n"); // <-- NOVO (dá um espaço duplo)
        // --- FIM DA MUDANÇA ---
    }
}