#include <iostream>
//#include "vehicul.h"===Clasa pt vehicule inainte de modificare
//#include "curier.h"
//#include "angajat.h"
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <math.h>       /* sqrt */
#include <cmath>
using namespace std;


class Angajat
{
protected:
    int nrang;
    int ore_zi;
    int salariu;
public:
    Angajat()
    {
    }
    Angajat(int na,int oz,int sal)
    {
        nrang=na;
        ore_zi=oz;
        salariu=sal;

    }
    Angajat(const Angajat &A)
    {
        nrang=A.nrang;
        ore_zi=A.ore_zi;
        salariu=A.salariu;

    }
    Angajat operator=(const Angajat &c)
    {

        nrang=c.nrang;
        ore_zi=c.ore_zi;
        salariu=c.salariu;


    }

};
class Manager:public Angajat
{
    int actiune;
    int acces=1;
public:
    Manager(int act,int na,int oz,int sal):Angajat(na,oz,sal)
    {

        actiune=act;
    }
    Manager(const Manager &c)
    {
        nrang=c.nrang;
        ore_zi=c.ore_zi;
        salariu=c.salariu;
        actiune=c.actiune;

    }
    int returntipacces()
    {
        return acces;

    }
    void setActiune(int act)
    {
        actiune=act;

    }
    int getActiune()
    {
        return actiune;

    }
    Manager operator=(const Manager &c)
    {

        nrang=c.nrang;
        ore_zi=c.ore_zi;
        actiune=c.actiune;
        salariu=c.salariu;


    }



};
class Sofer:public Angajat
{
    int actiune;
public:
    Sofer():Angajat()
    {
    }

    Sofer(int act,int na,int oz,int sal):Angajat(na,oz,sal)
    {
        actiune=act;
    }
    Sofer(const Sofer &c)
    {
        nrang=c.nrang;
        ore_zi=c.ore_zi;
        actiune=c.actiune;
        salariu=c.salariu;

    }
    Sofer operator=(const Sofer &c)
    {

        nrang=c.nrang;
        ore_zi=c.ore_zi;
        actiune=c.actiune;
        salariu=c.salariu;


    }
    void modificaAct(int nr)
    {
        if(nr>3 || nr<=0)
            throw 1;
        else
            actiune=nr;

    }
    void setActiune(int act)
    {
        actiune=act;

    }
    int getActiune()
    {
        return actiune;

    }



};

class Colet
{
private:
    float masa,volum;
    int x,y;
    int dx,dy;
    int tiprece;
    int dl;
    int tipDl;
    int preluat=0;
public:
    Colet operator=(const Colet &c)
    {
        masa=c.masa;
        volum=c.volum;
        x=c.x;
        y=c.y;
        tipDl=c.tipDl;
        tiprece=c.tiprece;
        dx=c.dx;
        dy=c.dy;


    }
    Colet() {}

    Colet(float m,float v,int xx,int yy,int dxx,int dyy,int tr,int d,int tdl)
    {
        masa=m;
        volum=v;
        x=xx;
        y=yy;
        dx=dxx;
        dy=dyy;
        tiprece=tr;
        dl=d;
        tipDl=tdl;

    }

