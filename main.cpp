#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int m, x, s;
char c[100], completare[100], introdus[100];
string cuv;

void reguli()
{
    cout<<endl;
    cout<<"Regulile jocului: "<<endl;
    cout<<"1. Tasteaza doar litere mici!"<<endl;
    cout<<"2. Distreaza-te!"<<endl;
    cout<<"3. Daca pierzi, spanzura-te!"<<endl;
    cout<<endl;
}

void citire_random()
{
    string cuvinte[1000];
    int nr_cuvinte = 0;
    ifstream f;
    f.open("cuvinte.txt");
    while(f >> cuvinte[nr_cuvinte])
    {
        f >> cuvinte[nr_cuvinte];
        nr_cuvinte++;
    }
    srand(time(0));
    string cuv = cuvinte[rand() % nr_cuvinte];
    //cout<<cuv<<endl;

    const int n = cuv.length();
    m=n;
    x=n;
    //cout<<n<<endl;
    char cuvin[n+1];
    strcpy(cuvin, cuv.c_str());
    strcpy(c, cuvin);
    for(int i = 0; i < m; i++)
        completare[i] = {0};
    introdus[100] = {0};
    s=0;
    //for(int i=0; i<m; i++)
    //cout<<c[i];
}

void prima_afisare()
{
    for(int i = 0; i < m; i++)
    {
        cout<<" "<<"_"<<" ";
        //char completare[i] = {'_'}; - nu merge!!!!!!!!!!!!!!!!!!!!!!
    }
}

int verificare(char a)
{
    int ok = 0, dubluri = 0;
    for(int i = 0; i < m; i++)
    {
        if(c[i] == a)
        {
            dubluri++;
            ok = 1;
            completare[i] = a;
            introdus[s] = a;
            s++;
        }
    }
    if(dubluri >= 1)
        x =x - dubluri;
    if(ok == 1)
        return 1;
    else return 0;
}

int complet()
{
    int ok = 0;
    for(int i = 0; i < m; i++)
    {
        if(c[i] == completare[i])
            ok = 1;
        //cout<<completare[i];
    }
    if(ok)
        return 1;
    else return 0;
}

void afisare_finala()
{
    for(int i = 0; i < m; i++)
        cout<<" "<<completare[i]<<" ";
}

int spanzuratoarea()
{
    int incercari = 7, castigat = 0;
    char a;
    //for(int i = 0; i < m; i++)
    //cout<<c[i]<<" ";
    cout<<"Cuvantul a fost selectat!"<<endl;
    cout<<"Aveti "<<incercari<<" incercari!"<<endl;
    cout<<endl;
    cout<<"~~Success~~"<<endl;
    cout<<endl;
    cout<<"Cuvantul are "<<m<<" litere"<<endl;
    prima_afisare();
    cout<<endl;
    while(incercari != 0 || castigat == 1)
    {
        cout<<endl;
        cout<<"Introduceti litera: ";
        cin>>a;
        if(verificare(a) == 1)
        {
            if(x != 0)
            {
                for(int j = 0; j < m; j++)
                {
                    if(completare[j] != 0)
                        cout<<" "<<completare[j]<<" ";
                    else cout<<" "<<"_"<<" ";
                }
                cout<<endl;
            }
            else
            {
                afisare_finala();
                cout<<endl;
                break;
            }
        }
        else
        {
            cout<<endl;
            cout<<"GRESIT!"<<endl;
            incercari--;
            cout<<"Mai ai "<<incercari<<" incercari!"<< endl;
            for(int j = 0; j < m; j++)
            {
                if(completare[j] != 0)
                    cout<<" "<<completare[j]<<" ";
                else cout<<" "<<"_"<<" ";
            }
            cout<<endl;
        }
    }
    if(castigat == 1 || incercari > 0)
        return 1;
    else return 0;
}

int main()
{
    char rasp[1];
    int again = 1;
    cout<<"Bine ai venit la ~SPANZURATOAREA!~"<<endl;
    cout<<endl;
    reguli();
    cout<<"Vrei sa joci?"<<endl;
    cout<<endl;
    cout<<"Y - da"<<"       "<<"N - nu"<<endl;
    cin>>rasp[1];
    cout<<endl;
    if(rasp[1] == 'Y' || rasp[1] == 'y')
    {
        while(again)
        {
            //cout<<"1";
            citire_random();
            //for(int i = 0; i<m; i++)
            //cout<<c[i]<<endl;
            if(spanzuratoarea() == 1)
            {
                cout<<endl;
                cout<<"Cuvantul final: ";
                for(int i = 0; i < m; i++)
                    cout<<completare[i];
                cout<<endl;
                cout<<"Felicitari! Ai castigat!";
                cout<<endl;
            }
            else
            {
                cout<<endl;
                cout<<"Imi pare rau! Ai pierdut!"<<endl;
                cout<<"Cuvantul tau era: ";
                for(int i = 0; i < m; i++)
                    cout<<c[i];
                cout<<endl;
            }
            cout<<"Vrei sa mai joci?"<<endl;
            cout<<endl;
            cout<<"Y - da"<<"       "<<"N - nu"<<endl;
            cin>>rasp[1];
            cout<<endl;
            if(rasp[1] == 'Y' || rasp[1] == 'y')
                again = 1;
            else again = 0;
        }
        cout<<"Pe data viitoare!";
        cout<<endl;
    }
    else cout<<"Pe data viitoare!";
    cout<<endl;
}
