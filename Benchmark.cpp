#include "Benchmark.h"
#include <cmath>
#include <iomanip>

clock_t Benchmark::fromTimer = clock();

void Benchmark::startTimer() {
    fromTimer = clock();
}

double Benchmark::getElapsedTimeMS() {
    clock_t endTimer = clock();
    return (double)(endTimer - fromTimer) * 1000 / CLOCKS_PER_SEC;
}

double Benchmark::getErrorPerct(const double& expected, const double& real) {
    return fabs(real - expected) / expected * 100;
}

void Benchmark::runHeuristics(
    const std::vector<ISolution*>& sols,
    const std::vector<TestData*>& tests,
    const bool& shouldPlot // plot
) {
    for(TestData* test : tests) {
        std::cout << "#############################################\n";
        std::cout << "Running test: " << test->getName() << '\n';

        std::pair<double, std::vector<unsigned> > res;
        double elapsedTime;
        std::cout << "#############################################\n";
        for(ISolution* sol : sols) {
            std::cout << "\tRunning " << sol->getName() << '\n';

            startTimer();
            res = sol->run(test->getGraph());
            elapsedTime = getElapsedTimeMS();

            std::cout << "\tTime: " << std::fixed << std::setprecision(3) << elapsedTime;
            std::cout << "ms\n";
            
            double expectedCost = test->getMinTourCost();
            double calculatedCost = res.first;
            std::cout << "\tError of path cost: "
                      << getErrorPerct(expectedCost, calculatedCost)
                      << "%\n";
            std::cout << "\tBest tour cost: " << expectedCost << '\n';
            std::cout << "\tCalculated tour cost: " << calculatedCost << '\n';

            std::cout << "#############################################\n";
        }
        std::cout << '\n';
    }

    std::cout << '\n';
}

void Benchmark::runRandomized(
   const std::vector<ISolution*>& sols,
   const unsigned& vertices,
   const unsigned& fromWeight,
   const unsigned& toWeight,
   const bool& // plot
) {
    MatrixGraph g = GraphGenerator::generate(vertices, fromWeight, toWeight);

    std::pair<double, std::vector<unsigned> > res;
    double elapsedTime;
    for(ISolution* sol : sols) {
        std::cout << "Running " << sol->getName() << '\n';

        startTimer();
        res = sol->run(&g);
        elapsedTime = getElapsedTimeMS();

        std::cout << "\tTime: " << std::fixed << std::setprecision(3) << elapsedTime;
        std::cout << "ms\n";
        
        double calculatedCost = res.first;
        std::cout << "\tCalculated tour cost: " << calculatedCost << '\n';
        std::cout << "\tPath: ";
        for(const unsigned& u : res.second) {
            std::cout << u << ' ';
        }
        std::cout << "\n\n";
    }

    std::cout << '\n';
}

