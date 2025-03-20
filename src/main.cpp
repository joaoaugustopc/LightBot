#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>


#include "../include/models.hpp"
#include <string>

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

/////////////////////////////////////////// BUSCA EM PROFUNDIDADE ////////////////////////////////////
bool buscaDFS(No* noAtual, std::set<Estado>& visitados, std::vector<Operacao>& caminho, const Board& board) {
    if(estadoObjetivo(noAtual->estado))
        return true;

    visitados.insert(noAtual->estado);

    std::vector<No*> sucessores = gerarSucessores(noAtual, board);
    for(No* sucessor : sucessores) {
        if(visitados.find(sucessor->estado) == visitados.end()) {
            caminho.push_back(sucessor->op);
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
    
    for (const auto& objetivo : board.goals) {
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
            }
        }
    }

    return false; // Caminho não foi encontrado
}
/////////////////////////////////////// FIM BUSCA GULOSA /////////////////////////////////////////////


//////////////////////////////////////// BUSCA A* ////////////////////////////////////////////////

     // Listas para armazenar informações sobre nós abertos e fechados
     struct InfoNo {
        int linha;
        int coluna;
        int custoTotal;
    
        InfoNo(No* no) {
            linha = no->estado.linha;
            coluna = no->estado.coluna;
            custoTotal = no->custoReal + no->heuristicaStar;
        }
    };
// Função para imprimir a lista de nós
void imprimirListaNos(const std::vector<InfoNo>& lista, const std::string& titulo);

struct ComparadorCustoTotal {
    bool operator()(const No* a, const No* b) const {
         return a->custo > b->custo; // Ordena pelo menor custo total
     }
 };
 



int custoDoCaminho(const Estado& estadoOrigem, const Estado& estadoDestino, const Board& tabuleiro) {
    
    return 1;
}


int heuristicaStar(const Estado& estado, const Board& board) {
    // Conta quantos objetivos faltam acender
    int objetivosRestantes = 0;
    for (bool aceso : estado.lighted) {
        if (!aceso) {
            objetivosRestantes++;
        }
    }
    
    // Se não há mais objetivos para acender, retorna 0
    if (objetivosRestantes == 0) {
        return 0;
    }
    
    // Para cada objetivo não aceso, calcula a distância Manhattan
    int menorDistancia = std::numeric_limits<int>::max();
    
    for (int i = 0; i < board.goals.size(); i++) {
        if (!estado.lighted[i]) {
            int distancia = abs(estado.linha - board.goals[i].first) + 
                            abs(estado.coluna - board.goals[i].second);
            
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
            }
        }
    }
    
    
    return menorDistancia;
}



    // nosAbertos e nosFechados
    std::vector<InfoNo> nosAbertos;
    std::vector<InfoNo> nosFechados;

     // Imprime o mapa com o caminho solução
     
          void imprimirListaNos(const std::vector<InfoNo>& lista, const std::string& titulo) {
            std::cout << "\n=== " << titulo << " ===\n";
            for (const auto& no : lista) {
                std::cout << "Linha: " << no.linha << ", Coluna: " << no.coluna << ", Custo Total: " << no.custoTotal << '\n';
            }
            std::cout << "=========================\n";
              // Imprime as listas de nós abertos e fechados
        imprimirListaNos(nosFechados, "LISTA DE NÓS FECHADOS");
        imprimirListaNos(nosAbertos, "LISTA DE NÓS ABERTOS");

        };
        
// Comparação otimizada para encontrar o caminho mais curto
struct ComparadorCustoTotalStar {
    bool operator()(const No* a, const No* b) const {
        // quantos objetivos já foram acesos 
        int acesosA = 0, acesosB = 0;
        for (bool aceso : a->estado.lighted) {
            if (aceso) acesosA++;
        }
        for (bool aceso : b->estado.lighted) {
            if (aceso) acesosB++;
        }
        
        if (acesosA != acesosB) {
            return acesosA < acesosB; // Priorizar estados com mais objetivos acesos
        }
        
        // Se iguais em objetivos acesos, compara f(n) = g(n) + h(n)
        int fA = a->custoReal + a->heuristicaStar;
        int fB = b->custoReal + b->heuristicaStar;
        
        if (fA != fB) {
            return fA > fB; // Menor custo total tem maior prioridade
        }
        
        // Em caso de empate, priorize o nó com menor g(n)
     
        return a->custoReal > b->custoReal;
    }
};


