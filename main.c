#include <stdio.h>
//print edges of a tree
void prufers_tree(int prufer[],int m)
{
    int vertices = m + 2;
    int degree[vertices];

    //initialize the arraz of vertices

    for(int i =0; i < vertices; i++)
        degree[i] = 0;

    //number of occurences of vertex in prufer sequence
    for(int i =0;i < vertices-2;i++)
        degree[prufer[i]-1] += 1;
    printf("\nThe edge set E(Graph) is: \n");
    //Find the smallest label not present in prufer
    int k = 0;
    for(int i = 0;i < vertices - 2;i++){
        for(k = 0;k < vertices;k++){
            //remove from prufers sequence
            if(degree[k] == 0){
                degree[k] = -1;
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
            printf("(%d, ",i+1);
            k++;
        }
        else if(degree[i] == 0 && k == 1)
            printf("%d)\n",i+1);

    }
}
int main() {
    int prufer []={ 4, 1, 3 ,4 };
    int n = sizeof(prufer)/sizeof(prufer[0]);
    prufers_tree(prufer,n);
    return 0;
}


