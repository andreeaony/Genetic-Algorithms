/*
//EX. 1

//1  1  1
//xP xQ xR
//yP yQ yR

#include <iostream>
#include <vector>
using namespace std;
long long numarTeste, xP, yP, xQ, yQ, xR, yR;
vector<string> rezultate={};
int main()
{
    cin>>numarTeste;
    for(int i=1; i<=numarTeste; i++)
    {
        cin>>xP>>yP>>xQ>>yQ>>xR>>yR;
        long long rezultat=xQ*yR+yP*xR+xP*yQ-xQ*yP-xR*yQ-xP*yR;

        if(rezultat==0)
            rezultate.push_back("TOUCH");
        else if(rezultat<0)
            rezultate.push_back("RIGHT");
        else rezultate.push_back("LEFT");
    }
    for(int i=0; i<rezultate.size(); i++)
        cout<<rezultate[i]<<'\n';
    return 0;
}
*/
/*
//EX. 2
#include <iostream>
using namespace std;
long long n, x, y;
int main()
{
    cin>>n;
    long long coordonateX[n+1]={0};
    long long coordonateY[n+1]={0};
    int viraje3[3]={0}; //stanga, dreapta, pe loc
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        coordonateX[i]=x;
        coordonateY[i]=y;
    }
    coordonateX[n]=coordonateX[0];
    coordonateY[n]=coordonateY[0];
    for(int i=0; i<n-1; i++)
    {
        long long rezultat=coordonateX[i+1]*coordonateY[i+2]+coordonateY[i]*coordonateX[i+2]+coordonateX[i]*coordonateY[i+1]-coordonateX[i+1]*coordonateY[i]-coordonateX[i+2]*coordonateY[i+1]-coordonateX[i]*coordonateY[i+2];
        if(rezultat==0)
            viraje3[2]++;
        else if(rezultat<0)
            viraje3[1]++;
        else viraje3[0]++;
    }
    cout<<viraje3[0]<<" "<<viraje3[1]<<" "<<viraje3[2];
    return 0;
}
*/
//EX. 3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Punct {
    long long x, y;
};

long long Orientare(Punct &p1, Punct &p2, Punct &p3) {
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

long long DistantaPatrat(Punct &p1, Punct &p2) {
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int main()
{
    long long n;
    cin>>n;
    vector<Punct> puncte(n);

    for(int i=0; i<n; i++)
        cin>>puncte[i].x>>puncte[i].y;

    if(n<3)
    {
        cout<<n<<endl;
        for(auto &p : puncte)
            cout<<p.x<<" "<<p.y<<endl;
        return 0;
    }

    //pornesc cu cel mai din stanga punct
    int indicePunctStanga=0;
    for(int i=1; i<n; i++)
    {
        if(puncte[i].x<puncte[indicePunctStanga].x || (puncte[i].x==puncte[indicePunctStanga].x && puncte[i].y<puncte[indicePunctStanga].y))
            indicePunctStanga=i;
    }

    vector<Punct> acoperireConvexa;
    int punctCurent = indicePunctStanga;
    do
    {
        acoperireConvexa.push_back(puncte[punctCurent]);
        int urmatorPunct=(punctCurent+1)%n;

        for(int i=0; i<n; i++)
        {
            if(i==punctCurent) continue; //nu fac nimic

            long long rezultat=Orientare(puncte[punctCurent], puncte[i], puncte[urmatorPunct]);

            //punctul i este mai la stanga sau coliniar, dar mai departe
            if(rezultat>0 || (rezultat==0 && DistantaPatrat(puncte[punctCurent], puncte[i])>DistantaPatrat(puncte[punctCurent], puncte[urmatorPunct])))
                urmatorPunct=i;
        }
        punctCurent=urmatorPunct; //trec la urmatorul punct din plan

    } while(punctCurent!=indicePunctStanga); //circular

    //eliminare coliniaritate consecutiva
    if(acoperireConvexa.size()>2)
    {
        vector<Punct> acoperire;
        acoperire.push_back(acoperireConvexa[0]);

        for(int i=1; i<acoperireConvexa.size(); i++)
        {
            long long rezultat=Orientare(acoperire.back(), acoperireConvexa[i], acoperireConvexa[(i+1)%acoperireConvexa.size()]);
            if(rezultat!=0)
                acoperire.push_back(acoperireConvexa[i]);
        }
        acoperireConvexa=acoperire;
    }

    cout<<acoperireConvexa.size()<<endl;
    for(Punct &p : acoperireConvexa)
        cout<<p.x<<" "<<p.y<<endl;
    return 0;
}
