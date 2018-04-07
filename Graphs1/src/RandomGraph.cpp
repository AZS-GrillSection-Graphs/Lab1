#include <iostream>
#include <cstring>
#include "RandomGraph.h"
#include "RandomGraphAmount.h"
#include "RandomGraphProbability.h"


RandomGraph::RandomGraph(const char *drawType, const char *numOfVertexes, const char *probabilityOrAmount) : m_randGraphType(NULL)
{
    int numberOFVertexes = std::atoi(numOfVertexes);
    double probOrAmount = std::atof(probabilityOrAmount);

    try
    {
        if(numberOFVertexes < 0)
            throw("Graph cannot has negative amount of vertexes.");
    }
    catch(const char * exp)
    {
        std::cerr << exp << std::endl;
        exit(EXIT_FAILURE);
    }

    if(strcmp(drawType,"probability") == 0)
        m_randGraphType = new RandomGraphProbability(numberOFVertexes, probOrAmount);
    else if(strcmp(drawType, "amount") == 0)
        m_randGraphType = new RandomGraphAmount(numberOFVertexes, static_cast<const int>(probOrAmount));
    else
    {
        std::cerr << "Not known draw type." << std::endl;
        exit(0);
    }
}

RandomGraph::~RandomGraph()
{
    delete m_randGraphType;
}
