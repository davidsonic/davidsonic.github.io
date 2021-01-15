#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

int main(){
    int a1, a2, a3, a4;
    cin>>a1>>a2>>a3>>a4;
    cout <<min(min(a1,a2), min(a3, a4));
    return 0;
}