#ifndef __TEST_DATA_H_INCLUDED
#define __TEST_DATA_H_INCLUDED

#include "MatrixGraph.h"
#include <fstream>

class TestData {
    private:
        MatrixGraph *g;
        double minTourCost;
        std::string name;

        void convertFrom2DtoGraph(const std::vector<std::pair<double, double> >&);

    public:
        TestData(std::ifstream&, std::ifstream&);
        TestData(const TestData&) = delete;
        TestData& operator = (const TestData&) = delete;
        ~TestData();

        const MatrixGraph* getGraph() const;
        double getMinTourCost() const;
        std::string getName() const;
};

#endif
