//
//  bn_fp.h
//  BN_Single_File_Elips
//
//  Created by Khandaker Md. Al-Amin on 1/25/18.
//  Copyright © 2018 Khandaker Md. Al-Amin. All rights reserved.
//

#ifndef bn_fp_h
#define bn_fp_h

#include "curve_settings.h"
#include "field_dtype.h"

//Fp

extern void Fp_init(Fp *A);
extern void Fp_clear(Fp *A);
extern void Fp_printf(Fp *A,char *str);
extern void Fp_set(Fp *ANS,Fp *A);
extern void Fp_set_ui(Fp *ANS,unsigned long int UI);
extern void Fp_set_mpz(Fp *ANS,mpz_t B);
extern void Fp_set_neg(Fp *ANS,Fp *A);
extern void Fp_set_random(Fp *ANS,gmp_randstate_t state);
extern void Fp_mul(Fp *ANS,Fp *A,Fp *B);
extern void Fp_mul_ui(Fp *ANS,Fp *A,unsigned long int UI);
extern void Fp_mul_mpz(Fp *ANS,Fp *A,mpz_t B);
extern void Fp_mul_basis(Fp *ANS,Fp *A);
extern void Fp_mul_basis_KSS16(Fp *ANS,Fp *A);
extern void Fp_add(Fp *ANS,Fp *A,Fp *B);
extern void Fp_add_ui(Fp *ANS,Fp *A,unsigned long int UI);
extern void Fp_add_mpz(Fp *ANS,Fp *A,mpz_t B);
extern void Fp_sub(Fp *ANS,Fp *A,Fp *B);
extern void Fp_sub_ui(Fp *ANS,Fp *A,unsigned long int UI);
extern void Fp_sub_mpz(Fp *ANS,Fp *A,mpz_t B);
extern void Fp_inv(Fp *ANS,Fp *A);
extern int  Fp_legendre(Fp *A);
extern int  Fp_isCNR(Fp *A);
extern void Fp_sqrt(Fp *ANS,Fp *A);
extern void Fp_pow(Fp *ANS,Fp *A,mpz_t scalar);
extern int  Fp_cmp(Fp *A,Fp *B);
extern int  Fp_cmp_ui(Fp *A,unsigned long int UI);
extern int  Fp_cmp_mpz(Fp *A,mpz_t B);
extern int  Fp_cmp_zero(Fp *A);
extern int  Fp_cmp_one(Fp *A);

// #pragma mark Fp methods

void Fp_sqr(struct Fp *ANS,struct Fp *A);
void Fp_mul(struct Fp *ans,struct Fp *a,struct Fp *b);//ans=a*b mod p
void Fp_mul_mpz(struct Fp *ans,struct Fp *a,mpz_t b);
void Fp_mul_ui(struct Fp *ans,struct Fp *a,unsigned long int b);//ans=a*b mod p
void Fp_mul_basis(struct Fp *ans,struct Fp *a);
void Fp_div(struct Fp *ans,struct Fp *a,struct Fp *b);//ans=a/b mod p
void Fp_pow(struct Fp *ans,struct Fp *a,mpz_t b);
void Fp_sqrt(struct Fp *ans,struct Fp *a);//x^2=a mod p
int  Fp_cmp_mpz(struct Fp *A,mpz_t B);
void Fp_mul_mpz(struct Fp *ANS,struct Fp *A,mpz_t B);
void Fp_neg(struct Fp *ANS,struct Fp *A);
int  Fp_cmp(struct Fp *A,struct Fp *B);
int  Fp_cmp_mpz(struct Fp *A,mpz_t B);
//--------------------------------------------

#endif /* bn_fp_h */
