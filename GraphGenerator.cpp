#include "GraphGenerator.h"
#include <ctime>
#include <cstdlib>
#include <set>

unsigned GraphGenerator::randBetween(const unsigned& left, const unsigned& right) {
    return left + rand() % (right - left) + 1;
}

Graph GraphGenerator::generate(const unsigned& vertices,
                               const unsigned& edges,
                               const unsigned& fromWeight,
                               const unsigned& toWeight) {
    Graph g(vertices);
    srand(time(NULL));

    std::set<std::pair<unsigned, unsigned> > used;
    unsigned edgesLeft = edges;
    while(edgesLeft) {
        unsigned u = randBetween(0, vertices - 2);
        unsigned v = randBetween(u + 1, vertices - 1);

        if(used.find(std::make_pair(u, v)) != used.end()) {
            continue;
        }

        used.insert(std::make_pair(u, v));
        unsigned w = randBetween(fromWeight, toWeight);
        g.addEdge(u, v, w);

        edgesLeft--;
    }

    return g;
}
