// program to count the total number of distinct numbers in an array

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

    int dist_c = 0;
    for(int i=0; i<n; i++){
        bool is_dist = true;
        for(int j=0; j<i; j++){
            if(arr[i] == arr[j]){
                is_dist = false;
                break;
            }
        }
        if(is_dist){
            dist_c++;
        }
    }
    
    cout<<"Number of distinct elements in the array: "<<dist_c<<endl;

    return 0;
}