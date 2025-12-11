/*
Question 1 (16 pts)
A Harshad number is an integer that is divisible by the sum of its digits.
Example:
- 18/(1+8) = 18/9 = 2, 18 is divisible by 2 → Harshad number.
- 21/(2+1) = 21/3 = 7, divisible → Harshad number.
- 19/(1+9) = 19/10 = 1.919, not divisible → not a Harshad number.
- 274/(2+7+4) = 274/13 = 21.07, not divisible → not a Harshad number.
▪ Implement a program in C/C++ using Iteration to find all Harshad numbers from 1 to n (n is
a natural number). (7pts)
▪ Implement another function using Recursion to complete the above question. (7pts)
▪ Calculate the complexity of your functions or algorithms. Justify the answer (comment
directly in your source files). (2pts)*/

#include<stdio.h>

int checkHarshad(int n ){
    int tmp = n;
    int sum = 0;
    while( tmp>0 ){                                              //logn
        sum += tmp%10;
        tmp /=10;
    }
    if( sum != 0 && n%sum ==0) return 1;
    return 0;

}
void findHarshad_iter(int n){
    for(int i = 1; i<= n ; i++){
        if(checkHarshad(i))printf("%d ", i);                    //nlogn
    }
    printf("\n");   
}

int sumd(int n ){
    if(n <=0 ) return 0;
    return (n%10) + sumd(n/10);
}
void findHarshad_rev(int i , int n){
    if(i>n) return ;
    int sum = sumd(i);
    if(sum !=0 && i % sum ==0){
        printf("%d ", i);
    }
    printf("\n");
    return findHarshad_rev(i+1, n);
}



int main(){
    int n =21;
    printf("Harshad number from 1 to n is: ");
    findHarshad_iter(n);
    printf("Harshad number from 1 to n is: ");
    findHarshad_rev(1, n);

    return 0;
}
/*
Question 2 (4 pts)
Note: The student can answer this question in a text format. The submitted file can be either .c or
.text.
A chat app buffers incoming messages to be displayed in the order they arrive.
▪ Propose an appropriate data structure to handle this display task. Justify your choice. (2pts)
▪ What are the basic functions to manipulate the proposed data structure? (1pt)
▪ Calculate the complexity of the display process. (1pt)*/

/*

1. Appropriate data structure + Justification (2 pts)

Use a Queue.

Justification:

A chat app displays messages in the exact order they arrive → First-In-First-Out (FIFO).

A queue naturally preserves this order: the first message inserted is the first message displayed.

Efficient operations: O(1) insertion (enqueue) and O(1) removal (dequeue).

2. Basic functions for Queue (1 pt)

The essential operations are:

enqueue(x) – insert new incoming message at the back

dequeue() – remove/display the oldest message at the front

front() – read the next message without removing

isEmpty() – check if no messages exist

(optional) isFull() if using array-based queue

3. Complexity of the display process (1 pt)

Displaying messages means performing dequeue() once per message.

Time complexity:

Each dequeue = O(1)

Displaying k messages = O(k)

Space complexity:

Storing n messages in the queue = O(n)*/