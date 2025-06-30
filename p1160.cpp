#include<iostream>
//双链表
struct Node{
    int num;
    Node* front;
    Node* next;
};

Node* a[100002];

Node* create_node(int num){
    Node* new_node = new Node;
    new_node->num = num;
    new_node->front = nullptr;
    new_node->next = nullptr;
    return new_node;
}

void link_list_insert(Node* &head,int k,int p ,int num){
    Node* current = a[k];
    Node* new_node = create_node(num);
    a[num] = new_node;
    if(p==0){//左插入
        if(current == head){//头节点左边插入
            new_node->next = head;
            head->front = new_node;
            head = new_node;
        }else{
            new_node->front = current->front;
            new_node->next = current;
            current->front = new_node;
            new_node->front->next = new_node;
        }
    }
    else if(p==1){//右插入
        if(current->next == nullptr){//尾节点右边插入
            current->next = new_node;
            new_node->front = current;
        }else{
            current->next->front = new_node;
            new_node->next = current->next;
            current->next = new_node;
            new_node->front = current;
        }
    }
}

void link_list_delete(Node* &head, int num_to_delete){
    Node* node_to_delete =  a[num_to_delete];
    if(node_to_delete == nullptr){
        //此节点被删除时
        return;
    }
    if(node_to_delete->front == nullptr && node_to_delete->next == nullptr){
        //当只剩这一个节点时
        head = nullptr;
    }else if(node_to_delete == head){//头节点
        head = node_to_delete->next;
        head->front = nullptr;
    }else if(node_to_delete->next == nullptr){//尾节点
        node_to_delete->front->next = nullptr;
    }else{
        node_to_delete->front->next = node_to_delete->next;
        node_to_delete->next->front = node_to_delete->front;
    }
    a[num_to_delete] = nullptr;
    delete node_to_delete;
}

void print_link_list(Node* &head){
    Node* current = head;
    while(current != nullptr){
        std::cout << current->num << " ";
        current = current->next;
    }
}

int main(){
    int n;
    std::cin >> n;
    Node* head = create_node(1);
    a[1] = head;
    for(int i=2;i<=n;i++){
        int k,p;
        std::cin >> k >> p;
        link_list_insert(head,k,p,i);
    }
    int m;
    std::cin >> m;
    for(int i=0;i<m;i++){
        int x;
        std::cin >> x;
        link_list_delete(head,x);
    }
    print_link_list(head);
    std::cout << std::endl;
    return 0;
}