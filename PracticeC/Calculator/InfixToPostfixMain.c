//
//  InfixToPostfixMain.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 7..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>
#include "InfixToPostfix.h"
#include "PostCalc.h"

int main(void)
{
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";
    char exp4[] = "3*4+2*(4/2)";
    
    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);
    ConvToRPNExp(exp4);

    
    //printf("%s = %d \n", exp1, EvalRPNExp(exp1));
    //printf("%s = %d \n", exp2, EvalRPNExp(exp2));
    //printf("%s = %d \n", exp3, EvalRPNExp(exp3));
    printf("%s = %d \n", exp4, EvalRPNExp(exp4));

    
    return 0;
}
