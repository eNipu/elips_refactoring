//
//  bls12_generate_points.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/6/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bls12_generate_points_h
#define bls12_generate_points_h

#include "curve_settings.h"
#include "bls12_twist.h"
#include "bls12_frobenius.h"

extern void BLS12_generate_G1_point(EFp12 *P);
extern void BLS12_generate_G2_point(EFp12 *Q);
extern void BLS12_generate_random_point(EFp12 *R);

#endif /* bls12_generate_points_h */
