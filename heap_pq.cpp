 #include<vector>
 #include<iostream>

class MaxPQ{
public:
    MaxPQ() = default;
    void insert(int value);
    int deleMax();
private:
    std::vector<int> arr;
    void sink(int k);
    void swim(int k);
};

void MaxPQ::swim(int k) {
    int pos = k;
    while(pos > 1 && arr[pos] > arr[pos/2])
    {
        //这是最大优先队列，较大的值在上面
        int tmp     = arr[pos];
        arr[pos]    = arr[pos/2];
        arr[pos/2]  = tmp;
        pos = pos/2;
    }
}

void MaxPQ::sink(int k) {
    //下沉操作，如果位于k的节点比其子节点要小，则下沉
    int pos     = k;
    int size    = arr.size();
    while(pos*2 <= size) {
         int j = pos*2;
         if (j < size && arr[j]<arr[j+1])j++;
         int tmp = arr[j];
         arr[j] = arr[pos];
         arr[pos] = tmp;
    }
}


int MaxPQ::deleMax() {
    //移除最大元素，并且返回
    int res = arr[0];
    arr[0]  = arr[arr.size() - 1];
    arr.pop_back();
    sink(0);
    return res;
}

void MaxPQ::insert(int value) {
    arr.push_back(value);
    swim(arr.size());
}
