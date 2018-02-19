//
//  curve_dtypes.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/1/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef curve_dtypes_h
#define curve_dtypes_h

#include "bn_fp12.h"
#include "field_dtype.h"

typedef struct EFp EFp;
struct EFp{
    Fp x,y;
    int infinity;
};

typedef struct EFp2 EFp2;
struct EFp2{
    Fp2 x,y;
    int infinity;
};

typedef struct EFp6 EFp6;
struct EFp6{
    Fp6 x,y;
    int infinity;
};

typedef struct EFp12 EFp12;
struct EFp12{
    Fp12 x,y;
    int infinity;
};

#endif /* curve_dtypes_h */
