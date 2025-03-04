#include <set>
#include <vector>
#include "../models.cpp"

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
