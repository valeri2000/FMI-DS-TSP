#ifndef __DP_SOLUTION_H_INCLUDED
#define __DP_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

/// \brief Dynamic programming solution
class DPSolution : public ISolution {
    public:
        /// \brief Override main function of interface class
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;

        /// \brief Set different name for every solution
        virtual std::string getName() const override;
};

#endif
