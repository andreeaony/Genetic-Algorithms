/*
#include <iostream>
#include <vector>
using namespace std;

int n, m;

struct Punct {
    long long x, y;
};

long long testOrientare(Punct A, Punct B, Punct C)
{
    return A.x*B.y+C.x*A.y+B.x*C.y-B.y*C.x-A.x*C.y-A.y*B.x;
}
bool peSegment(Punct A, Punct B, Punct C)
{
    if(C.x==A.x && C.y==A.y)
        return true;
    if(C.x==B.x && C.y==B.y)
        return true;
    if(testOrientare(A, B, C)==0)
        return(min(A.x, B.x)<=C.x && C.x<=max(A.x, B.x)) && (min(A.y, B.y)<=C.y && C.y<=max(A.y, B.y));
    return false;
}

int main()
{
    cin>>n;
    vector<Punct> poligon(n);
    for(int i=0; i<n; i++)
        cin>>poligon[i].x>>poligon[i].y;

    cin>>m;
    vector<Punct> puncte(m);
    for (int i=0; i<m; i++)
        cin>>puncte[i].x>>puncte[i].y;

    for(int i=0; i<m; i++)
    {
        long long o1=testOrientare(poligon[0], poligon[1], puncte[i]);
        long long o2=testOrientare(poligon[0], poligon[n-1], puncte[i]);

        if(o1==0 && peSegment(poligon[0], poligon[1], puncte[i]))
        {
            cout<<"BOUNDARY\n";
            continue;
        }
        else if(o2==0 && peSegment(poligon[0], poligon[n-1], puncte[i]))
        {
            cout<<"BOUNDARY\n";
            continue;
        }
        else if(o1<0 || o2>0)
        {
            cout<<"OUTSIDE\n";
            continue;
        }
        //caut triunghiul in care exista punctul
        int st=1, dr=n-1;
        while(dr-st>1)
        {
            int mijl=(st+dr)/2;
            if(testOrientare(poligon[0], poligon[mijl], puncte[i])>=0)
                st=mijl;
            else
                dr=mijl;
        }
        //pozitia punctului in triunghiul format de punctele poligon[0], poligon[st], poligon[st+1]
        long long orientare1=testOrientare(poligon[st], poligon[(st+1)%n], puncte[i]);
        long long orientare2=testOrientare(poligon[(st+1)%n], poligon[0], puncte[i]);
        long long orientare3=testOrientare(poligon[0], poligon[st], puncte[i]);
        int limitaStanga=max(0,st-1);
        int limitaDreapta=min(n-1,st+1);
        long long orientare4=testOrientare(poligon[limitaStanga], poligon[st], puncte[i]);
        long long orientare5=testOrientare(poligon[st], poligon[limitaDreapta], puncte[i]);


        if(orientare1>0 && orientare2>0)
            cout<<"INSIDE\n";
        else if((orientare1==0 && peSegment(poligon[st], poligon[(st+1)%n], puncte[i])) ||
                (orientare2==0 && peSegment(poligon[(st+1)%n], poligon[0], puncte[i])) ||
                (orientare3==0 && peSegment(poligon[0], poligon[st], puncte[i])) ||
                (orientare4==0 && peSegment(poligon[limitaStanga], poligon[st], puncte[i])) ||
                (orientare5==0 && peSegment(poligon[st], poligon[limitaDreapta], puncte[i])))
            cout<<"BOUNDARY\n";
        else
            cout<<"OUTSIDE\n";
    }
    return 0;
}
*/
/* 9/10
#include <iostream>
#include <vector>
using namespace std;

int n, m;

struct Punct {
    long long x, y;
};

long long testOrientare(Punct A, Punct B, Punct C)
{
    return A.x*B.y+C.x*A.y+B.x*C.y-B.y*C.x-A.x*C.y-A.y*B.x;
}
bool peSegment(Punct A, Punct B, Punct C)
{
    if(C.x==A.x && C.y==A.y)
        return true;
    if(C.x==B.x && C.y==B.y)
        return true;
    if(testOrientare(A, B, C)==0)
        return(min(A.x, B.x)<=C.x && C.x<=max(A.x, B.x)) && (min(A.y, B.y)<=C.y && C.y<=max(A.y, B.y));
    return false;
}

int main()
{
    cin>>n;
    vector<Punct> poligon(n);
    for(int i=0; i<n; i++)
        cin>>poligon[i].x>>poligon[i].y;

    cin>>m;
    vector<Punct> puncte(m);
    for (int i=0; i<m; i++)
        cin>>puncte[i].x>>puncte[i].y;

    for(int i=0; i<m; i++)
    {

        long long o1=testOrientare(poligon[0], poligon[1], puncte[i]);
        long long o2=testOrientare(poligon[0], poligon[n-1], puncte[i]);

        if(o1<0 || o2>0)
        {
            cout<<"OUTSIDE\n";
            continue;
        }
        else if(o1==0 && peSegment(poligon[0], poligon[1], puncte[i]))
        {
            cout<<"BOUNDARY\n";
            continue;
        }
        else if(o2==0 && peSegment(poligon[0], poligon[n-1], puncte[i]))
        {
            cout<<"BOUNDARY\n";
            continue;
        }

        //caut triunghiul in care exista punctul
        int st=1, dr=n-1;
        while(dr-st>1)
        {
            int mijl=(st+dr)/2;
            if(testOrientare(poligon[0], poligon[mijl], puncte[i])>=0)
                st=mijl;
            else
                dr=mijl;
        }
        //pozitia punctului in triunghiul format de punctele poligon[0], poligon[st], poligon[st+1]
        long long orientare1=testOrientare(poligon[st], poligon[(st+1)%n], puncte[i]);
        long long orientare2=testOrientare(poligon[(st+1)%n], poligon[0], puncte[i]);

        int urm=(st+1)%n;
        int urm2=(st+2)%n;
        if(testOrientare(poligon[urm], poligon[urm2], puncte[i])==0 && peSegment(poligon[urm], poligon[urm2], puncte[i]))
        {
            cout<<"BOUNDARY\n";
            continue;
        }
        if(orientare1>0 && orientare2>0)
            cout<<"INSIDE\n";
        else if((orientare1==0 && peSegment(poligon[st], poligon[(st+1)%n], puncte[i])) || (orientare2==0 && peSegment(poligon[(st+1)%n], poligon[0], puncte[i])))
            cout<<"BOUNDARY\n";
        else if(testOrientare(poligon[0], poligon[st], puncte[i])==0 && peSegment(poligon[0], poligon[st], puncte[i]))
            cout<<"BOUNDARY\n";
        else
            cout<<"OUTSIDE\n";
    }
    return 0;
}
*/
/*tentativa
#include <iostream>
#include <vector>
using namespace std;

struct Punct {
    long long x, y;
};

long long testOrientare(Punct primulPunct, Punct alDoileaPunct, Punct punctDeVerificat) //<0 =>stanga, 0=>pe, >0=>dreapta
{
    long long test=(alDoileaPunct.y-primulPunct.y)*(punctDeVerificat.x- alDoileaPunct.x) - (alDoileaPunct.x - primulPunct.x) * (punctDeVerificat.y - alDoileaPunct.y);
    return test;
}

bool peSegment(Punct primulPunct, Punct alDoileaPunct, Punct punctDeVerificat)
{
    long long orientare=testOrientare(primulPunct, alDoileaPunct, punctDeVerificat);
    if(orientare!=0) return false;

    if (min(primulPunct.x, alDoileaPunct.x)<=punctDeVerificat.x && punctDeVerificat.x<=max(primulPunct.x, alDoileaPunct.x) &&
        min(primulPunct.y, alDoileaPunct.y)<=punctDeVerificat.y && punctDeVerificat.y<=max(primulPunct.y, alDoileaPunct.y)) return true;
    return false;
}

string pozitieInPoligon(vector<Punct>& puncte, Punct punctDeVerificat)
{
    int numarPuncte=puncte.size();

    if(testOrientare(puncte[0], puncte[1], punctDeVerificat)==0 && peSegment(puncte[0], puncte[1], punctDeVerificat)) //prima
        return "BOUNDARY";
    if(testOrientare(puncte[0], puncte[numarPuncte-1], punctDeVerificat)==0 && peSegment(puncte[0], puncte[numarPuncte-1], punctDeVerificat)) //ultima
        return "BOUNDARY";
    if(testOrientare(puncte[0], puncte[1], punctDeVerificat)<0 || testOrientare(puncte[0], puncte[numarPuncte-1], punctDeVerificat)>0)
        return "OUTSIDE";

    //caut binar triunghiul in care se gaseste punctul
    int stanga=0, dreapta=numarPuncte-1;
    while(dreapta-stanga>1)
    {
        int mijloc=(stanga+dreapta)/2;
        if(testOrientare(puncte[0], puncte[mijloc], punctDeVerificat)<=0)
            stanga=mijloc;
        else
            dreapta=mijloc;
    }

    long long orientare=testOrientare(puncte[stanga], puncte[dreapta], punctDeVerificat);
    if(orientare<0)
        return "OUTSIDE";
    if(orientare==0)
    {
        if (peSegment(puncte[stanga], puncte[dreapta], punctDeVerificat))
            return "BOUNDARY";
        else
            return "OUTSIDE";
    }
    return "INSIDE";
}
int n, m;
int main() {

    cin>>n;
    vector<Punct> poligon(n);
    for(int i=0; i<n; i++)
        cin>>poligon[i].x>>poligon[i].y;

    cin>>m;
    vector<string> rezultate;
    Punct punct;
    for(int i=0; i<m; i++)
    {
        cin>>punct.x>>punct.y;
        rezultate.push_back(pozitieInPoligon(poligon, punct));
    }

    for(int i=0; i<m; i++)
        cout<<rezultate[i]<<endl;

    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Punct {
    long long x, y;
};


bool monotonX(vector<Punct>& poligon)
{
    int n=poligon.size();
    long long xmin=0, xmax=0;
    //caut x cel mai din stanga si cel mai din dreapta
    for(int i=1; i<n; i++)
    {
        if(poligon[i].x<poligon[xmin].x)
            xmin=i;
        if(poligon[i].x>poligon[xmax].x)
            xmax=i;
    }

    int i=xmin;
    //sens trigonometric
    do
    {
        int j=(i+1)%n;
        if(poligon[i].x>poligon[j].x) break;
        i=j;
    } while (i!=xmax);

    if(i==xmax)//am ajuns la capat
    {
        //sens invers trigonometric
        i=xmin;
        do
        {
            int j=(i-1+n)%n;
            if(poligon[i].x>poligon[j].x) return false;
            i=j;
        } while(i!=xmax);
        return true;
    }
    return false;
}

bool monotonY(vector<Punct>& poligon)
{
    int n=poligon.size();
    long long ymin=0, ymax=0;
    //caut y cel mai din stanga si cel mai din dreapta
    for(int i=1; i<n; i++)
    {
        if(poligon[i].y<poligon[ymin].y)
            ymin=i;
        if(poligon[i].y>poligon[ymax].y)
            ymax=i;
    }

    int i=ymin;
    //sens trigonometric
    do
    {
        int j=(i+1)%n;
        if(poligon[i].y>poligon[j].y) break;
        i=j;
    } while (i!=ymax);

    if(i==ymax)//am ajuns la capat
    {
        //sens invers trigonometric
        i=ymin;
        do
        {
            int j=(i-1+n)%n;
            if(poligon[i].y>poligon[j].y) return false;
            i=j;
        } while(i!=ymax);
        return true;
    }
    return false;
}

int n;
int main()
{
    cin>>n;
    vector<Punct> poligon(n);
    for(int i=0; i<n; i++)
        cin>>poligon[i].x>>poligon[i].y;

    if(monotonX(poligon)==true)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    if(monotonY(poligon)==true)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

struct Punct {
    long long x, y;
};

bool peSegment(Punct P, Punct A, Punct B)
{
     //A, B, P coliniare
    if((P.y-A.y)*(B.x-A.x)!=(P.x-A.x)*(B.y-A.y))
        return false;

    return (P.x>=min(A.x, B.x) && P.x<=max(A.x, B.x)) && (P.y>=min(A.y, B.y) && P.y<=max(A.y, B.y));
}

string pozitiaPunctuluiFataDePoligon(vector<Punct>& poligon, Punct P)
{
    int n=poligon.size();
    int intersectii=0;

    for(int i=0; i<n; i++)
    {
        Punct A=poligon[i];
        Punct B=poligon[(i+1)%n];

        if(peSegment(P,A,B))
            return "BOUNDARY";

        if((A.y>P.y)!=(B.y>P.y)) //daca P poate intersecta AB
        {
            double coordonataIntersectiePAB_X=(double)(P.y-A.y)*(B.x-A.x)/(B.y-A.y)+A.x;
            if(coordonataIntersectiePAB_X>P.x)
                intersectii++;
        }
    }
    if(intersectii%2)
        return "INSIDE";
    return "OUTSIDE";
}

int n;
int main()
{
    cin>>n;
    vector<Punct> poligon(n);
    for(int i=0; i<n; i++)
        cin>>poligon[i].x>>poligon[i].y;

    cin>>n;
    vector<string> rezultat;
    for(int i=0; i<n; i++)
    {
        Punct P;
        cin>>P.x>>P.y;
        rezultat.push_back(pozitiaPunctuluiFataDePoligon(poligon, P));
    }

    for(int i=0; i<n; i++)
        cout<<rezultat[i]<<endl;
    return 0;
}
