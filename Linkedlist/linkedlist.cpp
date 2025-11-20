#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
typedef struct Node* node;

// cap phat dong 1 node moi voi du lieu la int x
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
//kiem tra rong
bool isEmpty(node a){
    return a == NULL;
}
// dem xem bao nhieu phan tu
int Size(node a){ // a la node dau tien trong danh sach lien ket
    int cnt = 0;
    while(a != NULL){
        cnt++;
        a = a->next;
    }
    return cnt;
}


// chen phan tu vao dau danh sach lien ket

void insertFirst(node &a, int x){ // a de them tham chieu thay doi node a
    node tmp = makeNode(x);
    if( a== NULL){
        a = tmp;
    }
    else{
        tmp->next= a;
        a = tmp;
    }
}
//them phan tu vao cuoi danh sach
void insertLast(node &a , int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else{
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}


void insertMiddle(node &a, int x, int pos){
    int n = Size(a);
    if(0 <=n || n >pos +1){
        cout << "invalid";
    }
    if(n == 1){
        insertFirst(a, x);
    }
    else if(n == pos +1){
        insertLast(a, x);
    }
    else{
        node p = a;
        for(int i =1 ; i< pos - 1 ; i++){
            p = p ->next;
        }
        node tmp = makeNode(x);
        tmp -> next = p->next;
        p->next = tmp;
    }
}
//deleteFirst
void deteleFirst(node &a){
    if( a == NULL) return;
    else{
        a = a->next;
    }
}
void deteleLast(node &a){
    if( a == NULL) return;
    node trc = NULL, sau = a;
    while(sau->next != NULL){
        trc = sau;
        sau = sau->next;
    }
    if(trc == NULL) {
        a = NULL;
    }
    else{
        trc->next = NULL;
    }
}

int main(){
    node head = NULL;
    return 0;
}


