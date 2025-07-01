//选择左右，那就需要双链表来实现
#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* front;
};

Node* pos[100001];

Node* create_node(int data=0){
    Node* new_node = new Node;
    new_node->next = nullptr;
    new_node->front = nullptr;
    new_node->data = data;
    return new_node;
}

void link_list_insert(Node* &head,int data,int n,int p){
    Node* new_node = create_node(data);
    pos[data] = new_node;
    Node* current = pos[n];
    if(p==0){//往head的左边插入
        if(current == head){ //插入的成为新的头节点；
            head->front = new_node;
            new_node->next = head;
            head = new_node;
            return;
        }
        current = current->front;
        new_node->front = current;
        new_node->next = current->next;
        new_node->next->front = new_node;
        new_node->front->next = new_node;
    }
    if(p==1 ){                          //右插入
        if(current->next == nullptr){//代表这个是最后一个  类似尾插法
            current->next = new_node;
            new_node->front = current;
            return;
        }
        new_node->front = current;
        new_node->next = current->next;
        new_node->next->front = new_node;
        new_node->front->next = new_node;
    }
}

void link_list_delete(Node* &head, int data_to_delete){
    Node* current = pos[data_to_delete];
    if(current == nullptr){
        return;
    }
    // 2. 处理前一个节点的 next 指针
    if (current->front != nullptr) {
        // 如果存在前一个节点，就让它的 next 指向 current 的下一个节点
        current->front->next = current->next;
    } else {
        // 如果不存在前一个节点，说明 current 就是头节点，需要更新 head
        head = current->next;
    }
    // 3. 处理后一个节点的 front 指针
    if (current->next != nullptr) {
        // 如果存在后一个节点，就让它的 front 指向 current 的前一个节点
        current->next->front = current->front;
    }
    delete current;
    pos[data_to_delete] = nullptr;
}

void print_list(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* current = head;
    while(current != nullptr){
        std::cout << current->data << " ";
        current=current->next;
    }
    std::cout << std::endl;
}

int main(){
    int n;
    std::cin >> n;
    Node *head = create_node(1);//默认至少有一位同学，直接创建头节点
    pos[1] = head; 
    head->next = nullptr;
    head->front = nullptr;
    for(int i=2;i<=n;i++){
        int k,p;
        std::cin>>k>>p;
        link_list_insert(head,i,k,p);
    }
    int m;
    std::cin >> m;
    for(int i=0;i<m;i++){
        int num;
        std::cin >> num;
        link_list_delete(head,num);
    }
    print_list(head);
    return 0;
}