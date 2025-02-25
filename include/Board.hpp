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
    map<pair<int, int>, bool> lighted;

    Board();
    ~Board();
    void setBoard(vector<vector<BoardCell>> board);
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
}

#endif // BOARD_HPP
/*

class Board
{ 
    public:
        Board(std::vector<std::vector<BoardCell>> board, int n_targetCell);
        ~Board();
        bool isLighted(int x, int y);
        bool isGoal(int x, int y);
        bool isOnBoard(int x, int y);
        bool isVisited(int x, int y);
        void setVisited(int x, int y);
        void setLighted(int x, int y);
        bool isSolved();
        bool getHeigth(int x, int y);
        bool getNTargetCellLighted();
        bool getNTargetCell();

    private:
        std::vector<std::vector<BoardCell>> board;
        std::set<std::pair<int, int>> visited;
        int n_targetCellLighted;
};
*/
    