    Colet(const Colet &c)
    {
        masa=c.masa;
        volum=c.volum;
        x=c.x;
        y=c.y;
        dx=c.dx;
        dy=c.dy;
        tiprece=c.tiprece;
        dl=c.dl;
        tipDl=c.tipDl;

    }
    ~Colet()
    {
        cout<<"";

    }
    int returndl()
    {
        return dl;

    }
    int retm()
    {
        return masa;

    }
    int retv()
    {
        return volum;

    }
    void acceptat()
    {
        preluat=1;
    }
    int retStd()
    {
        return preluat;
    }
    int checkTlist(float masa_liber,float vol_liber,int tip)
    {
        if(tiprece==1)
        {
            if(tip!=1)
                return 0;
            if(masa_liber<masa)
                return 0;
            if(vol_liber<volum)
                return 0;

        }
        else
        {
            if(masa_liber<masa)
                return 0;
            if(vol_liber<volum)
                return 0;

        }
        return 1;
        cout<<masa_liber<<' '<<vol_liber<<' '<<tip<<endl;


    }
    int checkTimp(int vx,int vy,int tip,int vit)
    {
        if(tip==3)
            return (sqrt((vx-x)*(vx-x)+(vy-y)*(vy-y)))/vit;
        else
            return (abs(vx-x)+abs(vy-y))/vit;

    }
    int checkAprop(int vx,int vy,int tip,int vit)
    {
        if(tip==3)
            return sqrt((vx-x)*(vx-x)+(vy-y)*(vy-y));
        else
            return abs(vx-x)+abs(vy-y);

    }
    int checkDurata(int vit,int t)
    {

        if(t==3)
            return sqrt((x-dx)*(x-dx)+(y-dy)*(y-dy))/vit;
        else
            return abs(dx-x)+abs(dy-y)/vit;

    }
    int returnX()
    {
        return x;

    }
    int returnY()
    {
        return y;

    }
    int returndX()
    {
        return dx;

    }
    int returndY()
    {
        return dy;

    }
    void afisare()
    {
//        float masa,volum;
//        int x,y;
//        int dx,dy;
//        int tiprece;
        cout<<"Masa : "<<masa<<endl;
        cout<<"Volum : "<<volum<<endl;
        cout<<"Coordonate Gps"<<endl<<"x="<<x<<' '<<"y="<<y<<endl;
        cout<<"Coordonate Destinatie"<<endl<<"x="<<dx<<' '<<"y="<<dy<<endl;
        cout<<"Tip Rece:"<<tiprece<<endl<<endl;



    }
    ostream& operator<<(ostream& os){
        os<<"Masa : "<<masa<<endl;
        os<<"Coordonate Gps"<<endl<<"x="<<x<<' '<<"y="<<y<<endl;
        os<<"Volum : "<<volum<<endl;
        os<<"Coordonate Destinatie"<<endl<<"x="<<dx<<' '<<"y="<<dy<<endl;
        os<<"Tip Rece:"<<tiprece<<endl<<endl;
        return os;

    }
    istream& operator>> (istream& in){
//                float masa,volum;
//    int x,y;
//    int dx,dy;
//    int tiprece;
//    int dl;
//    int tipDl;
//    int preluat=0;
            cout<<"\nIntrodu tip : ";
            in>>tipDl;
            cout<<"\nIntrodu Masa disponibila : ";
            in>>masa;
            cout<<"\nIntrodu Volumul disponibil : ";
            in>>volum;
            cout<<"\nIntrodu coordonata X pe gps : ";
            in>>x;
            cout<<"\nIntrodu coordonata Y pe gps : ";
            in>>y;
            cout<<"\nIntrodu coordonata X destinatie pe gps : ";
            in>>dx;
            cout<<"\nIntrodu coordonata Y destinatie pe gps : ";
            in>>dy;
            cout<<"\nColetul trebuie sa ramana rece 1/0 :";
            in>>tiprece;
            cout<<"\nIntrodu deadline-ul in functie de tipul tau de deadline : ";
            in>>dl;
    return in;


    }



};


class Vehicul
{
private:
    float volum,masa;
    int viteza;
    int x,y;
    int tip;
    // int portbagaj[100];
public:
    Vehicul();
    Vehicul(float vol=0,float mass=0,int xx=0,int yy=0,int t=0)
    {
        if(vol<0 || mass<0 || t>4 || t<0)
            throw 1;

        volum=vol;
        masa=mass;
        x=xx;
        y=yy;
        tip=t;


    }

