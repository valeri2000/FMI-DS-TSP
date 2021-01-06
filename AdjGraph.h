#ifndef __ADJ_GRAPH_H_INCLUDED
#define __ADJ_GRAPH_H_INCLUDED

#include "IGraph.h"
#include <vector>
#include <utility>

class AdjGraph : public IGraph {
    private:
        unsigned vertices, edges;
        std::vector<std::vector<std::pair<unsigned, unsigned> > > data;

    public:
        AdjGraph(const unsigned& = 0);
        AdjGraph(std::ifstream&);

        const std::vector<std::pair<unsigned, unsigned> >& adjacent(const unsigned&) const;

        virtual void saveToFile(std::ofstream&) const override;
        virtual unsigned V() const override;
        virtual unsigned E() const override;
        virtual void addEdge(const unsigned&, const unsigned&, const unsigned&) override;
        virtual bool isMatrixRepr() const override;
};

#endif
