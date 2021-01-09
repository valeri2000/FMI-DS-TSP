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

/// \brief Singleton class for the whole application
class App {
    private:
        static App* instance;
        App();

        std::vector<ISolution*> sols; ///< solutions to be run
        std::vector<TestData*> tests; ///< test data to be used

        /// \brief Function to add new test
        /// \param first 'const std::string' which is the input file name of the graph
        /// \param second 'const std::string' which is the input file name of the correct solution
        void addTest(const std::string&, const std::string&);

        /// \brief Function to run all solutions on randomized graph
        void runAll();

        /// \brief Function to run heuristics solutions on prepared test data
        void runHeuristics();

    public:
        static App* getInstance();
        ~App();

        /// \brief Function which is called on start up
        void run();
};

#endif
