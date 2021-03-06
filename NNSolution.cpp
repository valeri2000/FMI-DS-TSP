#include "NNSolution.h"
#include <limits>

std::pair<double, std::vector<unsigned> > NNSolution::run(const MatrixGraph* g) {
    unsigned vertices = g->V();
    std::vector<bool> visited(vertices, false);

    double cost = 0;
    std::vector<unsigned> path;

    path.push_back(0);
    visited[0] = true;
    unsigned left = vertices - 1;
    while(left) {
        unsigned lastVertex = path.back();
        unsigned newVertex;
        double minEdge = std::numeric_limits<double>::max();
        const std::vector<double>& edges = g->adjacentRow(lastVertex);

        for(unsigned i = 0; i < vertices; ++i) {
            if(!visited[i] && minEdge > edges[i]) {
                newVertex = i;
                minEdge = edges[i];
            }
        }
        visited[newVertex] = true;
        left--;
        path.push_back(newVertex);
        cost += minEdge;
    }
    cost += g->adjacentRow(path.back())[0];
    path.push_back(0);

    return std::make_pair(cost, path);
}

std::string NNSolution::getName() const {
    return "Nearest Neighbour solution";
}

