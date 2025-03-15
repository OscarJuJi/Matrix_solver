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
             for (size_t i = 0; i < n; i++)
  { 
    determinante=determinante*matrixpro[i][i];
  }
  return determinante*signos;
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
int main ()
{  
puts("Introduce la dimension de los vectores de R en la que viven y luego el numero de vectorees que ingresara");
int n,m,i,j,k;
cout<<"n: ";
scanf("%d", &n);
cout<<"\n#v(Dim): \n";
scanf("%d", &m);
double matrixpro[n][10] = {};
double auxmatrixpro[n][10] = {};
double swapv[10][10];
double AuxiliaResultado[n];
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
printf("Ingrese los vectores en orden v1,v2,...,vn y hasta el ultimo el vector u que desea verificar si pertenece al plano generado por los vectores\n");
for (i = 0; i <m; i++)
{ cout<<"V"<<i+1<<": ";
  for ( j = 0; j <n; j++)
{cin>>matrixpro[j][i];
}}
++m;
for (i = 0; i <n; i++){
matrixpro[i][m-1]=0;
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
  cout<<ev<<pertenece<<endl;
} 

for (i = 0; i <n; i++){
  for ( j = 0; j <m; j++){
   cout<<swapv[i][j]<<" ";}
   cout<<"\n";}
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
             }
   }
                    for (int a=0;a<n;a++){
  { for (size_t b = 0; b < m; b++){
  if (matrixpro[a][b]!=matrixpro[a][b])
    cout<<" 0 ";
  else if(abs(matrixpro[a][b])<0.0001)
  cout<<"0 ";
  else  cout<<matrixpro[a][b]<<" ";
  }}
  cout<<"\n";}
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
  for (i = 0; i <n; i++){
  for ( j = 0; j <m-1; j++){
  auxmatrixpro[i][j]=matrixpro[n-1-i][m-2-j];}
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
i=0;
j=0;
k=0;
if(rangoa==1&&rangoass==1)
{
for ( j = 0; j<m; j++){
    if(j!=m-2)auxmatrixpro[n-1][j]=auxmatrixpro[n-1][j]/auxmatrixpro[n-1][m-2];
    if(abs(auxmatrixpro[i][j])<0.00001){auxmatrixpro[i][j]=0;}
    cout<<auxmatrixpro[n-1][m-1-j];}
    auxmatrixpro[n-1][m-2]=auxmatrixpro[n-1][m-2]/auxmatrixpro[n-1][m-2];
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
    if(j!=i)auxmatrixpro[i][j]=auxmatrixpro[i][j]/auxmatrixpro[i][i];
    if(abs(auxmatrixpro[i][j])<0.000001||auxmatrixpro[i][j]!=auxmatrixpro[i][j]){
      auxmatrixpro[i][j]=0;}}
     auxmatrixpro[i][i]=auxmatrixpro[i][i]/auxmatrixpro[i][i]; }
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
 for (i = 0; i < n; i++){
  for ( j = 0; j < m; j++){
   printf(" %1.3f ",auxmatrixpro[i][j]);}
    printf("\n");}
    determinante=determinate(pivote,matrixpro);
    if(determinante!=determinante||abs(determinante)<0.00001)determinante=0;
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
  if (abs(matrixpro[n-1][m-1])<0.000001 && abs(matrixpro[n-1][m-2])<0.000001 && (rangoa==rangoass)|| (rangoa==rangoass&&m-1>n)||(rangoa<n&&m-1<n)){
  if(m-1>=n){int p=0;
    cout<<"El conjunto de vectores de la imagen son:\n";
 for (i = 0; i <rangoa; i++){
  cout<<"(";
  for ( j = 0; j<n; j++){
   if(rangoa==1){printf("%1.3f,",swapv[j][m-2-i]);}
   else printf("%1.3f,",swapv[j][i]);}
   printf(") ");
   if(i<rangoa-1)cout<<",";
    }
cout<<"\nEl conjunto de vectores del espacio nulo es:\n";
if(auxmatrixpro[0][0]!=auxmatrixpro[0][0]){
  //para un lado con m>-1
  int sigue;
if(m-1>n){
  cout<<'x'<<m-2<<"(";
  for ( j = 0; j<rangoa; j++){
  printf("%1.3f,",auxmatrixpro[n-j-1][0]*-1);}
  for (int f=pivote; f<m-2; f++){
    if(f<i-1&&f!=pivote)printf(",");
   printf("0");
    }
    printf(",1"); 
      if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=pivote; f <m-1; f++){
   printf(",0");
    }
  }
  else{
  for (int f=pivote; f<m-1; f++){
    if(f<=m-2)printf(",");
   printf("0");
    }}
  printf(")+"); p++;
}
for (i=rangoa+p,p; i <m-1;p++,i++){
  cout<<'x'<<i+1<<"(";
  if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=0; f <pivote-1; f++){
    if(f<i&&f!=0)printf(",");
   printf("0");}}
  else{
  for ( j = 0; j<n-(n-rangoa); j++){
  printf("%1.3f",auxmatrixpro[n-j-1][i]*-1);
  if(j<n-(n-rangoa)-1)printf(",");}
  for (int f=n-(n-rangoa); f <m-1; f++){
    if(f<i-1&&f!=pivote)printf(",");
    if(((f)-(m-pivote))!=p)printf("0,");
   else printf("1");
  
}}
  if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=sigue; f <m-1; f++){
   printf(",0");
    }
  }
  // else{
  // for (int f=sigue-1; f<m; f++){
  //   if(f<m-1)printf(",");
  //  printf("0");
  //   }}
  printf(")");
  if(i<m-2)printf("+");}
  //para un lado con m==-1
