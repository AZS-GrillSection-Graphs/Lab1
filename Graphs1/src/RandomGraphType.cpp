#include "RandomGraphType.h"

RandomGraphType::RandomGraphType(const int numberOfVertexes)  : m_numberOfVertexes(numberOfVertexes), m_adjMatrix(nullptr)
{

}

RandomGraphType::~RandomGraphType()
{
    for(int i = 0; i < m_numberOfVertexes; ++i)
        delete [] m_adjMatrix[i];

    delete [] m_adjMatrix;
}


void RandomGraphType::CreateAdjMatrix()
{
    m_adjMatrix = new int * [m_numberOfVertexes];

    for(int i = 0; i < m_numberOfVertexes; ++i)
    {
        m_adjMatrix[i] = new int [m_numberOfVertexes];
        for(int j = 0; j < m_numberOfVertexes; ++j)
        {
            m_adjMatrix[i][j] = 0;
        }
    }
}

void RandomGraphType::PrintAdjMatrixToFile() const
{
    ////////// Macierz sasiedztwa //////////
    std::ofstream adjMatrixFile;

    if (!adjMatrixFile.is_open())
    {
        adjMatrixFile.open("MacierzSasiedztwaRandom.txt", std::ios::out);

        if(!adjMatrixFile)
        {
            std::cerr << "Failed to open " << "MacierzSasiedztwaRandom.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    adjMatrixFile << "MS" << std::endl;

    for(int i = 0; i < m_numberOfVertexes; ++i)
    {
        for(int j = 0; j < m_numberOfVertexes; ++j)
        {
            adjMatrixFile << m_adjMatrix[i][j] << " ";
        }
        adjMatrixFile << std::endl;
    }

    adjMatrixFile.close();
}

int RandomGraphType::iRand(const int min, const int max)
{
    return rand() % max + min;
}
