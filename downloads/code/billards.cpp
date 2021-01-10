#include <iostream>
using namespace std;

int main(){
    double sx, sy, gx, gy;
    cin>>sx>>sy>>gx>>gy;
    double x = (double)(sy*gx + sx * gy) / (sy+gy);
    printf("%.10lf\n", x);
    return 0;
}