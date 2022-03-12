#include <iostream>
#include <windows.h>
///directie 1= i-- , j++
///directie 2= i++ , j++
///directie 3= i++ , j--
///directie 4= i-- , j--
using namespace std;
int m[100][100];
int directie=1;
int a,b;
int k=0,nrmut=0;
int pozvec=0;
int nafisate=0;
int n;
int culoare=1;
void SetColor(int valoare){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  valoare);
}
struct punct{
int x,y,nrcur;
}vd[700];

// vector deplasari
int afiseaza(int i,int j)
{
    for(int num=nafisate;num<n;num++)
    {
        if(i==vd[num].x && j==vd[num].y)
            return 1;

    }
    return 0;

}
void afisare()
{
    //cout<<"X="<<vd[pozvec].x<<",y="<<vd[pozvec].y<<" \n Numar Lov : "<<k<<endl;
cout<<" Numar curent :"<<vd[n].nrcur<<'\n';
for(int i=0;i<=a+1;i++)
{
    for(int j=0;j<=b+1;j++)
        {
            if(i==0 && j==0)
                cout<<char(201);
            else if(i==a+1 && j==b+1)
                cout<<char(188);
            else if(i==a+1 && j==0)
                cout<<char(200);
            else if(i==0 && j==b+1)
                cout<<char(187);
            else if(i>0 && i<a+1 && j==0)
                cout<<char(186);
            else if(i>0 && i<a+1 && j==b+1)
                cout<<char(186);
            else if(j>0 && j<b+1 && i==0)
                cout<<char(205);
            else if(j>0 && j<b+1 && i==a+1)
                cout<<char(205);
            else if(afiseaza(i,j))
                {   if(culoare==16)
                        culoare=1;
                    SetColor(culoare);
                    cout<<'+';
                    culoare++;
                    SetColor(15);
                }

            else
                cout<<' ';

        }
        cout<<endl;
}
nafisate+=1;
n++;

Sleep(100);
system("cls");
}
int verifica(int i,int j)
{
    if(i==1 && j==1 && directie==4)
        return 1;
    if(i==1 && j==b && directie==1)
        return 1;
    if(i==a && j==b && directie==2)
        return 1;
    return 0;
}
int muchielovita(int i,int j)
{//888888
    if(i==1 && directie==1)
        return 1;
    if(i==1 && directie==4)
        return 1;
//888888
    if(i==a && directie==2)
        return 1;
    if(i==a && directie==3)
        return 1;
//888888
    if(j==1 && directie==4)
        return 1;
    if(j==1  && directie==3)
        return 1;
//88888
    if(j==b && directie==1)
        return 1;
    if(j==b && directie==2)
        return 1;
//999

    return 0;
}
int deplas()
{
    for(int i=0;i<nrmut;i++)
        afisare();
}
int main()
{int i,j;
    cout<<"Te rog sa introduci latimea, respectiv lungimea : ";
    cin>>a>>b;
    cout<<endl;
    cout<<"Introdu lungimea razei : ";cin>>n;

    i=a;
    j=1;
//cout<<i<<' '<<j<<endl;
//m[i][j]=directie;
//afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;


    while(verifica(i,j)==0)
    {
        if(muchielovita(i,j)==0)
        {
            switch(directie)
            {

                case 1:{i--;j++;break;}
                case 2:{i++;j++;break;}
                case 3:{i++;j--;break;}
                case 4:{i--;j--;break;}

            }
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;

//            m[i][j]=directie;
//            afisare(i,j);


        }
        else
        {
             /* =1= */
            if(directie==1 && j==b)
                {
                    directie=4;
                    i--;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;

                }
            if(directie==1 && i==1)
                {
                    directie=2;
                    j++;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;

                }
            /* =2= */
            if(directie==2 && j==b)
                {
                    directie=3;
                    i++;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;
                }
            if(directie==2 && i==a)
                {
                    directie=1;
                    j++;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;
                }
            /* =3= */
            if(directie==3 && j==1)
                {
                    directie=2;
                    i++;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;
                }
            if(directie==3 && i==a)
                {
                    directie=4;
                    j--;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;
                }
            /* =4= */
            if(directie==4 && i==1)
                {
                    directie=3;
                    j--;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;
                }
            if(directie==4 && j==1)
                {
                    directie=1;
                    i--;
                    k++;
//                    m[i][j]=directie;
//                    afisare(i,j);
                    vd[nrmut].x=i;
                    vd[nrmut].y=j;
                    vd[nrmut].nrcur=k;
                    nrmut+=1;
                }



        }

    }
deplas();

    return 0;
}

