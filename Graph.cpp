#include "Graph.h"
#include <cassert>

Graph::Graph(const unsigned& _vertices) {
    vertices = _vertices;
    edges = 0;

    if(vertices) {
        data.resize(vertices);
    }
}

Graph::Graph(std::ifstream& in) {
    in >> vertices;
    edges = 0;

    while(in) {
        unsigned u, v, w;
        in >> u >> v >> w;
        addEdge(u, v, w);
    }
}

void Graph::saveToFile(std::ofstream& out) const {
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

unsigned Graph::V() const {
    return vertices;
}

unsigned Graph::E() const {
    return edges;
}

const std::list<std::pair<unsigned, unsigned> >& Graph::adjacent(const unsigned& v) const {
    return data[v];
}

void Graph::addEdge(const unsigned& u, const unsigned& v, const unsigned& w) {
    data[u].push_back(std::make_pair(v, w));
    data[v].push_back(std::make_pair(u, w));
    edges++;
}

