#ifndef PROFISSIONAL_H
#define PROFISSIONAL_H

// --- TAD Competencia ---
typedef struct {
    char nome[50];
    int nivel;
} Competencia;

// --- TAD Profissional ---
typedef struct {
    char nome[100];
    Competencia skills[5]; // Limite de 5 skills
    int num_skills;
} Profissional;

// --- Assinaturas das Funções ---

/**
 * Adiciona uma nova skill a um profissional.
 */
void adicionar_skill(Profissional* p, const char* nome, int nivel);

/**
 * Pega o nível de uma skill específica de um profissional.
 * Retorna 0 se ele não tiver a skill.
 */
int get_nivel_skill(Profissional* p, const char* skill_nome);

/**
 * Ordena a lista de profissionais usando qsort (O(n log n))
 * com base no nível de uma skill específica.
 */
void ordenar_por_skill_qsort(Profissional* lista, int n, const char* skill_nome);

/**
 * Imprime a lista de profissionais, dando foco a uma skill.
 */
void imprimir_profissionais(Profissional* lista, int n, const char* skill_foco);

#endif