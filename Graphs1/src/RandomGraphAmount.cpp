#include "RandomGraphAmount.h"

RandomGraphAmount::RandomGraphAmount(const int numberOfVertexes, const int amountOfEdges) : RandomGraphType(numberOfVertexes)
{
    try
    {
        if(amountOfEdges < 0)
            throw "Amount of egdes cannot be negative";
        if(amountOfEdges > (numberOfVertexes * (numberOfVertexes - 1)) / 2)
            throw "Too much egdes in graph";
    }
    catch(const char * exp)
    {
        std::cerr << exp << std::endl;
        exit(EXIT_FAILURE);
    }

    RandomGraphType::CreateAdjMatrix();
    FillAdjMatrix(amountOfEdges);
    RandomGraphType::PrintAdjMatrixToFile();
}

void RandomGraphAmount::FillAdjMatrix(const int amountOfEdges) const
{
    int edges = 0;

    while(edges < amountOfEdges)
    {
        int i = RandomGraphType::iRand(0, m_numberOfVertexes);
        int j = RandomGraphType::iRand(0, m_numberOfVertexes);

        if(m_adjMatrix[i][j] == 0 && i != j)
        {
            m_adjMatrix[i][j] = 1;
            m_adjMatrix[j][i] = 1;
            ++edges;
        }
    }
}