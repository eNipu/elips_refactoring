//
//  bn_settings.c
//  BN_Single_File_Elips
//
//  Created by Khandaker Md. Al-Amin on 1/25/18.
//  Copyright © 2018 Khandaker Md. Al-Amin. All rights reserved.
//

#include "bn_settings.h"


struct bn_params bn_parameters;
struct bn_coefficient bn_curve_coefficient;
int X_binary[X_length+1];
int X_binary_opt[X_length+3];
//---------------------------------------------------------------------

void BN12_init(){
    init_parameters();
}

/*============================================================================*/
/*  init                                                                      */
/*============================================================================*/
void init_parameters(){
    //parameters
    mpz_init(bn_parameters.prime);
    mpz_init(bn_parameters.X);
    mpz_init(bn_parameters.trace_t);
    mpz_init(bn_parameters.order);
    mpz_init(bn_parameters.EFp_total);
    mpz_init(bn_parameters.EFp2_total);
    mpz_init(bn_parameters.EFp6_total);
    mpz_init(bn_parameters.EFp12_total);
    mpz_init(bn_curve_coefficient.curve_a);
    mpz_init(bn_curve_coefficient.curve_b);
    
    int i;
    for(i=0; i<X_length+1; i++){
        X_binary[i]=0;
    }
    for(i=0; i<X_length+3; i++){
        X_binary_opt[i]=0;
    }
}

//---------------------------------------------------------------------

