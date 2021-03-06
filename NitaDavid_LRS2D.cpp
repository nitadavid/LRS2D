#include<fstream>
#include<iostream>
using namespace std;

int n;

typedef struct
{int info;
int stang;
int drept;} nod;

nod v[100];

typedef struct arbore
{int inf;
arbore *stangul;
arbore *dreptul;};

arbore *r;

fstream f("input.dat",ios::in);
fstream g("output.dat",ios::out);

int read_data()
{
f>>n;
for(int i=1;i<=n;i++)
{
    f>>v[i].info;
}
for(int i=1;i<=n;i++)
{
    f>>v[i].stang;
}
for(int i=1;i<=n;i++)
{
    f>>v[i].drept;
}
f.close();
return 0;}

void convert(arbore *&r, int inf, int s)
{
    r=new arbore;

    if(s==0)
    r->inf=1;

    else if(s==-1)
    r->inf=v[inf].stang;

    else if(s==1)
    r->inf=v[inf].drept;

        if(v[r->inf].stang!=0) convert(r->stangul,r->inf,-1);
        else r->stangul=NULL;

        if(v[r->inf].drept!=0) convert(r->dreptul,r->inf,1);
        else r->dreptul=NULL;

}

 void rsd(arbore *r)
{
 if (r!=NULL)
      {
       g<<r->inf<<" ";
       rsd(r->stangul);
       rsd(r->dreptul);
      }
}

void srd(arbore *r)
{
 if (r!=NULL)
      {
       srd(r->stangul);
       g<<r->inf<<" ";
       srd(r->dreptul);
      }
}

void sdr(arbore *r)
{
 if (r!=NULL)
      {
       sdr(r->stangul);
       sdr(r->dreptul);
       g<<r->inf<<" ";
      }
}


int main()
{read_data();
convert(r,1,0);
rsd(r); g<<endl;
srd(r); g<<endl;
sdr(r);


 }



