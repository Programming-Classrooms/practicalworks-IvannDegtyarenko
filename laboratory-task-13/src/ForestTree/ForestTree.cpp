#include "ForestTree.hpp"


ForestTree::ForestTree(
	std::string initTreeName, 
	size_t initTreeAge, 
	treeTypes initTreeType, 
	double initWoodAmount
): Tree(initTreeName, initTreeAge, initTreeType), woodAmount(initWoodAmount)
{}

ForestTree::ForestTree(const ForestTree& init) :
	Tree(init), woodAmount(init.woodAmount)
{}

ForestTree::ForestTree(const ForestTree& init, double initWA) :
	Tree(init), woodAmount(initWA)
{}

double ForestTree::getWoodAmount() const
{
	return this->woodAmount;
}

void ForestTree::print() const
{
	std::cout << "Forest Tree: " << this->treeName << '\n';
	std::cout << "Tree age: " << this->treeAge << '\n';
	std::cout << "Amount of wood in this tree: " << this->woodAmount << '\n';
}
