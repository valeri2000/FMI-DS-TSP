#include "GraphGenerator.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>
#include <algorithm>

unsigned GraphGenerator::randBetween(const unsigned& left, const unsigned& right) {
    return left + rand() % (right - left) + 1;
}

void GraphGenerator::generate(std::ofstream& out, const unsigned& vertices,
                               const unsigned& edges,
                               const unsigned& fromWeight,
                               const unsigned& toWeight) {
    out << vertices << '\n';

    srand(time(NULL));
    std::set<std::pair<unsigned, unsigned> > used;

    std::vector<unsigned> permutation;
    for(unsigned i = 0 ; i < vertices; ++i) {
        permutation.push_back(i);
    }
    std::random_shuffle(permutation.begin(), permutation.end());

    for(unsigned i = 0; i < vertices - 1; ++i) {
        unsigned u = permutation[i];
        unsigned v = permutation[i + 1];

        used.insert(std::make_pair(u, v));
        unsigned w = randBetween(fromWeight, toWeight);

        out << u << ' ' << v << ' ' << w << '\n';
    }

    unsigned edgesLeft = edges;
    if(edges > vertices * (vertices - 1) / 2) {
        edgesLeft = vertices * (vertices - 1) / 2;
    }

    edgesLeft = edgesLeft - vertices + 1;
    while(edgesLeft) {
        unsigned u = randBetween(0, vertices - 2);
        unsigned v = randBetween(u + 1, vertices - 1);

        if(used.find(std::make_pair(u, v)) != used.end()) {
            continue;
        }

        used.insert(std::make_pair(u, v));
        unsigned w = randBetween(fromWeight, toWeight);

        out << u << ' ' << v << ' ' << w << '\n';

        edgesLeft--;
    }
}

