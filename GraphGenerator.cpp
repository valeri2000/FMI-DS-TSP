#include "GraphGenerator.h"
#include <ctime>
#include <cstdlib>

double GraphGenerator::randBetween(const unsigned& left, const unsigned& right) {
    return 1.0 * (left + rand() % (right - left + 1));
}

void GraphGenerator::generateToFile(std::ofstream& out, 
                              const unsigned& vertices,
                              const unsigned& fromWeight,
                              const unsigned& toWeight) {
    srand(time(NULL));

    out << vertices << '\n';
    for(unsigned i = 0; i < vertices - 1; ++i) {
        for(unsigned j = i + 1; j < vertices; ++j) {
            out << i << ' ' << j << ' ' << randBetween(fromWeight, toWeight) << '\n';
        }
    }
}

MatrixGraph GraphGenerator::generate(
                                    const unsigned& vertices, 
                                    const unsigned& fromWeight, 
                                    const unsigned& toWeight) {
    MatrixGraph g(vertices);
    srand(time(NULL));

    for(unsigned i = 0; i < vertices - 1; ++i) {
        for(unsigned j = i + 1; j < vertices; ++j) {
            g.addEdge(i, j, randBetween(fromWeight, toWeight));
        }
    }

    return g;
}
