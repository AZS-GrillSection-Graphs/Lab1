#ifndef ZAD1_RANDOMGRAPHTYPE_H
#define ZAD1_RANDOMGRAPHTYPE_H

#include <iostream>
#include <fstream>

class RandomGraphType
{
public:
    RandomGraphType(const int numberOfVertexes);
    virtual ~RandomGraphType();

protected:
    void CreateAdjMatrix();
    void PrintAdjMatrixToFile() const;

    static int iRand(const int min, const int max);

    int m_numberOfVertexes;
    int ** m_adjMatrix;
};


#endif //ZAD1_RANDOMGRAPHTYPE_H
