#include<iostream>
#include<iomanip>
using namespace std;
void convertone(float m[3][3],float a[3][3],int x){
    float f=m[x][x];
    for(int j=0;j<3;j++){
        if(m[x][x]!=0.0){
            m[x][j]/=f;
            a[x][j]/=f;
        }
    }
}
void rowoperation(float m[3][3], float a[3][3], int row, int n){
    for(int i=0;i<n;i++){
        float f=m[i][row];
        if(i!=row){
            for(int j=0;j<n;j++){
                m[i][j]-=(m[row][j]*f);
                a[i][j]-=(a[row][j]*f);
            }
        }
    }
}
void gaussjordan(float m[3][3],float a[3][3]){
    for(int i=0;i<3;i++){
        convertone(m,a,i);
        rowoperation(m,a,i,3);
    }
}
void argumentform(float m[3][3],float a[3][3],float b[3][6]){
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            if(j<3){
                b[i][j]=m[i][j];
            }else{
                b[i][j]=a[i][j-3];
            }
        }
    }
}
int main(){
    float m[3][3];
    float a[3][3]={0};
    float b[3][6];
    a[0][0]=1;
    a[1][1]=1;
    a[2][2]=1;
    cout<<"Enter elements of matrix M : "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>m[i][j];
        }
    }
    cout<<"Argumened form [M:I] : "<<endl;
    argumentform(m,a,b);
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    gaussjordan(m,a);
    cout<<"Inverse of M using Gauss Jordan Method: \n";
    cout<<fixed<<setprecision(2);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}

