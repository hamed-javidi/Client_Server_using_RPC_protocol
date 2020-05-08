/*  Names:
        Joe Masar
        Hamed Javidi

    Description: 
        Server code for RPCGEN

    Log: 
        4/25/2020: created 
*/

#include <stdio.h>
#include <string.h>
#include <rpc/rpc.h>
#include "rcalc.h"
#include <math.h>


double *
sumsqrt_range_1_svc(sqnumbers *r, struct svc_req *rqp)
{
	
    double max, min, num1, num2;

    //static so we can return to client
    static double total;

    num1 = r->in1;
    num2 = r->in2;

    //put into order
    if (num1 > num2){
        max = num1;
        min = num2;
    }
    else{
        max = num2;
        min = num1;
    }

    //add from min to max
	total = 0;
    for(int x = min; x <= max; x++){
        total += sqrt(x);
    }

    return ((double *) &total);
}

node *
update_list_1_svc(node *in, struct svc_req *rqp){
    struct node * current = in;
    
    //do calculation and return
    while(current != NULL){
        current->number = current->number * current->number/10.0;
        current = current->link;
    }

    return ((node *) in);
}

