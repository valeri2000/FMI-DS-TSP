#include "App.h"

App* App::instance = nullptr;

App::App() {
    addTest("tests/dj38.tsp", "tests/dj38-tour.txt");
    addTest("tests/xqg237.tsp", "tests/xqg237-tour.txt");
    addTest("tests/dka1376.tsp", "tests/dka1376-tour.txt");
    addTest("tests/ar9152.tsp", "tests/ar9152-tour.txt");
    addTest("tests/ho14473.tsp", "tests/ho14473-tour.txt");

    sols.push_back(new NNSolution());
    sols.push_back(new FISolution());
    sols.push_back(new BruteSolution());
    sols.push_back(new DPSolution());

    std::cout << "Loaded test data and solutions!\n\n";
}

void App::addTest(const std::string& nameIn, const std::string& nameSol) {
    std::ifstream in(nameIn);
    std::ifstream inSol(nameSol);

    TestData* test = new TestData(in, inSol);
    tests.push_back(test);
}

void App::runAll() {
    unsigned vertices = 13;
    while(vertices > 12) {
        std::cout << "Select number of vertices (less than 13): ";
        std::cin >> vertices;
    }
    unsigned fromWeight = 1002, toWeight = 1001;
    while(fromWeight > toWeight || toWeight > 1000) {
        std::cout << "Select weight range, max allowed is 1000 (<from this number> <to this number>): ";
        std::cin >> fromWeight >> toWeight;
    }

    std::cout << '\n';
    Benchmark::runRandomized(sols, vertices, fromWeight, toWeight);
}

void App::runHeuristics() {
    delete sols.back();
    sols.pop_back();
    delete sols.back();
    sols.pop_back();

    Benchmark::runHeuristics(sols, tests, true);
}
 
App* App::getInstance() {
    if(!instance) {
        instance = new App();
    }

    return instance;
}

App::~App() {
    for(ISolution* sol : sols) {
        delete sol;
    }
    for(TestData* test : tests) {
        delete test;
    }
}

void App::run() {
    std::cout << "Options:\n";
    std::cout << "(1) Run all algorithms on a random graph with specified number of vertices.\n";
    std::cout << "(2) Run and plot heuristic algorithms on a prepared test data.\n";

    bool good = false;
    std::string input;
    while(!good) {
        std::cout << "Choice: ";

        std::cin >> input;
        if(input == "1") {
            good = true;
            runAll();
        } else if(input == "2") {
            good = true;
            runHeuristics();
        } else {
            std::cout << "You should type '1' or '2'!\n\n";
        }
    }
}

