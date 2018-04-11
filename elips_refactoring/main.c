//
//  main.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 1/25/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bn_inits.h"
#include "bn_clears.h"
#include "bn_pairing_test.h"

#include "bls12_inits.h"
#include "bls12_pairings.h"
#include "bls12_test_pairings.h"

#include "kss16_inits.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    init_bn();
    print_curve_parameters();
//    BN12_test_x_ate_pairing();
//    BN12_test_plain_ate_pairing();
    BN12_test_opt_ate_pairing();
    clear_parameters();
    
    bls12_inits();
    BLS12_print_parameters();
    BLS12_test_opt_ate_pairing();
    clear_parameters();
    
//    kss16_inits();
//    mpz_t cc;
//    mpz_init(cc);
//    mpz_set_ui(cc, 2);
//    mpz_invert(cc,cc,curve_parameters.prime);
//    gmp_printf("CC== %Zd\n",cc);
//    print_curve_parameters();
    return 0;
}
