#ifndef __GRAPH_H_INCLUDED
#define __GRAPH_H_INCLUDED

#include <vector>
#include <list>
#include <utility>
#include <fstream>

class Graph {
    private:
        unsigned vertices, edges;
        std::vector<std::list<std::pair<unsigned, unsigned> > > data;

    public:
        Graph(const unsigned& = 0);
        Graph(std::ifstream&);

        void saveToFile(std::ofstream&) const;
        unsigned V() const;
        unsigned E() const;
        const std::list<std::pair<unsigned, unsigned> >& adjacent(const unsigned&) const;

        void addEdge(const unsigned&, const unsigned&, const unsigned&);
};

#endif
