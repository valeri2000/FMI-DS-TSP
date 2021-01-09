#ifndef __APP_H_INCLUDED
#define __APP_H_INCLUDED

#include "MatrixGraph.h"
#include "GraphGenerator.h"
#include "ISolution.h"
#include "BruteSolution.h"
#include "DPSolution.h"
#include "FISolution.h"
#include "NNSolution.h"
#include "TestData.h"
#include "Benchmark.h"
#include <iostream>

class App {
    private:
        static App* instance;
        App();

        std::vector<ISolution*> sols;
        std::vector<TestData*> tests;

        void addTest(const std::string&, const std::string&);
        void runAll();
        void runHeuristics();

    public:
        static App* getInstance();
        ~App();

        void run();
};

#endif
