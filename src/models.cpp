#include <vector>
#include "../include/models.hpp"


vector<No*> gerarSucessores(const No* noAtual,const Board& board){
    vector<No*> sucessores;

    // Operação para baixo

    No* down = moveDown(noAtual, board);
    if (down != nullptr){
        sucessores.push_back(down);
    }
    
    // Operação para direita

    No* right = moveRight(noAtual, board);
    if (right != nullptr){
        sucessores.push_back(right);
    }

    // Operação para esquerda

    No* left = moveLeft(noAtual, board);
    if (left != nullptr){
        sucessores.push_back(left);
    }
    
    // Operação para cima
    No* up = moveUp(noAtual, board);
    if (up != nullptr){
        sucessores.push_back(up);
    }

    // Operação para acender

    No* lighted = light(noAtual, board);
    if (lighted != nullptr){
        sucessores.push_back(lighted);
    }

    return sucessores;

}

No* getSucessor(const No* noAtual, Operacao op, const Board& board){
    switch(op){
        case UP:
            return moveUp(noAtual, board);
        case RIGHT:
            return moveRight(noAtual, board);
        case DOWN:
            return moveDown(noAtual, board);
        case LEFT:
            return moveLeft(noAtual, board);
        case LIGHT:
            return light(noAtual, board);
    }
}

vector<Operacao> listaOperacoes(const No* noAtual, const Board& board){
    vector<Operacao> operacoes;

    if (canMoveDown(noAtual, board)){
        operacoes.push_back(DOWN);
    }

    if (canMoveRight(noAtual, board)){
        operacoes.push_back(RIGHT);
    }

    if (canMoveLeft(noAtual, board)){
        operacoes.push_back(LEFT);
    }

    if (canMoveUp(noAtual, board)){
        operacoes.push_back(UP);
    }

    if (canLight(noAtual, board)){
        operacoes.push_back(LIGHT);
    }

    return operacoes;
}

bool canMoveUp(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha - 1;
    int novaColuna = estadoAtual.coluna;

    return board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna);
}

bool canMoveDown(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha + 1;
    int novaColuna = estadoAtual.coluna;

    return board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna);
}

bool canMoveLeft(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha;
    int novaColuna = estadoAtual.coluna - 1;

    return board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna);
}

bool canMoveRight(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha;
    int novaColuna = estadoAtual.coluna + 1;

    return board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna);
}

bool canLight(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int pos = board.getGoalIndex(estadoAtual.linha, estadoAtual.coluna);

    return pos>=0 && !estadoAtual.lighted[pos];
}

No* moveUp(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha - 1;
    int novaColuna = estadoAtual.coluna;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){
        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        return new No(novoEstado, const_cast<No*>(noAtual), UP, noAtual->custo + 1);
    }

    return nullptr;
}

No* moveDown(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha + 1;
    int novaColuna = estadoAtual.coluna;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){
        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        return new No(novoEstado, const_cast<No*>(noAtual), DOWN, noAtual->custo + 1);
    }

    return nullptr;
}

No* moveLeft(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha;
    int novaColuna = estadoAtual.coluna - 1;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){
        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        return new No(novoEstado, const_cast<No*>(noAtual), LEFT, noAtual->custo + 1);
    }

    return nullptr;
}

No* moveRight(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int novaLinha = estadoAtual.linha;
    int novaColuna = estadoAtual.coluna + 1;

    if (board.posValida(estadoAtual.linha, estadoAtual.coluna, novaLinha, novaColuna)){
        Estado novoEstado = estadoAtual;
        novoEstado.linha = novaLinha;
        novoEstado.coluna = novaColuna;
        return new No(novoEstado, const_cast<No*>(noAtual), RIGHT, noAtual->custo + 1);
    }

    return nullptr;
}

No* light(const No* noAtual, const Board& board){
    Estado estadoAtual = noAtual->estado;
    int pos = board.getGoalIndex(estadoAtual.linha, estadoAtual.coluna);

    if (pos>=0 && !estadoAtual.lighted[pos]){
        Estado novoEstado = estadoAtual;
        novoEstado.lighted[pos] = true;
        return new No(novoEstado, const_cast<No*>(noAtual), LIGHT, noAtual->custo + 1);
    }

    return nullptr;
}

bool estadoObjetivo(const Estado& estado){
    for (int i = 0; i < estado.lighted.size(); i++){
        if (!estado.lighted[i]){
            return false;
        }
    }

    return true;
}
