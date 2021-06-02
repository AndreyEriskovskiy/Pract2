#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;
bool TrialDivision(uint32_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1)==0)
        return false;
    for (uint32_t i = 3; i <= (uint32_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    uint32_t n;
    vector <uint32_t> v;
    random_device rd;
    mt19937 generator(rd());
    for(int i=0; i<1000; i++) {
        do {
            n=generator();
            v.push_back(n);
            
        } while(TrialDivision(n));

    }

    sort(v.begin(), v.end());
    cout<<"Минимум: "<<v[0]<<endl;
    cout<<"Максимум: "<<v[v.size()-1]<<endl;
    return 0;
}
