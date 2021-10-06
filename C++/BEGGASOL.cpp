#include<bits/stdc++.h>
using namespace std ;

#define  ff      first 
#define  ss      second
#define  ull     unsigned long long 
#define  mod     1000000007
#define  inf     1e18
#define  w(x)    int x;cin>>x;while(x--)
#define  f(x,y)  for( x=1;x<=y;x++) 

int main(){
    w(t){
        int n,arr[101],i;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>arr[i];
            // cout<<"arr "<<i<<" is "<<arr[i]<<" ";
        }
        int petrol=arr[0];
        int distance=0;
        // cout<<"petrol is"<<petrol<<endl;
        for(int j=1;j<n;j++){
            if(petrol>=1){
                 distance++;
                 petrol--;
                 petrol+=arr[j];
                //  cout<<"petrol in loop"<<j<<"is"<<petrol<<endl<<"dis is"<<distance<<endl;
                 continue;
            }
            else{
                break;
            }
        }    
        std::cout <<distance+petrol << std::endl;
    }
 	return 0;
}

