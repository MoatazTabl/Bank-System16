#include <iostream>
#include "Client.h"
using namespace std;


int main()
{
    system("color f0");
    
    Client c;

    c.setName("mittzo");
    c.setBalance(1500);
    c.checkBalance();
    cout<<c.getName();

}

