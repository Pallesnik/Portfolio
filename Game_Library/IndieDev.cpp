#include "IndieDev.h"

IndieDev::IndieDev(string n):Developer(n){
    DevName=n;
    salary=0;
}

bool IndieDev::backedByKickstarter(){
    char a;
    cout << "Was this developer backed by kickstarter?(Y for yes or N for no):";
    cin >> a;
    while(1){
    if(a == 'Y'){
        return true;
    }
    else if (a == 'N'){
        return false;
    }
    else{
        cout << "Enter a valid answer:";
        cin >> a;
    }

    }
}

int IndieDev::calcSalary(){
    if(backedByKickstarter()==true){
        salary = 10000;
    }
    else{
        salary = 1000;
    }
    cout << salary;
}
