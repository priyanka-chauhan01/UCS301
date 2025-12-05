// representation of transpose of a sparse matrix throught triplets (arrays)

#include<iostream>
using namespace std;

int main(){

    int r,n,nele;
    cout<<"Enter number of rows, columns and number of non zero elements: ";
    cin>>r>>n>>nele;
    int row[r],col[n],ele[nele];
    cout<<"Enter the triplet representation (row, column, element): \n";
    for(int i=0;i<nele;i++){
        cin>>row[i]>>col[i]>>ele[i];
    }
    cout<<"The matrix is: \n";
    for(int i=0;i<r;i++){
        for(int j=0;j<n;j++){
            int flag=0;
            for(int k=0;k<nele;k++){
                if(row[k]==i + 1 && col[k]==j + 1){
                    cout<<ele[k]<<" ";
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

    cout<<"The transpose of the matrix is: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            int flag=0;
            for(int k=0;k<nele;k++){
                if(col[k]==i + 1 && row[k]==j + 1){
                    cout<<ele[k]<<" ";
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