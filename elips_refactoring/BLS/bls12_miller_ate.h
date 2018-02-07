//
//  bls12_miller_ate.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/6/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bls12_miller_ate_h
#define bls12_miller_ate_h

#include "bls12_twist.h"
#include "bls12_p8sparse.h"
#include "bls12_line_ate.h"

//miller algo for plain ate
extern void BLS12_Miller_algo_for_plain_ate(Fp12 *ANS,EFp12 *Q,EFp12 *P);


#endif /* bls12_miller_ate_h */
