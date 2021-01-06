#ifndef __BRUTE_FORCE_SOLUTION_H_INCLUDED
#define __BRUTE_FORCE_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

class BruteSolution : public ISolution {
    private:
        const MatrixGraph* g;

    public:
        BruteSolution(const MatrixGraph&);

        virtual std::pair<unsigned, std::vector<unsigned> > run() override;
};

#endif
