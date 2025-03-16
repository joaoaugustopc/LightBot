#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <limits>
#include <fstream>
#include <functional> 
#include <unordered_map>


#include "../include/models.hpp"

//{height, isGoal, isLighted, isVisited}
vector<vector<BoardCell>> level1 = {
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(1, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(2, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(2, 0), BoardCell(2, 0), BoardCell(2, 0), BoardCell(2, 0), BoardCell(2, 0), BoardCell(2, 1)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)}};

vector<vector<BoardCell>> level2 = {
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(1, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(2, 1), BoardCell(2, 0), BoardCell(2, 0), BoardCell(3, 0), BoardCell(2, 0), BoardCell(3, 0), BoardCell(2, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(4, 0), BoardCell(3, 0), BoardCell(4, 0), BoardCell(2, 0), BoardCell(2, 1)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)}};

vector<vector<BoardCell>> level3 = {
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(4, 1), BoardCell(3, 1), BoardCell(2, 1), BoardCell(1, 1), BoardCell(2, 1), BoardCell(3, 1), BoardCell(4, 1), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(3, 1), BoardCell(0, 0), BoardCell(0, 0), BoardCell(2, 1), BoardCell(0, 0), BoardCell(0, 0), BoardCell(3, 1), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(2, 1), BoardCell(0, 0), BoardCell(0, 0), BoardCell(3, 1), BoardCell(0, 0), BoardCell(0, 0), BoardCell(2, 1), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(1, 1), BoardCell(2, 1), BoardCell(3, 1), BoardCell(4, 1), BoardCell(3, 1), BoardCell(2, 1), BoardCell(1, 1), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)},
    {BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0), BoardCell(0, 0)}};

using namespace std;

