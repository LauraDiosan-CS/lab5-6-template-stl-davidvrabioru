#include "UserInterface.h"
#include "Object.h"
#include <iostream>

using namespace std;



//======================== INIT ========================

UserInterface::UserInterface()
{
	Service serv;
}
UserInterface::UserInterface(Service sv)
{
	serv = sv;
}
UserInterface::~UserInterface()
{
}

//======================================================


void UserInterface::print_menu()
{
	cout << "------------  Main Menu  ------------\n";
	cout << "1. Adauga! \n";
	cout << "2. Afiseaza! \n";
	cout << "3. Sterge! \n";
	cout << "4. Update! \n";
	cout << "5. Filtreaza in functie de x! \n";
	cout << "6. Sterge dupa propietate! \n";
	cout << "x. Exit! ";
	cout << "-------------------------------------\n";
	cout << "Alege o cerinta din meniul de mai sus! \n";
	cout << "-------------------------------------\n";
}

void UserInterface::adauga()
{

	// adaugare obiect in repository

	cout << "Dati nume: ";
	char name[100];
	cin >> name;

	int nos = 0;
	cout << "Dati numarul de serii: ";
	cin >> nos;

	int nor = 0;
	cout << "Dati numarul de repetitii: ";
	cin >> nor;

	float weight = 0.0;
	cout << "Dati greutatea in kg: :";
	cin >> weight;

	Object obj(name, nos, nor, weight);
	serv.addObject(obj);

	cout << "Cerinta Executata! \n";

}

void UserInterface::afiseaza()
{
	// afisare obiecte din repository

	Object* obj = new Object[20];
	obj = serv.print();

	for (int i = 0; i < serv.len(); i++)
		cout << obj[i] << endl;
	cout << endl;
}


void UserInterface::sterge()
{
	// stergere obiect din repository

	int poz = -1;
	cout << "Dati pozitia obiectului: ";
	cin >> poz;
	serv.deleteObject(poz);

	cout << "Cerinta Executata! \n";
}

void UserInterface::upd()
{
	//update la un obiect din repository

	int poz = -1;
	cout << "Dati pozitia: ";
	cin >> poz;

	char nume[20];
	cout << "Dati noul numele: ";
	cin >> nume;

	int nos = 0;
	cout << "Dati noul nr de serii: ";
	cin >> nos;

	int nor = 0;
	cout << "Dati numarul de repetitii: ";
	cin >> nor;

	float weight = 0.0;
	cout << "Dati greutatea in kg: :";
	cin >> weight;

	serv.updateObject(poz, nume, nos, nor, weight);
	cout << "Cerinta Executata! \n";
}

void UserInterface::filtreaza_x()
{
	float x;
	cout << "Dati valoarea lui x: ";
	cin >> x;

	Object result[20];
	int m = 0;

	serv.filter_obj_x(x, result, m);
		for (int i = 0; i < m; i++)
			cout << result[i] <<endl;
		cout << endl;
}

void UserInterface::sterge_5()
{
	serv.delete_by_propety();
	cout << "Cerinta Executata! \n";
}


void UserInterface::Run()
{
	string op="";
	while (op != "x")
	{
		print_menu();
		cin >> op;

		if (op == "1")
			adauga();

		else if (op == "2")
			afiseaza();
		else if (op == "3")
			sterge();
		else if (op == "4")
			upd();
		else if (op == "5")
			filtreaza_x();
		else if (op == "6")
			sterge_5();

	}
}

