#include<iostream>
#include<math.h>
using namespace std;
double determinate(int n,double matrixpro[][10]){
  int i,j,k;
  int signos=1;
  double determinante=1;
  for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++){  
       if (abs (matrixpro[i][i]) < abs (matrixpro[j][i]))
          {signos=signos*(-1);
              for (k=0; k<n;k++)
              {   
                  /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                     swap(matrixpro[i][k],matrixpro[j][k]);
              }
          }
      double OperacionMatrices=matrixpro [j][i]/matrixpro [i][i];
         for (k=0; k<n;k++)
         {
           matrixpro[j][k]=matrixpro[j][k]-OperacionMatrices*matrixpro[i][k];}
           }}  
  // for (size_t i = 0; i <n; i++)
  // {if (matrixpro[i][i]==0)
  // cout<<"la matriz tiene una infinidad de soluciones";return 0;}
             for (size_t i = 0; i < n; i++)
  { 
    determinante=determinante*matrixpro[i][i];
  }
  return determinante*signos;
}
void multiplicacion(double A[10][10],double B[10],int n,double C[20]){
        double mira;
            for(int j=0;j<n;j++){
                C[j]=0;
                for(int k=0;k<n;k++){
                    C[j]=C[j]+A[j][k]*B[k];
                }
            }
    } 
