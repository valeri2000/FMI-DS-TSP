#ifndef __DP_SOLUTION_H_INCLUDED
#define __DP_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

class DPSolution : public ISolution {
    public:
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;
        virtual std::string getName() const override;
};

#endif
