#include <iostream>
#include "Lab5.0.h"
using namespace std;



// COORDONATOR !! 


int main()
{
    cout << "Start... \n";


    
    Repository test_repo1, test_repo2, repo;
    Service test_serv(test_repo2), service(repo);
    Tests test(test_serv, test_repo1);
    test.Object_test();
    test.Repository_test();
    test.Service_test();

    cout << "Teste trecute cu succes! \n";




   // program run 
   UserInterface ui(service);
   ui.Run();





    return 0;
}