void asignacion(double matrixpro[][10],double auxmatrixpro[][10],int m,int n,int pivote,int rangoa,int esco){
int i=0,j=0,z=0,k=0;
if((m-1)<n){
if(matrixpro[n-1][m-1]==0&&matrixpro[n-1][m-2]==0){
for (i = 0; i < pivote; i++){
  for ( j = 0; j <m; j++){
  auxmatrixpro[i][j]=matrixpro[pivote-1-i][pivote-1-j];}
  auxmatrixpro[i][m-1]=matrixpro[pivote-i-1][m-1];}  
}
else{
for (i = 0; i < n; i++){
  for ( j = 0; j <m; j++){
  auxmatrixpro[i][j]=matrixpro[n-1-i][m-2-j];}
  auxmatrixpro[i][m-1]=matrixpro[n-i-1][m-1];}}}
else
{
if(rangoa<n&&esco!=0&&m-1==n){
  for (i = 0; i < rangoa; i++){
  for ( j = 0; j <rangoa; j++){
  auxmatrixpro[i][j]=matrixpro[n-1-(n-rangoa)-i][m-2-(n-rangoa)-j];}
  auxmatrixpro[i][m-1]=matrixpro[rangoa-i-1][m-1];}}
  else 
  for (i = 0; i < pivote; i++){
  for ( j = 0; j <m; j++){
  auxmatrixpro[i][j]=matrixpro[pivote-1-i][pivote-1-j];}
  auxmatrixpro[i][m-1]=matrixpro[n-i-1][m-1];}}
if(m-1>n){
  for (i = 0; i < n; i++){
  for ( j = n; j < m; j++){
  auxmatrixpro[i][j]=matrixpro[n-1-i][j];}
  auxmatrixpro[i][m-1]=matrixpro[n-i-1][m-1];}}
 for (i = 0; i < n; i++){
  for ( j = 0; j < m; j++){
   printf(" %1.3f ",auxmatrixpro[i][j]);}
    printf("\n");}
}
bool Es_base_o_no(double bases[][10],double matrizdedtrancicion[][10],double matrizcanoonica[10],int posicion,int m,int n)
{  int i,j,k;
double matrixpro[10][10] ;
double auxmatrixpro[10][10];
double swapv[10][10];
double AuxiliaResultado[10];
double vectores[10][10];
double determinante=1,v0=1;
double v2[2][n+1];
double vaux0[10],vaux1[10],vauxinf[10],vaux2[10];
int pivote;
int esco=0;
int pertenece=0;
int nosera=0;
int vectorcero=0;
int rangoa=0,rangoass=0;
bool Esli;
bool Esgen;
bool Base;
for (size_t i = 0; i <m-1; i++)
    {   
        for (int j = 0; j <n; j++)
        {
        matrixpro[j][i]=bases[j][i];
        }
        
    }
for (size_t i = 0; i < n; i++)
{
    matrixpro[i][m-1]=matrizcanoonica[i];
}

for (i = 0; i <m-1; i++)
{v0=0;
for ( j = 0; j <n; j++)
{v0=abs(matrixpro[j][i])+v0;
}
if(v0==0)for (size_t z = 0; z < n; z++)
{
  vaux0[z]=matrixpro[z][m-2];
  matrixpro[z][m-2]=0;
  matrixpro[z][i]=vaux0[z];
}
}
double esvector[10][1];
for (size_t i = 0; i < n; i++)
{ esvector[i][1]=matrixpro[i][m-1];
  for (size_t j = 0; j < m; j++)
  {
    swapv[i][j]=matrixpro[i][j];
  }
  
}
int ev=0;
for (size_t p = 0; p < m-1; p++)
{ev=0;
  for (size_t q = 0; q <n; q++)
  {
    if(matrixpro[q][p]==esvector[q][1]||matrixpro[q][p]==esvector[q][1]*matrixpro[q][0])ev++;
  }
  if(ev==n)pertenece=p+1;
} 

// for (i = 0; i <n; i++){
//   for ( j = 0; j <m; j++){
//    cout<<swapv[i][j]<<" ";}
//    cout<<"\n";}
if(m==2){
  for (size_t i = 0; i < n; i++)
  {
    v2[1][i]=matrixpro[i][0];
    v2[2][i]=matrixpro[i][1];
}}
for (i = 0; i <n; i++){
  for ( j = 0; j <m; j++){
   vectores[j][i]=matrixpro[i][j];}
   vectores[i][m-1]=matrixpro[i][m-1];}
// for (i = 0; i <n-1; i++){
//   for ( j = 0; j <m+1; j++){
//    cout<<vectores[i][j]<<" ";}
//    cout<<"\n";}
if(n<m-1)pivote=n;
else pivote=m-1;
//Operacion de eliminacion por gauss-jordan
if(m-1>n)
{
for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {  if (abs (matrixpro[i][i]) < abs (matrixpro[j][i]))
         {
             for (k=0; k<m;k++)
             {
                 /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                    swap(matrixpro[i][k],matrixpro[j][k]);
             }
         }
      int p=0;
      while (abs(matrixpro[i][i])<0.000001){
        for (k=0; k<m;k++)
             {
                 /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                    swap(matrixpro[i][k],matrixpro[j+p][k]);
             }
        p++;
        if(p+j>n)break;
      }
  //  if (abs(matrixpro[j][j])<0.000001&&j<pivote-1){
  //     for (size_t l = i; l < pivote; l++)
  // {
  //   {
  //     for (size_t s = 0; s <m-1; s++)
  //     {
  //     if(matrixpro[l][m-s-2]!=0&&abs(matrixpro[l][l])<0.000001)
  //     for (size_t z = 0; z < n; z++)
  //     {
  //       vaux0[z]=matrixpro[z][m-s-2];
  //       vauxinf[z]=matrixpro[z][l];
  //       vaux1[z]=swapv[z][m-s-2];
  //       vaux2[z]=swapv[z][l];
  //       swapv[z][m-2-s]=vaux2[z];
  //       swapv[z][l]=vaux1[z];
  //       matrixpro[z][m-2-s]=vauxinf[z];
  //       matrixpro[z][l]=vaux0[z];}
  //     }
  //   }
  // }
  //   } 
    if (abs(matrixpro[j-1][j-1])<0.000001&&j>0){
      for (size_t l = i; l < pivote; l++)
  {
    {
      for (size_t s = 0; s <m-1; s++)
      {
      if(matrixpro[l][m-s-2]!=0&&abs(matrixpro[l][l])<0.000001)
      for (size_t z = 0; z < n; z++)
      {
        vaux0[z]=matrixpro[z][m-s-2];
        vauxinf[z]=matrixpro[z][l];
        vaux1[z]=swapv[z][m-s-2];
        vaux2[z]=swapv[z][l];
        swapv[z][m-2-s]=vaux2[z];
        swapv[z][l]=vaux1[z];
        matrixpro[z][m-2-s]=vauxinf[z];
        matrixpro[z][l]=vaux0[z];}
      }
    }
  }
    }
    if(abs(matrixpro[j][i])>0.000001){
      double OperacionMatrices=matrixpro [j][i]/matrixpro [i][i];
         for (k=0; k<m;k++)
         {
           matrixpro[j][k]=matrixpro[j][k]-OperacionMatrices*matrixpro[i][k];}}
           }
  //                              for (int a=0;a<n;a++){
  // { for (size_t b = 0; b < m; b++){
  // if (matrixpro[a][b]!=matrixpro[a][b])
  //   cout<<" 0 ";
  // else if(abs(matrixpro[a][b])<0.0001)
  // cout<<"0 ";
  // else  cout<<matrixpro[a][b]<<" ";
  // }}
  // cout<<"\n";}
           }
}
else for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {  if (abs (matrixpro[i][i]) < abs (matrixpro[j][i]) )
         {
             for (k=0; k<m;k++)
             {
                 /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                    swap(matrixpro[i][k],matrixpro[j][k]);
             }
         }
      if(i<pivote){
      int p=0;
      while (abs(matrixpro[i][i])<0.000001){
        for (k=0; k<m;k++)
             {
                 /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                    swap(matrixpro[i][k],matrixpro[j+p][k]);
             }
        p++;
        if(p+j>n)break;
      }}
      if (abs(matrixpro[j][j])<0.000001&&m-1==n&&abs(matrixpro[j-1][j-1])>0.000001&&j>0&&abs(matrixpro[i][m-2])>0.000001){esco++;
      if(matrixpro[n-1][m-2]!=0&&abs(matrixpro[j][j])<0.000001)
      for (size_t z = 0; z < n; z++)
      {
        vaux0[z]=matrixpro[z][m-2];
        vauxinf[z]=matrixpro[z][j];
        vaux1[z]=swapv[z][m-2];
        vaux2[z]=swapv[z][j];
        swapv[z][m-2]=vaux2[z];
        swapv[z][j]=vaux1[z];
        matrixpro[z][m-2]=vauxinf[z];
        matrixpro[z][j]=vaux0[z];}
    }
    if(abs(matrixpro[j][i])>0.000001){
      double OperacionMatrices=matrixpro [j][i]/matrixpro [i][i];
         for (k=0; k<m;k++)
         {
           matrixpro[j][k]=matrixpro[j][k]-OperacionMatrices*matrixpro[i][k];}}
          //  if(n!=m-1){{
          //    for(int l=j;l<m;l++){
          //      OperacionMatrices=matrixpro [i][l]/matrixpro [i][l];}
          //    for (k;k<m;k++)
          //    matrixpro[i+1][k]=matrixpro[i+1][k]-OperacionMatrices*matrixpro[i][k];
          //    }}
             }
  //                     for (int a=0;a<n;a++){
  // { for (size_t b = 0; b < m; b++){
  // if (matrixpro[a][b]!=matrixpro[a][b])
  //   cout<<" 0 ";
  // else if(abs(matrixpro[a][b])<0.0001)
  // cout<<"0 ";
  // else  cout<<matrixpro[a][b]<<" ";
  // }}
  // cout<<"\n";}
   }
  //                   for (int a=0;a<n;a++){
  // { for (size_t b = 0; b < m; b++){
  // if (matrixpro[a][b]!=matrixpro[a][b])
  //   cout<<" 0 ";
  // else if(abs(matrixpro[a][b])<0.0001)
  // cout<<"0 ";
  // else  cout<<matrixpro[a][b]<<" ";
  // }}
  // cout<<"\n";}
   if (abs(matrixpro[n-1][m-2])>0.00001&&abs(matrixpro[n-1][m-1])>0.00001&&abs(matrixpro[n-2][pivote-2])<0.00001&&m-1>n){
     for (k=0; k<n;k++)
             {
              vaux1[k]=swapv[k][pivote-1];
              vaux2[k]=swapv[k][pivote-2];
              swapv[k][pivote-2]=vaux2[k];
              swapv[k][pivote-1]=vaux1[k];
             }
    
     for (size_t i = 0; i < n; i++)
    {
    for (size_t j = 0; j < m; j++)
    {
    matrixpro[i][j]=swapv[i][j];
    }}
     for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {  if (abs (matrixpro[i][i]) < abs (matrixpro[j][i]))
         {
             for (k=0; k<m;k++)
             {
                 /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                    swap(matrixpro[i][k],matrixpro[j][k]);
             }
         }
      int p=0;
      while (abs(matrixpro[i][i])<0.000001){
        for (k=0; k<m;k++)
             {
                 /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                    swap(matrixpro[i][k],matrixpro[j+p][k]);
             }
        p++;
        if(p+j>n)break;
      }
    if (abs(matrixpro[j][j])<0.000001&&j>0){
      for (size_t l = i; l < pivote; l++)
  {
    {
      for (size_t s = 0; s <m-1; s++)
      {
      if(matrixpro[l][m-s-2]!=0&&abs(matrixpro[l][l])<0.000001)
      for (size_t z = 0; z < n; z++)
      {
        vaux0[z]=matrixpro[z][m-s-2];
        vauxinf[z]=matrixpro[z][l];
        vaux1[z]=swapv[z][m-s-2];
        vaux2[z]=swapv[z][l];
        swapv[z][m-2-s]=vaux2[z];
        swapv[z][l]=vaux1[z];
        matrixpro[z][m-2-s]=vauxinf[z];
        matrixpro[z][l]=vaux0[z];}
      }
    }
  }
    }
    if(abs(matrixpro[j][i])>0.000001){
      double OperacionMatrices=matrixpro [j][i]/matrixpro [i][i];
         for (k=0; k<m;k++)
         {
           matrixpro[j][k]=matrixpro[j][k]-OperacionMatrices*matrixpro[i][k];}}
           }
           }
      asignacion(matrixpro,auxmatrixpro,m,n,pivote,pivote,esco);   }

