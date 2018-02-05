//
//  bls12_finalexp.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/5/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bls12_finalexp.h"

void BLS12_Fp12_pow_X(Fp12 *ANS,Fp12 *A);

void BLS12_Final_exp_plain(Fp12 *ANS,Fp12 *A){
    Fp12 Tmp,Buf1,Buf2;
    Fp12_init(&Tmp);
    Fp12_set(&Tmp,A);
    Fp12_init(&Buf1);
    Fp12_init(&Buf2);
    mpz_t exp,buf;
    mpz_init(exp);
    mpz_init(buf);
    
    BLS12_Fp12_frobenius_map_p6(&Buf1,&Tmp);
    Fp12_inv(&Buf2,&Tmp);
    Fp12_mul(&Tmp,&Buf1,&Buf2);
    
    BLS12_Fp12_frobenius_map_p2(&Buf1,&Tmp);
    Fp12_mul(&Tmp,&Buf1,&Tmp);
    
    mpz_pow_ui(exp,bls12_parameters.prime,4);
    mpz_pow_ui(buf,bls12_parameters.prime,2);
    mpz_sub(exp,exp,buf);
    mpz_add_ui(exp,exp,1);
    mpz_tdiv_q(exp,exp,bls12_parameters.order);
    Fp12_pow(ANS,&Tmp,exp);
    
    
    mpz_clear(exp);
    mpz_clear(buf);
    Fp12_clear(&Tmp);
    Fp12_clear(&Buf1);
    Fp12_clear(&Buf2);
}

void BLS12_Final_exp_optimal(Fp12 *ANS,Fp12 *A){
    Fp12 t0,t1,t2,t3,t4,t5;
    Fp12_init(&t0);
    Fp12_init(&t1);
    Fp12_init(&t2);
    Fp12_init(&t3);
    Fp12_init(&t5);
    Fp12_init(&t4);
    
    //-------------------------------------------------------//
    //f←f^(p^6)*f^-1
    BLS12_Fp12_frobenius_map_p6(&t0,A);//f^(p^6)
    Fp12_inv(&t1,A);//f^-1
    Fp12_mul(A,&t0,&t1);//f^(p^6)*f^-1
    
    //f←f^(p^2)*f
    BLS12_Fp12_frobenius_map_p2(&t0,A);//f^(p^2)
    Fp12_mul(A,&t0,A);//f^(p^2)*f
    
    //-------------------------------------------------------//
    //f←f^(p^4-p2+1/r)
    Fp12_sqr(&t0,A);
    BLS12_Fp12_pow_X(&t1,&t0);
    
    BLS12_X_length=BLS12_X_length-1;
    BLS12_X_binary[77]=0;
    BLS12_X_binary[50]=0;
    BLS12_X_binary[33]=0;
    BLS12_X_binary[76]=-1;
    BLS12_X_binary[49]=1;
    BLS12_X_binary[32]=1;
    BLS12_Fp12_pow_X(&t2,&t1);      //t2:=t1^(u2);
    BLS12_X_length=BLS12_X_length+1;
    BLS12_X_binary[77]=-1;
    BLS12_X_binary[50]=1;
    BLS12_X_binary[33]=1;
    BLS12_X_binary[76]=0;
    BLS12_X_binary[49]=0;
    BLS12_X_binary[32]=0;
    
    BLS12_Fp12_frobenius_map_p6(&t3,A);            //t3:=f^(-1);
    Fp12_mul(&t1,&t3,&t1);            //t1:=t3*t1;
    BLS12_Fp12_frobenius_map_p6(&t1,&t1);        //t1:=t1^(-1);
    Fp12_mul(&t1,&t1,&t2);            //t1:=t1*t2;
    
    BLS12_Fp12_pow_X(&t2,&t1);          //t2:=t1^(u);
    BLS12_Fp12_pow_X(&t3,&t2);          //t3:=t2^(u);
    BLS12_Fp12_frobenius_map_p6(&t1,&t1);        //t1:=t1^(-1);
    
    Fp12_mul(&t3,&t1,&t3);            //t3:=t1*t3;
    BLS12_Fp12_frobenius_map_p6(&t1,&t1);        //t1:=t1^(-1);
    BLS12_Fp12_frobenius_map_p3(&t1,&t1);        //t1:=t1^(p^3);
    BLS12_Fp12_frobenius_map_p2(&t2,&t2);        //t2:=t2^(p^2);
    
    
    Fp12_mul(&t1,&t1,&t2);            //t1:=t1*t2;
    BLS12_Fp12_pow_X(&t2,&t3);      //t2:=t3^(u);
    Fp12_mul(&t2,&t2,&t0);            //t2:=t2*t0;
    Fp12_mul(&t2,&t2,A);            //t2:=t2*f;
    Fp12_mul(&t1,&t1,&t2);            //t1:=t1*t2;
    
    BLS12_Fp12_frobenius_map_p1(&t2,&t3);        //t2:=t3^p;
    Fp12_mul(ANS,&t1,&t2);            //t1:=t1*t2;
    
    
    Fp12_clear(&t0);
    Fp12_clear(&t1);
    Fp12_clear(&t2);
    Fp12_clear(&t3);
    //mpz_clear(positive_X);
    //mpz_clear(positive_X2);
}

void BLS12_Fp12_pow_X(Fp12 *ANS,Fp12 *A){
    int i;
    Fp12 tmp,A_inv;
    Fp12_init(&tmp);
    Fp12_init(&A_inv);
    BLS12_Fp12_frobenius_map_p6(&A_inv,A);
    
    Fp12_set(&tmp,&A_inv);
    for(i=BLS12_X_length-1; i>=0; i--){
        switch(BLS12_X_binary[i]){
            case 0:
                Fp12_sqr(&tmp,&tmp);
                break;
            case 1:
                Fp12_sqr(&tmp,&tmp);
                Fp12_mul(&tmp,&tmp,A);
                break;
            case -1:
                Fp12_sqr(&tmp,&tmp);
                Fp12_mul(&tmp,&tmp,&A_inv);
                break;
            default:
                break;
        }
    }
    Fp12_set(ANS,&tmp);
    
    Fp12_clear(&tmp);
    Fp12_clear(&A_inv);
}
