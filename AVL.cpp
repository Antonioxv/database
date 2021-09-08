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
    key_value getMax();
    key_value getMin();
    key_value deleteMax(string);            //删除key的子节点的最大值
    key_value deleteMin(string);            //删除key的子节点的最小值
    key_value floor(string);
    key_value ceiling(string);
private:
   Node* root;
   Node* insert(Node*, key_value);
};

void AVL::insert(string key, string value)
{
    key_value tmp = {key, value};
    insert(root, tmp);
}

Node* AVL::insert(Node* node, key_value tmp) 
{
    if (node == nullptr)return new Node(tmp);
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

