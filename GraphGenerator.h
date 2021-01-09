#ifndef __GRAPH_GENERATOR_H_INCLUDED
#define __GRAPH_GENERATOR_H_INCLUDED

#include <fstream>
#include "MatrixGraph.h"

/// \brief Class which generates complete graph with weights
class GraphGenerator {
    private:
        /// \brief Generate random number in interval
        /// \param first 'const unsigned' which is left number
        /// \param second 'const unsigned' which is right number
        /// \return 'double' which is the number converted to double
        static double randBetween(const unsigned&, const unsigned&);

    public:
        /// \brief Constructor is not allowed
        GraphGenerator() = delete;

        /// \brief Static function to generate graph to file
        /// \param first 'std::ofstream' which is output stream
        /// \param second 'const unsigned' which is the number of vertices
        /// \param third 'const unsigned' which is the minimum weight of edge
        /// \param forth 'const unsigned' which is the maximum weight of edge
        static void generateToFile(std::ofstream&, const unsigned&, const unsigned&, const unsigned&);

        /// \brief Static function to generate graph internally
        /// \param first 'const unsigned' which is the number of vertices
        /// \param second 'const unsigned' which is the minimum weight of edge
        /// \param third 'const unsigned' which is the maximum weight of edge
        /// \return 'MatrixGraph' which is a matrix representation of the graph
        static MatrixGraph generate(const unsigned&, const unsigned&, const unsigned&);
};

#endif