    Vehicul(const Vehicul &v)
    {
        volum=v.volum;
        masa=v.masa;
        x=v.x;
        y=v.y;
        tip=v.tip;
        tip=v.viteza;


    }
    ~Vehicul()
    {
        cout<<"Si a terminat lucrul.";

    }
    void setViteza(int vitez)
    {
        viteza=vitez;
    }
    int returnX()
    {
        return x;

    }
    int returnY()
    {
        return y;

    }
    int returnViteza()
    {
        return viteza;
    }
    int returntip()
    {
        return tip;
    }
    int returnMasa()
    {
        return masa;
    }
    int returnVolum()
    {
        return volum;
    }
    Vehicul operator=(const Vehicul &c)
    {
        masa=c.masa;
        volum=c.volum;
        x=c.x;
        y=c.y;
        tip=c.tip;
        viteza=c.viteza;


    }
    void modifica_MVD(float v,float m)
    {
        masa-=m;
        volum-=v;

    }
    void modifica_XY(int xnou,int ynou)
    {
        x=xnou;
        y=ynou;

    }
//    void adaugaObj(int nr_Obj)
//    {
//        portbagaj[portbagaj[0]+1]=nr_Obj;
//        portbagaj[0]++;
//
//    }
//    int returnNR_OBJ()
//    {
//        return portbagaj[0];
//
//    }
    void afisare()
    {

        // cout<<volum<<' '<<masa<<' '<<viteza<<' '<<'\n';
        cout<<"Volum : "<<volum<<endl;
        cout<<"Masa: "<<masa<<endl;
        cout<<"Viteza: "<<viteza<<endl;
        cout<<"Tip: ";
        switch (tip)
        {
        case 1:
            cout<<"Duba Rece\n\n";
            break;
        case 2:
            cout<<"Duba\n\n";
            break;
        case 3:
            cout<<"Scuter\n\n";
            break;
        default:
            cout<<"Masina\n\n";

        }
    }
    float calcTimpDist(int dx,int dy)
    {
        if(tip==3)
            return (sqrt((dx-x)*(dx-x)+(dy-y)*(dy-y)))/viteza;
        else
            return (abs(dx-x)+abs(dy-y))/viteza;
    }
    virtual void afiss()
    {
        cout<<"este masina";
    }
    friend ostream& operator<<(ostream& os, const Vehicul &V);
    friend istream& operator>> (istream& in, Vehicul &v);


};
ostream& operator<<(ostream& os, const Vehicul& V)
{

    os<<"Volum : "<<V.volum<<endl;
    os<<"Masa: "<<V.masa<<endl;
    os<<"Viteza: "<<V.viteza<<endl;
    os<<"Tip: ";
    switch (V.tip)
    {
    case 1:
        os<<"Duba Rece\n\n";
        break;
    case 2:
        os<<"Duba\n\n";
        break;
    case 3:
        os<<"Scuter\n\n";
        break;
    default:
        os<<"Masina\n\n";

    }
    return os;
}
istream& operator>> (istream& in, Vehicul &v)
{
    cout<<"\n Introdu masa disponibila : ";
    in>>v.masa;
    cout<<"\n Introdu volumul disponibil : ";
    in>>v.volum;
    cout<<"\n Introdu coordonata x : ";
    in>>v.x;
    cout<<"\n Introdu coordonata y : ";
    in>>v.y;
    cout<<"\n Introdu tipul masini : ";
    in>>v.tip;



    return in;

}


class Duba:public Vehicul
{
private:

public:
    Duba(float vol=0,float mass=0,int xx=0,int yy=0,int t=1):Vehicul(vol,mass,xx,yy,t)
    {
        Vehicul::setViteza(5);
    }
    void afiss()
    {
        cout<<"Este duba";

    }
    ~Duba()
    {
        cout<<"Duba si-a terminat programul.";

    }
//    friend ostream& operator<<(ostream& os, const Duba &D);
//    friend istream& operator>> (istream& in, Duba &D);

};


