//
//  bn_clears.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/1/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bn_clears.h"

void clear_bn(){
    int i,j;
    
    mpz_clear(bn_parameters.X);
    mpz_clear(bn_parameters.prime);
    mpz_clear(bn_parameters.order);
    mpz_clear(bn_parameters.trace_t);
    
    mpz_clear(bn_parameters.EFp_total);
    mpz_clear(bn_parameters.EFpd_total);
    mpz_clear(bn_curve_coefficient.curve_b);
    
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
}
