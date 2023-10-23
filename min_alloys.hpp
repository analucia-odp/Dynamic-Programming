//---------------------------------------------------------------------
// Arquivo	: min_alloys.hpp
// Conteudo	: Definição da classe que calculará o problema das ligas
// Autor	: Ana Lucia Oliveira de Paula (analop@ufmg.br)
// Historico	: 2023-06-17 - arquivo criado
//---------------------------------------------------------------------
#ifndef MIN_ALLOYS_HPP
#define MIN_ALLOYS_HPP

#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

class Min_Alloys{

    public:
        Min_Alloys(int number_of_alloys, int demand); //construtor
        ~Min_Alloys(); //destrutor

        void insert_alloy(int alloy); //insere as ligas no vetor
        int find_solution(); //encontra a solução do problema usando programação dinâmica

        // void print_vector();

    private:
        int client_demand; //demanda do cliente
        int number_alloys; //número total de ligas
        vector<int> alloys_array; //vetor de tamanho das ligas
        int **OPT; //matriz OPT definida na equação de bellman
};

#endif // MIN_ALLOYS_HPP