class Scuter:public Vehicul
{
private:

public:
    Scuter(int xx=0,int yy=0,float vol=0,float mass=0,int t=3):Vehicul(vol,mass,xx,yy,t)
    {
        Vehicul::setViteza(20);


    }
    ~Scuter()
    {
        cout<<"Scuterul si-a terminat programul.";
    }
//    friend ostream& operator<<(ostream& os, const Scuter &S);
//    friend istream& operator>> (istream& in, Scuter &S);
};
class Masina:public Vehicul
{
private:

public:
    Masina(int xx=0,int yy=0,float vol=0,float mass=0,int t=4):Vehicul(vol,mass,xx,yy,t)
    {
        Vehicul::setViteza(10);


    }
    ~Masina()
    {
        cout<<"Masina a iesit.";


    }
//    friend ostream& operator<<(ostream& os, const Masina &M);
//    friend istream& operator>> (istream& in, Masina &M);
};


Vehicul *masiniCurierat[1000];//upcast
//vector <Vehicul *> masiniCurierat[1000];
int nr_masini;

Sofer Sofs[100];
//Manager Mana;
int nr_sof;
int ktimp;
int m[100][100];
int nrlin=0;
int ct=1,pu=0;//pt a modifica masa sau a umple mai intai vehiculul

Colet colete[1000];
int nr_colete;
int curent_time[1000];
void citireAngj()
{
    ifstream a("angajati.in");
    a>>nr_sof;
    int i;
    int act,na,oz,sal;
    for(i=0; i<nr_sof; i++)
    {
        a>>act>>na>>oz>>sal;
        Sofer A(act,na,oz,sal);
        Sofs[i]=A;
    }


}
void ordonareUrgenta()
{
    int i,j;

    for(i=0; i<nr_colete-1; i++)
    {
        for(int j=i+1; j<nr_colete; j++)
            if(colete[i].returndl()>colete[j].returndl())
                swap(colete[i],colete[j]);

    }
//       for(i=0; i<nr_colete; i++)
//        colete[i].afisare();
}
int returnClosestOpen()
{
    ordonareUrgenta();

    int i=0;
    int min_aprop=-1;
    int j=0;
    int mint=1000;
    for(j=0; j<nr_colete; j++)
    {
        mint=10000;
        int nr_ms=-1;

        if(colete[j].retStd()==0)
        {


            for(i=0; i<nr_masini; i++)
            {

                float m=masiniCurierat[i]->returnMasa();
                float v=masiniCurierat[i]->returnVolum();
                int t=masiniCurierat[i]->returntip();

                if(colete[j].checkTlist(m,v,t))
                {
                    int x=masiniCurierat[i]->returnX(),y=masiniCurierat[i]->returnY();
                    int vit=masiniCurierat[i]->returnViteza();
                    // cout<<' '<<colete[j].checDist(x,y,t,vit)<<endl;
                    if(mint>colete[j].checkAprop(x,y,t,vit))
                    {
                        //functie care sa verifice timpul pt curent pt ult obiect
                        mint=colete[j].checkAprop(x,y,t,vit);
                        nr_ms=i;
                    }

                }

            }
        }
        if(mint!=10000)
        {
            //cout<<mint<<' '<<nr_ms<<'\n';

            //scade masa maxx si volum in masina[ms];
            //  masiniCurierat[nr_ms]->afisare();

            masiniCurierat[nr_ms]->modifica_MVD(ct*colete[j].retm(),ct*colete[j].retv());
            masiniCurierat[nr_ms]->modifica_XY(ct*colete[j].returnX()+pu*colete[j].returndX(),colete[j].returnY()+pu*colete[j].returndY());
            curent_time[nr_ms]+=mint;
            cout<<"Masina " <<nr_ms<<" modificata in, datorita coletului "<< j<< ":\n";
            masiniCurierat[nr_ms]->afisare();
            //cout<<colete[j].retm()<<','<<colete[j].retv()<<endl;
            m[nr_ms][m[nr_ms][0]+1]=j;
            m[nr_ms][0]+=1;

        }
        else
            cout<<"Colet "<<j<<" refuzat.\n";

    }




}
int returnLowOpen()
{
    int i=0;
    int min_aprop=-1;
    int j=0;
    float mint=1000;
    for(j=0; j<nr_colete; j++)
    {
        mint=10000;
        int nr_ms=-1;

        if(colete[j].retStd()==0)
        {


            for(i=0; i<nr_masini; i++)
            {

                float mass=masiniCurierat[i]->returnMasa();
                float v=masiniCurierat[i]->returnVolum();
                int t=masiniCurierat[i]->returntip();

                if(colete[j].checkTlist(mass,v,t))
                {
                    int x=masiniCurierat[i]->returnX(),y=masiniCurierat[i]->returnY();
                    int vit=masiniCurierat[i]->returnViteza();
                    // cout<<' '<<colete[j].checDist(x,y,t,vit)<<endl;
                    if(mint>m[int(i)][0])
                    {
                        //functie care sa verifice timpul pt curent pt ult obiect
                        mint=m[i][0];

                        nr_ms=i;

                    }

                }

            }
        }
        if(nr_ms!=-1)
        {
            //cout<<mint<<' '<<nr_ms<<'\n';

            //scade masa maxx si volum in masina[ms];
            // masiniCurierat[nr_ms]->afisare();
            masiniCurierat[nr_ms]->modifica_MVD(ct*colete[j].retm(),ct*colete[j].retv());
            masiniCurierat[nr_ms]->modifica_XY(ct*colete[j].returnX()+pu*colete[j].returndX(),ct*colete[j].returnY()+pu*colete[j].returndY());

            //masiniCurierat[nr_ms]->modifica_MVD(colete[j].retm(),colete[j].retv());
            //masiniCurierat[nr_ms]->modifica_XY(colete[j].returnX(),colete[j].returnY());
            cout<<"Masina "<< nr_ms << "modficata in, datorita colet "<<j<<" :\n";
            masiniCurierat[nr_ms]->afisare();
            cout<<colete[j].retm()<<','<<colete[j].retv()<<endl;
            m[nr_ms][m[nr_ms][0]+1]=j;
            m[nr_ms][0]+=1;

        }
        else
            cout<<"Colet "<< j <<" refuzat.\n";

    }



}
int returnFastOpen2()
{

    int i=0;
    int min_aprop=-1;
    int j=0;
    int mint=1000;
    for(j=0; j<nr_colete; j++)
    {
        mint=10000;
        int nr_ms=-1;

        if(colete[j].retStd()==0)
        {


            for(i=0; i<nr_masini; i++)
            {

                float m=masiniCurierat[i]->returnMasa();
                float v=masiniCurierat[i]->returnVolum();
                int t=masiniCurierat[i]->returntip();
                //  cout<<t<<' ';

                if(colete[j].checkTlist(m,v,t))
                {
                    int x=masiniCurierat[i]->returnX(),y=masiniCurierat[i]->returnY();
                    int vit=masiniCurierat[i]->returnViteza();
                    // cout<<' '<<colete[j].checDist(x,y,t,vit)<<endl;

                    if(mint>colete[j].checkDurata(vit,t))
                    {
                        //functie care sa verifice timpul pt curent pt ult obiect
                        mint=colete[j].checkDurata(vit,t);
                        nr_ms=i;
                    }

                }

            }
        }
        if(nr_ms!=-1)
        {
            //cout<<mint<<' '<<nr_ms<<'\n';

            //scade masa maxx si volum in masina[ms];
            //masiniCurierat[nr_ms]->afisare();

            masiniCurierat[nr_ms]->modifica_MVD(ct*colete[j].retm(),ct*colete[j].retv());
            masiniCurierat[nr_ms]->modifica_XY(ct*colete[j].returnX()+pu*colete[j].returndX(),ct*colete[j].returnY()+pu*colete[j].returndY());
            cout<<"Masina " <<nr_ms<<" modificata in, datorita coletului: "<<j<<" :\n";

            masiniCurierat[nr_ms]->afisare();
            curent_time[nr_ms]=mint+colete[j].checkTimp(masiniCurierat[nr_ms]->returnX(),masiniCurierat[nr_ms]->returnY(),masiniCurierat[nr_ms]->returntip(),masiniCurierat[nr_ms]->returnViteza());
            //colete[j].checkDurata(vit,t)+colete[j].checkTimp(x,y,t,vit);
            //cout<<colete[j].retm()<<','<<colete[j].retv()<<endl;
            m[nr_ms][m[nr_ms][0]+1]=j;
            m[nr_ms][0]+=1;

        }
        else
            cout<<"Colet "<<j<< " refuzat.\n";

    }



}




