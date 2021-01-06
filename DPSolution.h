#ifndef __DP_SOLUTION_H_INCLUDED
#define __DP_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

class DPSolution : public ISolution {
    private:
        const MatrixGraph* g;

    public:
        DPSolution(const MatrixGraph&);

        virtual std::pair<unsigned, std::vector<unsigned> > run() override;
};

#endif
