#include<iostream>

using namespace std;

class MaxPQ {
public:
    MaxPQ() {array = new int[1024];size = 0;}
    ~MaxPQ() {delete[] array;}
    void insert(int val);
    int deleMax();
    int getSize() {return size;}
private:
    int size;
    int* array;
    void sink(int pos);
    void swim(int pos);
    void exch(int i, int j);
};

void MaxPQ::exch(int i, int j) {
    int k = array[i];
    array[i] = array[j];
    array[j] = k;
}

void MaxPQ::sink(int pos) {
    int k = pos;
    while(k*2 <= size) {
        int j = k*2;
        if (j<size && array[j] < array[j+1])j++;
        if (array[j] < array[k])break;
        exch(k, j);
        k = k*2;
    }
}

void MaxPQ::swim(int pos) {
    int k = pos;
    while(k > 1 && array[k] > array[k/2]) {
        exch(k, k/2);
        k = k/2;
    }
}

void MaxPQ::insert(int value) {
    array[++size] = value;
    swim(size);
}

int MaxPQ::deleMax() {
    int res = array[1];
    exch(1, size--);
    array[size+1] = 0;
    sink(1);
    return res;
}

int main() {
    MaxPQ pq;
    pq.insert(1);
    pq.insert(7);
    pq.insert(2);
    pq.insert(4);
    pq.insert(8);

    while(pq.getSize()) {
        cout << pq.deleMax();
    }
}
