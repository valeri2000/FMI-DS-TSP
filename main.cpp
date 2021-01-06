#include <iostream>
#include "BruteSolution.h"
#include "DPSolution.h"
#include "ISolution.h"
#include "GraphGenerator.h"

int main() {
    std::ofstream out("gen.txt");
    GraphGenerator::generate(out, 11, 1, 15);
    out.close();

    std::ifstream in("gen.txt");
    MatrixGraph g(in);

    std::cout << "Finished generating\n";

    ISolution* sol2 = new DPSolution(g);
    auto res = sol2->run();
    std::cout << res.first << " -> ";
    for(const unsigned& v : res.second) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
    delete sol2;

    ISolution* sol = new BruteSolution(g);
    res = sol->run();
    std::cout << res.first << " -> ";
    for(const unsigned& v : res.second) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
    delete sol;


    in.close();
    return 0;
}
