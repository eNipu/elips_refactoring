//
//  bn_prints.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/1/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bn_prints_h
#define bn_prints_h

#include "bn_generate_points.h"

//rational points
extern void BN12_generate_G1_point(EFp12 *P);
extern void BN12_generate_G2_point(EFp12 *Q);
extern void BN12_generate_random_point(EFp12 *R);
#endif /* bn_prints_h */