for (i = 0; i < n; i++){
  for ( j = 0; j < m; j++){
    if(abs(matrixpro[i][j])<0.0000001||abs(matrixpro[i][j])!=abs(matrixpro[i][j])){matrixpro[i][j]=0;}}
    }
if(m-1>n&&matrixpro[pivote-1][pivote-1]==0){
  for (size_t l = 0; l < pivote; l++)
  {
    if(matrixpro[l][l]==0)
    {
      for (i = 0; i <m; i++)
      {
      if(matrixpro[l][m-i-2]!=0&&matrixpro[l][l]==0)
      for (size_t z = 0; z < n; z++)
      {
        vaux0[z]=matrixpro[z][m-i-2];
        vauxinf[z]=matrixpro[z][l];
        vaux1[z]=swapv[z][m-i-2];
        vaux2[z]=swapv[z][l];
        swapv[z][m-2]=vaux2[z];
        swapv[z][l]=vaux1[z];
        matrixpro[z][m-2]=vauxinf[z];
        matrixpro[z][l]=vaux0[z];}
      }
    }
  }
}
for (size_t i = 0; i < pivote; i++)
{
  if(matrixpro[i][i]!=0&&matrixpro[i][i]==matrixpro[i][i])++rangoa;
}
//if(matrixpro[n-1][m-1]!=0)++rangoass;
for (size_t i = 0; i<n; i++)
{   if(matrixpro[i][m-1]==matrixpro[i][m-1])++rangoass;
    if(n>m-1)if(abs(matrixpro[n-i-1][m-1])==0&&matrixpro[n-i-1][m-1-i]==0)--rangoass;
    if(n<=m-1)if(matrixpro[i][i]==0&&matrixpro[i][m-1]==0)--rangoass;
}
if(matrixpro[pivote-1][m-1]!=0&&matrixpro[pivote-1][pivote-1]!=0)rangoass=rangoa;
else rangoass--;
if(n>m-1){for (size_t i = 0; i <n-pivote; i++)
{
if (matrixpro[n-1-i][m-2]==0&&matrixpro[n-1-i][m-1]!=0)rangoass--;
}}
int sies=0;
if(m-1==n)if(abs(matrixpro[n-1][m-1])<0.0000001&&abs(matrixpro[n-1][m-2])<0.0000001)--rangoass;
if(m-1>n)if(abs(matrixpro[n-1][m-1])<0.0000001&&abs(matrixpro[n-1][m-2])<0.0000001&&abs(matrixpro[n-1][m-3])<0.000001&&abs(matrixpro[n-1][m-n])<0.000001)--rangoass;
if(m-1>n)if(rangoa>rangoass)rangoass=rangoa;
if(m-1==n){
  for (size_t i = 0; i < n; i++)
  {
    if(matrixpro[i][i]!=0&&(matrixpro[i][m-1]==matrixpro[i][m-1])){++sies;}
  }
  if(matrixpro[n-1][m-2]==0&&matrixpro[n-1][m-1]!=0)--sies;
  if(sies==rangoa)rangoass=rangoa;
}
if((m-1)<n){
if(matrixpro[n-1][m-1]==0&&matrixpro[n-1][m-2]==0){
for (i = 0; i < pivote; i++){
  for ( j = 0; j <m; j++){
  auxmatrixpro[i][j]=matrixpro[pivote-1-i][pivote-1-j];}
  auxmatrixpro[i][m-1]=matrixpro[pivote-i-1][m-1];}  
}
else{
for (i = 0; i < n; i++){
  for ( j = 0; j <m; j++){
  auxmatrixpro[i][j]=matrixpro[n-1-i][m-2-j];}
  auxmatrixpro[i][m-1]=matrixpro[n-i-1][m-1];}}}
