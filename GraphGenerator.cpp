#include "GraphGenerator.h"
#include <ctime>
#include <cstdlib>

unsigned GraphGenerator::randBetween(const unsigned& left, const unsigned& right) {
    return left + rand() % (right - left + 1);
}

void GraphGenerator::generate(std::ofstream& out, 
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

