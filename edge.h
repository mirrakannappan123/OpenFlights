#pragma once 

#include <string>
#include <limits.h>

using std::string;

typedef string Vertex;

/**
 * Represents an edge in a graph; used by the Graph class.
 * using code from lab_ml
 */
class Edge
{
  public:
    Vertex source; /**< The source of the edge **/
    Vertex dest; /**< The destination of the edge **/
    /**
     * Parameter constructor for weighted graphs.
     * @param first - one vertex the edge is connected to
     * @param next - the other vertex it is connected to
     * @param weig - the weight of the edge
     * @param label - the edge label
     */
    Edge(Vertex first, Vertex next, double weig, string label)
        : source(first), dest(next), weight(weig), label(label)
    { /* nothing */
    }

    Edge() : source(""), dest(""), label(""), weight(-1)
    { /* nothing */
    }

     Edge(Vertex u, Vertex v)
        : source(u), dest(v), label(""), weight(-1)
    { /* nothing */
    }
    /**
     * Compares two Edges.
     * operator< is defined so Edges can be sorted with std::sort.
     * @param other - the edge to compare with
     * @return whether the current edge is less than the parameter
     */
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }

    string getLabel() const
    {
        return this->label;
    }

    void setLabel(string lbl)
    {
        this->label = lbl;
    }
    /**
     * sets edge weight.
     */
    int setWeight(double w) const
    {
        w = weight; 
    }
    /**
     * Gets edge weight.
     */
    int getWeight() const
    {
        return this->weight;
    }

    /**
     * Compares two edges' source and dest.
     * @param other - the edge to compare with
     */
    bool operator==(Edge& other) const
    {
        if (this->source != other.source)
            return false;
        if (this->dest != other.dest)
            return false;
        return true;
    }
private:
    string label;
    double weight; 
};