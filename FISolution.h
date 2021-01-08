#ifndef __FI_SOLUTION_H_INCLUDED
#define __FI_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"
#include <unordered_set>

class FISolution : public ISolution {
    private:
        unsigned getMaxUnvisitedOf(const unsigned&, const MatrixGraph*, 
                                   const std::vector<bool>&);

    public:
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;
        virtual std::string getName() const override;
};

#endif
