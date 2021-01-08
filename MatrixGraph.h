#ifndef __MATRIX_GRAPH_H_INCLUDED
#define __MATRIX_GRAPH_H_INCLUDED

#include <fstream>
#include <vector>

class MatrixGraph {
    private:
        unsigned vertices, edges;
        std::vector<std::vector<double> > matrix;

    public:
        MatrixGraph(const unsigned& = 0);
        MatrixGraph(std::ifstream&);

        void saveToFile(std::ofstream&) const;
        unsigned V() const;
        unsigned E() const;
        const std::vector<double>& adjacentRow(const unsigned&) const;

        void addEdge(const unsigned&, const unsigned&, const double&);
};

#endif
