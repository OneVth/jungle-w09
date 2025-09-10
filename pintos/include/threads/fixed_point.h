#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

typedef int fp_t;
#define FP_F (1 << 14)  /* 17.14 format */

static inline fp_t to_fp(int n)
{
    return n * FP_F;
}

/* toward zero (truncate) */
static inline int to_int_zero(fp_t x)
{
    return x / FP_F;
}

/* round to nearest */
static inline int to_int_nearest(fp_t x)
{
    return x >= 0 ? (x + FP_F / 2) / FP_F : (x - FP_F / 2) / FP_F;
}

static inline fp_t add_fp_fp(fp_t x, fp_t y)
{
    return x + y;
} 

static inline fp_t add_fp_int(fp_t x, int n)
{
    return (fp_t)(x + n * FP_F);
}

static inline fp_t sub_fp_fp(fp_t x, fp_t y)
{
    return x - y;
}

static inline fp_t sub_fp_int(fp_t x, int n)
{
    return (fp_t)(x - n * FP_F);
}

static inline fp_t sub_int_fp(int n, fp_t x)
{
    return (fp_t)(n * FP_F - x);
}

static inline fp_t mul_fp_fp(fp_t x, fp_t y)
{
    return (fp_t)((int64_t)x * y / FP_F);
}

static inline fp_t mul_fp_int(fp_t x, int n)
{
    return (fp_t)(x * n);
}

static inline fp_t div_fp_fp(fp_t x, fp_t y)
{
    ASSERT(y != 0);
    return (fp_t)((int64_t)x * FP_F / y);
}

static inline fp_t div_fp_int(fp_t x, int n)
{
    ASSERT(n != 0);
    return (fp_t)(x / n);
}

#endif  /* THREADS_FIXED_POINT_H */