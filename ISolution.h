#ifndef __ISOLUTION_H_INCLUDED
#define __ISOLUTION_H_INCLUDED

#include <vector>
#include <utility>

class ISolution {
    public:
        virtual ~ISolution() { }
        virtual std::pair<unsigned, std::vector<unsigned> > run() = 0; // result, path
};

#endif
