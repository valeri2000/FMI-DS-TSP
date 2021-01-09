#ifndef __MATRIX_GRAPH_H_INCLUDED
#define __MATRIX_GRAPH_H_INCLUDED

#include <fstream>
#include <vector>

/// \brief Class for matrix representation of a graph
class MatrixGraph {
    private:
        unsigned vertices; ///< number of vertices
        unsigned edges; ///< number of and edges
        std::vector<std::vector<double> > matrix; ///< vector of vectors of weight

    public:
        /// \brief Create graph with X vertices
        /// \param first 'const unsigned' which is the number of vertices
        MatrixGraph(const unsigned& = 0);

        /// \brief Create graph from file
        /// \param first 'std::ifstream' which is the input stream
        MatrixGraph(std::ifstream&);

        /// \brief Function to save graph to file
        /// \param first 'std::ofstream' which is the output stream
        void saveToFile(std::ofstream&) const;

        /// \brief Getter for number of vertices
        /// \return 'unsigned' which is the number of vertices
        unsigned V() const;

        /// \brief Getter for number of edges
        /// \return 'unsigned' which is the nubmer of edges
        unsigned E() const;

        /// \brief Get whole row in the matrix representation for a vertex
        /// \param first 'const unsigned' which is the vertex
        /// \return 'const std::vector<double>&' which is const reference to the wanted vector
        const std::vector<double>& adjacentRow(const unsigned&) const;

        /// \brief Function for adding edges
        /// \param first 'const unsigned' which is a vertex
        /// \param second 'const unsigned' which is another vertex
        /// \param third 'const double' which is the weight of the edge
        void addEdge(const unsigned&, const unsigned&, const double&);
};

#endif
