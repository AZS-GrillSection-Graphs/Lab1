#include "IncidenceMatrix.h"


IncidenceMatrix::IncidenceMatrix(std::ifstream &inputFile) : m_numOfVer(0)
{
    std::vector<std::vector <int> >row;
    std::string line;

    while(getline(inputFile, line))
    {
        ++m_numOfVer;
        m_numOfEdges = 0;

        std::istringstream streamLine(line);
        std::vector<int> col;

        while(!streamLine.eof())
        {
            int value;
            streamLine >> value;

            if(streamLine.fail())
                break;

            col.push_back(value);
            ++m_numOfEdges;
        }

        m_incMatrix.push_back(col);
    }
}

void IncidenceMatrix::Print() const
{
    for(int i = 0; i < m_numOfVer; ++i)
    {
        for(int j = 0; j < m_numOfEdges; ++j)
        {
            std::cout << m_incMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void IncidenceMatrix::Convert() const
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


    int vertexStart = 0;
    int vertexEnd = 0;
    bool ifStart = false;


    for(int i = 0; i < m_numOfEdges; ++i)
    {
        for(int j = 0; j < m_numOfVer; ++j)
        {
            if(m_incMatrix[j][i] == 1 && !ifStart)
            {
                ifStart = true;
                vertexStart = j;
            }
            else if(m_incMatrix[j][i] == 1 && ifStart)
            {
                ifStart = false;
                vertexEnd = j;
                adjMatrix[vertexStart][vertexEnd] = 1;
                adjMatrix[vertexEnd][vertexStart] = 1;
            }
        }
    }

    for(int i = 0; i < m_numOfVer; ++i)
    {
        for(int j = 0; j < m_numOfVer; ++j)
        {
            adjMatrixFile << adjMatrix[i][j] << " ";
        }
        adjMatrixFile << std::endl;
    }

    adjMatrixFile.close();



    ////////// Lista sasiedztwa //////////
    std::ofstream adjListFile;

    if (!adjListFile.is_open())
    {
        adjListFile.open("ListaSasiedztwa.txt", std::ios::out);

        if(!adjListFile)
        {
            std::cerr << "Failed to open " << "ListaSasiedztwa.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    adjListFile << "LS" << std::endl;

    for(int i = 0; i < m_numOfVer; ++i)
    {
        for(int j = 0; j < m_numOfVer; ++j)
        {
            if(adjMatrix[i][j] == 1)
            {
                adjListFile << j + 1 << " ";
            }
        }
        adjListFile << std::endl;
    }
    adjListFile.close();

    for(int i = 0; i < m_numOfVer; ++i)
        delete [] adjMatrix[i];

    delete [] adjMatrix;
}
