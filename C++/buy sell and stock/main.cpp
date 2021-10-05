#include <iostream>
using namespace std;

int main()
{
    //int arr[]={1,5,3,8,12};
    int arr[]={5,3,1};
    //int arr[]={1,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout<<n;
    int min,max,profit,mincount=0,maxcount=0;
    for(int i=0;i<n;i++){
        if(arr[i]<arr[i+1] && (i-1)<0){
            min=arr[i];
            mincount++;
        }
        else if(arr[i]<arr[i+1] && arr[i]<arr[i-1]){
            min=arr[i];
            mincount++;
        }
        else if(arr[i]>arr[i-1] && (i+1)>=n){
            max=arr[i];
            maxcount++;
        }
        else if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            max=arr[i];
            maxcount++;
        }
        if(mincount==maxcount){
            profit += max - min;
            max=NULL;
            min=NULL;
        }
    }
    cout<<profit;
    return 0;
}
