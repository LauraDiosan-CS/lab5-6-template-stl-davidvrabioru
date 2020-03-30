#include "Object.h"
#include"Repository.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

Object::Object()
{
	this->name = NULL;
	this->nos = 0;
	this->nor = 0;
	this->weight = 0.0;
}


// constructor with param
Object::Object(const char* name, int nos, int nor, float weight)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->nos = nos;
	this->nor = nor;
	this->weight = weight;
}

// copy construcotr
Object::Object(const Object& g)
{
	this->name = new char[strlen(g.name) + 1];
	strcpy_s(this->name, strlen(g.name) + 1, g.name);
	this->nos = g.nos;
	this->nor = g.nor;
	this->weight = g.weight;
}

// deconstructor
Object::~Object()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}

	this->nos = 0;
	this->nor = 0;
	this->weight = 0.0;
}

// geters

char* Object::getName()
{
	return this->name;
}

int Object::getNos()
{
	return this->nos;
}

int Object::getNor()
{
	return this->nor;
}

float Object::getWeight()
{
	return this->weight;
}

// seters

void Object::setName(const char* nume)
{
	if (this->name)
	{
		delete[] this->name;
		
	}

	this->name = new char[strlen(nume) + 1];
	strcpy_s(this->name, strlen(nume) + 1, nume);
}

void Object::setNOS(int nos)
{
	this->nos = nos;
}

void Object::setNOR(int nor)
{
	this->nor = nor;
}

void Object::setWeight(float weight)
{
	this->weight = weight;
}

// operators

Object& Object::operator=(const Object& g)
{
	this->setName(g.name);
	this->setNOR(g.nor);
	this->setNOS(g.nos);
	this->setWeight(g.weight);
	return *this;
}

bool Object::operator==(const Object& g)
{
	return (strcmp(g.name, this->name) == 0) && this->nos == g.nos && this->nor == g.nor && this->weight == g.weight;
}

ostream& operator<<(ostream& os, const Object& g)
{
	os << g.name << " " << g.nos << " " << g.nor << " " << g.weight;
	return os;
}
