#include <stdio.h>

typedef struct {
    float x,y;
} Point;

Point add_points(Point a, Point b) {
    return(Point){a.x+b.x,a.y+b.y};
}

int main(void) {
    Point result=add_points(
            (Point){.x=10,.y=20},
            (Point){.x=5, .y=7}
            );
    printf("Point: (%1.f,%1.f)\n",result.x,result.y);
    return 0;
}

