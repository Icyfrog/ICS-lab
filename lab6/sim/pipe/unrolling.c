#include <stdio.h>

typedef word_t word_t;

word_t src[8], dst[8];

/* $begin ncopy */
/*
 * ncopy - copy src to dst, returning number of positive ints
 * contained in src array.
 */

word_t ncopy(word_t *src, word_t *dst, word_t len)
{
    word_t count = 0;
    word_t val;
    word_t val2;
    word_t val3;

    while (len > 2) {
	val = *src;
    src++;
    val2 = *src;
    src++;
    val3 = *src;
    src++;
    *dst = val;
    dst++;
    *dst = val2;
    dst++;
    *dst = val3;
    dst++;
    if (val > 0)
	    count++;
    if (val2 > 0)
        count++;
    if (val3 > 0)
        count++;
    len = len - 3;
    }
    for (; len > 0;len--)
    {
    	val = *src++;
	    *dst++ = val;
	    if (val > 0)
	    count++;
    }
        return count;
}
/* $end ncopy */

int main()
{
    word_t i, count;

    for (i=0; i<8; i++)
	src[i]= i+1;
    count = ncopy(src, dst, 8);
    printf ("count=%d\n", count);
    exit(0);
}


