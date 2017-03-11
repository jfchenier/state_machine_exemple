#include <stdio.h>
#include <stdlib.h>

typedef enum {
    STATE_1,
    STATE_2,
    STATE_3,
    STATE_4,
    STATE_5,
    STATE_MAX
} state_type;

typedef struct{
    state_type state;
    void (*func)(void);
}state_machine_type;

void run_state(void);

void state1(void);
void state2(void);
void state3(void);
void state4(void);
void state5(void);

state_machine_type state_machine[] =
{
    {STATE_1, state1},
    {STATE_2, state2},
    {STATE_3, state3},
    {STATE_4, state4},
    {STATE_5, state5},

};

state_type next_state = STATE_1;

int main()
{
    printf("Hello world!\n");
    for(;;){
        run_state();
    }
    return 0;
}

void run_state(void){
    if(next_state < STATE_MAX){
        (*state_machine[next_state].func)();
    }
    else {
        printf("error\n\r");
    }
}

void state1(void){
    printf("This is the state 1\n\r");
    next_state = STATE_2;
}

void state2(void){
    printf("This is the state 2\n\r");
    next_state = STATE_3;
}

void state3(void){
    printf("This is the state 3\n\r");
    next_state = STATE_4;
}

void state4(void){
    printf("This is the state 4\n\r");
    next_state = STATE_5;
}

void state5(void){
    printf("This is the state 5\n\r");
    next_state = STATE_1;
}


