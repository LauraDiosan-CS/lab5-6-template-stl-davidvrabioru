#include "Tests.h"
#include "Object.h"
#include <assert.h>
//======================== INIT ========================

Tests::Tests()
{
	Service test_service;
	Repository test_repo;
}

Tests::Tests(Service test_service1, Repository test_repo1)
{
	test_service = test_service1;
	test_repo = test_repo1;
}

Tests::~Tests()
{
	//this->test_service = NULL;
}

//======================================================

void Tests::Object_test()
{
	Object o1("floatari", 10, 3, 2.4);

	assert(o1.getNos() == 10 && o1.getNor() == 3 && o1.getWeight() == 2.4);

}


void Tests::Repository_test()
{
	Object o1("floatari", 10, 3, 2.4);
	Object o2("fandari", 9, 4, 3.4);
	Object o3("geno", 8, 2, 2.7);
	Object o4("abdomen",6, 1, 2.9);


	// test add()
	test_repo.add(o1);
	test_repo.add(o2);
	test_repo.add(o3);
	test_repo.add(o4);

	assert(test_repo.getItemFromPos(0) == o1);
	assert(test_repo.getItemFromPos(2) == o3);
	assert(test_repo.getSize() == 4);

	//test delete()
	test_repo.del(0);
	assert(test_repo.getItemFromPos(0) == o2);
	assert(test_repo.getSize() == 3);

	//test update()
	test_repo.update(0, "geno1", 1, 1, 1.1);
	assert(test_repo.getItemFromPos(0).getNos() == 1);


	//test getALL()
	Object* list = new Object[test_repo.getSize()];
	list = test_repo.getAll();
	assert(list[1]==o3 && list[2] == o4);
	
	//test findElem()
	assert(test_repo.findElem(o3) == 1);

	//test getItemFromPos()
	Object obj = test_repo.getItemFromPos(2);
	assert(obj == o4);

	//test getSize()
	assert(test_repo.getSize() == 3);

}

void Tests::Service_test()
{

	Object o1("floatari", 10, 3, 2.4);
	Object o2("fandari", 9, 4, 3.4);
	Object o3("geno", 8, 2, 2.7);
	Object o4("abdomen", 6, 1, 2.9);

	// addObject() test
	test_service.addObject(o1);
	test_service.addObject(o2);
	test_service.addObject(o3);
	test_service.addObject(o4);
	assert(test_service.len() == 4);

	// deleteObject() test
	test_service.deleteObject(0);
	assert(test_service.len() == 3);

	// filter_obj_x() test
	Object result[20];
	int len = 0;
	test_service.filter_obj_x(70, result, len);
	assert(len == 1 && result[0] == o2);

	// delete_by_propety test
	test_service.delete_by_propety();
	assert(test_service.len() == 2);



}