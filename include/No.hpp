#include "./Estado.hpp"

enum Operacao {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    LIGHT
};

typedef struct No
{
    Estado estado;
    No* pai;
    Operacao op; 
    int custo;
    int heuristica;
    int custoReal;  //// salva o custo real do caminho percorrido até o nó atual (A*)
    std::vector<No*> sucessores;  //// salva os sucessores do nó atual
    //int custoAleatorio; // Novo campo (valor aleatório entre 0-5) (A*)
    int heuristicaStar; //  (A*)
    int dificuldadeNo  = rand() % 4;
    

    No(const Estado& e, No* p, Operacao o, int c) : estado(e), pai(p), op(o), custo(c), heuristicaStar(0), heuristica(0) {}
} No;
