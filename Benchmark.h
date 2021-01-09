#ifndef __BENCHMARK_H_INCLUDED
#define __BENCHMARK_H_INCLUDED

#include "TestData.h"
#include "ISolution.h"
#include "GraphGenerator.h"
#include <ctime>
#include <map>
#include <utility>

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

class Benchmark {
    private:
        static clock_t fromTimer;

        static void startTimer();
        static double getElapsedTimeMS();
        static double getErrorPerct(const double&, const double&);
        static void plotTimeHeur(const std::map<std::string, std::vector<std::pair<unsigned, double>>>&);
        static void plotErrorHeur(const std::map<std::string, std::vector<std::pair<unsigned, double>>>&);

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
           const unsigned&
        );
};

#endif
