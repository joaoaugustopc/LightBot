#ifndef BOARD_HPP
#define BOARD_HPP

#include <set>
#include <map>
#include <vector>

using namespace std;

typedef struct BoardCell
{
    int height;
    bool isGoal;
    bool isLighted;
    bool isVisited;

    BoardCell(){
        this->height = 0;
        this->isGoal = false;
    }
    BoardCell(int h, bool g, bool l, bool v) : height(h), isGoal(g), isLighted(l), isVisited(v) {}
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

Board::Board(){
    this->n_lines = 0;
    this->n_columns = 0;
}

Board::~Board(){}

void Board::setBoard(vector<vector<BoardCell>> board){
    this->cells = board;
    this->n_lines = board.size();
    this->n_columns = board[0].size();

    for(int i = 0; i < this->n_lines; i++){
        for(int j = 0; j < this->n_columns; j++){
            if(board[i][j].isGoal){
                this->goals.push_back(make_pair(i, j));
            }
        }
    }
}

int Board::getGoalIndex(int line, int column) const{
    for(int i = 0; i < this->goals.size(); i++){
        if(this->goals[i].first == line && this->goals[i].second == column){
            return i;
        }
    }
    return -1;
}

int Board::getAltura(int line, int column) const{
    return this->cells[line][column].height;
}

bool Board::posValida(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) const{
    if(linhaDestino < 0 || linhaDestino >= this->n_lines || colunaDestino < 0 || colunaDestino >= this->n_columns){
        return false;
    }

    int alturaOrigem = this->getAltura(linhaOrigem, colunaOrigem);
    int alturaDestino = this->getAltura(linhaDestino, colunaDestino);

    if (abs(alturaOrigem - alturaDestino) > 1){
        return false;
    }
    return true;
}

#endif // BOARD_HPP
    