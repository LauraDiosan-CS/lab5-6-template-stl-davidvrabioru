#pragma once
#include "Service.h"
#include "Repository.h"
class Tests
{
private:
	Service test_service;
	Repository test_repo;
public:
	Tests();
	Tests(Service, Repository);
	~Tests();


	void Object_test();
	void Repository_test();
	void Service_test();

};

