#include <iostream>
#include "BruteSolution.h"
#include "DPSolution.h"
#include "NNSolution.h"
#include "FISolution.h"
#include "ISolution.h"
#include "GraphGenerator.h"

int main() {
    std::ofstream out("gen.txt");
    GraphGenerator::generate(out, 10, 1, 10);
    out.close();

    std::ifstream in("graph2.txt");
    MatrixGraph g(in);

    std::cout << "Finished generating\n\n";

    ISolution* sol3 = new NNSolution(g);
    auto res = sol3->run();
    std::cout << res.first << " -> ";
    for(const unsigned& v : res.second) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
    delete sol3;

    ISolution* sol4 = new FISolution(g);
    res = sol4->run();
    std::cout << res.first << " -> ";
    for(const unsigned& v : res.second) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
    delete sol4;

    ISolution* sol2 = new DPSolution(g);
    res = sol2->run();
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