if(m-1==n){
  cout<<'x'<<m-2<<"(";
  for ( j = 0; j<rangoa; j++){
  printf("%1.3f,",auxmatrixpro[n-j-1][0]*-1);}
  for (int f=pivote+(n-rangoa); f<m-2; f++){
    if(f<i-1&&f!=pivote)printf(",");
   printf("0");
    }
    printf(",1"); 
      if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=pivote; f <m-1; f++){
   printf(",0");
    }
  }
  else{
  for (int f=n; f<m-2; f++){
    if(f<=m-3)printf(",");
   printf("0");
    }}
  printf(")");}
}
else{
  for (i=rangoa; i <m-1; i++){
  cout<<'x'<<i+1<<"(";
    if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=0; f <pivote-1; f++){
    if(f<i&&f!=0)printf(",");
   printf("0");
    }
  }
  else{
  for ( j = 0; j<n-(n-rangoa); j++){
  printf("%1.3f",auxmatrixpro[n-j-1][i]*-1);
  if(j<n-(n-rangoa)-1)printf(",");}
  //
  int u=0;
  for (int f=n; f <m-1; f++){
    if(f<i-1&&f!=pivote)printf(",");
    if(f-n==p&&u==0){printf(",1");u=1;}
   else printf(",0");
  }}
  if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=pivote; f <m-1; f++){
   printf(",0");
    }
  }
  printf(") ");++p;
  if(i<m-2)printf("+ ");}}
  }
  else if(m-1<n){
    cout<<"El conjunto de vectores de la imagen son:\n";
 for (i = 0; i <rangoa; i++){
  cout<<"(";
  for ( j = 0; j<n; j++){
   if(rangoa==1){printf("%1.3f,",swapv[j][m-2-i]);}
   else printf("%1.3f,",swapv[j][i]);}
   printf(") ");
   if(i<rangoa-1)printf(",");
    }
cout<<"\nEl conjunto de vectores del espacio nulo es:\n";
if(auxmatrixpro[0][0]!=auxmatrixpro[0][0]){
for (i=rangoa+1; i <m-1; i++){
  cout<<'x'<<i+1<<"(";
    if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=0; f <pivote-1; f++){
    if(f<i&&f!=0)printf(",");
   printf("0");
    }
  }
  else{
  for ( j = 0; j<n-(n-rangoa); j++){
  printf("%1.3f",auxmatrixpro[n-j-1][i]*-1);
  if(j<n-(n-rangoa)-1)printf(",");}
  for (int f=pivote; f <m-2-i; f++){
    if(f<i-1&&f!=pivote)printf(",");
   printf("0");
    }}
  printf(",1"); 
  if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=pivote; f <m-1; f++){
   printf(",0");
    }
  }
  else{
  for (int f=pivote+(n-rangoa); f<m-2; f++){
    if(f<=m-3)printf(",");
   printf("0");
    }}
  printf(") + ");}
  {
  cout<<'x'<<m-2<<"(";
  for ( j = 0; j<rangoa; j++){
  printf("%1.3f,",auxmatrixpro[n-j-1][0]*-1);}
  for (int f=pivote+(n-rangoa); f<m-2; f++){
    if(f<i-1&&f!=pivote)printf(",");
   printf("0");
    }
    printf(",1"); 
      if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=pivote; f <m-1; f++){
   printf(",0");
    }
  }
  else{
  for (int f=n; f<m-2; f++){
    if(f<=m-3)printf(",");
   printf("0");
    }}
  printf(")");}
}
else{
  for (i=rangoa; i <m-1; i++){
  cout<<'x'<<i+1<<"(";
    if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=0; f <pivote-1; f++){
    if(f<i&&f!=0)printf(",");
   printf("0");
    }
  }
  else{
  for ( j = rangoa; j>0; j--){
  printf("%1.3f",auxmatrixpro[j][i-rangoa]*-1);
  if(j>1)printf(",");}
  for (int f=pivote; f <m-2-i; f++){
    if(f<i-1&&f!=pivote)printf(",");
   printf("0");
    }}
  printf(",1"); 
  if(auxmatrixpro[n-1][m-2]==0&&auxmatrixpro[0][m-2]==0&&auxmatrixpro[n/2][m-2]==0&&v0==0){
    for (int f=pivote; f <m-1; f++){
   printf(",0");
    }
  }
  else{
  for (int f=i; f<m-2; f++){
    if(f<=m-3)printf(",");
   printf("0");
    }}
  printf(") + ");}
  if(rangoa>=m-1){cout<<"(";
    for(int r=0;r<m-1;r++){cout<<"0";
    if(r<m-2)printf(",");}}
  cout<<")";}
  }
  }
  else if (rangoa==n&&m-1==n||(n>m-1&&rangoa==pivote)){
  cout<<"\nEl conjunto de vectores de la imagen son:\n";
  for (i = 0; i <m-1; i++){
    cout<<"(";
  for ( j = 0; j<n; j++){
   printf("%1.3f,",swapv[j][i]);}
   printf(")");
   if(i<m-2)cout<<",";
    }
  cout<<"\nEl conjunto del espacio nulo es:\n";
  cout<<"(";
    for(int r=0;r<m-1;r++){cout<<"0";
    if(r<m-2)printf(",");}
  cout<<")";}
   if(matrixpro[rangoa-1][m-1]==0&&matrixpro[rangoa-1][m-2]!=0&&n>m-1)
   {for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {
      double OperacionMatrices=auxmatrixpro [j][i]/auxmatrixpro [i][i];
         for (k=0; k<m;k++)
         {
           auxmatrixpro[j][k]=auxmatrixpro[j][k]-OperacionMatrices*auxmatrixpro[i][k];}}
           }
      auxmatrixpro[rangoa-1][m-1]=auxmatrixpro[rangoa-1][m-1]/auxmatrixpro[rangoa-1][m-2];
   }
    for (size_t i = 0; i < n; i++)
  {
    vectorcero=abs(matrixpro[i][m-1])+ vectorcero;
  }
