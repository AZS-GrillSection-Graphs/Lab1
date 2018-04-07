#ifndef ZAD1_RANDOMGRAPH_H
#define ZAD1_RANDOMGRAPH_H

#include "RandomGraphType.h"


class RandomGraph
{
public:
    RandomGraph(const char * drawType, const char * numOfVertexes, const char * probabilityOrAmount);
    ~RandomGraph();
private:
    RandomGraphType * m_randGraphType;
};

#endif //ZAD1_RANDOMGRAPH_H