int returnFastOpen1()
{

    int i=0;
    int min_aprop=-1;
    int j=0;
    int mint=1000;
    for(j=0; j<nr_colete; j++)
    {
        mint=10000;
        int nr_ms=-1;

        if(colete[j].retStd()==0)
        {


            for(i=0; i<nr_masini; i++)
            {

                float m=masiniCurierat[i]->returnMasa();
                float v=masiniCurierat[i]->returnVolum();
                int t=masiniCurierat[i]->returntip();
                //cout<<t<<' ';

                if(colete[j].checkTlist(m,v,t))
                {
                    int x=masiniCurierat[i]->returnX(),y=masiniCurierat[i]->returnY();
                    int vit=masiniCurierat[i]->returnViteza();
                    // cout<<' '<<colete[j].checDist(x,y,t,vit)<<endl;

                    if(mint>colete[j].checkDurata(vit,t)+colete[j].checkTimp(x,y,t,vit))
                    {
                        //functie care sa verifice timpul pt curent pt ult obiect
                        mint=colete[j].checkDurata(vit,t)+colete[j].checkTimp(x,y,t,vit);
                        nr_ms=i;
                    }

                }

            }
        }
        if(nr_ms!=-1)
        {
            //cout<<mint<<' '<<nr_ms<<'\n';

            //scade masa maxx si volum in masina[ms];
            // masiniCurierat[nr_ms]->afisare();
            cout<<"Masina " <<nr_ms<<" modificata in, datorita coletului: "<<j<<" :\n";
            masiniCurierat[nr_ms]->modifica_MVD(colete[j].retm(),colete[j].retv());
            masiniCurierat[nr_ms]->modifica_XY(colete[j].returnX(),colete[j].returnY());
            masiniCurierat[nr_ms]->afisare();
            //cout<<colete[j].retm()<<','<<colete[j].retv()<<endl;
            m[nr_ms][m[nr_ms][0]+1]=j;
            m[nr_ms][0]+=1;

        }
        else
            cout<<"Colet "<< j << " refuzat.\n";

    }



}








