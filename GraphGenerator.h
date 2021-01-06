#ifndef __GRAPH_GENERATOR_H_INCLUDED
#define __GRAPH_GENERATOR_H_INCLUDED

#include <fstream>

class GraphGenerator {
    private:
        static unsigned randBetween(const unsigned&, const unsigned&);

    public:
        GraphGenerator() = delete; // TODO, is it necessary

        static void generate(std::ofstream&, const unsigned&, const unsigned&, const unsigned&);
};

#endif
