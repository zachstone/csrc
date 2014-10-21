#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define WIDTH  16
#define HEIGHT 16

float lerp(float start, float stop, float t);
void genValueNoise();

int grid[WIDTH][HEIGHT];

int main()
{
    srand(time(NULL));
    rand();
    
    genValueNoise();
    
    int i;
    for(i = 0; i < WIDTH; ++i) {
        int j;
        for(j = 0; j < HEIGHT; ++j) {
            printf("%d ", (int)(((grid[i][j] / (float)RAND_MAX) * 10)));
        }
        printf("\n");
    }
}
float lerp(float start, float stop, float t)
{
    //return (start + stop) / 2.0;
    return ((1 - t) * start) + (t * stop);
}

void genValueNoise()
{
    grid[0][0] = rand();
    grid[WIDTH - 1][0] = rand();
    grid[0][HEIGHT - 1] = rand();
    grid[WIDTH - 1][HEIGHT - 1] = rand();
    
    int i;
    for(i = 0; i < WIDTH; ++i) {
        grid[i][0] = (int)lerp((float)grid[0][0], (float)grid[WIDTH-1][0],  (float)i / WIDTH);
        grid[i][HEIGHT-1] = (int)lerp((float)grid[0][HEIGHT-1], 
                                      (float)grid[WIDTH-1][HEIGHT-1], 
                                      (float)i / HEIGHT);
    }
    for(i = 0; i < WIDTH; ++i) {
        int j;
        for(j = 0; j < HEIGHT; ++j) {
            grid[i][j] = (int)lerp((float)grid[i][0], (float)grid[i][HEIGHT-1],  (float)j / WIDTH);
        }
    }
}