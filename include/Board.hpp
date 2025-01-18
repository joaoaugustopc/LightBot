#include <set>
#include <map>
#include <vector>

using namespace std;

struct BoardCell
{
    int height;
    bool isGoal;
    bool isLighted;
    bool isVisited;
};

struct Board{
    int n_lines;
    int n_columns;
    vector<std::vector<BoardCell>> cells;
    set<std::pair<int, int>> visited;
    map<std::pair<int, int>, bool> lighted;
};


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
    