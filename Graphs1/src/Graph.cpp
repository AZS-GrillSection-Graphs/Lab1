#include "Graph.h"


Graph::Graph(const char * inputFileName) : m_graphRepr(NULL)
{
    std::ifstream inputFile;

    if (!inputFile.is_open())
    {
        inputFile.open(inputFileName, std::ios::in);

        if(!inputFile)
        {
            std::cerr << "Failed to open " << inputFileName << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    std::getline(inputFile, m_reprType);
    try
    {
        if(m_reprType != "MS" && m_reprType != "LS" && m_reprType != "MI")
            throw "Not known graph representation";
    }
    catch (const char * exceptionName)
    {
        std::cerr << exceptionName;
        exit(EXIT_FAILURE);
    }

    if(m_reprType == "MS")
        m_graphRepr = new AdjacencyMatrix(inputFile);
    else if(m_reprType == "LS")
        m_graphRepr = new AdjacencyList(inputFile);
    else if(m_reprType == "MI")
        m_graphRepr = new IncidenceMatrix(inputFile);

    inputFile.close();
}

Graph::~Graph()
{
    delete m_graphRepr;
}

void Graph::Print() const
{
    std::cout << "Reprezentacja grafu: " << m_reprType << std::endl;

    m_graphRepr->Print();
}

void Graph::ConvertGraph() const
{
    m_graphRepr->Convert();
}
