//
//  bn_field_dtype.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 1/31/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bn_field_dtype_h
#define bn_field_dtype_h

#include "Commont_headers.h"


typedef struct Fp Fp;
struct Fp{
    mpz_t x0;
};

typedef struct Fp2 Fp2;
struct Fp2{
    struct Fp x0, x1;
};

typedef struct Fp6 Fp6;
struct Fp6{
    Fp2 x0,x1,x2;
};


typedef struct Fp12 Fp12;
struct Fp12{
    Fp6 x0,x1;
};


#endif /* bn_field_dtype_h */
