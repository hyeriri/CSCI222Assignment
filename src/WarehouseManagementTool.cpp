//
//  WarehouseManagementTool.cpp
//  CSCI222
//
// This class serves as a login page and the main() for A2

// to compile: 


#include <iostream>
#include <stdio.h>
#include <String.h>

using namespace std;

Manager m;

int main()
{
    // login
    m.readData();
    login();   
}

void login()
{
    string user , pass;
    cout << "Please kindly enter you username and password.\n";
    cout << "\nUser: ";
    cin >> user;
    
    cout << "\nPassword: ";
    cin >> pass;
    
    if(verify(user,pass) == "Login Successful") // if password and user name is correct
    {
        // WM_SystemInterface 
        WM_SystemInterface sys;
        sys.displayMenu();        
    }
    else if(verify(user,pass) == "You have exceeded the max. amount of login tries.")
    {
        cout << verify(user,pass) << endl;
        exit(0);

    }  
    else
    {
        cout << verify(user,pass) << endl;
        login();
    }

    
}

string verify(string user, string pass)
{
    // to verify username and password
    // access Manager database

    return m.verifyManager(user,pass);
}
    

