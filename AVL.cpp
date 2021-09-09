#include<string>
#include<utility>
#include<iostream>
using namespace std;

typedef pair<string, string> key_value;

class Node {
public:
    Node(key_value val): value(val), deep(1), left(nullptr), right(nullptr){};
    key_value value;
    int deep;           //深度
    Node* left;
    Node* right;
};

class AVL {
public:
    void deleteValue(string);
    void insert(string, string);
    string search(string);
    string getMax();
    string getMin();
    key_value floor(string);
    key_value ceiling(string);
private:
   Node* root;
   Node* insert(Node*, key_value);
   Node* search(Node*, string);
   Node* deleteMax(Node*);            //删除key的子节点的最大值
   Node* deleteMin(Node*);            //删除key的子节点的最小值
   Node* leftTurn(Node*);
   Node* rightTurn(Node*);
};


//若key值存在则更新
void AVL::insert(string key, string value)
{
    key_value tmp = {key, value};
    root = insert(root, tmp);
}

Node* AVL::insert(Node* node, key_value tmp) 
{
    if (node == nullptr) {
        Node res = Node(tmp);
        return &res;
    }
    if (node->value.first == tmp.first) {
        //key值相等
        node->value.second = tmp.second;
    }
    else if (node->value.first > tmp.first) {
        //节点的值比插入的值要大，向右插入
        node->left = insert(node->left, tmp);
    }
    else{
        node->right = insert(node->right, tmp);
    }
    return node;
}

string AVL::search(string key) {
    Node* res = search(root, key);
    if (res == nullptr)return string();
    else return res->value.second;
}

Node* AVL::search(Node* node, string key) {
    if (node == nullptr)return nullptr;
    if (node->value.first > key) {
        //节点的值较大，则向右查询
        return search(node->right, key);
    }
    else if (node->value.first < key) {
        return search(node->left, key);
    }
    else {
        return node;
    }
}

string AVL::getMax() {
    Node* head = root;
    while(head!=nullptr)
    {
        if (head->right == nullptr)break;
        head = head->right;
    }
    return head == nullptr ? string() : head->value.second;
}

string AVL::getMin() {
    Node* head = root;
    while(head!=nullptr)
    {
        if (head->left == nullptr)break;
        head = head->left;
    }
    return head == nullptr ? string() : head->value.second;
}

Node* AVL::deleteMax(Node* node) {
    if (node->left == nullptr)return node->right;
    node->left = deleteMax(node->left);
    return node;
}

Node* AVL::deleteMin(Node* node) {
    if (node->right == nullptr)return node->left;
    node->right = deleteMin(node->right);
    return node;
}

Node* AVL::rightTurn(Node* node) {
    //右旋
    Node* new_node = node->left;
    Node* old_right = new_node->right;
    node->left = old_right;
    new_node->right = node;
}

Node* AVL::leftTurn(Node* node) {
    //左旋
    Node* new_node = node->right;
    Node* old_left = new_node->left;
    node->right = old_left;
    new_node->left = node;
}


