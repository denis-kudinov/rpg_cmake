#pragma once

#include"Item.hpp"

class Inventory
{
private:
	Item** itemArray;
	unsigned nrOfItems;
	unsigned capacity;

	//Private functions
	void initialize();
	void nullify(unsigned from = 0);
	void freeMemory();

public:
	Inventory(unsigned capacity);
	virtual ~Inventory();

	//Accessors
	unsigned size() const;
	unsigned maxSize() const;

	//Modifiers

	//Functions
	void clear();
	bool empty() const;

	bool add(Item* item);
	bool remove(unsigned index);

	bool saveToFile(const std::string& fileName);
	bool loadFromFile(const std::string& fileName);
};

