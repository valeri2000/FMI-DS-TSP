#include <iostream>
#include "BruteSolution.h"
#include "DPSolution.h"
#include "NNSolution.h"
#include "FISolution.h"
#include "ISolution.h"
#include "GraphGenerator.h"

int main() {
    MatrixGraph g = GraphGenerator::generate(11, 1, 12);
    std::vector<ISolution*> sols;

    sols.push_back(new BruteSolution(g));
    sols.push_back(new DPSolution(g));
    sols.push_back(new NNSolution(g));
    sols.push_back(new FISolution(g));

    for(ISolution* sol : sols) {
        auto res = sol->run();
        std::cout << sol->getName() << '\n';
        std::cout << res.first << ": ";
        for(const unsigned v : res.second) {
            std::cout << v << ' ';
        }
        std::cout << '\n';
        std::cout << '\n';
    }

    for(ISolution* sol : sols) {
        delete sol;
    }

    return 0;
}

