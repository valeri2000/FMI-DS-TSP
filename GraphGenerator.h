#ifndef __GRAPH_GENERATOR_H_INCLUDED
#define __GRAPH_GENERATOR_H_INCLUDED

#include "Graph.h"

class GraphGenerator {
    private:
        static unsigned randBetween(const unsigned&, const unsigned&);

    public:
        GraphGenerator() = delete; // TODO, is it necessary

        static Graph generate(const unsigned&, const unsigned&, const unsigned&, const unsigned&);
};

#endif
