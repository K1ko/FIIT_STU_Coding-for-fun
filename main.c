#include <stdio.h>
#include <math.h>
//print edges of a tree
void prufers_tree(int prufer[],int m)
{
    int vertices = m + 2;
    int degree[vertices];

    //initialize the arraz of vertices

    for(int i =0; i < vertices; i++)
    {
        degree[i] = 1;
    }

    //number of occurences of vertex in prufer sequence
    for(int i =0;i < vertices-2;i++)
        degree[prufer[i]-1]++;
    printf("\nThe edge set E(Graph) is: \n");

    int k = 0;
    for(int i = 0;i < vertices -2;i++){
        for(k = 0;k < vertices;k++){
            if(degree[k] == 1){
                degree[k]--;
                printf("(%d,%d) ",k+1,prufer[i]);
                degree[prufer[i]-1]--;
                break;
            }
        }
    }
    k = 0;
    for(int i =0; i < vertices;i++)
    {
        if(degree[i]== 0 && k == 0)
        {
            printf("(%d,%d) ",i+1,k+1);
            k++;
        }
        else if(degree[i] == 0 && k == 1)
            printf("(%d,%d) ",i+1,k+1);

    }
}
int main() {
    int prufer[]={ 4, 1, 3 ,4 };
    int m = sizeof(prufer)/sizeof(prufer[0]);
    prufers_tree(prufer,m);






    return 0;
}


