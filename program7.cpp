#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Koloda
{
public:
    int nominal;
    int mast;
    Koloda() {};
    Koloda (int a, int b): nominal(a), mast(b) {};
    friend ostream& operator << (ostream& out, Koloda result)
    {
        return ou << to_string(result.nominal) + " " +to_string(result.mast);
    }
};
int main()
{
    string name[]= {"6","7","8","9","10","V","D","K","T"};
    string mastcard[]={"Bub","CH","Pik","Krest"};
    int p,kol;
    do {
        cout <<"Раздать колоду: 1 - для 36 карт, 0 - выход" << endl;
        cin >> p;
        if (!(p==1)) {}
        else if (p >0) {
            if (p == 1) {
                kol=36;
            }
            cout << endl << "Собираем колоду из " << kol << " карт ";
            cout << "6,7,8,9,10,V-валет,D-дама,К-король,T-туз" << endl;
            cout << "Krest-крести, CH-черви, Pik-вини, Bub-буби" << endl << endl;
            vector <Koloda> koloda;
            for (int i=0; i<4; i++) {
                for (int j=0; j<9; j++) {
                    koloda.push_back(Koloda(j, i));
                }
            }
            for (int i=0; i<kol; i++)
                cout << i+1 << " карта:= " << name[koloda[i].nominal]<<" "<<mastcard[koloda[i].mast] << endl;
            cout << endl << "Раздаем колоду карт из:"<< endl;
            srand(time(NULL));
            random_shuffle(koloda.begin(),koloda.end());
            for (int i=0; i<kol; i++)
                cout<<i+1 <<" карта:= " << name[koloda[i].nominal] <<" "<<mastcard[koloda[i].mast]<<endl;
            cout << endl;
            cout << "Карты одного цвета,лежащие рядом:" << endl;
            for (int i=0; i<kol-1; i++) {
                if (mastcard[koloda[i].mast] == mastcard[koloda[i+1].mast])
                    cout <<i+1 <<" карта:= " << name[koloda[i].nominal]<<" "<<mastcard[koloda[i].mast]<<" "<<i+2 <<" карта:= " << name[koloda[i+1].nominal]<<" "<<mastcard[koloda[i+1].mast]<<endl;
            }
            cout <<endl<< "Карты одного номинала,лежащие рядом: " << endl;
            for (int i=0; i<kol-1; i++) {
                if (name[koloda[i].nominal] == name[koloda[i+1].nominal])
                    cout<<i+1<<" "<<" карта:= " << name[koloda[i].nominal]<<" "<<mastcard[koloda[i].mast]<<", "<<i+2 <<" карта:= " << name[koloda[i+1].nominal]<<" "<<mastcard[koloda[i+1].mast]<< endl;
            }
            int i=0;
            cout << endl<<"Пиковая дама:= ";
            while (!((mastcard[koloda[i].mast] == mastcard[2]) && (name[koloda[i].nominal] == name[6]))) {
                i=i+1;
            }
            cout << i+1 << " Дама пики в колоде"<< endl;
            cout << "Тузы в колоде: "<<endl;
            for (int i=0; i<=kol; i++) {
                if (name[koloda[i].nominal] == name[8])
                    cout<<i+1 <<" карта"<< endl;
            }
            cout<<endl;
            cout<<"Масть:номинал"<<endl;
            for(int i=0; i<kol; i++) {
                cout<<i+1<<" карта "<<mastcard[koloda[i].mast]<<":"<<name[koloda[i].nominal]<<endl;
            }
        }
    } while (p!=0);
    return 0;
}
