#include <iostream>
#include <random>
using namespace std;

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
    uint64_t arr[3];
    random_device rd;
    mt19937 generator(rd());
    for(int i=0;i<3;i++) {
        s=true;
        while(s) {
            n=generator();
            if(TrialDivision(n))
                s=false;
            arr[i]=n;
            
        }
        cout<<arr[i]<<endl;
    }
    return 0;
}
