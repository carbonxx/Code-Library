#include<stdio.h>

int permutation(int n,int r){
    if(r==0)
        return 1;
    else
        return n*permutation(n,r-1);
}
int main(){
    int n,r;
    printf("Enter the number and permutation: ");
    scanf("%d%d",&n,&r);
    printf("%dP%d = %d",n,r,permutation(n,r));
    return 0;
}