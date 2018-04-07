#ifndef LAB1_ADJACENCYMATRIX_H
#define LAB1_ADJACENCYMATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "GraphRepresentation.h"

class AdjacencyMatrix : public GraphRepresentation
{
public:
    explicit AdjacencyMatrix(std::ifstream &inputFile);
    void Print() const override;
    void Convert() const override;

private:
    std::vector<std::vector<int> > m_adjMatrix;
    int m_numOfVer;
};

#endif //LAB1_ADJACENCYMATRIX_H