else
{
if(rangoa<n&&esco!=0&&m-1==n){
  for (i = 0; i < rangoa; i++){
  for ( j = 0; j <rangoa; j++){
  auxmatrixpro[i][j]=matrixpro[n-1-(n-rangoa)-i][m-2-(n-rangoa)-j];}
  auxmatrixpro[i][m-1]=matrixpro[rangoa-i-1][m-1];}}
  else 
  for (i = 0; i < pivote; i++){
  for ( j = 0; j <m; j++){
  auxmatrixpro[i][j]=matrixpro[pivote-1-i][pivote-1-j];}
  auxmatrixpro[i][m-1]=matrixpro[n-i-1][m-1];}}
if(m-1>n){
  for (i = 0; i < n; i++){
  for ( j = n; j < m; j++){
  auxmatrixpro[i][j]=matrixpro[n-1-i][j];}
  auxmatrixpro[i][m-1]=matrixpro[n-i-1][m-1];}}
//  for (i = 0; i < n; i++){
//   for ( j = 0; j < m; j++){
//    printf(" %1.3f ",auxmatrixpro[i][j]);}
//     printf("\n");}
// for (i=n-1;i>0;i--){
//     for (j=i+1;j>0;j--)
//     { for(int l=i;l<=m;l++){matrixpro [i][l]=matrixpro [i][l]/matrixpro [i][i];}
    
//       double OperacionMatrices=matrixpro[i][i];
      // for (k=n-1; k>=0;k--)
      //    {
      //      matrixpro[j][k]=matrixpro[j][k]-matrixpro[i][i]*matrixpro[j][k];
      //    }
    //}}
i=0;
j=0;
k=0;
if(rangoa==1&&rangoass==1)
{
auxmatrixpro[n-1][m-1]=auxmatrixpro[n-1][m-1]/auxmatrixpro[n-1][m-2];
}
else if(abs(matrixpro[n-1][m-1])>0.0000001&&abs(matrixpro[n-1][m-2])>0.0000001 && rangoa==rangoass)
{    
for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {
      double OperacionMatrices=auxmatrixpro [j][i]/auxmatrixpro [i][i];
         for (k=0; k<m;k++)
         {
           auxmatrixpro[j][k]=auxmatrixpro[j][k]-OperacionMatrices*auxmatrixpro[i][k];}}}
for (i = 0; i <n; i++){
  for ( j = 0; j<m; j++){
    auxmatrixpro[i][m-1-j]=auxmatrixpro[i][m-1-j]/auxmatrixpro[i][i];
    if(abs(auxmatrixpro[i][j])<0.00001){auxmatrixpro[i][j]=0;}}}
}
else if(abs(matrixpro[n-1][m-1])<0.0000001&&abs(matrixpro[n-1][m-2])<0.0000001 && rangoa==rangoass&&auxmatrixpro[0][0]==0)
{
if(abs(matrixpro[n-1-i][m-1-i])<0.0000001){
for (i=0;i<n-1;i++){
if(abs(matrixpro[n-1-i][m-1-i])<0.0000001)++i;
    for (j=i+1;j<n;j++)
    {
      double OperacionMatrices=auxmatrixpro [j][i]/auxmatrixpro [i][i];
         for (k=0; k<m;k++)
         {
           auxmatrixpro[j][k]=auxmatrixpro[j][k]-OperacionMatrices*auxmatrixpro[i][k];}}}}
else for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {
      double OperacionMatrices=auxmatrixpro [j][i]/auxmatrixpro [i][i];
         for (k=0; k<m;k++)
         {
           auxmatrixpro[j][k]=auxmatrixpro[j][k]-OperacionMatrices*auxmatrixpro[i][k];}}}
