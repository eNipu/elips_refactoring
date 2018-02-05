//
//  bn_settings.h
//
//  Created by Khandaker Md. Al-Amin on 1/25/18.
//  Copyright © 2018 Khandaker Md. Al-Amin. All rights reserved.
//

#ifndef bn_settings_h
#define bn_settings_h

#include "Commont_headers.h"
#include "bn_fp.h"
#include "bn_fp2.h"

extern int isCleared; // 1 is cleared. 0 is not cleared

struct bn_params {
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
//    mpz_t curve_parameter_A;
//    mpz_t curve_parameter_B;
};
/**
 * @brief BN curve's systematically obtained parameters.
 *
 * It's a global variable that give access to BN public parameters.
 */
extern struct bn_params bn_parameters;

/**
 * @brief BN curve's constant values.
 *
 * BN curve y^2 = x^3+ a * x has one constant value a. But at first we need to get the value of a by putting
 * arbitary values of x.
 */
struct bn_coefficient{
    mpz_t curve_a;            /**< Constant a in BN pairing-friedly elliptic curve y^2 = x^3+ a * x BN curve*/
    mpz_t curve_b;        /**< Temoporary variable for constant a*/
};

/**
 * @brief BN curve's constants.
 *
 * It's a global variable that give access to BN constant term a.
 */
extern struct bn_coefficient bn_curve_coefficient;


#define X_length 114

extern gmp_randstate_t state;

extern int X_binary[X_length+1];
extern int X_binary_opt[X_length+3];



//init
extern void init_settings(void);
extern void init_parameters( void);
extern void generate_X(void);
extern int  generate_prime(void);
extern int  generate_order(void);
extern void generate_trace(void);
extern void set_curve_parameter(void);
extern void weil(void);
extern void bn_print_parameters(void);



#endif /* bn_settings_h */