void citireCurierat()
{
//{
//    Duba(int frig=0,float vol=0,float mass=0,int xx=0,int yy=0,tip):Vehicul(vol,mass,xx,yy){
//        Vehicul::setViteza(5);
//        rece=frig;
//
//        }

}

void citireColete()
{
    cout<<"\nDoresti sa citesti datele pentru colete de la tastatura sau ai prefera sa folosesti functia de autocitire 1/0 : ";
    int rasp;
    cin>>rasp;
    if(rasp==0)
    {
        ifstream g("colete.in");
        g>>nr_colete;
        int i,m,v,x,y,dx,dy,tr,dl,tdl;
        //Colet(int m,int v,int xx,int yy,int dxx,int dyy,int tr)

        for(i=0; i<nr_colete; i++)
        {
            g>>m>>v>>x>>y>>dx>>dy>>tr>>dl>>tdl;
            if(tdl<=3)
            {
                Colet C(m,v,x,y,dx,dy,tr,dl,tdl);
                colete[i]=C;
            }
            else
            {
                i-=1;
                nr_colete-=1;

            }

        }

    }
    else
    {

        cout<<"\n Introdu noul numar de colete actual : ";
        cin>>nr_colete;
        int i,m,v,x,y,dx,dy,tr,dl,tdl;
        //Colet(int m,int v,int xx,int yy,int dxx,int dyy,int tr)
        system("cls");

        for(i=0; i<nr_colete; i++)
        {
//            g>>m>>v>>x>>y>>dx>>dy>>tr>>dl>>tdl;
            cout<<"\Coletul ["<<i<<"]";
            cout<<"\nIntrodu tip : ";
            cin>>tdl;
            cout<<"\nIntrodu Masa disponibila : ";
            cin>>m;
            cout<<"\nIntrodu Volumul disponibil : ";
            cin>>v;
            cout<<"\nIntrodu coordonata X pe gps : ";
            cin>>x;
            cout<<"\nIntrodu coordonata Y pe gps : ";
            cin>>y;
            cout<<"\nIntrodu coordonata X destinatie pe gps : ";
            cin>>dx;
            cout<<"\nIntrodu coordonata Y destinatie pe gps : ";
            cin>>dy;
            cout<<"\nColetul trebuie sa ramana rece 1/0 :";
            cin>>tr;
            cout<<"\nIntrodu deadline-ul in functie de tipul tau de deadline : ";
            cin>>dl;

            if(tdl<=3)
            {
                Colet C(m,v,x,y,dx,dy,tr,dl,tdl);
                colete[i]=C;
            }
            else
            {
                i-=1;
                nr_colete-=1;


            }
            system("cls");


        }
    }

//    for(i=0; i<nr_colete; i++)
//        colete[i].afisare();
//
//





}

