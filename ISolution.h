#ifndef __ISOLUTION_H_INCLUDED
#define __ISOLUTION_H_INCLUDED

#include <vector>
#include <utility>
#include <iostream>

class ISolution {
    public:
        virtual ~ISolution() { }
        virtual std::pair<double, std::vector<unsigned> > run() = 0; // result, path
        virtual std::string getName() const = 0;
};

#endif
