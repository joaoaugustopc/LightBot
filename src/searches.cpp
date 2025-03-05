#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include "./models.cpp"

bool buscaDFS(No* noAtual, std::set<Estado>& visitados, std::vector<Operacao>& caminho, const Board& board) {
    if(estadoObjetivo(noAtual->estado))
        return true;

    visitados.insert(noAtual->estado);

    std::vector<No*> sucessores = gerarSucessores(noAtual, board);
    for(No* sucessor : sucessores) {
        if(visitados.find(sucessor->estado) == visitados.end()) {
            caminho.push_back(sucessor->op);
            if(buscaDFS(sucessor, visitados, caminho, board))
                return true;
            caminho.pop_back();
        }
    }
    
    return false;
}

vector<Operacao> reconstruirCaminho(No *no)
{
    vector<Operacao> caminho;
    No *noAtual = no;

    while (noAtual->pai != nullptr)
    {
        caminho.push_back(noAtual->op);
        noAtual = noAtual->pai;
    }

    reverse(caminho.begin(), caminho.end());
    return caminho;
}

bool buscaBFS(No *noInicial, set<Estado> &visitados, vector<Operacao> &caminho, const Board &board)
{
    queue<No *> fila;

    fila.push(noInicial);
    visitados.insert(noInicial->estado);

    while (!fila.empty())
    {
        No *noAtual = fila.front();
        fila.pop();

        if (estadoObjetivo(noAtual->estado))
        {

            caminho = reconstruirCaminho(noAtual);
            return true;
        }

        vector<No *> sucessores = gerarSucessores(noAtual, board);
        for (No *sucessor : sucessores)
        {
            if (visitados.find(sucessor->estado) == visitados.end())
            {
                fila.push(sucessor);
                visitados.insert(sucessor->estado);
            }
        }
    }

    return false;
}