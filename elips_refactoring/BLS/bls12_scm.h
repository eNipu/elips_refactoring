//
//  bls12_scm.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/6/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bls12_scm_h
#define bls12_scm_h

#include "bn_efp12.h"
#include "bn_utils.h"
#include "bls12_timeprint.h"
#include "bls12_twist.h"
#include "bls12_skew_frobenius.h"
#include "bls12_settings.h"



//G1
extern void BLS12_plain_G1_scm(EFp12 *ANS,EFp12 *P,mpz_t scalar);
extern void BLS12_2split_G1_scm(EFp12 *ANS,EFp12 *P,mpz_t scalar);
//G2
extern void BLS12_plain_G2_scm(EFp12 *ANS,EFp12 *Q,mpz_t scalar);
extern void BLS12_2split_G2_scm(EFp12 *ANS,EFp12 *Q,mpz_t scalar);
extern void BLS12_4split_G2_scm(EFp12 *ANS,EFp12 *Q,mpz_t scalar);

#endif /* bls12_scm_h */
