#ifndef __ISOLUTION_H_INCLUDED
#define __ISOLUTION_H_INCLUDED

#include "MatrixGraph.h"
#include <vector>
#include <utility>
#include <iostream>

/// \brief Interface class for every solution
class ISolution {
    public:
        /// \brief Virtual destructor for efficient deletion
        virtual ~ISolution() { }

        /// \brief Virtual function which runs a solution on a given graph
        /// \param first 'const MatrixGraph*' which is a pointer to graph
        /// \return 'std::pair<double, std::vector<unsigned> >' which is a pair of the found cost and tour
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) = 0; // result, path

        /// \brief Virtual function to distinguish solutions
        /// \return 'std::string' which is a specific solution name
        virtual std::string getName() const = 0;
};

#endif
