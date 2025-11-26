/*
#include <iostream>
#include <vector>
using namespace std;

long long determinant3x3(long long a1, long long a2, long long a3, long long b1, long long b2, long long b3, long long c1, long long c2, long long c3)
{
    return a1*(b2*c3 - b3*c2) - a2*(b1*c3 - b3*c1) + a3*(b1*c2 - b2*c1);
}
long long determinant4x4(long long m[4][4])
{
    long long det=0; //formez minorul dupa randul 0 si coloanele 0 1 2 3 din det

    for(int col=0; col<4; col++)
    {
        long long minor[3][3];
        for(int i=1; i<4; i++) //din matrice iau fara primul rand
        {
            int minorCol=0;
            for(int j=0; j<4; j++) //din matrice iau fara col curenta
            {
                if(j==col)
                    continue; //sar coloana curenta
                minor[i-1][minorCol]=m[i][j];
                minorCol++;
            }
        }
        long long sign = (col % 2 == 0) ? 1 : -1;
        det+=sign*m[0][col]*determinant3x3(minor[0][0], minor[0][1], minor[0][2], minor[1][0], minor[1][1], minor[1][2], minor[2][0], minor[2][1], minor[2][2]);
    }

    return det;
}

int main()
{
    long long ax, ay, bx, by, cx, cy, nrPuncte, px, py;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    cin>>nrPuncte;
    vector<string> rezultate;
    for(int i=1; i<=nrPuncte; i++)
    {
        cin>>px>>py;
        long long m[4][4] = {
            {ax, ay, ax*ax + ay*ay, 1},
            {bx, by, bx*bx + by*by, 1},
            {cx, cy, cx*cx + cy*cy, 1},
            {px, py, px*px + py*py, 1}
        };

        long long D = determinant4x4(m);

        if(D>0)
            rezultate.push_back("INSIDE");
        else if(D==0)
            rezultate.push_back("BOUNDARY");
        else
            rezultate.push_back("OUTSIDE");
    }

    for(int i=0; i<rezultate.size(); i++)
        cout<<rezultate[i]<<endl;
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
using namespace std;

long long determinant3x3(long long a1, long long a2, long long a3, long long b1, long long b2, long long b3, long long c1, long long c2, long long c3)
{
    return a1*(b2*c3 - b3*c2) - a2*(b1*c3 - b3*c1) + a3*(b1*c2 - b2*c1);
}
long long determinant4x4(long long m[4][4])
{
    long long det=0; //formez minorul dupa randul 0 si coloanele 0 1 2 3 din det

    for(int col=0; col<4; col++)
    {
        long long minor[3][3];
        for(int i=1; i<4; i++) //din matrice iau fara primul rand
        {
            int minorCol=0;
            for(int j=0; j<4; j++) //din matrice iau fara col curenta
            {
                if(j==col)
                    continue; //sar coloana curenta
                minor[i-1][minorCol]=m[i][j];
                minorCol++;
            }
        }
        long long sign = (col % 2 == 0) ? 1 : -1;
        det+=sign*m[0][col]*determinant3x3(minor[0][0], minor[0][1], minor[0][2], minor[1][0], minor[1][1], minor[1][2], minor[2][0], minor[2][1], minor[2][2]);
    }

    return det;
}

int main()
{
    long long ax, ay, bx, by, cx, cy, dx, dy;
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

    //AC: D vs ABC
     long long mAC[4][4] = {
        {ax, ay, ax*ax + ay*ay, 1},
        {bx, by, bx*bx + by*by, 1},
        {cx, cy, cx*cx + cy*cy, 1},
        {dx, dy, dx*dx + dy*dy, 1}
    };

    //BD: C vs ABD
    long long mBD[4][4] = {
        {ax, ay, ax*ax + ay*ay, 1},
        {bx, by, bx*bx + by*by, 1},
        {dx, dy, dx*dx + dy*dy, 1},
        {cx, cy, cx*cx + cy*cy, 1}
    };

    long long dAC = determinant4x4(mAC);
    long long dBD = determinant4x4(mBD);

    if(dAC>0)
        cout<<"AC: ILLEGAL"<<endl;
    else
        cout<<"AC: LEGAL"<<endl;

    if(dBD>0)
        cout<<"BD: ILLEGAL"<<endl;
    else
        cout<<"BD: LEGAL"<<endl;

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int n, a, b, c;
int xmin=-999999999, xmax=999999999;
int ymin=-999999999, ymax=999999999;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c;
        if(b==0) //semiplan vertical, y nu exista in ecuatie
        {
            int x=-c/a; //ax+c<=0 => x=-c/a
            if(a>0) //raman cu x<=-c/a
                xmax=min(xmax, x);
            else // >=
                xmin=max(xmin, x);
        }
        else //semiplan orizontal, x nu exista in ecuatie
        {
            int y=-c/b;
            if(b>0)
                ymax=min(ymax, y);
            else
                ymin=max(ymin, y);
        }
    }

    if (xmin>xmax || ymin>ymax)
        cout<<"VOID";
    else if(xmin!=-999999999 && xmax!=999999999 && ymin!=-999999999 && ymax!=999999999)
        cout<<"BOUNDED";
    else
        cout<<"UNBOUNDED";
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int n, a, b, c, m;
double qx, qy;

int main()
{
    cin>>n;
    ///generez lista indecsi pentru determinarea dreptunghiurilor
    //2 semiplane orizontale + 2 semiplane verticale => dreptunghi
    vector<double> maximeX;
    vector<double> maximeY;
    vector<double> minimeX;
    vector<double> minimeY;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c;
        if(b==0) //semiplan vertical, y nu exista in ecuatie
        {
            double x=-(double)c/a; //ax+c<=0 => x=-c/a
            if(a>0) //raman cu x<=-c/a
                maximeX.push_back(x);
            else // >=
                minimeX.push_back(x);
        }
        else //semiplan orizontal, x nu exista in ecuatie
        {
            double y=-(double)c/b;
            if(b>0)
                maximeY.push_back(y);
            else
                minimeY.push_back(y);
        }
    }

    sort(maximeX.begin(), maximeX.end());
    sort(maximeY.begin(), maximeY.end());
    sort(minimeX.begin(), minimeX.end());
    sort(minimeY.begin(), minimeY.end());

    cin>>m;
    cout<<fixed<<setprecision(6);
    for(int i=0; i<m; i++)
    {
        cin>>qx>>qy;

       //gasesc bounds-urile cele mai stramte
        double xmin = -1e9, xmax = 1e9, ymin = -1e9, ymax = 1e9;
        bool ok = true;

        //cel mai mare xmin < qx
        for(int j=minimeX.size()-1; j>=0; j--)
        {
            if(minimeX[j]<qx)
            {
                xmin=minimeX[j];
                break;
            }
        }
        if(xmin==-1e9)
            ok=false;

        //cel mai mic xmax > qx
        for(int j=0; j<maximeX.size(); j++)
        {
            if(maximeX[j]>qx)
            {
                xmax=maximeX[j];
                break;
            }
        }
        if(xmax==1e9)
            ok=false;

        //cel mai mare ymin < qy
        for(int j=minimeY.size()-1; j>=0; j--)
        {
            if(minimeY[j]<qy)
            {
                ymin=minimeY[j];
                break;
            }
        }
        if(ymin==-1e9)
            ok=false;

        //cel mai mic ymax > qy
        for(int j=0; j<maximeY.size(); j++)
        {
            if(maximeY[j]>qy)
            {
                ymax=maximeY[j];
                break;
            }
        }
        if(ymax==1e9)
            ok=false;

        if(ok && xmin<qx && qx<xmax && ymin<qy && qy<ymax)
        {
            double arie = (xmax-xmin)*(ymax-ymin);
            cout<<"YES"<<endl<<arie<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
*/
/* //6/10
#include <iostream>
#include <vector>
using namespace std;

int n, x1, x2, y1, y2;
vector<int> ox1, ox2, oy; //sgm orizontale
vector<int> vx, vy1, vy2; //sgm verticale
int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>x1>>y1>>x2>>y2;

        //salvez coordonatele
        if(y1==y2)
        {
            //sgm orizontal
            if(x1>x2)
                swap(x1, x2);
            ox1.push_back(x1);
            ox2.push_back(x2);
            oy.push_back(y1);
        }
        else if(x1==x2)
        {
            //sgm vertical
            if(y1>y2)
                swap(y1, y2);
            vx.push_back(x1);
            vy1.push_back(y1);
            vy2.push_back(y2);
        }
    }

    int intersectii=0;
    for(int i=0; i<oy.size(); i++)
        for(int j=0; j<vx.size(); j++)
            if(vx[j]>ox1[i] && vx[j]<ox2[i] && oy[i]>vy1[j] && oy[i]<vy2[j]) //vertical intre limitele orizontalului si orizontal intre limitele verticalului
                intersectii++;

    cout<<intersectii<<endl;
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, x1, x2, y1, y2;
vector<int> ox1, ox2, oy; //sgm orizontale
vector<int> vx, vy1, vy2; //sgm verticale
struct Eveniment {
    int x, tip, y1, y2;
    // tip: 0=inceput orizontal, 1=vertical, 2=sfarsit orizontal
};
bool compara(int a, int b)
{
    return vx[a]<vx[b];
}
int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>x1>>y1>>x2>>y2;

        //salvez coordonatele
        if(y1==y2)
        {
            //sgm orizontal
            if(x1>x2)
                swap(x1, x2);
            ox1.push_back(x1);
            ox2.push_back(x2);
            oy.push_back(y1);
        }
        else if(x1==x2)
        {
            //sgm vertical
            if(y1>y2)
                swap(y1, y2);
            vx.push_back(x1);
            vy1.push_back(y1);
            vy2.push_back(y2);
        }
    }

    vector<Eveniment> ev;
    //evenimente sgm orizontale: start si sfarsit
    for (int i=0; i <ox1.size(); i++)
    {
        ev.push_back({ox1[i], 0, oy[i], oy[i]});
        ev.push_back({ox2[i], 2, oy[i], oy[i]});
    }

    //evenimente sgm verticale
    for (int i=0; i<(int)vx.size(); i++)
        ev.push_back({vx[i], 1, vy1[i], vy2[i]});

    //sortez evenimentele dupa x, apoi dupa tip
    sort(ev.begin(), ev.end(), [](Eveniment &ev1, Eveniment &ev2) {
        if (ev1.x!=ev2.x)
            return ev1.x<ev2.x;
        return ev1.tip<ev2.tip;
    });

    multiset<int> y; //y de luat in considerare
    long long intersectii=0;

    for(Eveniment &e : ev)
    {
        if(e.tip==0) //start segment orizontal => adaug y
            y.insert(e.y1);
        else if(e.tip==2) //sfarsit segment orizontal => scot y
        {
            auto it=y.find(e.y1);
            if(it!=y.end())
                y.erase(it);
        }
        else { //segment vertical => numar cate segmente intersecteaza

            //caut y-urile valide in y(intre e.y1 si e.y2)
            auto low=y.upper_bound(e.y1);
            auto high=y.lower_bound(e.y2);
            intersectii+=distance(low, high);
        }
    }
    /*
    int intersectii=0;
    for(int i=0; i<oy.size(); i++)
    {
        //caut primul segment vertical cu x > ox1[i]
        int left=0, right=ordine.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(vx[ordine[mid]]<=ox1[i])
            {
                left=mid+1;
            } else
                right=mid;
        }
        int start=left;

        //gasesc primul segment vertical cu x >= ox2[i]
        left=0; right=ordine.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(vx[ordine[mid]]<ox2[i])
                left=mid+1;
            else
                right=mid;
        }
        int fin=left;

        //verific doar segmentele din intervalul [start, fin)
        for(int j=start; j<fin; j++)
        {
            int id=ordine[j];
            if(vy1[id]<oy[i] && oy[i]<vy2[id])
                intersectii++;
        }
    }
    */
    /*
    int intersectii=0;
    for(int i=0; i<oy.size(); i++)
        for(int j=0; j<vx.size(); j++)
            if(vx[j]>ox1[i] && vx[j]<ox2[i] && oy[i]>vy1[j] && oy[i]<vy2[j]) //vertical intre limitele orizontalului si orizontal intre limitele verticalului
                intersectii++;
    */
    cout<<intersectii<<endl;
    return 0;
}
