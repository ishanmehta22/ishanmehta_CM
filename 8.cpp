#include<iostream>
#include<iomanip>
using namespace std;

float f(float x){
    return 1/(1+(x*x));
}

float simson_three_eighth_rule(float fx[],float h,int n){
    float res=0;
    for(int i=0;i<=n;i++){
        if(i==0||i==n){
            res+=fx[i];
        }
        else if(i%3==0){
            res=res+2*fx[i];
        }
        else{
            res=res+3*fx[i];
        }
    }
    res=(res*3*h)/8;
    return res;
}

int main(){
    float x,x1;
    cout<<"Enter values of X0 and Xn : ";
    cin>>x>>x1;
    int n;
    cout<<"Enter number of divisions : ";
    cin>>n;
    if(n==0 && n%3!=0){
        return 0;
    }
    float h=(x1-x)/n;
    float xn[n+1],fx[n+1];
    for(int i=0;i<=n;i++){
        xn[i]=x+i*h;
        fx[i]=f(x+i*h);
    }
    cout<<"x"<<"\t\t\t"<<"f(x)"<<endl;
    for(int i=0;i<=n;i++){
        cout<<xn[i]<<"\t\t\t"<<setprecision(5)<<fx[i]<<endl;
    }
    cout<<endl;
    cout<<"The value of integral using Simson's three-eighth rule is: ";
    cout<<simson_three_eighth_rule(fx,h,n);
    return 0;
}