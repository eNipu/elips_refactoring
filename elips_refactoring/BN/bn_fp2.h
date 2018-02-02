//
//  bn_fp2.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 1/29/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bn_fp2_h
#define bn_fp2_h

#include "bn_field_dtype.h"
#include "bn_fp.h"
#include "bn_precoms.h"

//Fp2

extern void Fp2_init(Fp2 *A);
extern void Fp2_clear(Fp2 *A);
extern void Fp2_printf(Fp2 *A,char *str);
extern void Fp2_set(Fp2 *ANS,Fp2 *A);
extern void Fp2_set_ui(Fp2 *ANS,unsigned long int UI);
extern void Fp2_set_mpz(Fp2 *ANS,mpz_t A);
extern void Fp2_set_neg(Fp2 *ANS,Fp2 *A);
extern void Fp2_set_random(Fp2 *ANS,gmp_randstate_t state);
extern void Fp2_mul(Fp2 *ANS,Fp2 *A,Fp2 *B);
extern void Fp2_mul_ui(Fp2 *ANS,Fp2 *A,unsigned long int UI);
extern void Fp2_mul_mpz(Fp2 *ANS,Fp2 *A,mpz_t B);
extern void Fp2_mul_basis(Fp2 *ANS,Fp2 *A);
extern void Fp2_inv_basis(Fp2 *ANS,Fp2 *A);
extern void Fp2_sqr(Fp2 *ANS,Fp2 *A);
extern void Fp2_add(Fp2 *ANS,Fp2 *A,Fp2 *B);
extern void Fp2_add_ui(Fp2 *ANS,Fp2 *A,unsigned long int UI);
extern void Fp2_add_mpz(Fp2 *ANS,Fp2 *A,mpz_t B);
extern void Fp2_sub(Fp2 *ANS,Fp2 *A,Fp2 *B);
extern void Fp2_sub_ui(Fp2 *ANS,Fp2 *A,unsigned long int UI);
extern void Fp2_sub_mpz(Fp2 *ANS,Fp2 *A,mpz_t B);
extern void Fp2_inv(Fp2 *ANS,Fp2 *A);
extern int  Fp2_legendre(Fp2 *A);
extern int  Fp2_isCNR(Fp2 *A);
extern void Fp2_sqrt(Fp2 *ANS,Fp2 *A);
extern void Fp2_pow(Fp2 *ANS,Fp2 *A,mpz_t scalar);
extern int  Fp2_cmp(Fp2 *A,Fp2 *B);
extern int  Fp2_cmp_ui(Fp2 *A,unsigned long int UI);
extern int  Fp2_cmp_mpz(Fp2 *A,mpz_t B);
extern int  Fp2_cmp_zero(Fp2 *A);
extern int  Fp2_cmp_one(Fp2 *A);

#endif /* bn_fp2_h */
