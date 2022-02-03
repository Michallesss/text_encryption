#include<iostream>
#include<cstring>

using namespace std;

bool sprawdz(char litera)
{
    switch(litera)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return 0;    
    }
    return 1;
}

void szyfrowanie(char *napis)
{
    int dl = strlen(napis); 
    
    bool f=1;
    int nr;
    char first;
    
    for(int i=0;i<dl;i++)
        {
            if(sprawdz(napis[i]))
            {
                if(f)
                {
                    nr = i;
                    first = napis[i];
                    f = 0;
                }
                else
                {
                    char pom = napis[i];
                    napis[i] = first;
                    first = pom;
                }    
            }
            
        }
        if(!f)
            napis[nr] = first;
}

void deszyfrowanie(char *napis)
{
    int dl = strlen(napis);
    
    
    bool f=1;   
    int nr;    
    char first;    
    
    for(int i=dl-1;i>=0;i--)
        {
            if(sprawdz(napis[i]))
            {
                if(f)    
                {        
                    nr = i;
                    first = napis[i];
                    f = 0;
                }
                else 
                {
                    char pom = napis[i];
                    napis[i] = first;
                    first = pom;
                }    
            }
            
        }
        if(!f)
            napis[nr] = first;
}

int main()
{
    char napis[100];

    cout <<"OPCJE:" <<endl <<"1.Zaszyfruj" <<endl <<"2.Odszyfruj" <<endl;
    cout <<"Wybierz opcje(wybierz 1 lub 2):";
    int opcja;
    cin >> opcja;
    
    if(cin.fail())
    {
        cerr<<"nie ma takiej opcji!";
        system("pause");
        exit(0);
    }

    switch (opcja)
    {
    case 1:
        cout<<"Podaj napis do zaszyfrowania: ";
        cin >>napis;

        szyfrowanie(napis);
        cout <<"Zaszyfrowany tekst: " <<napis <<endl;
        break;
    
    case 2:
        cout<<"Podaj napis do odszyfrowania: ";
        cin >>napis;

        deszyfrowanie(napis);
        cout <<"Odszyfrowany tekst: " <<napis <<endl;
        break;
    }

    system("pause");
    return 0;
}