// addition of two sparse matrices represented through triplets (arrays)

#include<iostream>
using namespace std;

int main(){

    int r,n,nele1,nele2;
    cout<<"Enter number of rows, columns and number of non zero elements of first matrix: ";
    cin>>r>>n>>nele1;
    
    int row1[r],col1[n],ele1[nele1];
    cout<<"Enter the triplet representation (row, column, element) of first matrix: \n";
    
    for(int i=0;i<nele1;i++){
        cin>>row1[i]>>col1[i]>>ele1[i];
    }
    
    cout<<"Enter number of non zero elements of second matrix: ";
    cin>>nele2;
    
    int row2[r],col2[n],ele2[nele2];
    cout<<"Enter the triplet representation (row, column, element) of second matrix: \n";
    
    for(int i=0;i<nele2;i++){
        cin>>row2[i]>>col2[i]>>ele2[i];
    }
    
    int row3[r],col3[n],ele3[nele1 + nele2];
    int nele3=0;
    
    for(int i=0;i<nele1;i++){
        row3[nele3]=row1[i];
        col3[nele3]=col1[i];
        ele3[nele3]=ele1[i];
        nele3++;
    }
    
    for(int i=0;i<nele2;i++){
        int flag=0;
        for(int j=0;j<nele3;j++){          
            if(row2[i]==row3[j] && col2[i]==col3[j]){
                ele3[j]+=ele2[i];
                flag=1;
                break;
            }
        }
        
        if(flag==0){
            row3[nele3]=row2[i];
            col3[nele3]=col2[i];
            ele3[nele3]=ele2[i];
            nele3++;
        }
    }
    
    cout<<"The resultant matrix is: \n";
    
    for(int i=0;i<r;i++){
        for(int j=0;j<n;j++){
            int flag=0;
            for(int k=0;k<nele3;k++){
                if(row3[k]==i + 1 && col3[k]==j + 1){
                    cout<<ele3[k]<<" ";
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}