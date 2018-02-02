//
//  bn_skew_frobenius.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/2/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bn_skew_frobenius_h
#define bn_skew_frobenius_h

#include "bn_precoms.h"
#include "bn_efp12.h"

extern void EFp_skew_frobenius_map_p2(EFp *ANS,EFp *A);
extern void EFp2_skew_frobenius_map_p1(EFp2 *ANS,EFp2 *A);
extern void EFp2_skew_frobenius_map_p2(EFp2 *ANS,EFp2 *A);
extern void EFp2_skew_frobenius_map_p3(EFp2 *ANS,EFp2 *A);
extern void EFp2_skew_frobenius_map_p10(EFp2 *ANS,EFp2 *A);

#endif /* bn_skew_frobenius_h */
