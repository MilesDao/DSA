#include<bits/stdc++.h>

using namespace std;
//push_back() // day vao cuoi vector
//foreach : Range base for loop (C++11 tro len)
using ll = long long;
int main(){

    // vector<int> v(10); vector co san 10 phantu
    vector<int> v(3, 100); //{100, 100, 100}
    // vector<int> v(3);// gia tri rac
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    cout << v.size() << endl;
    cout << v[2]<< endl;

    for( int x : v){
        cout << x << " ";
    }
    // int a[5] = {3,1,2,2,3};
    // for(int x:a){//foreach
    //     cout << x << ' ';
    // }
}