#ifndef __IGRAPH_H_INCLUDED
#define __IGRAPH_H_INCLUDED

#include <fstream>

class IGraph {
    public:
        virtual ~IGraph();

        virtual void saveToFile(std::ofstream&) const = 0;
        virtual unsigned V() const = 0;
        virtual unsigned E() const = 0;

        virtual void addEdge(const unsigned&, const unsigned&, const unsigned&) = 0;

        virtual bool isMatrixRepr() const = 0;
};

#endif
