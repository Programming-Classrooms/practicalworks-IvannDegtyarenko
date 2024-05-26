#include "FruitTree.hpp"

FruitTree::FruitTree(
	std::string initTreeName,
	size_t initTreeAge,
	treeTypes initTreeType,
	double initCropMass,
	size_t initStorageDuration
) :
	Tree(initTreeName, initTreeAge, initTreeType),
	cropMass(initCropMass),
	storageDuration(initStorageDuration)
{}

FruitTree::FruitTree(const FruitTree& init):
	Tree(init), cropMass(init.cropMass), storageDuration(init.storageDuration)
{}

FruitTree::FruitTree(
	const FruitTree& init, 
	double initCropMass, 
	size_t initStorageDuration
): Tree(init), cropMass(initCropMass), storageDuration(initStorageDuration)
{}

double FruitTree::getCropMass() const
{
	return this->cropMass;
}

size_t FruitTree::getStorageDration() const
{
	return this->storageDuration;
}

void FruitTree::print() const
{
	std::cout << "Fruit Tree: " << this->treeName << '\n';
	std::cout << "Tree age: " << this->treeAge << '\n';
	std::cout << "Crop Mass of this tree: " << this->cropMass << '\n';
	std::cout << "Storage duration: " << this->storageDuration << " Days" << '\n';
}
