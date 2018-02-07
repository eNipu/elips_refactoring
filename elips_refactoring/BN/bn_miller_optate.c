//
//  bn_miller_optate.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/2/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bn_miller_optate.h"

void Miller_algo_for_opt_ate(Fp12 *ANS,EFp12 *P,EFp12 *Q){
    EFp2 T;
    EFp2_init(&T);
    EFp2 mapped_Q,mapped_Q_neg,mapped_Q1,mapped_Q2_neg;
    EFp2_init(&mapped_Q);
    EFp2_init(&mapped_Q_neg);
    EFp2_init(&mapped_Q1);
    EFp2_init(&mapped_Q2_neg);
    EFp mapped_P;
    EFp_init(&mapped_P);
    Fp12 f;
    Fp12_init(&f);
    Fp L;
    Fp_init(&L);
    int i;
    
    //set
    Fp_set(&mapped_P.x,&P->x.x0.x0.x0);    //set P
    Fp_set(&mapped_P.y,&P->y.x0.x0.x0);
    mapped_P.infinity=P->infinity;
    EFp12_to_EFp2(&mapped_Q,Q);//set mapped_Q
    mapped_Q.infinity=Q->infinity;
    
    Pseudo_8_sparse_mapping(&mapped_P,&mapped_Q,&L);
    
    EFp2_set(&mapped_Q_neg,&mapped_Q);//set mapped_Q_neg
    Fp2_set_neg(&mapped_Q_neg.y,&mapped_Q_neg.y);
    EFp2_set(&T,&mapped_Q);        //set T
    Fp12_set_ui(&f,0);            //set f
    Fp_set_ui(&f.x0.x0.x0,1);
    //miller
    for(i=BN_X_length+1; i>=0; i--){
        switch(X_binary_opt[i]){
            case 0:
                ff_ltt(&f,&T,&mapped_P,&L);
                break;
            case 1:
                ff_ltt(&f,&T,&mapped_P,&L);
                f_ltq(&f,&T,&mapped_Q,&mapped_P,&L);
                break;
            case -1:
                ff_ltt(&f,&T,&mapped_P,&L);
                f_ltq(&f,&T,&mapped_Q_neg,&mapped_P,&L);
                break;
            default:
                break;
        }
        
    }
    
    EFp2_skew_frobenius_map_p1(&mapped_Q1,&mapped_Q);//Q^p
    EFp2_skew_frobenius_map_p2(&mapped_Q2_neg,&mapped_Q);//Q^(p^2)
    EFp2_set_neg(&mapped_Q2_neg,&mapped_Q2_neg);
    f_ltq(&f,&T,&mapped_Q1,&mapped_P,&L);
    f_ltq(&f,&T,&mapped_Q2_neg,&mapped_P,&L);
    
    Fp12_set(ANS,&f);
    
    Fp12_clear(&f);
    EFp2_clear(&T);
    EFp2_clear(&mapped_Q);
    EFp2_clear(&mapped_Q_neg);
    EFp2_clear(&mapped_Q1);
    EFp2_clear(&mapped_Q2_neg);
    EFp_clear(&mapped_P);
    Fp_clear(&L);
}
