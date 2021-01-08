#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(const unsigned& _vertices) {
    vertices = _vertices;
    edges = 0;

    matrix.resize(vertices, std::vector<double>(vertices, 0));
}

MatrixGraph::MatrixGraph(std::ifstream& in) {
    in >> vertices;
    edges = 0;
    matrix.resize(vertices, std::vector<double>(vertices, 0));

    unsigned u, v;
    double w;
    while(in) {
        in >> u >> v >> w;
        addEdge(u, v, w);
    }
}

const std::vector<double>& MatrixGraph::adjacentRow(const unsigned& u) const {
    return matrix[u];
}

void MatrixGraph::saveToFile(std::ofstream& out) const {
    out << vertices << '\n';

    for(unsigned i = 0; i < vertices; ++i) {
        for(unsigned j = i + 1; j < vertices; ++j) {
            if(matrix[i][j]) {
                out << i << ' ' << j << ' ' << matrix[i][j] << '\n';
            }
        }
    }
}

unsigned MatrixGraph::V() const {
    return vertices;
}

unsigned MatrixGraph::E() const {
    return edges;
}

void MatrixGraph::addEdge(const unsigned& u, const unsigned& v, const double& w) {
    matrix[u][v] = matrix[v][u] = w;
    edges++;
}

