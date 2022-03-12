#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int a=20, b=40;
/*
directia 1 : i,j++;
directia 2 : i,j--;
directia 3 : i--.j;
directia 4 : i++,j;



*/
int directie=1;
int marpozy,marpozx;
int meremancate=0;
int marmancat=1;
int n=3;
struct jucator
{
    int x,y;
}juc1[100];
void SetColor(int valoare){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  valoare);
}
/* =Verifica daca un punct din matrice coincide cu coordonatele sarpelui= */
int verificaj1(int x,int y)
{
    for(int i=0;i<n;i++)
    {
      if(juc1[i].x==x && juc1[i].y==y)
      return 1;

    }
    return 0;
}
/* =Afiseaza sarpe si mapa= */
void afisare()
{cout<<"WEAU, ai mancat "<<meremancate<<" mere, ESPORTS PRO PLAYER !"<<endl;
    SetColor(2);
for(int i=0;i<=a+1;i++)
{
    for(int j=0;j<=b+1;j++)
            {if(i==0 && j==0)
                cout<<char(201);
            else if(i==a+1 && j==b+1)
                cout<<char(188);
            else if(i==a+1 && j==0)
                cout<<char(200);
            else if(i==0 && j==b+1)
                cout<<char(187);
            else if(i>0 && i<a+1 && j==0)
                {
                     if(i==juc1[0].x)
                {
                    SetColor(14);
                    cout<<char(186);
                    SetColor(2);
                }
                else
                    cout<<char(186);
                }
            else if(i>0 && i<a+1 && j==b+1)
                 {
                     if(i==juc1[0].x)
                {
                    SetColor(14);
                    cout<<char(186);
                    SetColor(2);
                }
                else
                    cout<<char(186);
                }
            else if(j>0 && j<b+1 && i==0)
                {
                     if(j==juc1[0].y)
                {
                    SetColor(14);
                    cout<<char(205);
                    SetColor(2);
                }
                else
                    cout<<char(205);
                }
            else if(j>0 && j<b+1 && i==a+1)
            {
                if(j==juc1[0].y)
                {
                    SetColor(14);
                    cout<<char(205);
                    SetColor(2);
                }
                else
                    cout<<char(205);
            }
            else if(verificaj1(i,j))
            {
                if(i==juc1[0].x && j==juc1[0].y)
                {
                    SetColor(14);
                    cout<<'@';
                    SetColor(2);
                }
                else
                {
                    SetColor(5);
                    cout<<'+';
                    SetColor(2);
                }
            }
            else   if(i==marpozx && j==marpozy)
            {
                SetColor(4);
                cout<<"*";
                SetColor(2);
            }
            else
                cout<<' ';
            }
cout<<endl;
        }
     Sleep(10);
system("cls");


}


 /* =JUCATORUL 1= */
void crearejuc()
{
    juc1[0].x=9;
    juc1[0].y=3;
    juc1[1].x=10;
    juc1[1].y=3;
    juc1[2].x=11;
    juc1[2].y=3;

}
/* =MISCARI= */
void sus()
{if(juc1[0].x-1>0)
    {for(int i=n-1; i>0; i--)
        juc1[i]=juc1[i-1];

    juc1[0].x-=1;
    }
}
void jos()
{if(juc1[0].x+1<a+1)
    {for(int i=n-1; i>0; i--)
        juc1[i]=juc1[i-1];
    juc1[0].x+=1;



    }
}
void dreapta()
{
if(juc1[0].y+1<b+1)
    {
        for(int i=n-1;i>0;i--)
        {
            juc1[i]=juc1[i-1];
        }
        juc1[0].y+=1;
    }

}
void stanga()
{if(juc1[0].y-1>0)
    {for(int i=n-1;i>0;i--)
        {
            juc1[i]=juc1[i-1];
        }
        juc1[0].y-=1;
    }
}
/* =VERIFICA DACA POZITIA CAP DE SARPE E ACEEASI CU A MARULUI= */
int mancatmar()
{
    if(juc1[0].x==marpozx && juc1[0].y==marpozy)
        return 1;
    return 0;
}
/* ="PUNE" LA O ANUMITA POZITIE UN MAR= */
void mere()
{
    if(marmancat==1)
        {srand(time(NULL));
        marpozx=rand()%10+1;
        marpozy=rand()%10+1;
        marmancat=0;
        }

}
/* =Verifica daca pozitia capului este la fel cu pozitia altui element din sarpe, exceptand varful cozii= */
int pierdut()
{
    for(int i=1;i<n-1;i++)
    {
        if(juc1[0].x==juc1[i].x && juc1[0].y==juc1[i].y)
            return 0;
    }
    return 1;

}



void joc()
{
    while(GetAsyncKeyState('P')==0 && pierdut()==1)
    {mere();
        afisare();
    while(GetAsyncKeyState('W')  && GetAsyncKeyState('S')!=1  && pierdut()==1 )
        {
            sus();
            afisare();

            if(mancatmar())
            {   marmancat=1;
                mere();
                meremancate+=1;
                juc1[n].x=juc1[n-1].x+1;
                juc1[n].y=juc1[n-1].y;
                n++;


            }



        }
        while(GetAsyncKeyState('S') && GetAsyncKeyState('W')!=1  && pierdut()==1)
        {
            jos();
            afisare();
           if(mancatmar())
            {   marmancat=1;
                mere();
                meremancate+=1;
                juc1[n].x=juc1[n-1].x+1;
                juc1[n].y=juc1[n-1].y;
                n++;


            }

        }

        while(GetAsyncKeyState('A') && GetAsyncKeyState('D')!=1  && pierdut()==1 )
        {
            stanga();
            afisare();
            if(mancatmar())
            {marmancat=1;
                mere();
                meremancate+=1;
                juc1[n].x=juc1[n-1].x+1;
                juc1[n].y=juc1[n-1].y;
                n++;

            }

        }
        while(GetAsyncKeyState('D')  && GetAsyncKeyState('A')!=1  && pierdut()==1 )
        {
            dreapta();
            afisare();
            if(mancatmar())
            {marmancat=1;
                mere();
                meremancate+=1;
                juc1[n].x=juc1[n-1].x+1;
                juc1[n].y=juc1[n-1].y;
                n++;

            }

        }





    }
    system("pause");
    cout<<"\n Slabule";
}
int main()
{cout<<"Acest joc nu este terminat : Snake \n";
cout<<"Control : \n";
cout<<" W=sus \n"<<" S=jos \n"<<" A= stanga \n"<<" S=dreapta \n ";
char raspuns;
cout<<"Doresti sa incepi un joc nou ? D/N";cin>>raspuns;
if(raspuns=='D')
{system("pause");
crearejuc();
joc();}
else
    cout<<"Foarte Bine o zi buna ! ";
    return 0;
}
