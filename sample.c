#include <stdio.h>

main()
{
    int maxy, maxc, miny, minc, i, j;
    int zaiseki[3][8] = {
        {41,40,40,40,40,41,41,42},
        {39,38,34,40,37,39,35,39},
        {30,39,31,40,38,40,33,36}
    };
    maxy=0;
    maxc=0;
    miny=0;
    minc=0;

    for (i = 0; i < 3; i ++) {
        for (j = 0; j < 8; j ++) {
            if (zaiseki[maxy][maxc] < zaiseki[i][j]){
                maxy = i;
                maxc = j;
            } else if (zaiseki[miny][minc] >zaiseki[i][j]) {
                miny = i;
                minc = j;
            }
        }
    }

    printf("在籍人数が最も多いクラスは %d年 %d組で、在籍人数は %d人です。 \n", maxy + 1, maxc + 1, zaiseki[maxy][maxc]);
    printf("在籍人数が最も少ないクラスは %d年 %d組で、在籍人数は %d人です。 \n", miny + 1, minc + 1, zaiseki[miny][minc]);

    return(0);
}
