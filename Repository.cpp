#include "Repository.h"
#include "Object.h"
#include <algorithm>
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
//construcotr
Repository::Repository()
{
	this->n = 0;
}

// construcotr with param
Repository::Repository(int n)
{
	this->n = n;
}

// copy constructor
Repository::Repository(const Repository& r)
{
	this->n = r.n;
}

//destructor
Repository::~Repository()
{
	this -> n = 0;
}

// add to repository
void Repository::add(Object obj)
{
	this->objects[n++] = obj;
}

// delete from repository
void Repository::del(int poz)
{
	if (poz < n)
	{
		for (int k = poz; k < n - 1; k++)
			objects[k] = objects[k + 1];
		n--;
	}
}

//update object
void Repository::update(int poz,const char* name, int nos, int nor, float weight)
{
	objects[poz].setName(name);
	objects[poz].setNOR(nor);
	objects[poz].setNOS(nos);
	objects[poz].setWeight(weight);
}

int Repository::findElem(Object obj)
{
	for (int i = 0; i < n; i++)
		if (objects[i] == obj)
			return i;
	return -1;
}

Object Repository::getItemFromPos(int poz)
{
	return objects[poz];
}

int Repository::getSize()
{
	return this->n;
}

Object* Repository::getAll()
{
	return objects;
}

/*
Repository& Repository::operator=(const Repository& r)
{
	copy(begin(this->objects), end(this->objects), begin(r.objects));
	this->n = my_sizeof(r.objects) / my_sizeof(r.objects);
	return*this;
}*/