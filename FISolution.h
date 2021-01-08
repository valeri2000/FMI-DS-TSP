#ifndef __FI_SOLUTION_H_INCLUDED
#define __FI_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

class FISolution : public ISolution {
    private:
        const MatrixGraph* g;

        unsigned getMaxUnvisitedOf(const unsigned&, const std::vector<bool>&);

    public:
        FISolution(const MatrixGraph&);
        FISolution(const MatrixGraph*);

        virtual std::pair<double, std::vector<unsigned> > run() override;
        virtual std::string getName() const override;
};

#endif
