#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct node{
    double number;
    struct node * link;
}; 

double sumsqrt_range(int num1, int num2){
    double max, min, total;

    total = 0;

    if (num1 > num2){
        max = num1;
        min = num2;
    }
    else{
        max = num2;
        min = num1;
    }

    for(int x = min; x <= max; x++){
        total += sqrt(x);
    }
    return total;
} 

void update_list(struct node * in){
    struct node * current = in;

    while(current != NULL){
        current->number = current->number * current->number/10.0;
        printf("current:aft %lf\n", current->number);
        current = current->link;
    }
}

int main(int argc, char * argv[]){
    
    struct node * head;
    struct node * tail=NULL;

    head = tail;

    if(strcmp(argv[2], "-r") == 0 ){
        double returnValue;
        int in1 = atoi(argv[3]);
        int in2 = atoi(argv[4]);
        returnValue = sumsqrt_range(in1, in2);

        printf("%f\n", returnValue);
    }
    else if(strcmp(argv[2], "-u") == 0 ){
        
        for(int i = 3; i < argc; i++){
            struct node * temp;
            temp = malloc(sizeof(struct node *));
            temp->number = atoi(argv[i]);
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

        printf("HEAD %lf\n", head->number);

        update_list(head);
    }
    else{
        printf("Invalid input\n");
    }    
}