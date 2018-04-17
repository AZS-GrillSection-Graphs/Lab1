#include "AdjacencyList.h"


AdjacencyList::AdjacencyList(std::ifstream &inputFile) : m_numOfVer(0)
{
    std::vector<std::vector <int> >row;
    std::string line;

    while(getline(inputFile, line))
    {
        ++m_numOfVer;

        std::istringstream streamLine(line);
        std::vector<int> col;

        while(!streamLine.eof())
        {
            int value;
            streamLine >> value;

            if(streamLine.fail())
                break;

            col.push_back(value);
        }

        m_adjList.push_back(col);
    }
}

void AdjacencyList::Print() const
{
    for(int i = 0; i < m_numOfVer; ++i)
    {
        for(int j = 0; j < m_adjList[i].size(); ++j)
        {
            std::cout << m_adjList[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void AdjacencyList::Convert() const
{
    ////////// Macierz sasiedztwa //////////
    std::ofstream adjMatrixFile;

    if (!adjMatrixFile.is_open())
    {
        adjMatrixFile.open("MacierzSasiedztwa.txt", std::ios::out);

        if(!adjMatrixFile)
        {
            std::cerr << "Failed to open " << "MacierzSasiedztwa.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    adjMatrixFile << "MS" << std::endl;

    int ** adjMatrix = new int * [m_numOfVer];
    for(int i = 0; i < m_numOfVer; ++i)
    {
        adjMatrix[i] = new int [m_numOfVer];
        for(int j = 0; j < m_numOfVer; ++j)
        {
            adjMatrix[i][j] = 0;
        }
    }


    for(int i = 0; i < m_numOfVer; ++i)
    {
        for(int j = 0; j < m_adjList[i].size(); ++j)
        {
            adjMatrix[i][m_adjList[i][j] - 1] = 1;
        }

        for(int j = 0; j < m_numOfVer; ++j)
        {
            adjMatrixFile << adjMatrix[i][j] << " ";
        }
        adjMatrixFile << std::endl;
    }
    adjMatrixFile.close();


    ////////// Macierz incydencji //////////
    std::ofstream incMatrixFile;

    if (!incMatrixFile.is_open())
    {
        incMatrixFile.open("MacierzIncydencji.txt", std::ios::out);

        if(!incMatrixFile)
        {
            std::cerr << "Failed to open " << "MacierzIncydencji.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }


    int numOfEdges = 0;
    incMatrixFile << "MI" << std::endl;
    for(int i = 0; i < m_numOfVer; ++i)
        for(int j = i + 1; j < m_numOfVer; ++j)
            numOfEdges += adjMatrix[i][j];


    int ** incMatrix = new int * [numOfEdges];
    for(int i = 0; i < numOfEdges; ++i)
    {
        incMatrix[i] = new int [m_numOfVer];
        for(int j = 0; j < m_numOfVer; ++j)
        {
            incMatrix[i][j] = 0;
        }
    }

    int edge = 0;

    for(int i = 0; i < m_numOfVer; ++i)
    {
        for(int j = i + 1; j < m_numOfVer; ++j)
        {
            if(adjMatrix[i][j] == 1)
            {
                incMatrix[edge][i] = 1;
                incMatrix[edge][j] = 1;
                ++edge;
            }
        }
    }

    for(int j = 0; j < m_numOfVer; ++j)
    {
        for(int i = 0; i < edge; ++i)
        {
            if(incMatrix[i][j] == 1)
                incMatrixFile << "1 ";
            else
                incMatrixFile << "0 ";
        }
        incMatrixFile << std::endl;
    }
    incMatrixFile.close();

    for(int i = 0; i < m_numOfVer; ++i)
        delete [] adjMatrix[i];

    delete [] adjMatrix;

    for(int i = 0; i < numOfEdges; ++i)
        delete [] incMatrix[i];

    delete [] incMatrix;
}
