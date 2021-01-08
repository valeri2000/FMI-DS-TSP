#include <iostream>
#include "BruteSolution.h"
#include "DPSolution.h"
#include "NNSolution.h"
#include "FISolution.h"
#include "ISolution.h"
#include "GraphGenerator.h"
#include "TestData.h"
#include "Benchmark.h"

int main() {
    std::ifstream t1("tests/dj38.tsp"), st1("tests/dj38-tour.txt");
    TestData T1(t1, st1);
    t1.close();
    st1.close();

    t1.open("tests/ar9152.tsp");
    st1.open("tests/ar9152-tour.txt");
    TestData T2(t1, st1);
    t1.close();
    st1.close();

    t1.open("tests/ho14473.tsp");
    st1.open("tests/ho14473-tour.txt");
    TestData T3(t1, st1);
    t1.close();
    st1.close();

    std::vector<TestData*> tests;
    tests.push_back(&T1);
    tests.push_back(&T2);
    tests.push_back(&T3);

    std::vector<ISolution*> sols;
    sols.push_back(new NNSolution());
    sols.push_back(new FISolution());
    sols.push_back(new BruteSolution());
    sols.push_back(new DPSolution());

    Benchmark::runRandomized(sols, 10, 1, 15, false);
    sols.pop_back();
    sols.pop_back();
    Benchmark::runHeuristics(sols, tests, false);

    return 0;
}

