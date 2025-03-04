#include <vector>
#include <utility>
#include "Board.hpp"

using namespace std;

typedef struct Estado
{
    int linha;
    int coluna;

    // Vetor para indicar se as células objetivos foram acesas
    vector<bool> lighted;

    Estado (int l, int c, const vector<bool>& ligh) : linha(l), coluna(c), lighted(ligh) {}

    // Sobrecarga do operador de comparação para verificar se dois estados são iguais
    bool operator==(const Estado& e) const {
        return linha == e.linha && coluna == e.coluna && lighted == e.lighted;
    }

    bool operator<(const Estado& outro) const {
        if (linha != outro.linha) return linha < outro.linha;
        if (coluna != outro.coluna) return coluna < outro.coluna;
        return lighted< outro.lighted; 
    }


}Estado;

