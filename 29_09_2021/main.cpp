#include <bits/stdc++.h>

using namespace std;
//PROGRAM koji provjerava jel matrica dijagonalna ili jedinicna

void ispisPolje(int *polje,int N, int M)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout<<"["<<*(polje+(i*M)+j)<<"] ";
        }
        cout<<endl;
    }
}

void rucniUnos(int *polje, int N, int M)
{
    cout<<"Rucni unos\n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin>>*(polje+(i*M)+j);
        }
    }

}


void generirajPolje(int *polje, int N, int M)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            *(polje+(i*M)+j) = rand()%9+ 1;
        }
    }


}


int main()
{
    int N,M;
    bool dijagonalna = true,jedinicna = true,gornjeTrokutasta = true, donjeTrokutasta = true;

    cout<<"Unesi 2 broja\n";
    cin>>N>>M;

    int polje[N][M];

    rucniUnos(&polje[0][0],N,M);
    //generirajPolje(&polje[0][0],N,M);

    ispisPolje(&polje[0][0],N,M);


    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            {
                if(i == j)
                    if(polje[i][j] != 1)
                        jedinicna = false;
                if(i != j)
                    if(polje[i][j] != 0)
                        dijagonalna = false;
                if(j > i)
                    if(polje[i][j] != 0)
                        donjeTrokutasta = false;
                if(j < i)
                    if(polje[i][j] != 0)
                        gornjeTrokutasta = false;
            }
    }

    if(jedinicna)
        cout<<"jedinicna\n";
    else if(dijagonalna)
        cout<<"dijagonalna\n";
    else
        cout<<"ni dijagonalna ni jedinicna\n";

    if(gornjeTrokutasta)
        cout<<"gornjeTrokutasta\n";

    if(donjeTrokutasta)
        cout<<"donjeTrokutasta\n";





    return 0;
}
