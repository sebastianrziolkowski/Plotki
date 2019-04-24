#include <iostream>

using namespace std;

int steps=0;

class punkt
{
public:
    bool crossbarvertical;
    bool crossbarhorizontal;

    int steps;
    punkt()
    {
        crossbarhorizontal=false;
        crossbarvertical=false;
        steps=0;
    }
};

class start
{
public:
    int x,y;
    start()
    {
        x=0;
        y=0;
    }
};

class stop: public start
{
public:
    int steps;
    int number;
    int stepstoget;
    stop()
    {
        steps=0;
        number=0;
        stepstoget=0;
    }
};

void copytab(punkt **tab1,punkt **tab2, int sizer);
int evenodd(int step);


void cleartab(punkt **tab,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            tab[i][j].steps=0;
        }
    }
}



//////////////////////  TAB CHANGER //////////////////////

void tabchenger(punkt **tabb,punkt **tabb2, int sizer)    // wynajdowanie wspolzednych z wartosciami 1
{

    int x=0;
    int y=0;
    while(x<sizer)
    {
        y=0;
        while(y<sizer && tabb[x][y].steps==0)
        {
            y++;
        }
        while(y<sizer)
        {
            if((x>0)&&(tabb2[x-1][y].crossbarhorizontal==false)){
                tabb[x][y].steps=tabb[x][y].steps%1000000007;
                tabb2[x-1][y].steps=tabb2[x-1][y].steps%1000000007;
                tabb2[x-1][y].steps=tabb2[x-1][y].steps+tabb[x][y].steps;
                tabb2[x-1][y].steps=tabb2[x-1][y].steps%1000000007;
            }
                if((x+1<sizer)&&(tabb2[x][y].crossbarhorizontal==false)){

                tabb2[x+1][y].steps=tabb2[x+1][y].steps&1000000007;
                tabb[x][y].steps=tabb[x][y].steps%1000000007;
                tabb2[x+1][y].steps=tabb2[x+1][y].steps+tabb[x][y].steps;
                tabb2[x+1][y].steps=tabb2[x+1][y].steps%1000000007;
            }
                if((y>0)&&(tabb2[x][y-1].crossbarvertical==false)){

                tabb2[x][y-1].steps=tabb2[x][y-1].steps%1000000007;
                tabb[x][y].steps=tabb[x][y].steps%1000000007;
                tabb2[x][y-1].steps=tabb2[x][y-1].steps+tabb[x][y].steps;
                tabb2[x][y-1].steps=tabb2[x][y-1].steps%1000000007;
            }
                if((y+1<sizer)&&(tabb2[x][y].crossbarvertical==false)){
                tabb2[x][y+1].steps=tabb2[x][y+1].steps%1000000007;
                tabb[x][y].steps=tabb[x][y].steps%1000000007;
                tabb2[x][y+1].steps=tabb2[x][y+1].steps+tabb[x][y].steps;
                tabb2[x][y+1].steps=tabb2[x][y+1].steps%1000000007;
            }
                y=y+2;
        }
        x=x+1;
    }

}



//////////////////////  QUICK SORT ///////////////////////////////

void Qucik( stop tab[], int left, int right )
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ].steps;
    do
    {
        while( tab[ i ].steps < x )
             i++;

        while( tab[ j ].steps > x )
             j--;

        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );            
            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) Qucik( tab, left, j );

    if( right > i ) Qucik( tab, i, right );

}


//////////////////////  QUICK SORT2 ///////////////////////////////

void Qucik2( stop tab[], int left, int right )
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ].number;
    do
    {
        while( tab[ i ].number < x )
             i++;

        while( tab[ j ].number > x )
             j--;

        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );                         //// ???????? to dzial!??!?!
            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) Qucik2( tab, left, j );

    if( right > i ) Qucik2( tab, i, right );

}

//////////////////////////////////////////////////////////////////////////////////




int main()
{
int size;
cin >> size;
punkt **tab = new punkt*[size];
punkt **tab2 = new punkt*[size];

 for(int i=0;i<size;i++)
 {
   tab[i] = new punkt[size];
   tab2[i] = new punkt[size];
 }

//----------------------------------------------
int x,y,crossbar,numbercrossbar,queries;
cin >> numbercrossbar;

 for(int i=0;i<numbercrossbar;i++)
 {
     cin >> crossbar >> x >> y;
     if(crossbar==1)
     {
        tab[x][y].crossbarhorizontal=true;
        tab2[x][y].crossbarhorizontal=true;
     }
     else if(crossbar==0)
     {
       tab[x][y].crossbarvertical=true;
       tab2[x][y].crossbarvertical=true;
     }
 }

    start starter;
    cin >> starter.x >> starter.y;
    cin >> queries;

     tab[starter.x][starter.y].steps=1;

stop *stopper = new stop[queries];

        for(int i=0;i<queries;i++)
         {
            cin >> stopper[i].steps >> stopper[i].x >> stopper[i].y;
            stopper[i].number=i;
         }
         Qucik(stopper,0,queries-1);

int numer=0;
int xx=0;


while(stopper[queries-1].steps+1>xx){
    if((xx)%2!=0)
    {


        tabchenger(tab,tab2,size);

        while(stopper[numer].steps==(xx))
        {
            stopper[numer].stepstoget=tab2[stopper[numer].x][stopper[numer].y].steps;
            numer++;
        }
         cleartab(tab,size);
    }
    if((xx)%2==0)
    {


        tabchenger(tab2,tab,size);

        while(stopper[numer].steps==(xx))
        {
            stopper[numer].stepstoget=tab[stopper[numer].x][stopper[numer].y].steps;
            numer++;
        }
        cleartab(tab2,size);
    }

xx++;
}

         Qucik2(stopper,0,queries-1);

         for(int i=0;i<queries;i++)
         {
            cout<<stopper[i].stepstoget<<endl;
         }


    return 0;
}
