#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char url[100];
    char title[100];
} website;

typedef struct node{
    website data;
    struct node *next;
} node;

typedef struct {
    node *top;
} stack;

stack *init(){
    stack *st = (stack*)malloc(sizeof(stack));
    st->top = NULL;
    return st;
}
int isEmpty(stack *st){
    return st->top == NULL;
}
void push(stack *st, website w){
    node *n = (node*)malloc(sizeof(node));
    n->data = w;
    n->next = st->top;
    st->top = n;
}
website pop(stack *st) {
    website empty = {"", ""};
    if (isEmpty(st)) {
        return empty;
    }
    node *temp = st->top;
    website w = temp->data;
    st->top = temp->next;
    free(temp);
    return w;
}
website peek(stack *s) {
    website empty = {"", ""};
    if (isEmpty(s)) return empty;
    return s->top->data;
}

void display(stack *st) {
    printf("\nStack (top to bottom):\n");
    node *p = st->top;
    while (p != NULL) {
        printf("[%s] - %s\n", p->data.title, p->data.url);
        p = p->next;
    }
    printf("-----------------------\n");
}

void visit(stack *back, stack *forward, char url[], char title[]) {
    website w;
    strcpy(w.url, url);
    strcpy(w.title, title);

    while (!isEmpty(forward)) pop(forward);

    push(back, w);
    printf("Visited: %s (%s)\n", title, url);
}
void goBack(stack *back, stack *forward) {
    if (isEmpty(back)) {
        printf("No pages to go back.\n");
        return;
    }

    website current = pop(back);

    push(forward, current);

    website now = peek(back);

    printf("Back to: %s (%s)\n", now.title, now.url);
}

void goForward(stack *back, stack *forward) {
    if (isEmpty(forward)) {
        printf("No pages to go forward.\n");
        return;
    }

    website nextW = pop(forward);

    
    push(back, nextW);

    printf("forward to: %s (%s)\n", nextW.title, nextW.url);
}

int main(){
    stack *backward = init();
    stack *forward  = init();

    visit(backward, forward, "google.com", "Google");
    visit(backward, forward, "youtube.com", "YouTube");
    visit(backward, forward, "chatgpt.com", "ChatGPT");
    visit(backward, forward, "facebook.com", "Facebook");

    printf("\nBackward stack\n");
    display(backward);

    goBack(backward, forward); 
    goBack(backward, forward);

    printf("\nGoing back twice\n");
    printf("Backward:"); display(backward);
    printf("Forward:");  display(forward);

    goForward(backward, forward);  

    printf("\nAfter going forward\n");
    printf("Backward:"); display(backward);
    printf("Forward:");  display(forward);
    return 0;
}