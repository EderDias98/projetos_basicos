#include <stdio.h>


int main( int argc, char* argv[]){

    int N;
    scanf("%d%*c", &N);
    int l =1;
    int num = 0;
    while( l<=N){
        
        for(int i=0; i<l;i++){
            num++;
            printf("%d ", num);
        }
        printf("\n");

        l++;
    }

    return 0;
}