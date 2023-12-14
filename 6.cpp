#include<iostream>
#include<iomanip>
using namespace std;

float f(float x){
    if(x==0){
        return 1;
    }
    return 1/(1+(x*x));
}

float trapezoidal (float fx[],float h, int n){
    float res=0;
    for(int i=0;i<=n;i++){
        if(i==0||i==n){
            res+=fx[i];
        }else{
            res+=2*fx[i];
        }
    }
    return (res*h)/2;
}

int main(){
    float x,x1;
    cout<<"Enter values of X0 and Xn : ";
    cin>>x>>x1;
    int n;
    cout<<"Enter number of divisions : ";
    cin>>n;
    float h=(x+x1)/n;
    float xn[n],fx[n];
    for(int i=0;i<=n;i++){
        xn[i]=x+(i*h);
        fx[i]=f(x+(i*h));
    }
    cout<<"x"<<"\t\t\t"<<"f(x)"<<endl;
    for(int i=0;i<=n;i++){
        cout<<xn[i]<<"\t\t\t"<<setprecision (5)<<fx[i]<<endl;
    }
    cout<<endl;
    cout<<"The value of integral using trapezoidal method is : ";
    cout<<trapezoidal(fx,h,n);
    return 0;
}