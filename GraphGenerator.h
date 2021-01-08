#ifndef __GRAPH_GENERATOR_H_INCLUDED
#define __GRAPH_GENERATOR_H_INCLUDED

#include <fstream>
#include "MatrixGraph.h"

class GraphGenerator {
    private:
        static double randBetween(const unsigned&, const unsigned&);

    public:
        GraphGenerator() = delete; // TODO, is it necessary

        static void generateToFile(std::ofstream&, const unsigned&, const unsigned&, const unsigned&);
        static MatrixGraph generate(const unsigned&, const unsigned&, const unsigned&);
};

#endif
