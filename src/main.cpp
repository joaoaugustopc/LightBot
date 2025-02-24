#include <iostream>  
#include "../include/Board.hpp"

using namespace std;

//{height, isGoal, isLighted, isVisited}
vector<vector<BoardCell>> level1 =  {
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(1,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(2,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(2,0,0,0), BoardCell(2,0,0,0), BoardCell(2,0,0,0), BoardCell(2,0,0,0), BoardCell(2,0,0,0), BoardCell(2,1,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)}
 };

 vector<vector<BoardCell>> level2 = {
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(1,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(2,1,0,0), BoardCell(2,0,0,0), BoardCell(2,0,0,0), BoardCell(4,0,0,0), BoardCell(2,0,0,0), BoardCell(3,0,0,0), BoardCell(2,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(4,0,0,0), BoardCell(3,0,0,0), BoardCell(4,0,0,0), BoardCell(2,0,0,0), BoardCell(2,1,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)}
};

vector<vector<BoardCell>> level3 = {
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(4,1,0,0), BoardCell(3,1,0,0), BoardCell(2,1,0,0), BoardCell(1,1,0,0), BoardCell(2,1,0,0), BoardCell(3,1,0,0), BoardCell(4,1,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(3,1,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(2,1,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(3,1,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(2,1,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(3,1,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(2,1,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(1,1,0,0), BoardCell(2,1,0,0), BoardCell(3,1,0,0), BoardCell(4,1,0,0), BoardCell(3,1,0,0), BoardCell(2,1,0,0), BoardCell(1,1,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)},
    {BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0), BoardCell(0,0,0,0)}
};

int main() {
    
    Board *board = new Board();

    /////////////// MENU INICIAL ////////////////////////
    cout << "Selecione o mapa: 1, 2 ou 3" << endl;
    int level;
    cin >> level;
    switch(level){
        case 1:
            board->setBoard(level1);
            break;
        case 2:
            board->setBoard(level2);
            break;
        case 3:
            board->setBoard(level3);
            break;
        default:
            cout << "Mapa inválido" << endl;
            return 0;
    }
    //////////////////////////////////////////////////////
    cout << "Mapa selecionado: " << level << endl;
    cout << "Mapa: " << endl;
    for(int i = 0; i < board->n_lines; i++){
        for(int j = 0; j < board->n_columns; j++){
            cout << board->cells[i][j].height << " ";
        }
        cout << endl;
    }
    
    return 0;  
}

