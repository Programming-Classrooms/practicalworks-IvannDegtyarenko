#ifndef TREECONTAINER_HPP
#define TREECONTAINER_HPP
#include "tree.hpp"
#include "forestTree.hpp"
#include "fruitTree.hpp"
#include <vector>
#include <algorithm>

class TreesContainer final : public Tree
{
private:
    std::vector<Tree*> trees;
    static bool compareTrees(Tree*, Tree*);
public:
    ~TreesContainer() = default;

    size_t getContainerSize() const;

    size_t countingByTreeType(treeTypes);
    void sortTreesVector();
    void pushBack(Tree*);

    void print() const override;
    friend std::istream& operator>>(std::istream&, TreesContainer&);
};
#endif // !TREECONTAINER_HPP
