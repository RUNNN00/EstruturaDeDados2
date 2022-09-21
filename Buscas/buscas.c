#include "buscas.h"

int buscaBin(int *v, int l, int r, int e) {

    if (l <= r) {
        int m = (l+r)/2;
        if (e == v[m])
            return m;
        if (e < v[m])
            return buscaBin(v, l, m-1, e);
        return buscaBin(v, m+1, r, e);
    }
    return -1;
}