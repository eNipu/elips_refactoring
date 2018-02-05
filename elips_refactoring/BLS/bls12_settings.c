//
//  bls12_settings.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 2/2/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bls12_settings.h"

struct bls12_params  bls12_parameters;
 int BLS12_X_length;
 mpz_t BLS12_X;
 int BLS12_X_binary[78];

void BLS12_init_settings(){
    BLS12_init_parameters();
    
    BLS12_generate_X();
    BLS12_generate_prime();
    BLS12_generate_order();
    BLS12_generate_trace();
    
    BLS12_weil();
//    BLS12_get_epsilon();
//    BLS12_set_basis();
//    BLS12_set_frobenius_constant();
    BLS12_set_curve_parameter();
}

//---------------------------------------------------------------------

void BLS12_init_parameters(){
    mpz_init(bls12_parameters.X);
    mpz_init(bls12_parameters.prime);
    mpz_init(bls12_parameters.order);
    mpz_init(bls12_parameters.trace_t);
    
    mpz_init(bls12_parameters.EFp_total);
    mpz_init(bls12_parameters.EFpd_total);
    mpz_init(bls12_parameters.curve_b);
    
    int i;
    BLS12_X_length=77;
    for(i=0; i<BLS12_X_length+1; i++){
        BLS12_X_binary[i]=0;
    }
}

void BLS12_generate_X(){
    int i;
    mpz_t buf,set_2;
    mpz_init(buf);
    mpz_init(set_2);
    mpz_set_ui(set_2,2);
    
    //BLS12_X_binary
    BLS12_X_binary[77]=-1;
    BLS12_X_binary[50]=1;
    BLS12_X_binary[33]=1;
    
    //BLS12_X
    mpz_init(BLS12_X);
    mpz_set_ui(BLS12_X,0);
    for(i=BLS12_X_length; i>=0; i--){
        if(BLS12_X_binary[i]==1){
            mpz_pow_ui(buf,set_2,i);
            mpz_add(BLS12_X,BLS12_X,buf);
        }else if(BLS12_X_binary[i]==-1){
            mpz_pow_ui(buf,set_2,i);
            mpz_sub(BLS12_X,BLS12_X,buf);
        }
    }
    
    mpz_clear(buf);
    mpz_clear(set_2);
}

int  BLS12_generate_prime(){
    mpz_t result,buf1,buf2,modtest;
    mpz_init(result);
    mpz_init(buf1);
    mpz_init(buf2);
    mpz_init(modtest);
    
    mpz_sub_ui(result,BLS12_X,1);
    mpz_pow_ui(result,result,2);
    
    mpz_pow_ui(buf1,BLS12_X,4);
    mpz_pow_ui(buf2,BLS12_X,2);
    mpz_sub(buf1,buf1,buf2);
    mpz_add_ui(buf1,buf1,1);
    
    mpz_mul(result,result,buf1);
    
    //check div3
    mpz_mod_ui(modtest,result,3);
    if(mpz_cmp_ui(modtest,0)!=0){
        mpz_init(result);
        mpz_init(buf1);
        mpz_init(buf2);
        mpz_init(modtest);
        return 0;
    }
    
    mpz_tdiv_q_ui(result,result,3);
    mpz_add(result,result,BLS12_X);
    
    //isprime
    if(mpz_probab_prime_p(result,25)==0){
        mpz_init(result);
        mpz_init(buf1);
        mpz_init(buf2);
        mpz_init(modtest);
        return 0;
    }
    
    mpz_set(bls12_parameters.prime,result);
    
    mpz_init(result);
    mpz_init(buf1);
    mpz_init(buf2);
    mpz_init(modtest);
    return 1;
}

int  BLS12_generate_order(){
    mpz_t buf1,buf2;
    mpz_init(buf1);
    mpz_init(buf2);
    
    mpz_pow_ui(buf1,BLS12_X,4);
    mpz_pow_ui(buf2,BLS12_X,2);
    mpz_sub(bls12_parameters.order,buf1,buf2);
    mpz_add_ui(bls12_parameters.order,bls12_parameters.order,1);
    
    mpz_clear(buf1);
    mpz_clear(buf2);
    
    return 0;
}

void BLS12_generate_trace(){
    mpz_add_ui(bls12_parameters.trace_t,BLS12_X,1);
}

void BLS12_set_curve_parameter(){
    mpz_set_ui(bls12_parameters.curve_b,4);
}

void BLS12_weil(){
    mpz_t t2,t6,t12,p2,p6,buf;
    mpz_init(t2);
    mpz_init(t6);
    mpz_init(t12);
    mpz_init(p2);
    mpz_init(p6);
    mpz_init(buf);
    
    //EFp_total
    mpz_add_ui(buf,bls12_parameters.prime,1);
    mpz_sub(bls12_parameters.EFp_total,buf,bls12_parameters.trace_t);
    
    //t2←α^2+β^2
    mpz_pow_ui(t2,bls12_parameters.trace_t,2);
    mpz_mul_ui(buf,bls12_parameters.prime,2);
    mpz_sub(t2,t2,buf);
    mpz_pow_ui(p2,bls12_parameters.prime,2);
    
    //α^6+β^6
    mpz_pow_ui(t6,t2,3);
    mpz_mul(buf,t2,p2);
    mpz_mul_ui(buf,buf,3);
    mpz_sub(t6,t6,buf);
    mpz_pow_ui(p6,p2,3);
    
    //α^12+β^12
    mpz_pow_ui(t12,t6,2);
    mpz_mul_ui(buf,p6,2);
    mpz_sub(t12,t12,buf);
    
    //EFp12_total
    mpz_pow_ui(buf,p6,2);
    mpz_sub(buf,buf,t12);
    mpz_add_ui(bls12_parameters.EFpd_total,buf,1);
    
    mpz_clear(t2);
    mpz_clear(t6);
    mpz_clear(t12);
    mpz_clear(p2);
    mpz_clear(p6);
    mpz_clear(buf);
}

void BLS12_print_parameters(){
    printf("====================================================================================\n");
    printf("BLS12\n\n");
    gmp_printf("parameters\n");
    gmp_printf("X     (%dbit length) : %Zd \n",(int)mpz_sizeinbase(BLS12_X,2),BLS12_X);
    gmp_printf("prime (%dbit length) : %Zd \n",(int)mpz_sizeinbase(bls12_parameters.prime,2),bls12_parameters.prime);
    gmp_printf("order (%dbit length) : %Zd \n",(int)mpz_sizeinbase(bls12_parameters.order,2),bls12_parameters.order);
    gmp_printf("trace (%dbit length) : %Zd \n",(int)mpz_sizeinbase(bls12_parameters.trace_t,2),bls12_parameters.trace_t);
    
    gmp_printf("\nelliptic curve\n");
    gmp_printf("E:y^2=x^3+4\n",bls12_parameters.curve_b);
    
    gmp_printf("\nmodulo polynomial\n");
    gmp_printf("Fp2  : f(x) = x^2+1\n");
    gmp_printf("Fp6  : f(x) = x^3-(alpha+1)\n");
    gmp_printf("Fp12 : f(x) = x^2-beta\n");
    
}

