/*  Names:
        Joe Masar
        Hamed Javidi

    Description: 
        Client code for RPCGEN

    Log: 
        4/25/2020: created 
*/


#include <stdio.h>
#include <ctype.h>
#include <rpc/rpc.h>
#include <string.h>
#include "rcalc.h"

//static sqnumbers *out_sq = NULL;
//static node *out_list = NULL;



int main(argc, argv)
int argc;
char *argv[];
{
	CLIENT  *cl; 
	//char  *value;
	int key;
	sqnumbers *out_sq = NULL;
	node * head = NULL;
	node * tail = NULL;
	//check for correct length
	if (argc < 4) {
		printf( "Usage: server type num1.. num2.. etc \n");
		exit(1);
	}

	//setup server
	if (!(cl = clnt_create(argv[1], RCALC, RECALC_V1, "tcp"))) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	//read switch
	if(strcmp(argv[2], "-r") == 0){
		key = 1;
	}
	else if(strcmp(argv[2], "-u") == 0){
		key = 2;
	}
	else{
		key = 3;
	}

	  switch (key) {
		case SUMSQRT_RANGE:
			//Square root call
			
			out_sq = malloc(sizeof(sqnumbers));
			out_sq->in1 = atoi(argv[3]);
			out_sq->in2 = atoi(argv[4]);
			
			printf("%lf\n", * sumsqrt_range_1(out_sq, cl));

			break;

		case UPDATE_LIST:
			//update list

			//convert input to list for passing
			for(int i = 3; i < argc; i++){
				node * temp;
				temp = malloc(sizeof(node *));

				temp->number = atof(argv[i]);
				temp->link= NULL;

				if(tail == NULL){
					head = tail = temp;
				}
				else
				{
					tail->link=temp;
					tail = tail->link;
				}
			}

			//print list
			head = update_list_1(head, cl);
			tail = head;

			while(tail != NULL){
				 printf("%.1lf ", tail->number);
				 tail = tail->link;
			}
			printf("\n");

			break;
		default:
			fprintf(stderr, "%s: unknown key\n", argv[0]);
			exit(1);
	  }
}
