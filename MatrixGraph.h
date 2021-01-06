#ifndef __MATRIX_GRAPH_H_INCLUDED
#define __MATRIX_GRAPH_H_INCLUDED

#include "IGraph.h"
#include <vector>

class MatrixGraph : public IGraph {
    private:
        unsigned vertices, edges;
        std::vector<std::vector<unsigned> > matrix;

    public:
        MatrixGraph(const unsigned& = 0);
        MatrixGraph(std::ifstream&);

        const std::vector<unsigned>& adjacentRow(const unsigned&) const;

        virtual void saveToFile(std::ofstream&) const override;
        virtual unsigned V() const override;
        virtual unsigned E() const override;
        virtual void addEdge(const unsigned&, const unsigned&, const unsigned&) override;
        virtual bool isMatrixRepr() const override;
};

#endif