void closestPossible()
{
    int i,j;

    int mint=10000000,nr_col=-1;
    for(i=0; i<nr_masini; i++)
    {
        mint=100000;
        nr_col=-1;

        for(j=0; j<nr_colete; j++)
        {
            if(colete[j].retStd()==0)
            {

                float m=masiniCurierat[i]->returnMasa();
                float v=masiniCurierat[i]->returnVolum();
                int t=masiniCurierat[i]->returntip();
                //cout<<t<<' ';

                if(colete[j].checkTlist(m,v,t))
                {
                    int x=masiniCurierat[i]->returnX(),y=masiniCurierat[i]->returnY();
                    int vit=masiniCurierat[i]->returnViteza();
                    // cout<<' '<<colete[j].checDist(x,y,t,vit)<<endl;
                    if(mint>colete[j].checkAprop(x,y,t,vit))
                    {
                        //functie care sa verifice timpul pt curent pt ult obiect
                        mint=colete[j].checkAprop(x,y,t,vit);
                        nr_col=j;
                    }



                }


            }





        }
        if(nr_col!=-1)
        {
            //masiniCurierat[i]->afisare();
            masiniCurierat[i]->modifica_MVD(ct*colete[nr_col].retm(),ct*colete[nr_col].retv());
            masiniCurierat[i]->modifica_XY(ct*colete[nr_col].returnX()+pu*colete[nr_col].returndX(),colete[nr_col].returnY()+pu*colete[nr_col].returndY());
            cout<<"Masina " <<i<<" modificata in, datorita coletului: "<<nr_col<<" :\n";

            masiniCurierat[i]->afisare();

            //cout<<colete[nr_col].retm()<<','<<colete[nr_col].retv()<<endl;
            m[i][m[i][0]+1]=nr_col;
            m[i][0]+=1;
            colete[nr_col].acceptat();

        }
        else
        {
            cout<<"Nu exista colet valabil pt masina "<<i<<'\n';

        }



    }



}

