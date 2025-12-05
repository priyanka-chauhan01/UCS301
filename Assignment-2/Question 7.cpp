// program to count the number of inversion in an array

#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int inv_c = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                inv_c++;
            }
        }
    }

    cout<<"Number of inversions in the array: "<<inv_c<<endl;
    
    return 0;
}