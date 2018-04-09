#include <iostream>
#include "Graph.h"
#include "RandomGraph.h"

int main(int argc, const char * argv[])
{
    ////////// Zadanie 1 //////////
    if(argc == 1)
    {
        Graph graph("graphRep.txt");
        graph.Print();
        graph.ConvertGraph();
    }

    ////////// Zadanie 3 //////////
    if(argc != 4)
    {
        std::cout << "To generate random graph please type: Lab1.out 'probability/amount' num_of_vertexes probability_of_edge/amount_of_edges " << std::endl;
        exit(0);
    }

    srand(time(0));

    RandomGraph randomGraph(argv[1], argv[2], argv[3]);

    return 0;
}