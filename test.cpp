#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v;
    int a[11] = {1,2,2,2,3,4,4,5,6,6,7};
    for(int i = 0;i < 11;i++){
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    vector<int>::iterator point = unique(v.begin(),v.end());
    v.erase(point,v.end());
    for(vector<int>::iterator iter = v.begin(); iter != point;iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}
