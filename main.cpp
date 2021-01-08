#include <iostream>
#include "BruteSolution.h"
#include "DPSolution.h"
#include "NNSolution.h"
#include "FISolution.h"
#include "ISolution.h"
#include "GraphGenerator.h"
#include "TestData.h"

int main() {
    std::ifstream t1("tests/dj38.tsp"), st1("tests/dj38-tour.txt");
    TestData T(t1, st1);
    t1.close();
    st1.close();
    ISolution* sol = new FISolution(T.getGraph());

    std::cout << sol->getName() << '\n';
    auto res = sol->run();
    std::cout << res.first << ": ";
    for(const unsigned& v : res.second) {
        std::cout << v << ' ';
    }
    std::cout << '\n';

    std::cout << "Test data name: " << T.getName() << '\n';
    std::cout << "Test data solution: " << T.getMinTourCost() << '\n';

    delete sol;
    //MatrixGraph g = GraphGenerator::generate(10, 1, 12);
    //std::vector<ISolution*> sols;

    //sols.push_back(new BruteSolution(g));
    //sols.push_back(new DPSolution(g));
    //sols.push_back(new NNSolution(g));
    //sols.push_back(new FISolution(g));

    //for(ISolution* sol : sols) {
        //auto res = sol->run();
        //std::cout << sol->getName() << '\n';
        //std::cout << res.first << ": ";
        //for(const unsigned v : res.second) {
            //std::cout << v << ' ';
        //}
        //std::cout << '\n';
        //std::cout << '\n';
    //}

    //for(ISolution* sol : sols) {
        //delete sol;
    //}

    return 0;
}

