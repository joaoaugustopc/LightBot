#ifndef MODELS_HPP
#define MODELS_HPP

#include "../include/No.hpp"
#include <vector>

vector<No*> gerarSucessores(const No* noAtual,const Board& board);
vector<Operacao> listaOperacoes(const No* noAtual, const Board& board);
No* getSucessor(const No* noAtual, Operacao op, const Board& board);
bool canMoveUp(const No* noAtual, const Board& board);
bool canMoveDown(const No* noAtual, const Board& board);
bool canMoveLeft(const No* noAtual, const Board& board);
bool canMoveRight(const No* noAtual, const Board& board);
bool canLight(const No* noAtual, const Board& board);
No* moveUp(const No* noAtual, const Board& board);
No* moveDown(const No* noAtual, const Board& board);
No* moveLeft(const No* noAtual, const Board& board);
No* moveRight(const No* noAtual, const Board& board);
No* light(const No* noAtual, const Board& board);
bool estadoObjetivo(const Estado& estado);

#endif // MODELS_HPP
