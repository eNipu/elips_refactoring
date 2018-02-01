//
//  main.c
//  elips_refactoring
//
//  Created by Khandaker Md. Al-Amin on 1/25/18.
//  Copyright © 2018 ISec Lab. All rights reserved.
//

#include "bn_inits.h"
#include "bn_clears.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    init_bn();
    bn_print_parameters();
    clear_bn();
    printf("Hello, World!\n");
    return 0;
}
