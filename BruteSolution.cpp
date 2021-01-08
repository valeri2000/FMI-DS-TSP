#include "BruteSolution.h"
#include <algorithm>
#include <limits>

std::pair<double, std::vector<unsigned> > BruteSolution::run(const MatrixGraph* g) {
    double minCost = std::numeric_limits<double>::max();
    std::vector<unsigned> minPath;

    std::vector<unsigned> currentPath;
    unsigned vertices = g->V();
    for(unsigned i = 0; i < vertices; ++i) {
        currentPath.push_back(i);
    }

    do {
        if(currentPath[0] == 1) {
            break;
        }

        double currentCost = 0, w;
        for(unsigned i = 0; i < vertices - 1; ++i) {
            w = g->adjacentRow(currentPath[i])[currentPath[i + 1]];
            currentCost += w;
        }
        w = g->adjacentRow(currentPath.back())[currentPath[0]];
        currentCost += w;

        if(currentCost < minCost) {
            minCost = currentCost;
            minPath = currentPath;
            minPath.push_back(currentPath[0]);
        }
    } while(std::next_permutation(currentPath.begin(), currentPath.end()));

    return std::make_pair(minCost, minPath);
}

std::string BruteSolution::getName() const {
    return "Brute Force Solution";
}

