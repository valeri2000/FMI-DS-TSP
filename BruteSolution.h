#ifndef __BRUTE_FORCE_SOLUTION_H_INCLUDED
#define __BRUTE_FORCE_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"

/// \brief Class for brute force solution
class BruteSolution : public ISolution {
    public:
        /// \brief Override main function of interface class
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;

        /// \brief Set different name for every solution
        virtual std::string getName() const override;
};

#endif
