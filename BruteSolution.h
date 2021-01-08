#ifndef __BRUTE_FORCE_SOLUTION_H_INCLUDED
#define __BRUTE_FORCE_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

class BruteSolution : public ISolution {
    public:
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;
        virtual std::string getName() const override;
};

#endif
