#ifndef LAB1_ADJACENCYLIST_H
#define LAB1_ADJACENCYLIST_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "GraphRepresentation.h"

class AdjacencyList : public GraphRepresentation
{
public:
    explicit AdjacencyList(std::ifstream &inputFile);
    void Print() const override;
    void Convert() const override;

private:
    std::vector<std::vector<int> > m_adjList;
    int m_numOfVer;
};

#endif //LAB1_ADJACENCYLIST_H
