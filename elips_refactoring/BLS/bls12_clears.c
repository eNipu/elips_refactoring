//
//  bls12_clears.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/5/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bls12_clears.h"


void clear_bls12(){
    
    mpz_clear(bls12_parameters.X);
    mpz_clear(bls12_parameters.prime);
    mpz_clear(bls12_parameters.order);
    mpz_clear(bls12_parameters.trace_t);
    
    mpz_clear(bls12_parameters.EFp_total);
    mpz_clear(bls12_parameters.EFpd_total);
    mpz_clear(bls12_parameters.curve_b);
    
//    int s = (int)mpz_size(Fp_basis.x0);
//    printf("Size %d\n",s);
    if (isCleared != 1){
        Fp_clear(&Fp_basis);
        Fp2_clear(&Fp2_basis);
        Fp6_clear(&Fp6_basis);
        mpz_clear(epsilon1);
        mpz_clear(epsilon2);
        
        int i,j;
        for(i=0; i<d12; i++){
            for(j=0; j<6; j++){
                Fp2_clear(&d12_frobenius_constant[i][j]);
            }
            for(j=0; j<2; j++){
                Fp2_clear(&d12_skew_frobenius_constant[i][j]);
            }
        }
        isCleared = 1;
    }
}
