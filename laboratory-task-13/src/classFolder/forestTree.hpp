#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "tree.hpp"


class ForestTree final : public Tree
{
private:
	double woodAmount;
public:
	ForestTree(std::string, size_t, treeTypes, double);
	ForestTree(const ForestTree&);
	ForestTree(const ForestTree&, double);
	~ForestTree() {}

	double getWoodAmount() const;

	void print() const override;
};
#endif // !FORESTTREE_HPP
