#include <iostream>
#include "Graph.h"
#include "RandomGraph.h"

void Draw()
{
    std::string drawing = "python3 GraphVisualizationBeta.py MacierzIncydencji.txt";
    system(drawing.c_str());
}

void Convert(const char * fileName)
{
    Graph graph(fileName);
    graph.ConvertGraph();
}

int main(int argc, const char * argv[])
{
    ////////// Zadanie 1 //////////
    if(argc == 1)
    {
        Convert("graphRep.txt");
        Draw();
    }

    ////////// Zadanie 3 //////////
    if(argc != 4)
    {
        std::cout << "To generate random graph please type: Lab1.out 'probability/amount' num_of_vertexes probability_of_edge/amount_of_edges " << std::endl;
        exit(0);
    }

    srand(time(0));

    RandomGraph randomGraph(argv[1], argv[2], argv[3]);
    Convert("MacierzSasiedztwaRandom.txt");
    Draw();

    return 0;
}