#include <stdio.h>

int main() {
    int n=20;
    int a[21][21];
    for(int i=1;i<=20;++i) {
        for(int j=1;j<=20;++j) {
            scanf("%d",&a[i][j]);
        }
    }
    long res=0;
    for(int i=1;i<=17;++i){
        for(int j=1;j<=17;++j){
            long pre=a[i][j];
            pre*=(a[i+1][j+1])*(a[i+2][j+2]);
            pre*=(a[i+3][j+3]);
            res =  pre>res ? pre : res;
        }
    }
    printf("%ld",res);
    return 0;
}
