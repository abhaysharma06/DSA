#include <iostream>
#include<vector>
using namespace std;
int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    int a[4] = {8,-8,7,9};
    
    int count = 0;
    for(int i=0;i<4;i+2){
        if((a[i]+a[i+1])!=0){
            count++;
        }
    }
    if(count>0)
     cout<<"No";
     else
     cout<<"Yes";

}