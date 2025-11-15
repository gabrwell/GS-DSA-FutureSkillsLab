# GS-DSA-FutureSkillsLab

Gabriel Gibin Leoncio  - RM: 565462
Rai Augusto Ribeiro - RM: 562870 

Este repositório contém a solução para o Desafio Global Solution da disciplina de **Estrutura de Dados e Algoritmos (Data Structures and Algorithms)**.

O objetivo deste projeto é duplo:
1.  Aplicar conceitos fundamentais de Estrutura de Dados em C (TADs, Busca, Ordenação).
2.  Desenvolver a "future skill" de analisar criticamente códigos gerados por Inteligência Artificial, tratando a IA como uma ferramenta de apoio ao raciocínio algorítmico, e não como um substituto.

---

## 1. O Problema: "Matchmaking de Competências"

Dentro do tema "Future Skills Lab", nosso grupo escolheu o desafio de criar um **sistema de "matchmaking" de competências profissionais**.

A descrição do problema é:

> "Criar um sistema em C que permita o cadastro de múltiplos profissionais e suas respectivas 'soft skills' (como 'Comunicação', 'Liderança', 'Python', etc.), cada uma com um nível de proficiência (1-10). O sistema deve ser capaz de receber o nome de uma 'skill' prioritária (ex: uma vaga busca 'Comunicação') e, em seguida, **buscar e ordenar** a lista de profissionais cadastrados, do mais relevante (maior nível) ao menos relevante (nível 0 ou inexistente) para aquela skill."

Este problema exige a aplicação direta dos seguintes conceitos da disciplina:
* **TAD (Tipo Abstrato de Dados):** Para modelar as estruturas `Competencia` e `Profissional`.
* **Busca (Search):** Para encontrar a "skill" específica dentro da lista de competências de cada profissional (`Busca Linear`).
* **Ordenação (Sort):** Para classificar a lista final de profissionais com base no nível da skill (o foco da análise).

---

## 2. O Prompt (O Pedido à IA)

Para iniciar o experimento, utilizamos o seguinte prompt para solicitar a um "AI Companion" a geração do código-base:

> "Preciso de um código-fonte em C que resolva o seguinte problema:
> 1. Crie um TAD `Competencia` (struct) que tenha `char nome[50]` e `int nivel` (de 1 a 10).
> 2. Crie um TAD `Profissional` (struct) que tenha `char nome[100]` e um array de `Competencia` chamado `skills` (com capacidade para 5 skills) e um `int num_skills`.
> 3. Crie uma função `adicionar_skill(Profissional* p, const char* nome, int nivel)`.
> 4. Crie uma função principal (`main`) que inicialize 3 profissionais.
> 5. Crie uma função `ordenar_por_skill(Profissional* lista, int n, const char* skill_nome)` que ordene a lista de profissionais (do maior para o menor) com base no `nivel` da `skill_nome` procurada. Se o profissional não tiver a skill, ele deve ir para o fim da lista (nível 0).
> 6. Use o algoritmo **Bubble Sort** para a ordenação."

*(Nota: O pedido explícito do Bubble Sort foi uma "armadilha" intencional, comum em prompts de iniciantes, para permitir uma análise crítica de eficiência na etapa seguinte.)*

---

## 3. Código da IA (Versão Original)

A IA gerou o seguinte código-fonte em um arquivo único:

```c
/* GS-DSA-FutureSkillsLab - VERSÃO GERADA PELA IA */

#include <stdio.h>
#include <string.h>

// --- TAD Competencia ---
typedef struct {
    char nome[50];
    int nivel; // Nível de 1 a 10
} Competencia;

// --- TAD Profissional ---
typedef struct {
    char nome[100];
    Competencia skills[5]; // Array estático de 5 skills
    int num_skills;
} Profissional;

// Função para adicionar uma skill a um profissional
void adicionar_skill(Profissional* p, const char* nome, int nivel) {
    if (p->num_skills < 5) {
        strcpy(p->skills[p->num_skills].nome, nome);
        p->skills[p->num_skills].nivel = nivel;
        p->num_skills++;
    } else {
        printf("Limite de skills atingido para %s\n", p->nome);
    }
}

// Função auxiliar para pegar o nível de uma skill específica
int get_nivel_skill(Profissional* p, const char* skill_nome) {
    for (int i = 0; i < p->num_skills; i++) {
        if (strcmp(p->skills[i].nome, skill_nome) == 0) {
            return p->skills[i].nivel;
        }
    }
    return 0; // Nível 0 se não encontrar
}

// Função para ordenar usando Bubble Sort
void ordenar_por_skill(Profissional* lista, int n, const char* skill_nome) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            int nivel_j = get_nivel_skill(&lista[j], skill_nome);
            int nivel_j1 = get_nivel_skill(&lista[j+1], skill_nome);

            // Ordena do maior para o menor (decrescente)
            if (nivel_j < nivel_j1) {
                // Troca
                Profissional temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }
}

// ... (Função de imprimir e main) ...

// --- Função Principal ---
int main() {
    // BUG: A IA não inicializou o num_skills para os profissionais!
    Profissional time[3];
    
    // ... (código de inicialização) ...

    return 0;
}
