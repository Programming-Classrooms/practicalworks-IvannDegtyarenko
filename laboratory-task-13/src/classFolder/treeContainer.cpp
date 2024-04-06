#include "treeContainer.hpp"

void TreesContainer::print() const
{
    for (size_t i = 0; i < this->trees.size(); ++i) {
        trees[i]->print();
        std::cout << '\n';
    }
}

bool TreesContainer::compareTrees(Tree* left, Tree* right)
{
    if (left->getTreeName() == right->getTreeName()) {
        return left->getTreeAge() > right->getTreeAge();
    }
    return left->getTreeName() < right->getTreeName();
}

size_t TreesContainer::getContainerSize() const
{
    size_t containerSize = trees.size();
    return containerSize;
}

size_t TreesContainer::countingByTreeType(treeTypes type)
{
    size_t counter = 0, containerSize = this->trees.size();
    for (size_t i = 0; i < containerSize; ++i) {
        if (this->trees[i] != nullptr && this->trees[i]->getTreeType() == type) {
            ++counter;
        }
    }
    return counter;
}

void TreesContainer::pushBack(Tree* initTree)
{
    this->trees.push_back(initTree);
}

std::istream& operator>>(std::istream& in, TreesContainer& rhs)
{
    std::string type ,treeType, fruit("Leafy"), forest("Coniferous"), treeName;
    size_t treeAge = 0, storageDuration = 0;
    double woodAmount = 0.0, cropMass = 0.0;
    Tree* initTree = nullptr;

    while (in >> type) {
        if (type == fruit || type == forest) {
            in >> treeName;
            in >> treeAge;
            in >> treeType;
            if (treeType == "forest") {
                in >> woodAmount;
                initTree = new ForestTree(treeName, treeAge, (type == fruit ? treeTypes::Leafy : treeTypes::Coniferous), woodAmount);
                rhs.pushBack(initTree);
            }
            else if (treeType == "fruit") {
                in >> cropMass;
                in >> storageDuration;
                initTree = new FruitTree(treeName, treeAge, (type == fruit ? treeTypes::Leafy : treeTypes::Coniferous), cropMass, storageDuration);
                rhs.pushBack(initTree);
            }
            else {
                throw std::runtime_error("Wrong tree Type name!");
            }
        }
        else {
            throw std::runtime_error("Can't find right Types of trees");
        }
    }

    return in;
}

void TreesContainer::sortTreesVector()
{
    std::sort(trees.begin(), trees.end(), compareTrees);
}
