//Jose Carmelo Ramirez Beltran A01175987 (Clase Lu Ju 12:00pm) y Miguel Cuellar Gauna A01280736 (Clase Lu Ju 3:00pm)
//Bibliografia: made by Rajeev Agrawal, posted in Geeks For Geeks link: http://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/
//ClosestPoints
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 110L

struct point{int x,y;};
struct point pC1,pC2;
double minimo=1e10;

int sortX(const void *a,const void *b){
    return(((*(struct point *)a).x<(*(struct point *)b).x)?-1:1);
}
double dDist(struct point a,struct point b){
    return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

void busca(struct point *p,int iNum){
    int iX,iY,iA,iB;
    double dist;
    if(iNum <= 1)return;
    
    qsort(p,iNum,sizeof(struct point),sortX);
    busca(p,iNum/2);
    busca(p+iNum/2,(iNum+1)/2);
    for(iX=iNum/2; iX>0 && p[iNum/2].x-p[iX].x<minimo; iX--);
    for(iY=iNum/2; iY<iNum-1 && p[iY].x-p[iNum/2].x<minimo; iY++);
    for(iA=iX;iA<=iY;iA++)
        for(iB=iA+1;iB<=iY;iB++)
            if((dist=dDist(p[iA],p[iB]))<minimo){
                minimo=dist;
                pC1.x=p[0].x;
                pC1.y=p[0].y;
                pC2.x=p[1].x;
                pC2.y=p[1].y;
            }
}

int main(){
    int iN;
    int dX,dY;
    struct point distancias[MAX];
    cin>>iN;
    for(int ix=0;ix<iN;ix++){
        cin>>dX>>dY;
        distancias[ix].x=dX;
        distancias[ix].y=dY;
    }
    busca(distancias,iN);
    printf("The distance of best friends are: %.2f\n", minimo);

    
}

