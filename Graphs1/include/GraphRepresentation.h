//
// Created by piotr on 05.04.18.
//
#ifndef LAB1_GRAPHREPRESENTATION_H
#define LAB1_GRAPHREPRESENTATION_H


class GraphRepresentation
{
public:
    virtual void Print() const = 0;
    virtual void Convert() const = 0;
    virtual ~GraphRepresentation() {}
};

#endif //LAB1_GRAPHREPRESENTATION_H
