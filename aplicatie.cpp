#include "aplicatie.h"
#include <string.h>
#include <iostream>
#include <ostream>
#include <cstddef>

using namespace std;


aplicatie::aplicatie()
{
	this->name = NULL;
	this->memory = 0;
	this->status = false;
}

aplicatie::aplicatie(const char* name, int memory, bool status)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name)+1, name);
	this->memory = memory;
	this->status = status;
}

aplicatie::aplicatie(const aplicatie& ap)
{
	this->name = new char[strlen(ap.name) + 1];
	strcpy_s(this->name, strlen(ap.name ) + 1, ap.name);
	this->memory = ap.memory;
	this->status = ap.status;
}

aplicatie::~aplicatie()
{
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
	memory = 0;
	status = false;
}

char* aplicatie::getname()
{
	return this->name;
}

int aplicatie ::  getmemory()
{
	return this->memory;
}

bool aplicatie::getstatus()
{
	return this->status;
}

void aplicatie::setName(const char* name)
{
	if (this->name)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];

	strcpy_s(this->name, strlen(name) + 1, name);
}

void aplicatie::setMemory(int mem)
{
	this->memory = mem;
}

void aplicatie::setStatus(bool stat)
{
	this->status = stat;
}

aplicatie& aplicatie::operator=(const aplicatie& ap)
{
	this->setName(ap.name);
	this->setMemory(ap.memory);
	this->setStatus(ap.status);
	return*this;
}

bool aplicatie::operator==(const aplicatie& ap)
{
	return(strcmp(this->name, ap.name) == 0 && (this->memory == ap.memory) && (this->status == ap.status));
}
ostream& operator<<(ostream& os, const aplicatie& ap)
{
	os << ap.name << " " << ap.memory << " ";
	if (ap.status == false)
		os << "swap";
	else os << "RAM";

	return os;
}