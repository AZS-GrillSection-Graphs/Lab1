#include "RandomGraphProbability.h"

RandomGraphProbability::RandomGraphProbability(const int numberOfVertexes, const double probabilityOfEdges) : RandomGraphType(numberOfVertexes)
{
    try
    {
        if(probabilityOfEdges < 0)
            throw "Probability cannot be negative.";
        if(probabilityOfEdges > 1)
            throw "Probabiliy cannot be bigger then 1.";
    }
    catch(const char * exp)
    {
        std::cerr << exp << std::endl;
    }

    RandomGraphType::CreateAdjMatrix();
    FillAdjMatrix(probabilityOfEdges);
    RandomGraphType::PrintAdjMatrixToFile();
}

void RandomGraphProbability::FillAdjMatrix(const double probabilityOfEdges) const
{
    for(int i = 0; i < m_numberOfVertexes; ++i)
    {
        for(int j = i + 1; j < m_numberOfVertexes; ++j)
        {
            int random;
            int probability;
            CalculateProbability(probabilityOfEdges, random, probability);

            if(random <= probability)
            {
                m_adjMatrix[i][j] = 1;
                m_adjMatrix[j][i] = 1;
            }
        }
    }
}

void RandomGraphProbability::CalculateProbability(const double probabilityOfEdges, int &random, int &probability) const
{
    random = RandomGraphType::iRand(1, 100);
    probability = static_cast<int>(probabilityOfEdges * 100);
}
