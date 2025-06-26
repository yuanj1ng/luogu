#include <iostream>

struct Node {
    int data=0;           // 数据域（以int为例）
    struct Node* next;  // 指针域
};


Node* create_node(int data=0){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void insert_tail(Node *&head,Node *&end,int key=0){
    Node* new_node = create_node(key);
    if (head == nullptr) {
        head = new_node;
        end = new_node;
        new_node->next = new_node; // 自身形成循环
    } else {
        new_node->next = head;  //head是一个地址（之前最前面的node），让链表新加入指向之前的最前面的node
        end->next = new_node;    //head是一个地址，存的是第一个node的地址
        end = new_node;
    }
}


void create_link_list(int n,Node*& head,Node*& end){
    head = nullptr; // 初始化头指针
    end = nullptr;  // 初始化尾指针
    if (n <= 0) return ;
    for (int i = 1; i <= n; ++i) { // 修正: 从1开始循环，方便输入
        insert_tail(head, end, i); // 调用尾插函数
    }
}

void link_list_delete_node(Node*& head,Node*& end,Node* node_to_delete){
    if(head == end && head == node_to_delete){ //如果只有一个节点，也就是说head=end；
        delete head;
        head = nullptr;
        end = nullptr;
        return;
    }
    Node* current = head;
    while(current->next != node_to_delete){//找到current->next 指向d
        current =current->next;
        if (current == head) {
            // 如果遍历了一圈都没找到，说明要删除的节点不在链表中
            std::cout << "Error: Node to delete not found in the list." << std::endl;
            return;
        }
    }
    current->next = node_to_delete->next; //让delete前面结点的指向delete后面的结点
    if(node_to_delete == end){  //如果删除的是尾结点，需要更新尾结点
        end = current;
    }
    if(node_to_delete == head){ //如果删除的是头结点，需要更新头结点
        end->next = head->next;
        head = head->next;
    }
    delete node_to_delete;
}

int main(){
    int n,m;
    std::cin >> n >> m;
    Node* head = nullptr,*end = nullptr;
    create_link_list(n, head, end);
    int num = 1;
    Node* current = head;
    while(head != end){
        if(num==m){
            std::cout << current->data << " ";
            Node* temp = current->next;
            link_list_delete_node(head,end,current);
            current = temp ;
        }else{
            current = current->next;
        }
        num = num % m + 1;
    }
    std::cout << head->data << std::endl;
    return 0;
}