int main()
{

    int i;
    int x,y;
    float m,v;
    int tip,rece;
    int rasp;
tryagain:
    try
    {
        system("cls");

        cout<<"Doresti sa citesti datele de la tastatura sau ai prefera sa folosesti functia de autocitire 1/0 : ";

        cin>>rasp;

        if(rasp!=0 && rasp!=1)
            throw 2;
    }
    catch(int caz)
    {
        if(caz==2)
            cout<<"Ai introdus un raspuns gresit.Incearca din nou :) ";
        getchar();
        goto tryagain;
    }
    system("cls");
    ifstream f("curierat.in");
    // ifstream f("curierat.in");
    f>>nr_masini;
    nrlin=nr_masini;

    if(rasp==0)
    {
        for(i=0; i<nr_masini; i++)
        {
            f>>x>>y>>m>>v>>tip;
            if(tip==1)
            {
                Duba D(v,m,x,y,tip);
                masiniCurierat[i]=&D;

            }
            if(tip==2)
            {
                Duba D(v,m,x,y,tip);
                masiniCurierat[i]=&D;

            }
            if(tip==3)
            {

                Scuter S(x,y,v,m,tip);
                masiniCurierat[i]=&S;

            }
            if(tip==4)
            {

                Masina M(x,y,v,m,tip);
                masiniCurierat[i]=&M;

            }
        }
        goto jover;
    }
    cout<<"Introdu numarul de masini, te rog : ";
    cin>>nr_masini;
    for(i=0; i<nr_masini; i++)
    {
        cout<<"\n Tipurile de masini sunt : "<<"\n1.Duba Rece"<<"\n2.Duba Normala"<<"\n3.Scuter"<<"\n4.Masina\n";
        cout<<"\nVehiculul ["<<i<<"]";
        cout<<"\nIntrodu tip : ";
        cin>>tip;
        cout<<"\nIntrodu Masa disponibila : ";
        cin>>m;
        cout<<"\nIntrodu Volumul disponibil : ";
        cin>>v;
        cout<<"\nIntrodu coordonata X pe gps : ";
        cin>>x;
        cout<<"\nIntrodu coordonata Y pe gps : ";
        cin>>y;
        if(tip==1)
        {
            Duba D(v,m,x,y,tip);
            masiniCurierat[i]=&D;

        }
        if(tip==2)
        {
            Duba D(v,m,x,y,tip);
            masiniCurierat[i]=&D;

        }
        if(tip==3)
        {

            Scuter S(x,y,v,m,tip);
            masiniCurierat[i]=&S;

        }
        if(tip==4)
        {

            Masina M(x,y,v,m,tip);
            masiniCurierat[i]=&M;

        }
        system("cls");


    }



jover:
    system("cls");
    citireColete();
    citireAngj();
    system("cls");
    //cout<<"============================----=============\n";
    // Pt cel mai aproape sofer de colet === //////
    //returnClosestOpen();
    // cout<<"===================================================\n";
    // =======Pt cel mai rapid=============//
    //returnFastOpen1();
    // cout<<"===================================================\n";
    //=========== Pt cel mai gol vehicul======//
    //returnLowOpen();
    //===========Pentru cel mai aproape colet de sofer====//
    //   cout<<"===================================================\n";

    //closestPossible();
loop:
    int tact_firma,tact_sofer;
    cout<<"Buna ziua, cum doriti sa ordonam operatiile?\n";
    cout<<"Tactica pentru toata firma: \n";
    cin>>tact_firma;
    cout<<"\nColectam prima data ? Introdu 0/1 in caz de livrari+colectari: ";
    cin>>pu;
    if(pu==1)
        ct=0;
    cout<<"\n In urmatoarele momente o sa setezi tacticile pentru soferi :";
    cin>>tact_sofer;
    if(tact_firma==1)
        returnClosestOpen();
    else if(tact_firma==2 && tact_sofer==1)

    {
        returnFastOpen1();
        ordonareUrgenta();
    }

    else if(tact_firma==2)
        returnFastOpen2();
    else if(tact_firma=3 && tact_sofer==1)
    {
        returnLowOpen();
        ordonareUrgenta();
    }
    else if(tact_sofer==2)
        closestPossible();
    cout<<"\nContinuam? 1/0. Raspuns : ";
    cin>>rasp;
    if(rasp==1)
        goto loop;



    return 0;
}
