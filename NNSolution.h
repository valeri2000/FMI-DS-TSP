#ifndef __NN_SOLUTION_H_INCLUDED
#define __NN_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

/// \brief Nearest neighbour solution
class NNSolution : public ISolution {
    public:
        /// \brief Override main function of interface class
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;

        /// \brief Set different name for every solution
        virtual std::string getName() const override;
};

#endif
