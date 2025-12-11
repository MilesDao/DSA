#include<stdio.h>
#include<stdlib.h>


struct Car{
    char id;
    int capacity;
    int reserved;
    struct Car* next;
};
typedef struct Car car;

car *makeCar(char id , int capacity, int reserved){
    if(reserved > capacity){
        printf("error\n");
    }
    car *tmp = (car*)malloc(sizeof(car));
    tmp->id = id;
    tmp->capacity = capacity;
    tmp->reserved = reserved;
    tmp->next = NULL;
    return tmp;
}

void addCar(car **a, char id, int capacity, int reserved){
    car *tmp = makeCar(id , capacity, reserved);
    if(*a == NULL){
        *a = tmp;
        return;
    }
    car *p = *a;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = tmp;
}

void removeCar(car **a){

    while(*a != NULL && (*a)->reserved ==0){
        car *del = *a;
        *a = (*a)->next;
        free(del);
    }
    // car *p = *a;
    // while(p!=NULL&&p->next != NULL){
    //     if(p->next->reserved == 0){
    //         car *del = p->next;
    //         p->next = p->next->next;   
    //         free(del);
    //     }
    //     else{
    //         p = p->next;
    //     }
    // }

    car *p = *a;
    while(p->next != NULL){
        if(p->next->reserved ==0){
            p ->next = p->next->next;
        }
        else{
            p = p->next;
        }
    }
}
void display(car *a){
    while(a != NULL){
        printf("id = %c, capacity = %d, reserved = %d\n", a->id, a->capacity, a->reserved);
        a = a->next;
    }
    
}
int length(car *a){
    int cnt = 0;
    while(a != NULL){
        cnt++;
        a= a->next;
    }
    return cnt;
}
int main(){
    car *head = NULL;
    
    addCar(&head, 'A', 50 , 0);
    addCar(&head, 'B', 20 , 10);
    addCar(&head, 'C', 80 , 60);
    addCar(&head, 'D', 70 , 0);


    display(head);

    printf("length: %d\n", length(head));

    printf("========================\n");
    addCar(&head, 'E', 20 , 10);
    addCar(&head, 'F', 100 , 0);
    removeCar(&head);
    display(head);

    printf("length: %d\n", length(head));

    
    return 0;
}
