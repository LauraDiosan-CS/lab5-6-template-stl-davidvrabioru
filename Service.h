#pragma once
#include "Repository.h"
class Service
{
private:
	Repository repo;
	Repository Undo_Stack[20];
	int poz = -1;
public:
	Service();
	Service(Repository repo);
	Service(const Service& s);
	~Service();

	void filter_obj_x(float, Object result[], int&);
	void delete_by_propety();
	void addObject(Object obj);
	void deleteObject(int poz);
	void updateObject(int poz,const char*, int, int, float);
	Object* print();
	int len();


	
	//void undo();


};

