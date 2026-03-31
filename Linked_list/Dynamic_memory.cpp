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
    pokemon p1("pikacu",200);
    pokemon p2("rayquaza",1200);

    pokemon* ptr3 = new pokemon("bulbasaur",200);   // dynamic object
    cout<<ptr3->name<<endl;
    cout<<ptr3->power<<endl;

    int* ptr = new int(4);  // dynamic variable
    cout<<*ptr<<endl;

    int* ptr2 = new int[10]; // dynamic array
    // *ptr = ptr->
return 0;
}