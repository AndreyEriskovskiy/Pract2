#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    time_t timer=time(nullptr);
    tm* timeinfo=localtime(&timer);
    char buf[80];
    strftime(buf,80,"%A %d %B %X %Y",timeinfo);
    cout<<buf<<endl;
    return 0;
}
