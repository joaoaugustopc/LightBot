#include <vector>
#include "../include/No.hpp"


vector<No*> gerarSucessores(const No* noAtual,const Board& board){
    vector<No*> sucessores;
    Estado estadoAtual = noAtual->estado;

    int novaLinha, novaColuna;

    // Operação para cima

    novaLinha = estadoAtual.linha - 1;
    novaColuna = estadoAtual.coluna;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){

        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        sucessores.push_back(new No(novoEstado, const_cast<No*>(noAtual), UP, noAtual->custo + 1));
        
    }

    // Operação para direita

    novaLinha = estadoAtual.linha;
    novaColuna = estadoAtual.coluna + 1;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){

        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        sucessores.push_back(new No(novoEstado, const_cast<No*>(noAtual), RIGHT, noAtual->custo + 1));
        
    }

    // Operação para baixo

    novaLinha = estadoAtual.linha + 1;
    novaColuna = estadoAtual.coluna;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){

        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        sucessores.push_back(new No(novoEstado, const_cast<No*>(noAtual), DOWN, noAtual->custo + 1));
        
    }

    // Operação para esquerda

    novaLinha = estadoAtual.linha;
    novaColuna = estadoAtual.coluna - 1;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){

        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        sucessores.push_back(new No(novoEstado, const_cast<No*>(noAtual), LEFT, noAtual->custo + 1));
        
    }

    // Operação para acender

    int pos = board.getGoalIndex(estadoAtual.linha, estadoAtual.coluna);

    if (pos>=0 && !estadoAtual.lighted[pos]){

        Estado novoEstado = estadoAtual;
        novoEstado.lighted[pos] = true;
        sucessores.push_back(new No(novoEstado, const_cast<No*>(noAtual), LIGHT, noAtual->custo + 1));
        
    }

    return sucessores;

}

bool estadoObjetivo(const Estado& estado){
    for (int i = 0; i < estado.lighted.size(); i++){
        if (!estado.lighted[i]){
            return false;
        }
    }

    return true;
}