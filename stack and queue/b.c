#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================
// Website Struct
// ============================
typedef struct {
    char url[100];
    char title[100];
} Website;


// ============================
// Node for Stack
// ============================
typedef struct Node {
    Website data;
    struct Node *next;
} Node;


// ============================
// Stack (Linked List)
// ============================
typedef struct {
    Node *top;
} Stack;


// Initialize stack
Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

// Push
void push(Stack *s, Website w) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = w;
    n->next = s->top;
    s->top = n;
}

// Pop
Website pop(Stack *s) {
    Website empty = {"", ""};
    if (isEmpty(s)) {
        return empty;
    }
    Node *temp = s->top;
    Website w = temp->data;
    s->top = temp->next;
    free(temp);
    return w;
}

// Peek
Website peek(Stack *s) {
    Website empty = {"", ""};
    if (isEmpty(s)) return empty;
    return s->top->data;
}

// Display stack
void display(Stack *s) {
    printf("\nStack (top to bottom):\n");
    Node *p = s->top;
    while (p != NULL) {
        printf("[%s] - %s\n", p->data.title, p->data.url);
        p = p->next;
    }
    printf("-----------------------\n");
}


// ============================
// Visit Website
// ============================
void visit(Stack *back, Stack *forward, char url[], char title[]) {
    Website w;
    strcpy(w.url, url);
    strcpy(w.title, title);

    // Clear forward stack because new navigation resets forward history
    while (!isEmpty(forward)) pop(forward);

    push(back, w);
    printf("Visited: %s (%s)\n", title, url);
}


// ============================
// Go Back
// ============================
void goBack(Stack *back, Stack *forward) {
    if (isEmpty(back)) {
        printf("⚠️  No pages to go back.\n");
        return;
    }

    // Pop current page
    Website current = pop(back);

    // Move it to forward stack
    push(forward, current);

    // New current page is now the next one on back
    Website now = peek(back);

    printf("⬅️  Back to: %s (%s)\n", now.title, now.url);
}


// ============================
// Go Forward
// ============================
void goForward(Stack *back, Stack *forward) {
    if (isEmpty(forward)) {
        printf("⚠️  No pages to go forward.\n");
        return;
    }

    // Pop from forward
    Website nextW = pop(forward);

    // Push into backward
    push(back, nextW);

    printf("➡️  Forward to: %s (%s)\n", nextW.title, nextW.url);
}



// ============================
// MAIN FUNCTION
// ============================
int main() {
    Stack *backward = initStack();
    Stack *forward  = initStack();

    // Start visiting pages
    visit(backward, forward, "google.com", "Google");
    visit(backward, forward, "youtube.com", "YouTube");
    visit(backward, forward, "github.com", "GitHub");
    visit(backward, forward, "stackoverflow.com", "StackOverflow");

    printf("\n--- Backward Stack ---\n");
    display(backward);

    goBack(backward, forward);   // back to GitHub
    goBack(backward, forward);   // back to YouTube

    printf("\n--- After going back twice ---\n");
    printf("Backward:"); display(backward);
    printf("Forward:");  display(forward);

    goForward(backward, forward);  // forward to GitHub

    printf("\n--- After going forward ---\n");
    printf("Backward:"); display(backward);
    printf("Forward:");  display(forward);

    return 0;
}
