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
int main()
{
    int a=10;
    cout<<&a<<endl; // address of 'a' output: 0x16aeeaa68 here 0x means it is address and 16aeeaa68 is hexadecimal address

    int *ptr = &a;
    cout<<ptr<<endl;

    // pointer to pointer

    int** ptr2=&ptr;
    cout<<ptr2<<endl;

    // dereference Opreator *
    cout<<*(&a)<<endl; // value at a
    cout<<*(ptr)<<endl; //vlaue at adress stored in ptr
    cout<<*(ptr2)<<endl;
    cout<<**(ptr2)<<endl;

    // NULL pointer
    int* ptr3=NULL;
    cout<<ptr3<<endl; // output (0x0)
    // cout<<*(ptr3)<<endl; NULL pointer ko derefernce nhi kar skte segmentation fault aayega

    // array pointer (address of array is same as address of arr[0])
    int arr[]={1,2,3,4};
    cout<<&arr<<endl;
    cout<<arr<<endl; // arr in c++ is already a pointer
    cout<<*arr<<endl;  // point to first element
    cout<<&arr[0]<<endl;

    // increment in array
    int b=20;
    int *pt=&b;
    cout<<pt++<<endl;

    // addition in pointer
    int arr2[]={2,4,6,8};
    cout<<*arr<<endl;
    cout<<*(arr+1)<<endl;
    cout<<*(arr+2)<<endl;
    cout<<*(arr+3)<<endl;

    // substraction between pointers
    int c=30;
    int* ptc=&c;
    int* ptc2=ptc+2;
    cout<<ptc2-ptc<<endl;

return 0;
}