//
//  bls12_settings.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/2/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bls12_settings_h
#define bls12_settings_h

#include "Commont_headers.h"


struct bls12_params {
    mpz_t prime;
    mpz_t X;
    int sign;
    mpz_t trace_t;
    mpz_t order;
    mpz_t EFp_total;
    mpz_t EFp2_total;
    mpz_t EFp6_total;
    mpz_t EFp12_total;
    mpz_t EFpd_total;
    mpz_t curve_b;
    //    mpz_t curve_parameter_B;
};
/**
 * @brief bls12 curve's systematically obtained parameters.
 *
 * It's a global variable that give access to bls12 public parameters.
 */
extern struct bls12_params  bls12_parameters;

//struct  bls12_coefficient{
//    mpz_t curve_b;        /**< Temoporary variable for constant a*/
//};


//BLS12
extern int BLS12_X_length;
extern mpz_t BLS12_X;
extern int BLS12_X_binary[78];

//init
extern void BLS12_init_settings(void);
extern void BLS12_init_parameters( void);
extern void BLS12_generate_X(void);
extern int  BLS12_generate_prime(void);
extern int  BLS12_generate_order(void);
extern void BLS12_generate_trace(void);
extern void BLS12_set_curve_parameter(void);
extern void BLS12_weil(void);
extern void BLS12_print_parameters(void);

#endif /* bls12_settings_h */
