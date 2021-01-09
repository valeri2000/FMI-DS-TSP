#ifndef __TEST_DATA_H_INCLUDED
#define __TEST_DATA_H_INCLUDED

#include "MatrixGraph.h"
#include <fstream>

/// \brief Class for special test data
class TestData {
    private:
        MatrixGraph *g; ///< linked graph to this test
        double minTourCost; ///< optimal tour cost for this test
        std::string name; ///< name of test data

        /// \brief Function to convert 2D representation to graph
        /// \param first 'const std::vector<std::pair<double, double> >' which is a vector of points
        void convertFrom2DtoGraph(const std::vector<std::pair<double, double> >&);

    public:
        /// \brief Constructor by graph input and solution input
        /// \param first 'std::ifstream' which is the graph input
        /// \param second 'std::ifstream' which is the solution input
        TestData(std::ifstream&, std::ifstream&);

        TestData(const TestData&) = delete;
        TestData& operator = (const TestData&) = delete;

        /// \brief Destructor
        ~TestData();

        /// \brief Getter for the linked graph
        /// \return 'const MatrixGraph*' which is a pointer to the graph
        const MatrixGraph* getGraph() const;

        /// \brief Getter for the minimum tour cost
        /// \return 'double' which is the minimum tour cost
        double getMinTourCost() const;

        /// \brief Getter for the test data name
        /// \return 'std::string' which is the name of the test data
        std::string getName() const;
};

#endif
