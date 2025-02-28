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
        this->isLighted = false;
        this->isVisited = false;
    }
    BoardCell(int h, bool g, bool l, bool v) : height(h), isGoal(g), isLighted(l), isVisited(v) {}
    ~BoardCell(){}
}BoardCell;

typedef struct Board{
    int n_lines;
    int n_columns;
    vector<vector<BoardCell>> cells;
    set<pair<int, int>> visited;
    vector<pair<int, int>> goals;

    Board();
    ~Board();
    void setBoard(vector<vector<BoardCell>> board);
    int getGoalIndex(int line, int column);
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

int Board::getGoalIndex(int line, int column){
    for(int i = 0; i < this->goals.size(); i++){
        if(this->goals[i].first == line && this->goals[i].second == column){
            return i;
        }
    }
    return -1;
}

#endif // BOARD_HPP
    