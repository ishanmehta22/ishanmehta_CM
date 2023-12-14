#include<iostream>
using namespace std;
float f(float x, float y){
    return (y*y-x*x)/(y*y+x*x);
}
float Rungekutta(float k[]){
    float res=0;
    for(int i=0;i<4;i++){
        if(i==0||i==3){
            res+=k[i];
        }else{
            res+=2*k[i];
        }
    }
    return res/6;
}
int main(){
    float x0,y0;
    cout<<"Enter values of x0 & y0 : ";
    cin>>x0>>y0;
    float xn;
    cout<<"Enterr final value : ";
    cin>>xn;
    float h=xn-x0;
    float k[4];
    for(int i=0;i<4;i++){
        if(i==0){
            k[i]=h*f(x0,y0);
        }else if(i==3){
            k[i]=h*f(x0+h,y0+(0.5*k[i-1]));
        }else{
            k[i]=h*f(x0+(0.5*h),y0+(.5*k[i-1]));
        }
    }
    for(int i=0;i<4;i++){
        cout<<"k"<<i+1<<" : "<<k[i]<<endl;
    }
    cout<<"\n The value of y at"<<xn<<" is "<<y0+Rungekutta(k);
    return 0;

}