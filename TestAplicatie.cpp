#include "TestAplicatie.h"
#include "aplicatie.h"
#include<string.h>
#include <assert.h>
#include <iostream>
using namespace std;
void test()
{

	aplicatie ap((char*)"ap1", 2, true);
	ap.setName("ap1");

	ap.setMemory(3);
	assert(ap.getmemory() == 3);
	ap.setStatus(false);
	assert(ap.getstatus() == false);


	aplicatie ap1((char*)"ap1", 2, true);
	aplicatie ap2((char*)"ap1", 2, true);

	assert(ap1 == ap2);
}