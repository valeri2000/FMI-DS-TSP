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

void Benchmark::plotTimeHeur(const std::map<std::string, std::vector<std::pair<unsigned, double>>>& m) {
    plt::backend("Agg");
    for(auto algo : m) {
        std::vector<double> x, y; // vertices X time
        for(const std::pair<unsigned, double>& p : algo.second) {
            x.push_back(p.first);
            y.push_back(p.second / 1000);
        }
        plt::named_plot(algo.first, x, y, "o-");
    }
    plt::title("Time comparison");
    plt::xlabel("Vertices");
    plt::ylabel("Time (in seconds)");
    plt::legend();
    plt::save("heurstics-time.png");
    plt::close();
}

void Benchmark::plotErrorHeur(const std::map<std::string, std::vector<std::pair<unsigned, double>>>& m) {
    plt::backend("Agg");
    for(auto algo : m) {
        std::vector<double> x, y; // vertices X error
        for(const std::pair<unsigned, double>& p : algo.second) {
            x.push_back(p.first);
            y.push_back(p.second);
        }
        plt::named_plot(algo.first, x, y, "o-");
    }
    plt::title("Error comparison");
    plt::xlabel("Vertices");
    plt::ylabel("Error (in %)");
    plt::legend();
    plt::save("heurstics-error.png");
    plt::close();
}

void Benchmark::runHeuristics(
    const std::vector<ISolution*>& sols,
    const std::vector<TestData*>& tests,
    const bool& shouldPlot // plot
) {
    std::map<std::string, std::vector<std::pair<unsigned, double>>> timeData;
    std::map<std::string, std::vector<std::pair<unsigned, double>>> errorData;
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
            double error = getErrorPerct(expectedCost, calculatedCost); 
            std::cout << "\tError of path cost: "
                      << error
                      << "%\n";
            std::cout << "\tBest tour cost: " << expectedCost << '\n';
            std::cout << "\tCalculated tour cost: " << calculatedCost << '\n';

            std::cout << "#############################################\n";

            timeData[sol->getName()].push_back(std::make_pair(test->getGraph()->V(), elapsedTime));
            errorData[sol->getName()].push_back(std::make_pair(test->getGraph()->V(), error));
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    if(shouldPlot) {
        plotTimeHeur(timeData);
        plotErrorHeur(errorData);
        std::cout << "Time comparison plot saved to 'heurstics-time.png'\n";
        std::cout << "Error comparison plot saved to 'heurstics-error.png'\n";
    }
}

void Benchmark::runRandomized(
   const std::vector<ISolution*>& sols,
   const unsigned& vertices,
   const unsigned& fromWeight,
   const unsigned& toWeight
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

    std::ofstream out("graph.txt");
    g.saveToFile(out);
    out.close();
    std::cout << "Generated graph saved to 'graph.txt'\n";
}