// Função para imprimir o mapa com o caminho solução
void imprimirMapaComCaminho(int numLinhas, int numColunas,
                            std::vector<std::vector<char>> &mapa,
                            std::vector<Operacao> caminho,
                            int linhaInicial, int colunaInicial)
{
    // Criar uma cópia do mapa original para modificar
    std::vector<std::vector<std::string>> mapaSolucao(numLinhas, std::vector<std::string>(numColunas));

    // Copiar os caracteres do mapa original para a versão editável
    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j < numColunas; j++)
        {
            mapaSolucao[i][j] = std::string(1, mapa[i][j]); // Converte char para string
        }
    }

    // Posição atual do robô
    int linha = linhaInicial;
    int coluna = colunaInicial;

    // Marcar posição inicial do robô
    mapaSolucao[linha][coluna] = "R";

    int passo = 1; // Contador do percurso

    // Percorrer os movimentos e atualizar o mapa
    for (Operacao op : caminho)
    {
        switch (op)
        {
        case UP:
            linha--;
            break;
        case DOWN:
            linha++;
            break;
        case LEFT:
            coluna--;
            break;
        case RIGHT:
            coluna++;
            break;
        case LIGHT:
            mapaSolucao[linha][coluna] = "O"; // Marca célula acesa
            continue;                         // Não move o robô ao acender
        }

        // Marcar o caminho percorrido com números indicando a ordem
        if (mapaSolucao[linha][coluna] == ".")
        {
            mapaSolucao[linha][coluna] = std::to_string(passo++);
        }
    }

    // Atualizar posição final do robô
    mapaSolucao[linha][coluna] = "R";

    // **Imprimir o mapa atualizado com tabulação automática**
    std::cout << "\nMapa com Caminho Solucao e Ordem do Percurso:\n\n";
    for (const auto &linha : mapaSolucao)
    {
        std::cout << "  "; // Indenta um pouco à esquerda para melhor alinhamento
        for (const std::string &celula : linha)
        {
            std::cout << std::setw(4) << celula; // Espaço fixo de 4 caracteres por célula
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void gerarArquivoDOT(No* raiz, const std::string& nomeArquivo, const std::vector<Operacao>& caminho) {
    std::ofstream arquivo(nomeArquivo);
    arquivo << "digraph G {" << std::endl;

    // Conjunto para armazenar os nós que fazem parte do caminho solução
    std::set<No*> nosCaminho;
    No* noAtual = raiz;
    for (const auto& op : caminho) {
        nosCaminho.insert(noAtual);
        for (No* sucessor : noAtual->sucessores) {
            if (sucessor->op == op) {
                noAtual = sucessor;
                break;
            }
        }
    }
    nosCaminho.insert(noAtual); // Adiciona o nó final
    

    std::function<void(No*)> adicionarNos = [&](No* no) {
        if (!no) return;

        // Adiciona o nó atual ao arquivo DOT com destaque se fizer parte do caminho solução
        if (nosCaminho.find(no) != nosCaminho.end()) {
            arquivo << "  \"" << no << "\" [label=\"(" << no->estado.linha << "," << no->estado.coluna << ")\", style=filled, fillcolor=yellow];" << std::endl;
        } else {
            arquivo << "  \"" << no << "\" [label=\"(" << no->estado.linha << "," << no->estado.coluna << ")\"];" << std::endl;
        }
        //arquivo << "  \"" << no << "\" [label=\"(" << no->estado.linha << "," << no->estado.coluna << ")\"];" << std::endl;
        if (no->pai) {
            if (nosCaminho.find(no) != nosCaminho.end() && nosCaminho.find(no->pai) != nosCaminho.end()) {
                arquivo << "  \"" << no->pai << "\" -> \"" << no << "\" [color=red, penwidth=2.0];" << std::endl;
            } else {
                arquivo << "  \"" << no->pai << "\" -> \"" << no << "\";" << std::endl;
            }
            //arquivo << "  \"" << no->pai << "\" -> \"" << no << "\";" << std::endl;
        }
        for (No* sucessor : no->sucessores) {
            adicionarNos(sucessor);
        }
    };

    adicionarNos(raiz);
    arquivo << "}" << std::endl;
    arquivo.close();
}

/////////////////////////////////////////// BUSCA EM PROFUNDIDADE ////////////////////////////////////
bool buscaDFS(No* noAtual, std::set<Estado>& visitados, std::vector<Operacao>& caminho, const Board& board) {
    if(estadoObjetivo(noAtual->estado))
        return true;

    visitados.insert(noAtual->estado);

    std::vector<No*> sucessores = gerarSucessores(noAtual, board);
    for(No* sucessor : sucessores) {
        if(visitados.find(sucessor->estado) == visitados.end()) {
            caminho.push_back(sucessor->op);
            noAtual->sucessores.push_back(sucessor);
            if(buscaDFS(sucessor, visitados, caminho, board))
                return true;
            caminho.pop_back();
        }
    }
    
    return false;
}
//////////////////////////////////////// FIM BUSCA PROFUNDIDADE ////////////////////////////////////////
vector<Operacao> reconstruirCaminho(No *no)
{
    vector<Operacao> caminho;
    No *noAtual = no;

    while (noAtual->pai != nullptr)
    {
        caminho.push_back(noAtual->op);
        noAtual = noAtual->pai;
    }

    reverse(caminho.begin(), caminho.end());
    return caminho;
}

///////////////////////////////////////////// BUSCA EM LARGURA ////////////////////////////////////////
bool buscaBFS(No *noAtual, set<Estado> &visitados, vector<Operacao> &caminho, const Board &board)
{
    queue<No *> fila;

    fila.push(noAtual);
    visitados.insert(noAtual->estado);

    while (!fila.empty())
    {
        No *noAtual = fila.front();
        fila.pop();

        if (estadoObjetivo(noAtual->estado))
        {

            caminho = reconstruirCaminho(noAtual);
            return true;
        }

        vector<No *> sucessores = gerarSucessores(noAtual, board);
        for (No *sucessor : sucessores)
        {
            if (visitados.find(sucessor->estado) == visitados.end())
            {
                fila.push(sucessor);
                visitados.insert(sucessor->estado);
                noAtual->sucessores.push_back(sucessor);
            }
        }
    }

    return false;
}
//////////////////////////////////// FIM BUSCA LARGURA ///////////////////////////////////////////////

//////////////////////////////////// BUSCA BACKTRACKING //////////////////////////////////////////////
bool buscaBacktracking(No* noAtual, std::set<Estado>& visitados, std::vector<Operacao>& caminho, const Board& board) {
    if (estadoObjetivo(noAtual->estado))
        return true;

    visitados.insert(noAtual->estado);

    //std::vector<No*> sucessores = gerarSucessores(noAtual, board);
    std::vector<Operacao> operacoes = listaOperacoes(noAtual, board);

    for (Operacao operacao : operacoes) {
        No* sucessor = getSucessor(noAtual, operacao, board);
        if (visitados.find(sucessor->estado) == visitados.end()) {
            caminho.push_back(operacao);
            noAtual->sucessores.push_back(sucessor);
            if (buscaBacktracking(sucessor, visitados, caminho, board))
                return true;
            caminho.pop_back();
        }
    }

    //visitados.erase(noAtual->estado);
    return false;
}
/////////////////////////////////// FIM BUSCA BACKTRACKING ///////////////////////////////////////////

/////////////////////////////////// HEURISTICA BUSCA GULOSA //////////////////////////////////////////
struct ComparadorHeuristica {
    bool operator()(const No* a, const No* b) const {
        return a->heuristica > b->heuristica; // Força a escolher a menor heurística primeiro
    }
};

int heuristica(const Estado& estado, const Board& board) {
    int menorDistancia = std::numeric_limits<int>::max();

    for (const auto& objetivo : board.goals)
    {
        int distancia = abs(estado.linha - objetivo.first) + abs(estado.coluna - objetivo.second);
        menorDistancia = std::min(menorDistancia, distancia);
    }

    return menorDistancia;
}
///////////////////////////////// FIM HEURISTICA BUSCA GULOSA ////////////////////////////////////////

//////////////////////////////////////// BUSCA GULOSA ////////////////////////////////////////////////
bool buscaGulosa(No* noAtual, std::set<Estado>& visitados, std::vector<Operacao>& caminho, const Board& board) {
    std::priority_queue<No*, std::vector<No*>, ComparadorHeuristica> filaPrioridade;

    noAtual->heuristica = heuristica(noAtual->estado, board);
    filaPrioridade.push(noAtual);
    visitados.insert(noAtual->estado);

    while (!filaPrioridade.empty()) {
        No* noAtual = filaPrioridade.top();
        filaPrioridade.pop();

        if (estadoObjetivo(noAtual->estado)) {
            caminho = reconstruirCaminho(noAtual);
            return true;
        }

        std::vector<No*> sucessores = gerarSucessores(noAtual, board);
        for (No* sucessor : sucessores) {
            if (visitados.find(sucessor->estado) == visitados.end()) {
                sucessor->heuristica = heuristica(sucessor->estado, board);
                filaPrioridade.push(sucessor);
                visitados.insert(sucessor->estado);
                noAtual->sucessores.push_back(sucessor);
            }
        }
    }

    return false; // Caminho não foi encontrado
}
/////////////////////////////////////// FIM BUSCA GULOSA /////////////////////////////////////////////



//////////////////////////////////////// BUSCA A* ////////////////////////////////////////////////
struct ComparadorCustoTotal {
   bool operator()(const No* a, const No* b) const {
        return a->custo > b->custo; // Ordena pelo menor custo total
    }
};

bool buscaAEstrela(No* noAtual, std::set<Estado>& visitados, std::vector<Operacao>& caminho, const Board& tabuleiro) {
    // Fila de prioridade para A*, ordenada por f(n) = g(n) + h(n)
    std::priority_queue<No*, std::vector<No*>, ComparadorCustoTotal> filaPrioridade;

    // Inicializa o nó atual
    noAtual->custoReal = 0; // g(n): custo real do caminho percorrido até o nó atual
    noAtual->heuristica = heuristica(noAtual->estado, tabuleiro); // h(n): estimativa do custo restante
    noAtual->custo = noAtual->custoReal + noAtual->heuristica; // f(n) = g(n) + h(n)
    filaPrioridade.push(noAtual);
    visitados.insert(noAtual->estado);

    while (!filaPrioridade.empty()) {
        No* noAtual = filaPrioridade.top();
        filaPrioridade.pop();

        // Verifica se o nó atual é o objetivo
        if (estadoObjetivo(noAtual->estado)) {
            caminho = reconstruirCaminho(noAtual);
            return true;
        }

        // Gera os sucessores do nó atual
        std::vector<No*> sucessores = gerarSucessores(noAtual, tabuleiro);
        for (No* sucessor : sucessores) {
            // Calcula o custo real do sucessor (g(n))
            int custoRealSucessor = noAtual->custoReal + 1; // Assume-se que o custo de cada operação é 1

            // Verifica se o sucessor já foi visitado ou se encontrou um caminho melhor
            if (visitados.find(sucessor->estado) == visitados.end() || custoRealSucessor < sucessor->custoReal) {
                sucessor->custoReal = custoRealSucessor; // Atualiza g(n)
                sucessor->heuristica = heuristica(sucessor->estado, tabuleiro); // Calcula h(n)
                sucessor->custo = sucessor->custoReal + sucessor->heuristica; // f(n) = g(n) + h(n)

                // Adiciona o sucessor à fila de prioridade
                filaPrioridade.push(sucessor);
                visitados.insert(sucessor->estado);
                noAtual->sucessores.push_back(sucessor);
            }
        }
    }

    return false; // Caminho não foi encontrado
}

/////////////////////////////////////// FINAL DA BUSCA A* /////////////////////////////////////////////

int main()
{

    Board *board = new Board();

    /////////////// MENU INICIAL ////////////////////////
    cout << "Selecione o mapa: 1, 2 ou 3" << endl;
    int level;
    cin >> level;
    switch (level)
    {
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
        cout << "Mapa invalido" << endl;
        return 0;
    }
    //////////////////////////////////////////////////////
    cout << "Mapa selecionado: " << level << endl;
    cout << "Mapa: " << endl;
    for (int i = 0; i < board->n_lines; i++)
    {
        for (int j = 0; j < board->n_columns; j++)
        {

            cout << board->cells[i][j].height << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < board->n_lines; i++)
    {
        for (int j = 0; j < board->n_columns; j++)
        {

            if (board->cells[i][j].isGoal)
            {
                cout << "G ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }


    // Selecionar tipo de busca
    cout << "Selecione o tipo de busca: 1 - BFS, 2 - DFS, 3 - Backtracking, 4 - Gulosa, 5 - A*" << endl;
    int searchType;
    cin >> searchType;

    Estado estadoInicial = Estado(0, 0, vector<bool>(board->goals.size(), false));
    No *noAtual = new No(estadoInicial, nullptr, UP, 0);
    std::set<Estado> visitados;
    std::vector<Operacao> caminho;
    bool found = false;

    switch (searchType)
    {
        case 1:
            found = buscaBFS(noAtual, visitados, caminho, *board);
            break;
        case 2:
            found = buscaDFS(noAtual, visitados, caminho, *board);
            break;
        case 3:
            found = buscaBacktracking(noAtual, visitados, caminho, *board);
            break;
        case 4:
            found = buscaGulosa(noAtual, visitados, caminho, *board);
            break;
        case 5:
            found = buscaAEstrela(noAtual, visitados, caminho, *board);
            break;

    default:
        cout << "Tipo de busca inválido" << endl;
        return 0;
    }

    if (found)
    {
        // Imprimir mapa com caminho

        // Convert BoardCell vector to char vector
        std::vector<std::vector<char>> mapaChar(board->n_lines, std::vector<char>(board->n_columns, '.'));
        for (int i = 0; i < board->n_lines; ++i)
        {
            for (int j = 0; j < board->n_columns; ++j)
            {
                if (board->cells[i][j].isGoal)
                {
                    mapaChar[i][j] = 'G';
                }
            }
        }
        imprimirMapaComCaminho(board->n_lines, board->n_columns, mapaChar, caminho, 0, 0);
        gerarArquivoDOT(noAtual, "arvore_busca.dot", caminho);
        system("dot -Tpng arvore_busca.dot -o arvore_busca.png");
        std::cout << "Árvore de busca gerada: arvore_busca.png" << std::endl;
    }
    else
    {
        cout << "Caminho nao encontrado" << endl;
    }

    cout << "Total de Movimentos: " << caminho.size() << endl;

    delete board;

    return 0;
}
