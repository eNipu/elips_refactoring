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


int main(int argc, const char * argv[]) {
    // insert code here...
    init_bn();
    bn_print_parameters();
//    BN12_test_x_ate_pairing();
    BN12_test_plain_ate_pairing();
//    BN12_test_opt_ate_pairing();
    clear_bn();
    return 0;
}
