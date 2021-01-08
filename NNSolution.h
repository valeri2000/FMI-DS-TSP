#ifndef __NN_SOLUTION_H_INCLUDED
#define __NN_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

class NNSolution : public ISolution {
    public:
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;
        virtual std::string getName() const override;
};

#endif
