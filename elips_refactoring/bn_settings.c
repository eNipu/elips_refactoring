//
//  bn_settings.c
//  BN_Single_File_Elips
//
//  Created by Khandaker Md. Al-Amin on 1/25/18.
//  Copyright © 2018 Khandaker Md. Al-Amin. All rights reserved.
//

#include "bn_settings.h"
//#include "bn_precoms.h"


struct bn_params bn_parameters;
struct bn_coefficient bn_curve_coefficient;
int X_binary[X_length+1];
int X_binary_opt[X_length+3];
//---------------------------------------------------------------------

void init_settings(){
    init_parameters();
    
    generate_X();
    generate_prime();
    generate_order();
    generate_trace();
    
    weil();
    set_curve_parameter();
}

/*============================================================================*/
/*  init                                                                      */
/*============================================================================*/
void init_parameters(){
    //parameters
    mpz_init(bn_parameters.prime);
    mpz_init(bn_parameters.X);
    mpz_init(bn_parameters.trace_t);
    mpz_init(bn_parameters.order);
    mpz_init(bn_parameters.EFp_total);
    mpz_init(bn_parameters.EFp2_total);
    mpz_init(bn_parameters.EFp6_total);
    mpz_init(bn_parameters.EFp12_total);
    mpz_init(bn_curve_coefficient.curve_a);
    mpz_init(bn_curve_coefficient.curve_b);
    
    int i;
    for(i=0; i<X_length+1; i++){
        X_binary[i]=0;
    }
    for(i=0; i<X_length+3; i++){
        X_binary_opt[i]=0;
    }
    
//    Fp_init(&Fp_basis);
//    Fp2_init(&Fp2_basis);
//    Fp2_init(&Fp2_basis_inv);
//    Fp6_init(&Fp6_basis);
//    mpz_init(epsilon1);
//    mpz_init(epsilon2);
    
//    for(i=0; i<d12; i++){
//        for(j=0; j<6; j++){
//            Fp2_init(&d12_frobenius_constant[i][j]);
//        }
//        for(j=0; j<2; j++){
//            Fp2_init(&d12_skew_frobenius_constant[i][j]);
//        }
//    }
//
//    EFp12_init(&G1_P);
//    EFp12_init(&G2_Q);
//    EFp12_init(&Random_R);
}

void generate_X(){
    int i;
    mpz_t buf;
    mpz_init(buf);
    
    //X_binary
    X_binary[114]=1;
    X_binary[101]=1;
    X_binary[14]=-1;
    X_binary[0]=-1;
    
    //X_binary_opt
    X_binary_opt[116]=1;
    X_binary_opt[115]=1;
    X_binary_opt[103]=1;
    X_binary_opt[102]=1;
    X_binary_opt[16]=-1;
    X_binary_opt[15]=-1;
    X_binary_opt[2]=-1;
    
    //X
    mpz_set_ui(bn_parameters.X,0);
    for(i=X_length; i>=0; i--){
        if(X_binary[i]==1){
            mpz_ui_pow_ui(buf,2,i);
            mpz_add(bn_parameters.X,bn_parameters.X,buf);
        }else if(X_binary[i]==-1){
            mpz_ui_pow_ui(buf,2,i);
            mpz_sub(bn_parameters.X,bn_parameters.X,buf);
        }
    }
    
    mpz_clear(buf);
}

int  generate_prime(){
    mpz_t buf,result;
    mpz_init(buf);
    mpz_init(result);
    
    //prime
    mpz_pow_ui(buf,bn_parameters.X,4);
    mpz_mul_ui(buf,buf,36);
    mpz_set(result,buf);
    mpz_pow_ui(buf,bn_parameters.X,3);
    mpz_mul_ui(buf,buf,36);
    mpz_add(result,result,buf);
    mpz_pow_ui(buf,bn_parameters.X,2);
    mpz_mul_ui(buf,buf,24);
    mpz_add(result,result,buf);
    mpz_mul_ui(buf,bn_parameters.X,6);
    mpz_add(result,result,buf);
    mpz_add_ui(result,result,1);
    
    //isprime
    if(mpz_probab_prime_p(result,25)==0){
        mpz_clear(buf);
        mpz_clear(result);
        return 0;
    }else{
        mpz_set(bn_parameters.prime,result);
        mpz_clear(buf);
        mpz_clear(result);
        return 1;
    }
}

int  generate_order(){
    mpz_t buf,result;
    mpz_init(buf);
    mpz_init(result);
    
    //prime
    mpz_pow_ui(buf,bn_parameters.X,4);
    mpz_mul_ui(buf,buf,36);
    mpz_set(result,buf);
    mpz_pow_ui(buf,bn_parameters.X,3);
    mpz_mul_ui(buf,buf,36);
    mpz_add(result,result,buf);
    mpz_pow_ui(buf,bn_parameters.X,2);
    mpz_mul_ui(buf,buf,18);
    mpz_add(result,result,buf);
    mpz_mul_ui(buf,bn_parameters.X,6);
    mpz_add(result,result,buf);
    mpz_add_ui(result,result,1);
    
    //isprime
    if(mpz_probab_prime_p(result,25)==0){
        mpz_clear(buf);
        mpz_clear(result);
        return 0;
    }else{
        mpz_set(bn_parameters.order,result);
        mpz_clear(buf);
        mpz_clear(result);
        return 1;
    }
}


void generate_trace(){
    mpz_t buf;
    mpz_init(buf);
    
    mpz_pow_ui(buf,bn_parameters.X,2);
    mpz_mul_ui(buf,buf,6);
    mpz_add_ui(bn_parameters.trace_t,buf,1);
    
    mpz_clear(buf);
}

void set_curve_parameter(){
    mpz_set_ui(bn_curve_coefficient.curve_b,4);
}

void weil(){
    mpz_t t2,t6,t12,p2,p6,buf;
    mpz_init(t2);
    mpz_init(t6);
    mpz_init(t12);
    mpz_init(p2);
    mpz_init(p6);
    mpz_init(buf);
    
    //EFp_total
    mpz_add_ui(buf,bn_parameters.prime,1);
    mpz_sub(bn_parameters.EFp_total,buf,bn_parameters.trace_t);
    
    //t2←α^2+β^2
    mpz_pow_ui(t2,bn_parameters.trace_t,2);
    mpz_mul_ui(buf,bn_parameters.prime,2);
    mpz_sub(t2,t2,buf);
    mpz_pow_ui(p2,bn_parameters.prime,2);
    
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
    mpz_add_ui(bn_parameters.EFpd_total,buf,1);
    
    mpz_clear(t2);
    mpz_clear(t6);
    mpz_clear(t12);
    mpz_clear(p2);
    mpz_clear(p6);
    mpz_clear(buf);
}


//---------------------------------------------------------------------

