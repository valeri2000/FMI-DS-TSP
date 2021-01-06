#include <iostream>
#include "BruteSolution.h"
#include "DPSolution.h"
#include "ISolution.h"

int main() {
    std::ifstream in("graph1.txt");
    MatrixGraph g(in);

    ISolution* sol = new BruteSolution(g);
    auto res = sol->run();
    std::cout << res.first << " -> ";
    for(const unsigned& v : res.second) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
    delete sol;

    ISolution* sol2 = new DPSolution(g);
    res = sol->run();
    std::cout << res.first << " -> ";
    for(const unsigned& v : res.second) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
    delete sol2;

    in.close();
    return 0;
}
