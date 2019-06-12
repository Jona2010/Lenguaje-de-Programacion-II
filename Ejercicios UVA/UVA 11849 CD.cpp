#include <set>
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    set <int> cd_jk;
    int N; int M; int X;
    while(cin>>N && N!=0 && cin>>M && M!=0){
        for(int i=0;i<N+M;i++){
            cin>>X;
            cd_jk.insert(X);
        }
        printf("\n%i ",(N+M)-cd_jk.size());
        printf("\n");
    }
    return 0;
}
