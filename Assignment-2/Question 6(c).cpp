// multiplication of two sparse matrices using triplet representation

#include <iostream>
using namespace std;

int main(){

    int r1,c1,nele1;
    cout<<"Enter number of rows, columns and number of non zero elements of first matrix: ";
    cin>>r1>>c1>>nele1;
    int row1[r1],col1[c1],ele1[nele1];
    cout<<"Enter the triplet representation (row, column, element) of first matrix: \n";

    for(int i=0;i<nele1;i++){
        cin>>row1[i]>>col1[i]>>ele1[i];
    }
    
    int r2,c2,nele2;
    cout<<"Enter number of rows, columns and number of non zero elements of second matrix: ";
    cin>>r2>>c2>>nele2;
    
    if(c1!=r2){
        cout<<"Matrix multiplication not possible\n";
        return 0;
    }

    int row2[r2],col2[c2],ele2[nele2];
    cout<<"Enter the triplet representation (row, column, element) of second matrix: \n";
    for(int i=0;i<nele2;i++){
        cin>>row2[i]>>col2[i]>>ele2[i];
    }

    int row3[r1],col3[c2],ele3[r1*c2];
    int nele3=0;
    for(int i=0;i<nele1;i++){
        for(int j=0;j<nele2;j++){
            if(col1[i]==row2[j]){
                int r=row1[i];
                int c=col2[j];
                int e=ele1[i]*ele2[j];
                
                int flag=0;
                for(int k=0;k<nele3;k++){
                    if(row3[k]==r && col3[k]==c){
                        ele3[k]+=e;
                        flag=1;
                        break;
                    }
                }
                
                if(flag==0){
                    row3[nele3]=r;
                    col3[nele3]=c;
                    ele3[nele3]=e;
                    nele3++;
                }
            }
        }
    }

    cout<<"The resultant matrix is: \n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            int flag=0;
            for(int k=0;k<nele3;k++){
                if(row3[k]== i+1 && col3[k]== j+1){
                    cout<<ele3[k]<<" ";
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
    
    return 0;
}