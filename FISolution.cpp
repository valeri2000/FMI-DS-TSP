#include "FISolution.h"
#include <iostream>
#include <climits>

unsigned FISolution::getMaxUnvisitedOf(const unsigned& u, const std::vector<bool>& visited) {
    unsigned bestVertex = 0;
    unsigned maxEdge = 0;

    const std::vector<unsigned>& matrixRow = g->adjacentRow(u);
    unsigned currVertex = 0;
    for(const unsigned& w : matrixRow) {
        if(!visited[currVertex] && w > maxEdge) {
            bestVertex = currVertex;
            maxEdge = w;
        }
        ++currVertex;
    }

    return bestVertex;
}

FISolution::FISolution(const MatrixGraph& _g) {
    g = &_g;
}

std::pair<unsigned, std::vector<unsigned> > FISolution::run() {
    unsigned vertices = g->V();
    std::vector<bool> visited(vertices, false);

    std::vector<unsigned> path;
    visited[0] = true;
    path.push_back(0);

    unsigned newFarthest = getMaxUnvisitedOf(0, visited);
    visited[newFarthest] = true;
    path.push_back(newFarthest);
    path.push_back(0);

    std::vector<unsigned> minDistances(vertices, UINT_MAX);
    for(unsigned i = 0; i < vertices; ++i) {
        if(!visited[i]) {
            minDistances[i] = std::min(minDistances[i], g->adjacentRow(newFarthest)[i]);
            minDistances[i] = std::min(minDistances[i], g->adjacentRow(0)[i]);
        }
    }

    unsigned left = vertices - 2;
    while(left) {
        unsigned maxDist = 0;
        for(unsigned i = 0; i < vertices; ++i) {
            if(!visited[i] && maxDist < minDistances[i]) {
                maxDist = minDistances[i];
                newFarthest = i;
            }
        }
        visited[newFarthest] = true;

        for(unsigned i = 0; i < vertices; ++i) {
            if(!visited[i]) {
                minDistances[i] = std::min(minDistances[i], g->adjacentRow(newFarthest)[i]);
            }
        }

        unsigned tourSize = path.size();
        unsigned bestPos = 0;
        long long bestDiff = LLONG_MAX;
        for(unsigned i = 0; i < tourSize - 1; ++i) {
            unsigned u = path[i], v = path[i + 1];

            unsigned newCost = g->adjacentRow(u)[newFarthest] + g->adjacentRow(newFarthest)[v];
            unsigned currCost = g->adjacentRow(u)[v];

            long long currDiff = (long long)(newCost) - (long long)(currCost);
            if(currDiff < bestDiff) {
                bestDiff = currDiff;
                bestPos = i;
            }
        }

        std::vector<unsigned> newPath;
        for(unsigned i = 0; i < tourSize; ++i) {
            newPath.push_back(path[i]);
            if(i == bestPos) {
                newPath.push_back(newFarthest);
            }
        }
        path = newPath;

        left--;
    }

    unsigned cost = 0;
    for(unsigned i = 0; i < vertices; ++i) {
        cost += g->adjacentRow(path[i])[path[i + 1]];
    }

    std::cout << "Farthest insertion\n";
    return std::make_pair(cost, path);
}

