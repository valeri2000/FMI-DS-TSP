#include "BruteSolution.h"
#include <algorithm>

BruteSolution::BruteSolution(const MatrixGraph& _g) {
    g = &_g;
}

std::pair<unsigned, std::vector<unsigned> > BruteSolution::run() {
    unsigned minCost = 0;
    std::vector<unsigned> minPath;

    std::vector<unsigned> currentPath;
    unsigned vertices = g->V();
    for(unsigned i = 0; i < vertices; ++i) {
        currentPath.push_back(i);
    }

    do {
        unsigned currentCost = 0, w;
        bool valid = true;
        for(unsigned i = 0; i < vertices - 1; ++i) {
            w = g->adjacentRow(currentPath[i])[currentPath[i + 1]];

            if(w == 0) {
                valid = false;
                break;
            }

            currentCost += w;
        }
        w = g->adjacentRow(currentPath.back())[currentPath[0]];
        if(w != 0 && valid) {
            currentCost += w;

            if(currentCost < minCost || minCost == 0) {
                minCost = currentCost;
                minPath = currentPath;
                minPath.push_back(currentPath[0]);
            }
        }
    } while(std::next_permutation(currentPath.begin(), currentPath.end()));

    return std::make_pair(minCost, minPath);
}