for (i = 0; i <n; i++){
  for ( j = 0; j<m; j++){
    auxmatrixpro[i][m-1-j]=auxmatrixpro[i][m-1-j]/auxmatrixpro[i][i];
    if(abs(auxmatrixpro[i][j])<0.00001){auxmatrixpro[i][j]=0;}}}
}
else if(rangoa==rangoass){
for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {
      double OperacionMatrices=auxmatrixpro [j][i]/auxmatrixpro [i][i];
         for (k=0; k<m;k++)
         {
           auxmatrixpro[j][k]=auxmatrixpro[j][k]-OperacionMatrices*auxmatrixpro[i][k];}}}
for (i = 0; i <n; i++){
  for ( j = 0; j<m; j++){
    auxmatrixpro[i][m-1-j]=auxmatrixpro[i][m-1-j]/auxmatrixpro[i][i];
    if(abs(auxmatrixpro[i][j])<0.00001){auxmatrixpro[i][j]=0;}}}}
    for (i = 0; i < n; i++){
  for ( j = 0; j < m; j++){
    if(abs(matrixpro[i][j])<0.00001){matrixpro[i][j]=0;}}
    }
//  for (i = 0; i < n; i++){
//   for ( j = 0; j < m; j++){
//    printf(" %1.3f ",auxmatrixpro[i][j]);}
//     printf("\n");}
     determinante=determinate(pivote,matrixpro);
    if(determinante!=determinante||abs(determinante)<0.00001)determinante=0;
    
           // el proceso de acontinucion es la representacionn de la eliminacionn gauss jorda pero debido a que no se puede hacer de forma exacta por los decimales para arriba se tendra que hacer con na variable auxiliar