if(rangoa==1&&(n>=m-1||n<m-1)){int p=0;
cout<<"Los vectores de la imagen son: "<<endl;
auxmatrixpro[n-2-(n-(m))][m-1]=auxmatrixpro[n-2-(n-(m))][m-1]/auxmatrixpro[n-2-(n-(m))][m-3];
  for (i = 0; i <rangoa; i++){
  printf("(");
  if(auxmatrixpro[rangoa-1-i][m-1]==auxmatrixpro[rangoa-1-i][m-1]||abs(auxmatrixpro[rangoa-1-i][m-1])>0.0000001)
  for ( j = 0; j<n; j++){
   printf("%1.3f,",swapv[j][i]);}
   printf(")");
  if(i<rangoa-1)printf(",");
    }
    int cont=0; 
    cout<<"\nEl conjunto de vectores del espacio nulo es:\n";
  for (i=1,cont=0; i <m-1; i++,cont++){
  cout<<'(';  
  cout<<auxmatrixpro[n-1][m-2-i]*-1;
  for (size_t as = 0; as < n-1; as++)
  {
    if(cont==as)cout<<",1";
    else cout<<",0";
  }
  cout<<")+";  
}
  cout<<"0";}
  cout<<"\nLas matriz para obtener los rangos (con eliminacion parcial) es la siguiente\n";
cout<<rangoa<<"     "<<rangoass<<"   "<<determinante<<endl;
for (i=0;i<n;i++){
  { for (size_t j = 0; j < m; j++){
  if (matrixpro[i][j]!=matrixpro[i][j])
    cout<<" 0 ";
  else if(abs(matrixpro[i][j])<0.0001)
  cout<<"0 ";
  else  cout<<matrixpro[i][j]<<" ";
  }
  cout<<"\n";}}
  return 0;}
//        ^^^^^^^^^^^^
//       ^^********* ^^
//       ^* ^   ^   *^^^
//      ^^* o   o   * ^^
//      ^^*  O   * **^^  
// *    ^^^* * *^^^^^^
// * ****    *
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