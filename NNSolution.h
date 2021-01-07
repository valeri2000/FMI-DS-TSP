#ifndef __NN_SOLUTION_H_INCLUDED
#define __NN_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

class NNSolution : public ISolution {
    private:
        const MatrixGraph* g;

    public:
        NNSolution(const MatrixGraph&);

        virtual std::pair<unsigned, std::vector<unsigned> > run() override;
};

#endif
