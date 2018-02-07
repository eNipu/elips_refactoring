//
//  bls12_test_pairings.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/6/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bls12_test_pairings_h
#define bls12_test_pairings_h

#include "bls12_pairings.h"
#include "bls12_generate_points.h"
#include "bls12_timeprint.h"
#include "bls12_scm.h"
#include "bls12_G3_exp.h"

extern void BLS12_test_tate_pairing(void);
extern void BLS12_test_plain_ate_pairing(void);
extern void BLS12_test_opt_ate_pairing(void);
extern void BLS12_test_G1_scm(void);
extern void BLS12_test_G2_scm(void);
extern void BLS12_test_G3_exp(void);

#endif /* bls12_test_pairings_h */
