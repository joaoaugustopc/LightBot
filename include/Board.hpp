#ifndef BOARD_HPP
#define BOARD_HPP

#include <set>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

typedef struct BoardCell
{
    int height;
    bool isGoal;

    BoardCell(){
        this->height = 0;
        this->isGoal = false;
    }
    BoardCell(int h, bool g): height(h), isGoal(g) {}
    ~BoardCell(){}
}BoardCell;

typedef struct Board{
    int n_lines;
    int n_columns;
    vector<vector<BoardCell>> cells;
    vector<pair<int, int>> goals;

    Board();
    ~Board();
    void setBoard(vector<vector<BoardCell>> board);
    int getGoalIndex(int line, int column) const;
    int getAltura(int line, int column) const;
    bool posValida(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) const;

}Board;


#endif // BOARD_HPP
    