#include <iostream>

using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int arr[]={1,2,3,10,4};
    /* int rev[5],j=0;
    for(int i=4;i>=0;i--){
        rev[j]=arr[i];
        j++;
    }
    for(int i=0;i<5;i++){
        cout<<rev[i]<<" ";
    } */

    int low=0,high=4;
    while(low<high){
        swap(arr[low],arr[high]);
        low++;high--;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
