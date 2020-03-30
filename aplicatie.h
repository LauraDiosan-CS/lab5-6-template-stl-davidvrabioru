#pragma once
#include <ostream>
using namespace std;
class aplicatie
{
private:
	char* name;
	int memory;
	bool status;
public:

	aplicatie();
	aplicatie(const char* name, int memory, bool status);
	aplicatie(const aplicatie& ap);
	~aplicatie();

	char* getname();
	int getmemory();
	bool getstatus();

	void setName(const char* name);
	void setMemory(int);
	void setStatus(bool);

	aplicatie& operator=(const aplicatie& ap);
	bool operator ==(const aplicatie& ap);
	friend ostream& operator<<(ostream& os, const aplicatie& ap);

};

