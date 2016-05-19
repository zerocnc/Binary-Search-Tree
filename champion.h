#pragma once

#include <string>
#include <iostream>

/**
	Champion object holds only three properties, name(string), id(int), other(int).
*/
class Champion
{
private:
	std::string name;
	int id;
	int other;

public:
	Champion(void);
	Champion(std::string name, int id, int other);
	~Champion();

	friend std::ostream& operator<<(std::ostream& os, Champion champion);
	int operator<(Champion& champion) const;
	int operator>(Champion& champion) const;
	int operator==(Champion& champion) const;
	void operator=(const Champion champion);
};

/**
	Default values
	name: ""
	id: -1
	other: -1
*/
Champion::Champion(void)
{

}

/**
	Overloaded operator to display object into console.  cout << myObject;
	*/
std::ostream& operator<<(std::ostream& os, Champion champion)
{
	os << "Champion: " << champion.name << "\n"
		<< "ID #: " << champion.id << "\n"
		<< "Other: " << champion.other << "\n";
	return os;
}


// Assumes I'm just comparing names.
int Champion::operator<(Champion& champion) const
{
	if (this->name < champion.name )
		return true;
	else
		return false;

	/*
	if (this->name.compare(champion.name) < 0)
		return true;
	else
		return false;*/

	/*
	if (this->name.compare(champion.name) == 0)
	{
		if (this->id < champion.id)
			return this->other < champion.other;
		return this->id < champion.id;
	}
	else
		return this->name.compare(champion.name);*/
}

int Champion::operator>(Champion& champion) const
{
	if (this->name.compare(champion.name) > 0)
		return true;
	else
		return false;
	/*
	if (this->name.compare(champion.name) == 0)
	{
		if (this->id > champion.id)
			return this->other > champion.other;
		return this->id > champion.id;
	}
	else
		return this->name.compare(champion.name);*/
}

int Champion::operator==(Champion& champion) const
{
	if (this->name.compare(champion.name) == 0)
		return true;
	else
		return false;
	/*
	return (this->name.compare(champion.name) &&
		   (this->id == champion.id ) &&
		   this->other == champion.other);*/
}

void Champion::operator=(const Champion champion)
{
	this->name = champion.name;
	this->id = champion.id;
	this->other = champion.other;
}

Champion::Champion(std::string Name, int ID, int Other) : name(Name), id(ID), other(Other)
{

}

Champion::~Champion()
{

}

