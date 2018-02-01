//
//  bn_utils.h
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/1/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#ifndef bn_utils_h
#define bn_utils_h

#include <stdio.h>
#include <sys/time.h>

extern struct timeval t0,t1;

extern float MILLER_TATE,MILLER_PLAINATE,MILLER_OPTATE,MILLER_XATE;
extern float FINALEXP_PLAIN,FINALEXP_OPT;
extern float G1SCM_PLAIN,G1SCM_2SPLIT;
extern float G2SCM_PLAIN,G2SCM_2SPLIT,G2SCM_4SPLIT;
extern float G3SCM_PLAIN,G3SCM_2SPLIT,G3SCM_4SPLIT;

extern float timedifference_msec(struct timeval t0, struct timeval t1);
extern float timedifference_usec(struct timeval t0, struct timeval t1);

#endif /* bn_utils_h */
