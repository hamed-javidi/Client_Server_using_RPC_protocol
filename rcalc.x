/*
 Names:
        Joe Masar
        Hamed Javidi

    Description: 
        x code for RPCGEN

    Log: 
        4/25/2020: created 
 */

/* structure definitions, no enumerations needed */
struct node{
    double number;
    struct node * link;
}; 

struct sqnumbers{
    int in1;
    int in2;
};

/* program definition, no union or typdef definitions needed */
program RCALC { /* could manage multiple servers */
	version RECALC_V1 {
		double SUMSQRT_RANGE(sqnumbers) = 1;
		node UPDATE_LIST(node) = 2;
	} = 1;
} = 0x20000134;  /* program number ranges established by ONC */
