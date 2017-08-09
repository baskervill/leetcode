#include <cmath>
#include <ctime>
#include <cstdio>
using namespace std;

float rsqrt(float number){
    float y = 1.0/sqrt(number);
    return y;
}
float Q_rsqrt(float number){
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *) &y;
    i = 0x5f3759df - (i>>1);
    y = *(float *) &i;
    y = y*(threehalfs - (x2 * y * y));
    return y;
}
int main(){
    clock_t start,end;
    float nums = 10;
    start = clock();
    float y1 = rsqrt(nums);
    end = clock();
    double time1 = (double)(end - start)/CLOCKS_PER_SEC;
    start = clock();
    float y2 = Q_rsqrt(nums);
    end = clock();
    double time2 = (double)(end - start)/CLOCKS_PER_SEC;
    printf("%f,%f,%lf,%lf \n",y1,y2,time1,time2);
    return 0;
}