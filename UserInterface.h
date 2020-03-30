#pragma once
#include "Service.h"
class UserInterface
{
private:
	Service serv;
	void print_menu();

	// crud
	void adauga();
	void sterge();
	void upd();
	void afiseaza();

	// cerinte
	void filtreaza_x();
	void sterge_5();
	


public:
	UserInterface();
	UserInterface(Service service);
	~UserInterface();

	void Run();

};

