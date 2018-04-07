//
// Created by piotr on 06.04.18.
//

#ifndef ZAD1_RANDOMGRAPHPROBABILITY_H
#define ZAD1_RANDOMGRAPHPROBABILITY_H

#include "RandomGraphType.h"

class RandomGraphProbability : public RandomGraphType
{
public:
    RandomGraphProbability(const int numberOfVertexes, const double probabilityOfEdges);
    void CalculateProbability(const double probabilityOfEdges, int &random, int &probability) const;
    void FillAdjMatrix(const double probabilityOfEdges) const;
};

#endif //ZAD1_RANDOMGRAPHPROBABILITY_H
