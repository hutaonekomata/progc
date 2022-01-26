#define STACK_SIZE 53
#define NUM_INIT 0
#define SP_INIT 0
#define SP_INIT2 -1
#define SUCCESS 1
#define FAIL 0
#define ADD 1
#define SUB -1

typedef struct{
	int strage[STACK_SIZE];
	int sp;
}Stack;

void initStack(Stack *s);
int push(Stack *s,int data);
int pop(Stack *s,int *data);