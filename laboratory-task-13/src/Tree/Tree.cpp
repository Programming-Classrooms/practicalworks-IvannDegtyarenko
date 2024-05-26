#include "Tree.hpp"


Tree::Tree(
	std::string initTreeName, 
	size_t initTreeAge, 
	treeTypes initTreeType
): treeType(initTreeType)
{
	if (initTreeName.length() == 0) {
		throw std::runtime_error("String of Tree Name is empty");
	}
	treeName = initTreeName;
	if (initTreeAge < 0) {
		throw std::invalid_argument("Wrong value of Tree Age");
	}
	treeAge = initTreeAge;
}

Tree::Tree(const Tree& init): treeName(init.treeName), treeAge(init.treeAge), treeType(init.treeType)
{}

std::string Tree::getTreeName() const
{
	return this->treeName;
}

size_t Tree::getTreeAge() const
{
	return this->treeAge;
}

treeTypes Tree::getTreeType() const
{
	return this->treeType;
}