// for (i=n-1;i>=0;i--)
// { AuxiliaResultado[i]=matrixpro[i][n];
//     for (j=i+1;j<n;j++)
//     {
//       if (i!=j)
//       {AuxiliaResultado[i]=AuxiliaResultado[i]-matrixpro[i][j]*AuxiliaResultado[j];
//       if(n!=m-1)
//       matrixpro[i][m-2]=matrixpro[i][m-2]-matrixpro[i][j]*AuxiliaResultado[j]; }
//             } AuxiliaResultado [i]=AuxiliaResultado [i]/matrixpro [i][i];}
if((m-1)>n){
  Esli=false;
  Esgen=true;
  Base=false;
}
else if((m-1)<n){
  Esli=true;
  Esgen=false;
  Base=false;
}
else if(n<=m-1){if(determinante!=0){
  Esli=true;
  Esgen=true;
  Base=true;
}
else{
Esli=false;
Esgen=false;
Base=false;}
}
if(rangoa<n){Esgen=false;Base=false;if(determinante==0)Esli=false;}
for (size_t i = 0; i < pivote; i++)
{
  if(abs(auxmatrixpro[i][i])<0.00001)nosera++;
}
if(nosera!=0)Esgen=false;
//   if(Base==true){
//     cout<<"Los vectores dados forman una base"<<endl;
//   }
//   else cout<<"Los vectores dados no forman una base"<<endl;
//   if(Esli==true){
//     cout<<"Los vectores dados son linealmente independientes"<<endl;
//   }
//   else cout<<"Los vectores dados son linealmente codependientes"<<endl;
//   if (Esgen==true)
//   {
//     cout<<"Los vectores dados generan a R^"<<(n)<<endl;
//   }else cout<<"Los vectores dados no generan a R^"<<n<<endl;
if(Base==true){
for (size_t i = 0; i <n; i++)
{
    matrizdedtrancicion[i][posicion]=auxmatrixpro[n-1-i][m-1];
}

}
//   if (abs(matrixpro[n-1][m-1])<0.000001 && abs(matrixpro[n-1][m-2])<0.000001 && (rangoa==rangoass)|| (rangoa==rangoass&&m-1>n)){
//   cout<<"la cobinacion lineal tiene una infinidad de soluciones la siguinte representacion lineal considera a los parametros libres como 0 para obtener una solucion\n(";
//   if(m-1>n){
//     cout<<'(';
//   for (size_t i = 0; i < n; i++)
// {cout<<vectores[i][m-1]<<",";
// }
// cout<<") =";
//  for (i = 0; i <pivote; i++){
//   if(auxmatrixpro[n-1-i][m-1]==auxmatrixpro[n-1-i][m-1]||abs(auxmatrixpro[n-1-i][m-1])>0.0000001)
//   cout<<auxmatrixpro[n-1-i][m-1]<<"(";
//   else cout<<"0(";
//   for ( j = 0; j<n; j++){
//    if(rangoa==1){printf("%1.3f,",swapv[j][m-2-i]);}
//    else printf("%1.3f,",swapv[j][i]);}
//    printf(") + ");
//     }
//   for (i = pivote; i <m-1; i++){
//    cout<<"0(";
//   for ( j = 0; j<n; j++){
//    printf("%1.3f,",swapv[j][i]);}
//    printf(") + ");
//     }
//   }
//   else if(m-1<n){
//     for (size_t i = 0; i <= m; i++)
// {cout<<vectores[m-1][i]<<",";
// }
// cout<<") =";
//  for (i = 0; i < pivote; i++){
//   if(auxmatrixpro[pivote-1-i][m-1]==auxmatrixpro[pivote-1-i][m-1])
//   cout<<auxmatrixpro[pivote-1-i][m-1]<<"(";
//   else cout<<"0 (";
//   for ( j = 0; j < n; j++){
//    printf("%1.3f,",vectores[i][j]);}
//    printf(") + ");
//     }
//   }
//     else if(m-1==n){
//     for (size_t i = 0; i < n; i++)
// {cout<<vectores[i][m-1]<<",";
// }
// cout<<")=";
//  for (i = 0; i <m-(m-rangoa); i++){
//   if(auxmatrixpro[0][0]!=auxmatrixpro[0][0])cout<<auxmatrixpro[m-(m-rangoa)-i][m-1]<<"(";
//   // else cout<<"0(";
//   for ( j = 0; j<n; j++){
//    printf("%1.3f,",swapv[j][i]);}
//    printf(") + ");
//     }
//     for (i = rangoa; i <m-1; i++){
//    cout<<"0(";
//   for ( j = 0; j<n; j++){
//    printf("%1.3f,",swapv[j][i]);}
//    printf(") + ");
//     }
//   }
//   cout<<"0";}
//    else if (auxmatrixpro[n-1][m-2]!=auxmatrixpro[n-1][m-2] || rangoa!=rangoass){
//   cout<<"El vector u dado no pertenece a el espacio vectorial formado por los vectores dados\n";
//   }
//   else if (abs(matrixpro[n-1][m-1])>0.0001 && abs(matrixpro[n-1][m-2])>0.0001&&abs(matrixpro[n-1][m-3])<0.0001){
//   cout<<"\nLa combinacion lineal de los vectores dados para que u perteneca al espacio vectorial generado es:\n(";
// for (size_t i = 0; i < n; i++)
// {cout<<vectores[i][m-1]<<",";
// }
// cout<<") =";
//   for (i = 0; i <m-1; i++){
//   if(auxmatrixpro[rangoa-1-i][m-1]==auxmatrixpro[rangoa-1-i][m-1]||abs(auxmatrixpro[rangoa-1-i][m-1])>0.0000001)
//   cout<<auxmatrixpro[n-1-i][m-1]<<"(";
//   else cout<<"0(";
//   for ( j = 0; j<n; j++){
//    printf("%1.3f,",swapv[j][i]);}
//    printf(") + ");
//     }
//    cout<<"0"; }
//    if(matrixpro[rangoa-1][m-1]==0&&matrixpro[rangoa-1][m-2]!=0)
//    {for (i=0;i<n-1;i++){
//     for (j=i+1;j<n;j++)
//     {
//       double OperacionMatrices=auxmatrixpro [j][i]/auxmatrixpro [i][i];
//          for (k=0; k<m;k++)
//          {
//            auxmatrixpro[j][k]=auxmatrixpro[j][k]-OperacionMatrices*auxmatrixpro[i][k];}}
//            }
//       auxmatrixpro[rangoa-1][m-1]=auxmatrixpro[rangoa-1][m-1]/auxmatrixpro[rangoa-1][m-2];
//      cout<<'(';
//      for (size_t i = 0; i < n; i++)
// {cout<<swapv[i][m-1]<<",";
// }
// cout<<")= ";
//  for (i = 0; i <rangoa; i++){
//   if(auxmatrixpro[rangoa-1-i][m-1]==auxmatrixpro[rangoa-1-i][m-1]||abs(auxmatrixpro[n-1-i][m-1])>0.0000001)
//   cout<<auxmatrixpro[i][m-1]<<"(";
//   else cout<<"0(";
//   for ( j = 0; j<n; j++){
//    printf("%1.3f,",swapv[j][m-2-i]);}
//    printf(") + ");
//     }
//     cout<<'0';
//    }
//     for (size_t i = 0; i < n; i++)
//   {
//     vectorcero=abs(matrixpro[i][m-1])+ vectorcero;
//   }
//   if(vectorcero==0){cout<<"El vector u dado es el vector cero por lo tanto puede haber una infinidad de soluciones sin embargo la forma mas facil es con las constantes igual a 0 entonces\n";
//   cout<<"(";
//   for (size_t i = 0; i<n; i++)
// {
//   cout<<"0,";
// }
// cout<<")";
// cout<<"=";
//  for (i = 0; i < pivote; i++){
//   if(auxmatrixpro[n-i-1][m-1]==auxmatrixpro[n-i-1][m-1])
//   cout<<auxmatrixpro[n-1-i][m-1]<<"(";
//   else cout<<"0(";
//   for ( j = 0; j < n; j++){
//    printf("%1.3f,",swapv[j][i]);}
//    printf(") + ");
//     }
//   cout<<"0";}
// finale:
// if(m==2){
//   if(matrixpro[1][1]==0){
//   for (size_t l = -1; l <n; l++)
//   {
//   cout<<v2[2][l]<<",";}
//   cout<<"u =";
//   if(auxmatrixpro[n-1][m-1]==auxmatrixpro[n-1][m-1])
//   cout<<matrixpro[0][m-1]/matrixpro[0][0]<<"(";
//   else cout<<"0(";
//   for ( j = 0; j < n; j++){
//    printf("%1.3f,",v2[1][j]);}
//    printf(") + "); 
//   cout<<"0\ntampoco es base no genera a R de la dimension en la que se encuntran los vectores y el vector es evidentemente li";}
//   else cout<<"No son  multiplos porr lo tanto no exite una constante que multiplicada por el vector dado de el vector u, tampoco es base no gnera a R de la dimension en la que se encuntra y le vector es evidentemente li";
//   }
//   // if(pertenece!=0)
//   // for (size_t i = 0; i < n; i++)
//   // {
//   //   cout<<'('<<swapv[i][pertenece]<<",";
//   // }
// else if(rangoa==1&&n>=m-1){
//     cout<<"(";if(n==m-1)
//     for (size_t i = 0; i < n; i++)
// {cout<<vectores[i][m-1]<<",";
// }
// else {for (size_t i = 0; i < n; i++)
// {cout<<swapv[i][m-1]<<",";
// }
// auxmatrixpro[n-2-(n-(m))][m-1]=auxmatrixpro[n-2-(n-(m))][m-1]/auxmatrixpro[n-2-(n-(m))][m-3];}
// cout<<") =";
//   for (i = 0; i <m-1; i++){
//   if(auxmatrixpro[rangoa-1-i][m-1]==auxmatrixpro[rangoa-1-i][m-1]||abs(auxmatrixpro[rangoa-1-i][m-1])>0.0000001)
//   if(n==m-1)cout<<auxmatrixpro[n-1-i][m-1]<<"(";
//   else cout<<auxmatrixpro[n-1-(n-m)-i][m-1]<<"(";
//   else cout<<"0(";
//   for ( j = 0; j<n; j++){
//    printf("%1.3f,",swapv[j][i]);}
//    printf(") + ");
//     }
//    cout<<"0";
//   }
//   cout<<"\nLas matriz para obtener los rangos (con eliminacion parcial) es la siguiente\n";
// cout<<rangoa<<"     "<<rangoass<<"   "<<determinante<<endl;
// for (i=0;i<n;i++){
//   { for (size_t j = 0; j < m; j++){
//   if (matrixpro[i][j]!=matrixpro[i][j])
//     cout<<" 0 ";
//   else if(abs(matrixpro[i][j])<0.0001)
//   cout<<"0 ";
//   else  cout<<matrixpro[i][j]<<" ";
//   }}
//   cout<<"\n";}
  if(Base==true) return true;
  else return false;
}
void transponer( double matriz[10][10],double transpuesta[10][10],int n){
for (size_t i = 0; i <n; i++)
{
  for (size_t j = 0; j <n; j++)
  {
    transpuesta[i][j]=matriz[j][i];
  }
  
}

}
int main(){
    cout<<"Este programa detrmina si las matrices dadas son bases o no y de ser asi tranforma al vector w=(1,1,1...,1) en base canonica a las bases dadas\n";
    double matrizdedtrancicionB1[10][10];
    double matrizdedtrancicionB2[10][10];
    double matrizdedtrancicionB3[10][10];
    double matrizcanonica[10][10],transpuesta[10][10];
    double matrizaux[10][10],vectoruno[10],vectortransformado[10],vectortransformado1[10],vectortransformado2[10],vectormas[10];
    double B1[10][10],B2[10][10],B3[10][10];
    int n=0,m=0,mas=1;
    bool Eb1=false,Eb2=false;
    puts("Introduce la dimension n de los vectores de R en la que viven y luego el numero de vectorees que ingresara (Dimension de la matriz)");
    cout<<"n: ";
    scanf("%d", &n);
    cout<<"\n#v(Dim): \n";
    scanf("%d", &m);
    if(m==n){
    printf("Ingrese los vectores en orden v1,v2,...,vn\n");
    for (size_t i = 0; i <m; i++)
    {   cout<<"V "<<i+1<<": ";
        for (int j = 0; j <n; j++)
        {
        cin>>B1[j][i];
        }
        cout<<"\n";
    }
    printf("Ingrese los vectores en orden v1,v2,...,vn\n");
    for (size_t i = 0; i <m; i++)
    {   cout<<"V"<<i+1<<": ";
        for (int j = 0; j <n; j++)
        {
        cin>>B2[j][i];
        }
        cout<<"\n";
    }
    for (size_t i = 0; i < n; i++)
    {   matrizcanonica[i][i]=1;
        vectoruno[i]=1;
        for (size_t j = 0; j < m; j++)
    {   if(j!=i)
        matrizcanonica[i][j]=0;
    }
    }
    
    m+=1;
    if(Es_base_o_no(B1,matrizdedtrancicionB1,matrizcanonica[0],0,m,n)==true)Eb1=true;
    if(Es_base_o_no(B2,matrizdedtrancicionB2,matrizcanonica[0],0,m,n)==true)Eb2=true;
    if (Eb1==true&&Eb2==true)
    {
    transponer(B1,transpuesta,n);
    Es_base_o_no(B2,B3,transpuesta[0],0,m,n);
    for (size_t i = 1; i < n; i++)
    {
    Es_base_o_no(B1,matrizdedtrancicionB1,matrizcanonica[i],i,m,n);
    Es_base_o_no(B2,B3,transpuesta[i],i,m,n);
    } 
    for (size_t i = 1; i < n; i++)
    {
    Es_base_o_no(B2,matrizdedtrancicionB2,matrizcanonica[i],i,m,n);
    }
    for (size_t i = 0; i < n; i++)
    {
      Es_base_o_no(B3,matrizdedtrancicionB3,matrizcanonica[i],i,m,n);
    }
    multiplicacion(matrizdedtrancicionB1,vectoruno,n,vectortransformado); 
    cout<<"La matriz de trancision de la base B1 a la base canonica es y el vector w se expresa como\n";
    for (size_t i = 0; i < m-1; i++)
    {   
        for (size_t j = 0; j < n; j++)
        {
            cout<<' '<<matrizdedtrancicionB1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"w en base b1 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado[i];
        if(i<n-1)cout<<',';
    }
    cout<<")";
    cout<<"\nLa matriz de trancision de la base B2 a base canonica es y el vector w se expresa como\n";
    multiplicacion(matrizdedtrancicionB2,vectoruno,n,vectortransformado1); 
    for (size_t i = 0; i < m-1; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout<<' '<<matrizdedtrancicionB2[i][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<"w en base b2 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado1[i];
        if(i<n-1)cout<<',';
        
    }
    cout<<")";
        cout<<"\nLa matriz de trancision de la base B1 a la base B2 (B3) es la siguinete\n";
    multiplicacion(B3,vectortransformado,n,vectortransformado2); 
    for (size_t i = 0; i < m-1; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout<<' '<<B3[i][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<"Y el vector w se expresa en base B3 como : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado2[i];
        if(i<n-1)cout<<',';
        
    }
    cout<<")\n";
        while(mas==1){
    cout<<"Desea tranformar otro venctor a base B1,B2 y b3, si es asi digite 1 y posterirormente ingrese el vector u"<<endl;
    cin>>mas;
    if(mas==1){
      cout<<"u: ";
      for (size_t i = 0; i < n; i++)
      {
        cin>>vectormas[i];
      }
      multiplicacion(matrizdedtrancicionB1,vectormas,n,vectortransformado); 
    cout<<"u en base B1 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado[i];
        if(i<n-1)cout<<',';
    }
    cout<<")\n";
    multiplicacion(matrizdedtrancicionB2,vectormas,n,vectortransformado1); 
    cout<<"u en base B2 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado1[i];
        if(i<n-1)cout<<',';
    }
    cout<<")\n";
    multiplicacion(B3,vectortransformado,n,vectortransformado2); 
    cout<<"u en base B3 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado2[i];
        if(i<n-1)cout<<',';
    }
    cout<<")\n";
    }}
    }
    else{ cout<<"Una de las matrices dadas no forman una base";
    if(Eb1==true){
    for (size_t i = 1; i < n; i++)
    {
    Es_base_o_no(B1,matrizdedtrancicionB1,matrizcanonica[i],i,m,n);
    } 
    multiplicacion(matrizdedtrancicionB1,vectoruno,n,vectortransformado); 
      cout<<"La matriz de trancision de la base B1 es y el vector w se expresa como\n";
    for (size_t i = 0; i < m-1; i++)
    {   
        for (size_t j = 0; j < n; j++)
        {
            cout<<' '<<matrizdedtrancicionB1[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"w en base b1 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado[i];
        if(i<n-1)cout<<',';
    }
    cout<<")\n";
    while(mas==1){
    cout<<"Desea tranformar otro venctor a base B1, si es asi digite 1 y posterirormente ingrese el vector u"<<endl;
    cin>>mas;
    if(mas==1){
      for (size_t i = 0; i < n; i++)
      {
        cin>>vectormas[i];
      }
      multiplicacion(matrizdedtrancicionB1,vectormas,n,vectortransformado); 
    cout<<"u en base b1 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado[i];
        if(i<n-1)cout<<',';
    }
    cout<<")\n";
    }}
    }
    else if(Eb2==true){
          cout<<"\nLa matriz de trancision de la base B2 es y el vector w se expresa como\n";
    for (size_t i = 1; i < n; i++)
    {
    Es_base_o_no(B2,matrizdedtrancicionB2,matrizcanonica[i],i,m,n);
    }
    multiplicacion(matrizdedtrancicionB2,vectoruno,n,vectortransformado); 
    for (size_t i = 0; i < m-1; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout<<' '<<matrizdedtrancicionB2[i][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<"w en base b2 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado[i];
        if(i<n-1)cout<<',';
        
    }
    cout<<")";
    while(mas==1){
    cout<<"Desea tranformar otro venctor a base B2, si es asi digite 1 y posterirormente ingrese el vector u"<<endl;
    cin>>mas;
    if(mas==1){
      for (size_t i = 0; i < n; i++)
      {
        cin>>vectormas[i];
      }
      multiplicacion(matrizdedtrancicionB2,vectormas,n,vectortransformado); 
    cout<<"u en base B2 : (";
        for (size_t i = 0; i < n; i++)
    {
        cout<<' '<<vectortransformado[i];
        if(i<n-1)cout<<',';
    }
    cout<<")\n";
    }}
    }
    else cout<<"Ninguna de las matrices dadas es base";
    }
    }   else cout<<"Las matrices no pueden ser bases";
    return 0;
}
//        ^^^^^^^^^^^^
//       ^^********* ^^
//       ^* ^   ^   *^^^
//      ^^* o   o   * ^^
//      ^^*  O   * **^^  
//      ^^^* * *^^^^^^
//   ****    *
// ***  *    *
//      ************
//           *     * 
//           *     ****
//           *        ***
//           * 
//           *
//           *
//         * * *
//       *     *
//     *       *
//     *         *
//      *         *
//       *         *