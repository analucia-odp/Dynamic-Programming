//---------------------------------------------------------------------
// Arquivo	: main.cpp
// Conteudo	: Main
// Autor	: Ana Lucia Oliveira de Paula (analop@ufmg.br)
// Historico	: 2023-06-17 - arquivo criado
//---------------------------------------------------------------------
#include <iostream>
#include "min_alloys.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    // Your code here

    int number_tests;
    int count = 0;

    cin >> number_tests;

    int types_of_alloys;
    int client_demand;

    int alloy;

    while (count < number_tests ){

        cin >> types_of_alloys >> client_demand; //types_of_alloys = tamanho do vetor

        try{
            if ( types_of_alloys < 1 || types_of_alloys > 1000)
                throw "Número inválido de ligas";
            if ( client_demand < 1 || client_demand > 1000000)
                throw "Demanda inválida";

        }catch(char* msg){
            cout << msg << endl;
        }

        Min_Alloys *p = new Min_Alloys(types_of_alloys, client_demand);

        for (int i=0; i< types_of_alloys; i++){
            cin >> alloy; //le a liga
            p->insert_alloy(alloy); //insere a liga
        }

        // p->print_vector();
        cout << p->find_solution() << endl;
        delete p;

        count ++;
    }
    return 0;
}
