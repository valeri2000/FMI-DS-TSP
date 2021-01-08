#ifndef __BENCHMARK_H_INCLUDED
#define __BENCHMARK_H_INCLUDED

#include "TestData.h"
#include "ISolution.h"
#include "GraphGenerator.h"
#include <ctime>

class Benchmark {
    private:
        static clock_t fromTimer;

        static void startTimer();
        static double getElapsedTimeMS();
        static double getErrorPerct(const double&, const double&);

    public:
        static void runHeuristics(
            const std::vector<ISolution*>&,
            const std::vector<TestData*>&,
            const bool& // plot
        );

        static void runRandomized(
           const std::vector<ISolution*>&,
           const unsigned&,
           const unsigned&,
           const unsigned&,
           const bool& // plot
        );
};

#endif
