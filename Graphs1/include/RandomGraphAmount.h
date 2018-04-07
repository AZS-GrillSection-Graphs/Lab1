#ifndef ZAD1_RANDOMGRAPHAMOUNT_H
#define ZAD1_RANDOMGRAPHAMOUNT_H

#include "RandomGraphType.h"

class RandomGraphAmount : public RandomGraphType
{
public:
    RandomGraphAmount(const int numberOfVertexes, const int amountOfEdges);
    void FillAdjMatrix(const int amountOfEdges) const;
};


#endif //ZAD1_RANDOMGRAPHAMOUNT_H
