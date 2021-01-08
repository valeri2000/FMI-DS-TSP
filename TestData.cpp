#include "TestData.h"
#include <cmath>

void TestData::convertFrom2DtoGraph(const std::vector<std::pair<double, double> >& data) {
    unsigned vertices = data.size();
    g = new MatrixGraph(vertices);

    for(unsigned i = 0; i < vertices - 1; ++i) {
        for(unsigned j = i + 1; j < vertices; ++j) {
            double x1 = data[i].first;
            double y1 = data[i].second;
            double x2 = data[j].first;
            double y2 = data[j].second;

            double w = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

            g->addEdge(i, j, w);
        }
    }
}

TestData::TestData(std::ifstream& in, std::ifstream& solIn) : g(nullptr) {
    solIn >> minTourCost;

    unsigned vertices;
    in >> name;
    in >> vertices;

    std::vector<std::pair<double, double> > vertices2D(vertices);

    unsigned vertex; double x; double y;
    for(unsigned i = 0; i < vertices; ++i) {
        in >> vertex >> x >> y;
        vertices2D[i] = std::make_pair(x, y);
    }

    convertFrom2DtoGraph(vertices2D);
}

TestData::~TestData() {
    delete g;
    g = nullptr;
}

const MatrixGraph* TestData::getGraph() const {
    return g;
}

double TestData::getMinTourCost() const {
    return minTourCost;
}

std::string TestData::getName() const {
    return name;
}

