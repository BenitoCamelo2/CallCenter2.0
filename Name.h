#ifndef PROGRAMA_NAME_H
#define PROGRAMA_NAME_H

#include <iostream>

using namespace std;

class Name {
private:
    string firstName;
    string lastName;
public:
    Name();
    Name(string fname, string lname);
    string getFirstName();
    string getLastName();
    void setData(const string& fname, const string& lname);
    string toString();
    Name& operator = (const Name& name);
    bool operator == (const Name& name);
    bool operator != (const Name& name);
    bool operator < (const Name& name);
    bool operator <= (const Name& name);
    bool operator > (const Name& name);
    bool operator >= (const Name& name);
};


#endif //PROGRAMA_NAME_H
