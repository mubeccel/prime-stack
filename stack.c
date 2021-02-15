#include <stdio.h> 
#include <stdlib.h> 

int i,num;

//functions
int prime(), pop(), mid();
void push();

struct DLLNode 
{ 
    struct DLLNode *prev; 
    int data; 
    struct DLLNode *next; 
};  

struct myStack 
{ 
    struct DLLNode *head; 
    struct DLLNode *mid; 
    int count; 
}; 
  
struct myStack *createMyStack() 
{ 
    struct myStack *ms = 
               (struct myStack*) malloc(sizeof(struct myStack)); 
    ms->count = 0; 
    return ms; 
}; 
  

void push(struct myStack *ms, int new_data) 
{ 
    struct DLLNode* new_DLLNode = 
               (struct DLLNode*) malloc(sizeof(struct DLLNode)); 
    new_DLLNode->data  = new_data; 

    new_DLLNode->prev = NULL; 

    new_DLLNode->next = ms->head; 

    ms->count += 1; 

    if (ms->count == 1) 
    { 
         ms->mid = new_DLLNode; 
    } 
    else
    { 
        ms->head->prev = new_DLLNode; 
        
        if (ms->count & 1) 
           ms->mid = ms->mid->prev; 
    } 
    ms->head  = new_DLLNode; 
} 
  
int pop(struct myStack *ms) 
{ 
    if (ms->count  ==  0) 
    { 
        printf("Stack is empty \n"); 
        return -1; 
    } 
    struct DLLNode *head = ms->head; 
    int item = head->data; 
    ms->head = head->next; 
 
    if (ms->head != NULL) 
        ms->head->prev = NULL; 
  
    ms->count -= 1; 

    if (!((ms->count) & 1 )) 
        ms->mid = ms->mid->next; 
  
    free(head); 
    return item; 
} 
  

int mid(struct myStack *ms) //the middle element
{ 
    if (ms->count  ==  0) 
    { 
        printf("Stack is empty \n"); 
        return -1; 
    } 
    return ms->mid->data; 
} 

int prime(){  
	num =  rand() % 100; //get random integer
	int flag = 0, i ;
	
	//check if the integer is free
    for( i = 2; i <= num/2; i++) {
		if(num % i == 0) {
  	    	flag = 1;
   			break;
        }
    } 
    if(flag == 0){
       	//num is prime
       	prime();
   	}
    else
  		//num is not prime
		return num;
	}
		
int main() 
{ 
    struct myStack *ms = createMyStack(); 
    int j;
    for (j=0; j<5; j++) { 
    
		push(ms, prime());   
    }
	
    printf("", mid(ms)); //when the pop function runs, stack becomes empty so we should get the mid element as constant
    const int a = mid(ms); 
    
    printf("Stack: %d -> %d -> %d -> %d -> %d\n", pop(ms), pop(ms), pop(ms), pop(ms), pop(ms)); 
    printf("Middle element is: %d", a);
    return 0; 
} 
