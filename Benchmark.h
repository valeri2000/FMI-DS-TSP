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

/// \brief Class which is responsible for benchmarking
class Benchmark {
    private:
        static clock_t fromTimer; ///< static field, saved time before running a solution

        /// \brief Static function to save time before running a solution
        static void startTimer(); 

        /// \brief Static function to calculated running time of a solution
        /// \return 'double' which is the time in ms
        static double getElapsedTimeMS();

        /// \brief Static function to calculate error percentage
        /// \param first 'double' which is expected value
        /// \param second 'double' which is the actual value
        /// \return 'double' which is the error percentage
        static double getErrorPerct(const double&, const double&);

        /// \brief Static function responsible for plotting time result for heurstic solutions
        /// \param first map solution name to vector of number of vertices in test and time for every test
        static void plotTimeHeur(const std::map<std::string, std::vector<std::pair<unsigned, double>>>&);
        //
        /// \brief Static function responsible for plotting error result for heurstic solutions
        /// \param first map solution name to vector of number of vertices in test and error % for every test
        static void plotErrorHeur(const std::map<std::string, std::vector<std::pair<unsigned, double>>>&);

    public:
        /// \brief Static function which performs heuristics benchmark
        /// \param first 'const std::vector<ISolution*>' which is a vector of solutions
        /// \param second 'const std::vector<TestData*>' which is a vector of tests
        /// \param third 'bool' which tells whether to plot results or not
        static void runHeuristics(
            const std::vector<ISolution*>&,
            const std::vector<TestData*>&,
            const bool&
        );

        /// \brief Static function which performs full benchmark on randomized graph
        /// \param first 'const std::vector<ISolution*>' which is a vector of solutions
        /// \param second 'const unsigned' which is number of vertices for the graph
        /// \param third 'const unsigned' which is the minimum edge cost
        /// \param forth 'const unsigned' which is the maximum edge cost
        static void runRandomized(
           const std::vector<ISolution*>&,
           const unsigned&,
           const unsigned&,
           const unsigned&
        );
};

#endif
