//
//  bn_settings.h
//
//  Created by Khandaker Md. Al-Amin on 1/25/18.
//  Copyright © 2018 Khandaker Md. Al-Amin. All rights reserved.
//

#ifndef bn_settings_h
#define bn_settings_h

#include "Commont_headers.h"

/*============================================================================*/
/* Macro definitions                                                          */
/*============================================================================*/

/**
 * @brief Defines TRUE or FALSE using integer
 *
 * The TRUE_1 defines true as int 1 when boolean decesion in true.
 * FALSE_0 defines the oppsite
 */
#define TRUE_1 1
#define FALSE_0 0
/**
 * @brief maximum degree of mother parameter X's polynomial
 *
 *
 */
#define X_length 114
//#define x_bit 114
#define x_bit_for_opt_ate 116


/*============================================================================*/
/* Data structure declarations                                                */
/*============================================================================*/

/**
 * @brief Structure to hold the BN curve settings.
 *
 * #bn_params hold the BN curves parametets.
 */
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

/**
 * @brief The qudratic non residue over prime filed Fp.
 *
 * X^2-c1 is irreducible over the Fp
 */
extern int c1;

/**
 * @brief Checks if all the parameters of BN curve is initialize.
 *
 */
extern int is_params_set;

extern int TRUE;
extern int FALSE;

/**
 * @brief Chracter arry of size [x_bit+1] that holds the singned binary representation of the mother parameter X.
 *
 * This x_signed_binary is important since it is used in the Miller's algorithm for efficeint calculation using the singned
 * binary representation of the mother parameter X.
 */
extern char x_signed_binary [X_length+1];
extern int X_binary[X_length+1];
extern int X_bit_binary_for_opt_ate[x_bit_for_opt_ate+1];
/*============================================================================*/
/* Function declarations                                                      */
/*============================================================================*/

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
