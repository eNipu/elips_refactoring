//
//  bls12_p8sparse.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/5/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bls12_p8sparse.h"

void BLS12_Pseudo_8_sparse_mapping(EFp *P,EFp2 *Q,Fp *L){
    EFp2 Tmp_Q;
    EFp2_init(&Tmp_Q);
    EFp Tmp_P;
    EFp_init(&Tmp_P);
    Fp A,B,C,D,c;
    Fp_init(&A);
    Fp_init(&B);
    Fp_init(&C);
    Fp_init(&D);
    Fp_init(&c);
    
    EFp_set(&Tmp_P,P);
    EFp2_set(&Tmp_Q,Q);
    
    Fp_mul(&A,&Tmp_P.x,&Tmp_P.y);
    Fp_inv(&A,&A);
    Fp_mul(&B,&Tmp_P.x,&Tmp_P.x);
    Fp_mul(&B,&B,&A);
    Fp_mul(&C,&Tmp_P.y,&A);
    Fp_mul(&D,&B,&B);
    
    Fp2_mul_mpz(&Q->x,&Tmp_Q.x,D.x0);
    Fp_mul(&c,&B,&D);
    Fp2_mul_mpz(&Q->y,&Tmp_Q.y,c.x0);
    
    Fp_mul(&P->x,&D,&Tmp_P.x);
    Fp_set(&P->y,&P->x);
    
    Fp_mul(L,&C,&Tmp_P.y);
    Fp_mul(L,L,L);
    Fp_mul(L,L,&C);
    
    
    EFp2_clear(&Tmp_Q);
    EFp_clear(&Tmp_P);
    Fp_clear(&A);
    Fp_clear(&B);
    Fp_clear(&C);
    Fp_clear(&D);
    Fp_clear(&c);
}

void BLS12_Pseudo_8_sparse_mul(Fp12 *ANS,Fp12 *A,Fp12 *B){
    //A= f0 + f1γ^2 + f2γ^4 + f3γ　+ f4γ^3 + f5γ^5
    //B= 1  +                        aγ^3 +  bγ^5
    // x0.x0  x0.x1   x0.x2  x1.x0  x1.x1   x1.x2
    Fp12 ans;
    Fp12_init(&ans);
    Fp2 tmp0,tmp1,tmp2,tmp3;
    Fp2_init(&tmp0);
    Fp2_init(&tmp1);
    Fp2_init(&tmp2);
    Fp2_init(&tmp3);
    
    Fp2_mul(&tmp0,&A->x0.x0,&B->x1.x1);        //tmp0←a*f0
    Fp2_mul(&tmp1,&A->x0.x1,&B->x1.x2);        //tmp1←b*f1
    Fp2_add(&tmp2,&A->x0.x0,&A->x0.x1);        //tmp2←f0+f1
    Fp2_add(&tmp3,&B->x1.x1,&B->x1.x2);        //tmp3←a+b
    Fp2_mul(&tmp2,&tmp2,&tmp3);            //tmp2←tmp2*tmp3
    Fp2_sub(&tmp2,&tmp2,&tmp0);            //tmp2←tmp2-tmp0
    Fp2_sub(&tmp2,&tmp2,&tmp1);            //tmp2←tmp2-tmp1
    
    Fp2_add(&ans.x1.x2,&tmp2,&A->x1.x2);    //ans[γ^5]←tmp2+f5
    Fp2_add(&ans.x1.x1,&tmp0,&A->x1.x1);    //ans[γ^3]←tmp0+f4
    Fp2_mul(&tmp2,&A->x0.x2,&B->x1.x2);        //tmp2←b*f2
    Fp2_mul_basis(&tmp2,&tmp2);            //tmp2←tmp2*α
    Fp2_add(&ans.x1.x1,&ans.x1.x1,&tmp2);    //ans[γ^3]←ans[γ^3]+tmp2
    Fp2_mul(&tmp0,&A->x0.x2,&B->x1.x1);        //tmp0←a*f2
    Fp2_add(&tmp0,&tmp0,&tmp1);            //tmp0←tmp0+tmp1
    Fp2_mul_basis(&tmp0,&tmp0);            //tmp0←tmp0*α
    Fp2_add(&ans.x1.x0,&tmp0,&A->x1.x0);    //ans[γ]←tmp0+f3
    
    Fp2_mul(&tmp0,&A->x1.x0,&B->x1.x1);        //tmp0←a*f3
    Fp2_mul(&tmp1,&A->x1.x1,&B->x1.x2);        //tmp1←b*f4
    Fp2_add(&tmp2,&A->x1.x0,&A->x1.x1);        //tmp2←f3+f4
    Fp2_mul(&tmp2,&tmp2,&tmp3);            //tmp2←tmp2+tmp3
    Fp2_sub(&tmp2,&tmp2,&tmp0);            //tmp2←tmp2-tmp0
    Fp2_sub(&tmp2,&tmp2,&tmp1);            //tmp2←tmp2-tmp1
    
    Fp2_mul_basis(&tmp2,&tmp2);            //tmp2←tmp2*α
    Fp2_add(&ans.x0.x0,&tmp2,&A->x0.x0);    //ans[1]←tmp2+f0
    
    Fp2_mul(&tmp2,&A->x1.x2,&B->x1.x1);        //tmp2←a*f5
    Fp2_add(&tmp2,&tmp1,&tmp2);            //tmp2←tmp1+tmp2
    Fp2_mul_basis(&tmp2,&tmp2);            //tmp2←tmp2*α
    Fp2_add(&ans.x0.x1,&tmp2,&A->x0.x1);    //ans[γ^2]←tmp2+f1
    Fp2_mul(&tmp3,&A->x1.x2,&B->x1.x2);        //tmp3←b*f5
    Fp2_mul_basis(&tmp3,&tmp3);            //tmp3←tmp3*α
    
    Fp2_add(&tmp0,&tmp0,&tmp3);            //tmp0←tmp0+tmp3
    Fp2_add(&ans.x0.x2,&tmp0,&A->x0.x2);    //ans[γ^2]←tmp0+f2
    
    Fp12_set(ANS,&ans);
    
    Fp12_clear(&ans);
    Fp2_clear(&tmp0);
    Fp2_clear(&tmp1);
    Fp2_clear(&tmp2);
    Fp2_clear(&tmp3);
}

