#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, f, i, j, count = 0;
    cin>>N;
    int mat[N][N];
    cout<<"Input the matrix:\n";
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Enter dimensions of the filter:\n";
    cin>>f;
    int filter[f][f];
    cout<<"Input the matrix:\n";
    for(i=0;i<f;i++){
        for(j=0;j<f;j++){
            cin>>filter[i][j];
        }
    }
    int featureMap[N-f+1][N-f+1];
    for(int convRow=0; convRow<N-f+1; convRow++){
        for(int convColumn=0; convColumn<N-f+1; convColumn++){
            int val = 0;
            for(i=0;i<f;i++){
                for(j=0;j<f;j++){
                    val = val + mat[convRow+i][convColumn+j]*filter[i][j];
                    count++;
                }
            }
        featureMap[convRow][convColumn] = val;
        }
   }
    cout<<"Output matrix:\n";
    for(i=0;i<N-f+1;i++){
        for(j=0;j<N-f+1;j++){
            cout<<featureMap[i][j]<<" ";
        }
    cout<<endl;
    }
    cout<<"Number of multiplication operations: "<<count<<endl;
}