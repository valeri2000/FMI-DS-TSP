#include "AdjGraph.h"
#include <cassert>

AdjGraph::AdjGraph(const unsigned& _vertices) {
    vertices = _vertices;
    edges = 0;

    if(vertices) {
        data.resize(vertices);
    }
}

AdjGraph::AdjGraph(std::ifstream& in) {
    in >> vertices;
    edges = 0;

    unsigned u, v, w;
    while(in) {
        in >> u >> v >> w;
        addEdge(u, v, w);
    }
}

const std::vector<std::pair<unsigned, unsigned> >& AdjGraph::adjacent(const unsigned& u) const {
    return data[u];
}

void AdjGraph::saveToFile(std::ofstream& out) const {
    out << vertices << '\n';
    
    unsigned u, v, w;
    unsigned pEdges = 0;
    for(unsigned i = 0; i < vertices; ++i) {
        u = i;
        for(const std::pair<unsigned, unsigned>& p : data[i]) {
            v = p.first;
            w = p.second;

            if(u < v) {
                out << u << ' ' << v << ' ' << w << '\n';
                pEdges++;
            }
        }
    }

    assert(pEdges == edges);
}

unsigned AdjGraph::V() const {
    return vertices;
}

unsigned AdjGraph::E() const {
    return edges;
}

void AdjGraph::addEdge(const unsigned& u, const unsigned& v, const unsigned& w) {
    data[u].push_back(std::make_pair(v, w));
    data[v].push_back(std::make_pair(u, w));
    edges++;
}

