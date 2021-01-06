#include <iostream>
#include "BruteSolution.h"
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
    in.close();
    return 0;
}
