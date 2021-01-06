#ifndef __ISOLUTION_H_INCLUDED
#define __ISOLUTION_H_INCLUDED

#include "IGraph.h"
#include <vector>
#include <utility>

class ISolution {
    public:
        virtual ~ISolution();
        virtual std::pair<unsigned, std::vector<unsigned> > run(IGraph*) = 0; // result, path
};

#endif
