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

    No(const Estado& e, No* p, Operacao o, int c) : estado(e), pai(p), op(o), custo(c), heuristica(0) {}
} No;


