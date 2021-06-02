#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

bool TrialDivision(uint64_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1)==0)
        return false;
    for (uint64_t i = 3; i <= (uint64_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}


int main()
{
    uint64_t n;
    bool s;
    const int size=3;
    uint64_t arr[size];
    mt19937_64 generator(clock());
    for(int i=0;i<size;i++) {
        s=true;
        auto begin=steady_clock::now();
        while(s) {
            n=generator();
            if(TrialDivision(n))
                s=false;
            arr[i]=n;
        }
        auto end=steady_clock::now();
        duration<double> elapsed = duration_cast<duration<double>>(end - begin);
        cout<<arr[i]<<endl;
        cout<<elapsed.count()<<" секунд"<<endl;
    }
    return 0;
}
