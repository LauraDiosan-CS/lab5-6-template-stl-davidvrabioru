#pragma once
#include <ostream>
using namespace std;
class Object
{
private:
	char* name;
	int nos;
	int nor;
	float weight;
public:
	Object();
	Object(const char* name, int nos, int nor, float weight);
	Object(const Object& ge);
	~Object();

	char* getName();
	int getNos();
	int getNor();
	float getWeight();

	void setName(const char* name);
	void setNOS(int nos);
	void setNOR(int nor);
	void setWeight(float w);

	Object& operator=(const Object& g);
	bool operator == (const Object& g);
	friend ostream& operator<<(ostream& os, const Object& g);
};

