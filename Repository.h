#pragma once
#include "Object.h"
class Repository
{
private:
	Object objects[20];
	int n;
public:
	Repository();
	~Repository();
	Repository(int n);
	Repository(const Repository& r);
	void add(Object obj);
	void del(int poz);
	void update(int poz,const char* n, int, int, float);
	Object* getAll();
	int findElem(Object obj);
	Object getItemFromPos(int);
	int getSize();

	//Repository& operator=(const Repository& r);

};

