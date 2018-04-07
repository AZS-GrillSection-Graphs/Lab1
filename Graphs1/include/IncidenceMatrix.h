#ifndef LAB1_INCIDENCEMATRIX_H
#define LAB1_INCIDENCEMATRIX_H

#include "GraphRepresentation.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"


class IncidenceMatrix : public GraphRepresentation
{
public:
    explicit IncidenceMatrix(std::ifstream &inputFile);
    void Print() const override;
    void Convert() const override;

private:
    std::vector<std::vector<int> > m_incMatrix;
    int m_numOfVer;
    int m_numOfEdges;
};

#endif //LAB1_INCIDENCEMATRIX_H