bool buscaAEstrela(No* noAtual, std::set<Estado>& visitados, std::vector<Operacao>& caminho, const Board& tabuleiro) {
    std::cout << "\n=== INICIANDO BUSCA A* OTIMIZADA PARA LIGHTBOT ===\n";
    
    // Fila de prioridade para A*
    std::priority_queue<No*, std::vector<No*>, ComparadorCustoTotalStar> filaPrioridade;
    
    // Mapa para armazenar o menor custo conhecido para cada estado
    std::map<Estado, int> custoMinimo;
    

    // Inicializa o nó inicial
    noAtual->custoReal = 0 ; // Custo inicial é 0
    noAtual->heuristicaStar = heuristicaStar(noAtual->estado, tabuleiro);
    //noAtual->custo = noAtual->custoReal + noAtual->heuristicaStar;
    noAtual->custo = noAtual->custoReal + noAtual->heuristicaStar ; //considerando o custo

    filaPrioridade.push(noAtual);
    custoMinimo[noAtual->estado] = noAtual->custoReal;
    nosAbertos.push_back(InfoNo(noAtual));
    
    int nosProcessados = 0;
    int nosGerados = 1; // Conta o nó inicial
    
    while (!filaPrioridade.empty()) {
        No* noAtual = filaPrioridade.top();
        filaPrioridade.pop();
        
        // Remove da lista de abertos (para impressão)
        for (auto it = nosAbertos.begin(); it != nosAbertos.end(); ++it) {
            if (it->linha == noAtual->estado.linha && 
                it->coluna == noAtual->estado.coluna && 
                it->custoTotal == noAtual->custoReal + noAtual->heuristicaStar) {
                it = nosAbertos.erase(it);
                break;
            }
        }
        
        nosProcessados++;
        
        // Verifica se já existe um caminho melhor para este estado
        auto it = custoMinimo.find(noAtual->estado);
        if (it != custoMinimo.end() && it->second < noAtual->custoReal) {
            continue; 
        }
        
        // Verifica se o estado atual já foi visitado com um custo melhor
        if (visitados.find(noAtual->estado) != visitados.end()) {
            continue;
        }
        
        // Marca o estado como visitado
        visitados.insert(noAtual->estado);
        nosFechados.push_back(InfoNo(noAtual));
        
        // Usei pra debug - Imprime informações sobre o nó atual para debug
        if (nosProcessados % 50 == 0) {
            std::cout << "Nós processados: " << nosProcessados 
                      << ", Nós gerados: " << nosGerados 
                      << ", Lista de abertos: " << nosAbertos.size() << std::endl;
        }
        
        // Verifica se encontrou o objetivo
        if (estadoObjetivo(noAtual->estado)){ 
            caminho = reconstruirCaminho(noAtual);
            
            // Imprime INFORMAÇÕES finais
            std::cout << "\n======================================================\n";
            std::cout << "=== INFORMAÇÕES DA BUSCA - SOLUÇÃO ENCONTRADA! ===\n";
            std::cout << "======================================================\n";
            std::cout << "Total de nós gerados: " << nosGerados << std::endl;
            std::cout << "Total de nós processados: " << nosProcessados << std::endl;
            std::cout << "Total de nós na lista de ABERTOS: " << nosAbertos.size() << std::endl;
            std::cout << "Total de nós na lista de FECHADOS: " << nosFechados.size() << std::endl;
            std::cout << "Comprimento do caminho solução: " << caminho.size() << " passos" << std::endl;
            std::cout << "Custo total da solução: " << noAtual->custoReal << std::endl;
            return true;
        }


        // Gera os sucessores 
    std::vector<Operacao> operacoes = listaOperacoes(noAtual, tabuleiro);
        
        // Primeiro, verifica se pode acender 
    bool acendeu = false;
        for (Operacao op : operacoes) {
            if (op == LIGHT) {
                No* sucessor = getSucessor(noAtual, op, tabuleiro);
                if (sucessor != nullptr) {
                    nosGerados++;
                    
                    
                    //atribuído valor randomico para escolha do caminho mais curto
                    //RANDOMICO
                    // Todos os movimentos têm custo de acordo com a dificuldade da passagem pelo nó (esse aqui é RANDOMICO - atribuído no nó)
                    int novoCustoReal = noAtual->custoReal + noAtual->dificuldadeNo;

                    // Verifica se já existe um caminho melhor para este estado
                    auto it = custoMinimo.find(sucessor->estado);
                    if (it != custoMinimo.end() && it->second <= novoCustoReal) {
                        delete sucessor;
                        continue;
                    }
                    
                    // Atualiza o custo do sucessor
                    sucessor->custoReal = novoCustoReal;
                    sucessor->heuristicaStar = heuristicaStar(sucessor->estado, tabuleiro);
                    sucessor->custo = sucessor->custoReal + sucessor->heuristicaStar;
                    
                    // Atualiza o custo mínimo conhecido para este estado
                    custoMinimo[sucessor->estado] = novoCustoReal;
                    
                    // Adiciona à fila de prioridade e lista de abertos
                    filaPrioridade.push(sucessor);
                    nosAbertos.push_back(InfoNo(sucessor));
                    
                    acendeu = true;
                    break; 
                }
            }
        }
        
        // Se não acendeu, gera os outros sucessores 
        if (!acendeu) {
            for (Operacao op : operacoes) {
                if (op == LIGHT) continue; 
                
                No* sucessor = getSucessor(noAtual, op, tabuleiro);
                if (sucessor != nullptr) {
                    nosGerados++;
                    
                      
                    //atribuído valor randomico para escolha do caminho mais curto
                    //RANDOMICO
                    // Todos os movimentos têm custo de acordo com a dificuldade da passagem pelo nó (esse aqui é RANDOMICO - atribuído no nó)
                    int novoCustoReal = noAtual->custoReal + noAtual->dificuldadeNo;
                    
                    
                    // Verifica se já existe um caminho melhor para este estado
                    auto it = custoMinimo.find(sucessor->estado);
                    if (it != custoMinimo.end() && it->second <= novoCustoReal) {
                        delete sucessor;
                        continue;
                    }
                    
                    // Atualiza o custo do sucessor
                    sucessor->custoReal = novoCustoReal;
                    sucessor->heuristicaStar = heuristicaStar(sucessor->estado, tabuleiro);
                    sucessor->custo = sucessor->custoReal + sucessor->heuristicaStar;
                    
                    // Atualiza o custo mínimo conhecido para este estado
                    custoMinimo[sucessor->estado] = novoCustoReal;
                    
                    // Adiciona à fila de prioridade e lista de abertos
                    filaPrioridade.push(sucessor);
                    nosAbertos.push_back(InfoNo(sucessor));
                }
            }
        }
    }
    
    std::cout << "\n=== BUSCA ENCERRADA SEM ENCONTRAR SOLUÇÃO ===\n";
    
    // Imprime INFORMAÇÕES finais mesmo que não tenha encontrado solução
    std::cout << "\n=== INFORMAÇÕES DA BUSCA ===\n";
    std::cout << "Total de nós gerados: " << nosGerados << std::endl;
    std::cout << "Total de nós processados: " << nosProcessados << std::endl;
    std::cout << "Total de nós na lista de ABERTOS: " << nosAbertos.size() << std::endl;
    std::cout << "Total de nós na lista de FECHADOS: " << nosFechados.size() << std::endl;
    
    // Imprime as listas de nós abertos e fechados
    //imprimirListaNos(nosAbertos, "LISTA DE NÓS ABERTOS");
    //imprimirListaNos(nosFechados, "LISTA DE NÓS FECHADOS");
    
    return false;
}

 /////////////////////////////////////// FINAL DA BUSCA A* /////////////////////////////////////////////
 
int main() {
    
    srand(time(0)); // Inicializa a semente do gerador aleatório - A*

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
    cout << "Mapa selecionado: " << level << std::endl;
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
    }
    else
    {
        cout << "Caminho nao encontrado" << endl;
    }

    cout << "Total de Movimentos: " << caminho.size() << endl;

    delete board;

    return 0;
}
