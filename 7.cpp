#include<iostream>
#include<iomanip>
using namespace std;

float f(float x){
    return 1/(1+(x*x));
}

float simson_one_third_rule(float fx[],float h,int n){
    float res=0;
    for(int i=0;i<=n;i++){
        if(i==0||i==n){
            res+=fx[i];
        }
        else if(i%2==0){
            res=res+2*fx[i];
        }
        else if(i%2!=0){
            res=res+4*fx[i];
        }
    }
    res=res*(h/3);
    return res;
}

int main(){
    float x,x1;
    cout<<"Enter values of X0 and Xn : ";
    cin>>x>>x1;
    int n;
    cout<<"Enter number of divisions : ";
    cin>>n;
    if(n==0 && n%2!=0){
        return 0;
    }
    float h=(x+x1)/n;
    float xn[n],fx[n];
    for(int i=0;i<=n;i++){
        xn[i]=x+i*h;
        fx[i]=f(x+i*h);
    }
    cout<<"x"<<"\t\t\t"<<"f(x)"<<endl;
    for(int i=0;i<=n;i++){
        cout<<xn[i]<<"\t\t\t"<<setprecision(5)<<fx[i]<<endl;
    }
    cout<<endl;
    cout<<"The value of integral using Simson's one-third method is: ";
    cout<<simson_one_third_rule(fx,h,n);
    return 0;
}