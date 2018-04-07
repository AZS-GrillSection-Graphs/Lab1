//
// Created by piotr on 02.04.18.
//
#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "GraphRepresentation.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"


class Graph
{
public:
    explicit Graph(const char * inputFileName);
    ~Graph();
    void Print() const;
    void ConvertGraph() const;


private:
    std::string m_reprType;

    GraphRepresentation * m_graphRepr;
};

#endif //LAB1_GRAPH_H
