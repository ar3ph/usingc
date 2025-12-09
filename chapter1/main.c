#include "allheads.h"
int main() {
    printf("%g\n", erf(1.96*sqrt(1/2.)));
    
    double bottom_tail = gsl_cdf_gaussian_P(-1.96, 1);

    printf("%g\n", 1-2*bottom_tail);

    
    char *repstext = getenv("reps");
    int reps = repstext ? atoi(repstext) : 10;
    
    char *msg = getenv("msg");
    if (!msg) msg = "hello";
    for (int i = 0; i<reps; ++i) {
        printf("%s\n", msg);
    }
    
}