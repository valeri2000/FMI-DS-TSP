#ifndef __FI_SOLUTION_H_INCLUDED
#define __FI_SOLUTION_H_INCLUDED

#include "ISolution.h"
#include "MatrixGraph.h"
#include <unordered_set>

/// \brief Farthest insertion solution
class FISolution : public ISolution {
    private:
        /// \brief Function to get the unvisited vertex which is farthest from given one
        /// \param first 'const unsigned' which is a vertex
        /// \param second 'const MatrixGraph*' which is a pointer to the graph
        /// \param third 'const std::vector<bool>' which is the visited array
        /// \return 'unsigned' which is the wanted vertex
        unsigned getMaxUnvisitedOf(const unsigned&, const MatrixGraph*, 
                                   const std::vector<bool>&);

    public:
        /// \brief Override main function of interface class
        virtual std::pair<double, std::vector<unsigned> > run(const MatrixGraph*) override;

        /// \brief Set different name for every solution
        virtual std::string getName() const override;
};

#endif
