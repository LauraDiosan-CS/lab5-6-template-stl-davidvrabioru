#include<iostream>
#include "Object.h"
#include "Service.h"


//======================== INIT ========================


Service::Service()
{
	Repository repo;
	Repository Undo_Stack[20];
	int poz = -1;
}
Service::Service(Repository rep1)
{
	repo = rep1;
}
Service::Service(const Service& s)
{
	repo = s.repo;
}
Service::~Service()
{
	this->repo = NULL;
	poz = 0;
}

//======================================================






//======================== CRUD ========================

void Service::addObject(Object obj)
{
	this->Undo_Stack[++poz] = repo;
	this->repo.add(obj);
}

void Service::deleteObject(int poz)
{
	this->Undo_Stack[++poz] = repo;
	this->repo.del(poz);
}

void Service::updateObject(int poz,const char* name, int nos, int nor, float weight)
{
	this->Undo_Stack[++poz] = repo;
	if(poz < repo.getSize())
	this->repo.update(poz, name, nos, nor, weight);
}

Object* Service::print()
{
	return this->repo.getAll();
}

int Service::len()
{
	return this->repo.getSize();
}

//======================================================








//======================== Requests ====================

void Service::filter_obj_x(float x, Object result[], int& m)
{

	// function filters all objects that have noOfSeries * noOfReps * weightKg > X, X given by user

	for (int i = 0; i < repo.getSize(); i++)
	{
		Object obj = repo.getItemFromPos(i);
		
		if ((obj.getNor() * obj.getNos() * obj.getWeight()) > x)
			result[m++] = obj;
	}
}


void Service::delete_by_propety()
{

	this->Undo_Stack[++poz] = repo;

	// deletes all objects that have weightKg * noOfReps  < 5
	for (int i = 0; i < repo.getSize(); i++)
	{
		Object obj = repo.getItemFromPos(i);

		if ((obj.getNor() * obj.getWeight()) < 5)
			repo.del(i);
	}
}



/*
void Service::undo()
{
	if (this->poz >= -1)
		this->repo = this->Undo_Stack[poz--];
}
*/

//======================================================


