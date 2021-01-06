#ifndef __ISOLUTION_H_INCLUDED
#define __ISOLUTION_H_INCLUDED

#include "Graph.h"

class ISolution {
    public:
        virtual ~ISolution();
        virtual std::pair<unsigned, std::vector<unsigned> > run(const Graph&) = 0; // result, path
};

#endif
