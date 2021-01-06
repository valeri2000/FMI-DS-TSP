#ifndef __ADJ_GRAPH_H_INCLUDED
#define __ADJ_GRAPH_H_INCLUDED

#include <fstream>
#include <vector>
#include <utility>

class AdjGraph {
    private:
        unsigned vertices, edges;
        std::vector<std::vector<std::pair<unsigned, unsigned> > > data;

    public:
        AdjGraph(const unsigned& = 0);
        AdjGraph(std::ifstream&);

        void saveToFile(std::ofstream&) const;
        unsigned V() const;
        unsigned E() const;
        const std::vector<std::pair<unsigned, unsigned> >& adjacent(const unsigned&) const;

        void addEdge(const unsigned&, const unsigned&, const unsigned&);
};

#endif
