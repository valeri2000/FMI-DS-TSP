#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(const unsigned& _vertices) {
    vertices = _vertices;
    edges = 0;

    matrix.resize(vertices, std::vector<unsigned>(vertices, 0));
}

MatrixGraph::MatrixGraph(std::ifstream& in) {
    in >> vertices;
    edges = 0;
    matrix.resize(vertices, std::vector<unsigned>(vertices, 0));

    unsigned u, v, w;
    while(in) {
        in >> u >> v >> w;
        addEdge(u, v, w);
    }
}

const std::vector<unsigned>& MatrixGraph::adjacentRow(const unsigned& u) const {
    return matrix[u];
}

void MatrixGraph::saveToFile(std::ofstream& out) const {
    out << vertices << '\n';

    unsigned pEdges = 0;
    for(unsigned i = 0; i < vertices; ++i) {
        for(unsigned j = i + 1; j < vertices; ++j) {
            if(matrix[i][j]) {
                out << i << ' ' << j << ' ' << matrix[i][j] << '\n';
                pEdges++;
            }
        }
    }

    assert(pEdges == edges);
}

unsigned MatrixGraph::V() const {
    return vertices;
}

unsigned MatrixGraph::E() const {
    return edges;
}

void MatrixGraph::addEdge(const unsigned& u, const unsigned& v, const unsigned& w) {
    matrix[u][v] = matrix[v][u] = w;
    edges++;
}

bool MatrixGraph::isMatrixRepr() const {
    return true;
}

