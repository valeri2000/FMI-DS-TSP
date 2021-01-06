#include "DPSolution.h"
#include <climits>

DPSolution::DPSolution(const MatrixGraph& _g) {
    g = &_g;
}

std::pair<unsigned, std::vector<unsigned> > DPSolution::run() {
    unsigned vertices = g->V();
    unsigned lim_set = (1 << vertices) - 1;

    std::vector<std::vector<unsigned> > dp(
        vertices,
        std::vector<unsigned>(lim_set, UINT_MAX)
    );

    std::vector<std::vector<std::pair<unsigned, unsigned> > > memo(
        vertices,
        std::vector<std::pair<unsigned, unsigned> >(lim_set, std::make_pair(0, 0))
    );

    for(unsigned i = 1; i < vertices; ++i) {
        dp[i][(1 << i)] = g->adjacentRow(0)[i];
    }

    for(unsigned set = 2; set < lim_set; ++set) {
        for(unsigned last = 1; last < vertices; ++last) {
            if((1 << last) & set) {
                unsigned new_set = set ^ (1 << last);

                for(unsigned last2 = 1; last2 < vertices; ++last2) {
                    if(last == last2) {
                        continue;
                    }

                    if((1 << last2) & new_set) {
                        unsigned w = g->adjacentRow(last2)[last];

                        if(dp[last][set] > dp[last2][new_set] + w) {
                            dp[last][set] = dp[last2][new_set] + w;
                            memo[last][set] = std::make_pair(last2, new_set);
                        }
                    }
                }
            }
        }
    }

    unsigned minCost = UINT_MAX;
    unsigned saveVertex, saveSet = lim_set - 1;
    for(unsigned i = 1; i < vertices; ++i) {
        unsigned w = g->adjacentRow(i)[0];
        unsigned currentCost = dp[i][lim_set - 1] + w;

        if(minCost > currentCost) {
            minCost = currentCost;
            saveVertex = i;
        }
    }

    std::vector<unsigned> path;
    path.push_back(0);
    std::pair<unsigned, unsigned> nullPair = std::make_pair(0, 0);
    while(memo[saveVertex][saveSet] != nullPair) {
        path.push_back(saveVertex);
        unsigned newVertex = memo[saveVertex][saveSet].first;
        unsigned newSet = memo[saveVertex][saveSet].second;
        saveVertex = newVertex;
        saveSet = newSet;
    }
    path.push_back(saveVertex);
    path.push_back(0);

    return std::make_pair(minCost, path);
}

