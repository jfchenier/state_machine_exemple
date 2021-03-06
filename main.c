#include <stdio.h>



struct state
{
    void (*next)(struct state *state);
    void *arg;
};

void state1(struct state *state);
void state2(struct state *state);
void state3(struct state *state);
void state4(struct state *state);
void state5(struct state *state);

int main(void)
{
    struct state state = { state1, 0 };
    while(state.next){
        state.next(&state);
    }
}

void state1(struct state *state)
{
    int i = 5;
    printf("this is the state 1\n\r");
    state->arg = 5;
    state->next = state2;
}

void state2(struct state *state)
{
    printf("this is the state 2\n\r");
    state->next = state3;
}

void state3(struct state *state)
{
    printf("this is the state 3\n\r");
    state->next = state4;
}

void state4(struct state *state)
{
    printf("this is the state 4\n\r");
    state->next = state5;
}

void state5(struct state *state)
{
    printf("this is the state 5\n\r");
    state->next = 0;
}
