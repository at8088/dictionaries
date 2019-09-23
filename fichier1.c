#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int* fusion(int t1[],int t2[],int size1, int size2){
    int it1=0,it2=0,i=0;
    int  fus[size1+size2] ;
    while (it1 < size1 && it2 < size2){
        if (t1[it1]<t2[it2]){
            fus[i]=t1[it1];
            i++;
            it1++;
        }else{
            fus[i]=t2[it2];
            i++;
            it2++;
        }
    }
    while (it1 < size1){
        fus[i]=t1[it1];
        i++;
        it1++;
    }
    while (it2 < size2) {
        fus[i]=t2[it2];
        i++;
        it2++;
    }
    return fus;
}
void affiche(int t[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",t[i]);
    }
    puts("");
}
void tri_fusion_bis(int t[] , int n){
    if (n<=1)
    {
        return;
    }
    tri_fusion_bis(t,n/2);
    tri_fusion_bis(t+n/2,n-n/2);
    t=fusion(t,t+n/2,n/2,n/2);
}
void tri_fusion(int t[], int n){
    if(n>0){
        tri_fusion_bis(t,n);
    }
}

bool rech_dicho(int t[],int n,int val){
    if (n==0)
    {
        return false;
    }
    
    int m = n/2;
    if (t[m]==val){
        return true;
    }
    if (t[m] < val){
        return rech_dicho(t+m+1,m,val);
    }else{
         return rech_dicho(t,m,val);   
    }
}

int main(int argc, char const *argv[]){
    int t[5]={1,5,6,8,10};
    int l[7]={3,69,17,0,10,11,12};
    int p = 10/6;
    //printf("%d\n",p);
   tri_fusion(l,7);
    // bool b = rech_dicho(t,5,8);
    // printf("%d\n",b);
    affiche(l,7);
    //affiche(fus,12);
   // free(t);
    return 0;
}
