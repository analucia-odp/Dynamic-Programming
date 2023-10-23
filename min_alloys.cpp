//---------------------------------------------------------------------
// Arquivo	: min_alloys.cpp
// Conteudo	: Implementação da classe que calculará o problema das ligas
// Autor	: Ana Lucia Oliveira de Paula (analop@ufmg.br)
// Historico	: 2023-06-17 - arquivo criado
//---------------------------------------------------------------------
#include "min_alloys.hpp"

Min_Alloys::Min_Alloys(int number_of_alloys, int demand){
    client_demand = demand;
    number_alloys = number_of_alloys;
    OPT = new int* [number_of_alloys + 1]; //as linhas serão a quantidade de ligas + 1

    for (int i=0; i<=number_of_alloys; i++){
        OPT[i] = new int [demand + 1]; //as colunas irá até o valor de demanda do cliente
    }
}

void Min_Alloys::insert_alloy(int alloy){
    alloys_array.push_back(alloy);
}

int Min_Alloys::find_solution(){

    OPT[0][0] = 0; //caso base

    for (int weight = 1; weight <= client_demand; weight++){
        OPT[0][weight] = INF; //inicializa as demais colunas, referente ao peso maximo local, como infinito para realizar a comparação de min
    }

    for (int alloy = 1; alloy <= number_alloys; alloy++){ //começa da linha 1, pois a linha 0 é o caso base para as demais linhas
        for (int weight = 0; weight <= client_demand; weight++){
            int alloy_weight = alloys_array[alloy - 1];
            if ( alloy_weight > weight){ //se o tamanho da minha liga for maior que a capacidade máxima local
                OPT[alloy][weight] = OPT[alloy-1][weight]; //não coloco minha liga na solução.
            }
            else{
                int not_alloy = OPT[alloy - 1][weight]; //não coloco a liga na solução.
                int yes_alloy = 1 + OPT[alloy][weight - alloy_weight]; //coloco a liga na solução + a melhor solução colocando essa liga e as outras com a capacidade restante.
                OPT[alloy][weight] = not_alloy < yes_alloy ? not_alloy : yes_alloy;
            }
        }
    }

    return OPT[number_alloys][client_demand]; //retorna o valor referente a linha contendo todas as ligas possíveis + a coluna que contém a capacidade máxima = demanda do cliente
}

// void Min_Alloys::print_vector(){
//     cout << client_demand << " " << number_alloys << endl;
//     cout << "[ ";
//     for (auto it : alloys_array){
//         cout << it << ", ";
//     }

//     cout << "] " << endl;
// }

Min_Alloys::~Min_Alloys(){
    //desaloca vetor de ligas e a matriz OPT
    alloys_array.clear();

    for (int i=0; i<=number_alloys; i++){
        delete [] OPT[i];
    }

    delete [] OPT;

}