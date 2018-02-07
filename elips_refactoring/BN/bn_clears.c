//
//  bn_clears.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/1/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bn_clears.h"

int isCleared = 0;

void clear_parameters(){
    
    //    if (isCleared != 1){
    int i,j;
//    unsigned int base = 10;
    
    mpz_clear(curve_parameters.X);
    mpz_clear(curve_parameters.prime);
    mpz_clear(curve_parameters.order);
    mpz_clear(curve_parameters.trace_t);
    
    mpz_clear(curve_parameters.EFp_total);
    
//    printf(" has exact length %zu in base %d\n", strlen(mpz_get_str(NULL, base, curve_parameters.EFpd_total)), base);
//    printf("Size in base %d\n ",(int)mpz_sizeinbase(curve_parameters.EFpd_total,10));
//    i = (int)strlen(mpz_get_str(NULL, base, curve_parameters.EFpd_total));
//    if (i > 10) {
        mpz_clear(curve_parameters.EFpd_total);
//    }
//    printf("Size in base after %d\n ",(int)mpz_sizeinbase(curve_parameters.EFpd_total,2));
    mpz_clear(curve_parameters.curve_b);
    
    Fp_clear(&Fp_basis);
    Fp2_clear(&Fp2_basis);
    Fp6_clear(&Fp6_basis);
    mpz_clear(epsilon1);
    mpz_clear(epsilon2);
    
    for(i=0; i<d12; i++){
        for(j=0; j<6; j++){
            Fp2_clear(&d12_frobenius_constant[i][j]);
        }
        for(j=0; j<2; j++){
            Fp2_clear(&d12_skew_frobenius_constant[i][j]);
        }
    }
    //    }
    //    isCleared = 1;
}
