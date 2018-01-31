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

#define d12 12
#define d24 24
#define X_length 114

enum state{
    f_p1,f_p2,f_p3,f_p4,f_p5,f_p6,f_p7,f_p8,f_p9,f_p10,f_p11,f_p12
};

extern gmp_randstate_t state;


extern int X_binary[X_length+1];
extern int X_binary_opt[X_length+3];

extern struct Fp Fp_basis;
extern struct Fp2 Fp2_basis;
extern struct Fp2 Fp2_basis_inv;
extern struct Fp6 Fp6_basis;

extern mpz_t epsilon1,epsilon2;

//extern struct Fp2 d12_frobenius_constant[d12][6];
//extern struct Fp2 d12_skew_frobenius_constant[d12][2];


//init
extern void init_parameters( void);
extern void generate_X(void);
extern int  generate_prime(void);
extern int  generate_order(void);
extern void generate_trace(void);
extern void get_epsilon(void);
extern void set_curve_parameter(void);
extern void set_basis(void);
extern void set_frobenius_constant(void);
extern void weil(void);




#endif /* bn_settings_h */
