#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
class pokemon{
public:
    string name;
    int power;
    pokemon(string name , int power){
        this->name=name;
        this->power=power;
    }
};
int main()
{
    // object pointer
    pokemon p1("pikacu",200);
    pokemon p2("rayquaza",1200);

    pokemon *ptr1 = &p1; //object to pointer
    pokemon *ptr2 = &p2;

    cout<<(*ptr1).name<<" "<<(*ptr1).power<<endl;
    cout<<(*ptr2).name<<" "<<(*ptr2).power<<endl;

    cout<<ptr1->name<<" "<<ptr1->power<<endl;
    cout<<ptr2->name<<" "<<ptr2->power<<endl;

    // *ptr = ptr->
return 0;
}