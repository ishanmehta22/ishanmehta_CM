#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
float f(float x){
    return x*x*x - 2*x - 5;
}
int main(){
    float x0, x1, x2, f0, f1, f2, e;
    int itr = 1, N;
    cout<<"Enter first guess: ";
    cin>>x0;
    cout<<"Enter second guess: ";
    cin>>x1;
    cout<<"Enter tolerable error: ";
    cin>>e;
    cout<<"Enter maximum iteration: ";
    cin>>N;
    do{
        f0 = f(x0);
        f1 = f(x1);
        if(f0 == f1)
        {
            cout<<"Mathematical Error.";
            exit(0);
        }
        x2 = x1 - (x1 - x0) * f1/(f1-f0);
        f2 = f(x2);
        cout<<"Iteration-"<< itr<<":\t x2 = "<< setw(10)<< x2<<" and f(x2) = "<<
        setw(10)<< f(x2)<< endl;
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        itr = itr + 1;
        if(itr > N){
            cout<<"Not Convergent.";
            exit(0);
        }
    }while(fabs(f2)>e);
    cout<< endl<<"Root is: "<< x2<<endl;
    return 0;
}