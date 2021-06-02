#include <iostream>
#include <cmath>
using namespace std;
bool prostoi(long long unsigned  j)
{
    long long unsigned i;
    if (j==0) 
        return false;
    for (i=2; i<=sqrt(j); i++) {
        if (j % i == 0) {
            return false;
        }
    }
    return true;
}
int BitOne(long long unsigned j)
{
    long long unsigned i;
    int bit = 0;
    for (i=0; i<64; i++) {
        if((j>>i)%2==1) 
            bit++;
    }
    return bit;
}
int main()
{
    long long unsigned int i;
    long long unsigned int limit = 0xFFFFFFFFFFFFFFFF;
    for(i=2; i<limit; i++) {
        if ((BitOne(i) == 2) && (prostoi(i))) {
            cout<<"Decimal: "<<dec<<i<<"\tHexadecimal: "<<hex<<i<<endl;
        
        }
    }
    return 0;
}
