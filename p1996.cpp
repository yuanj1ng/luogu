#include <iostream>

typedef struct Node {
    int data;           // 数据域（以int为例）
    struct Node* next;  // 指针域
} Node;


Node* create_node(int data){
    Node* new_node = (Node*)malloc(sizeof(int));
    if(new_node == NULL){
        std::cout << "内存分配失败" << std::endl;
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_head(Node ** head ,int data){
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_tail(Node ** head ,int data){
    Node* new_node = create_node(data);
    if(*head == NULL){
        *head = new_node;
    }
    Node *current = *head; 
    while(current->next != NULL){
        current = current->next ;
    }
    current->next = new_node;
}

int main(){
    Node head;
    Node *link;
    head.next = link;
    
}