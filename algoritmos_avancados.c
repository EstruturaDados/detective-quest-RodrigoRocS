#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char valor[50];
    struct No *esquerda;
    struct No *direita;
} No;

// --- Protótipos ---
No *criarSala(char *valor);
void liberar(No *raiz);
void explorarSalas(No *raiz);
void limpaBuffer();
void exibeSalas(No *raiz);

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

int main() {
     No *raiz = criarSala("Hall de Entrada");
    raiz->esquerda = criarSala("Sala de Estar");
    raiz->direita = criarSala("Biblioteca");
    raiz->esquerda->esquerda = criarSala("Quarto");
    raiz->direita->direita = criarSala("Cozinha");
    explorarSalas(raiz);
    liberar(raiz);

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}
No *criarSala(char *valor) // cria sala
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) // verifica se a alocação deu certo
    {
        printf("Erro na alocação de memória!\n");
        return NULL;
    }
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void liberar(No *raiz) // libera filho esquerdo , direito , raiz memmoria alocada para arvore
{
    if (raiz != NULL)
    {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
};

void explorarSalas(No *raiz) // exibe caminho escolhido: esquerda, direita ou sair
{

    int opcao;
    No *salaAtual = raiz;
    do
    {
        exibeSalas(salaAtual);
        printf("\nPara que sala voce irá ?: \n");
        printf("1 - Esquerda\n");
        printf("2 - Direita\n");
        printf("0 - Sair\n");

        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao)
        {
        case 1: // vai para esquerda
            if (salaAtual->esquerda != NULL)
            {
                salaAtual = salaAtual->esquerda;
            }
            else
            {
                printf("Não há sala à esquerda!\n");
            }
            break;

        case 2: // vai para direita
            if (salaAtual->direita != NULL)
            {
                salaAtual = salaAtual->direita;
            }
            else
            {
                printf("Não há sala à direita!\n");
            }
            break;

        case 0: // Sair
            printf("Saindo do jogo...\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }

    } while (opcao != 0);
};

void limpaBuffer() // Limpa buffer de entrada
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
};

void exibeSalas(No *raiz)
{
    if (raiz != NULL)
    {
        printf("Sala vazia ! ");
    }
    printf("Sala Atual: %s ", raiz->valor);
    printf("Sala Esquerda: %s ", raiz->esquerda->valor);
    printf("Sala Direita: %s ", raiz->direita->valor);
}

