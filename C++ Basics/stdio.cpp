//cin and cout are good if the number of inputs or outputs are small
// but if we have a million of i/p or o/p it's efficient to use
//scanf("%s\n", ); and printf("%s\n", ); functions
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a; long b; char c; float d; double e;
    scanf("%i %li %c %f %lf", &a, &b, &c, &d, &e);
    printf("%i \n%li \n%c \n%.3f \n%.9lf \n", a,b, c, d, e);
    return 0;
}
