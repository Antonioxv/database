# 优先队列的实现
## Thinking-基本思想
优先队列是一个数据结构，数据进入队列，并且按照权值的大/小顺序出队

## API-调用
* void insert(int val);  //用于插入数据
* int deleMax();         //用于删除数据，此处是按照最大的数据返回！
* int getSize();         //获取队列大小

## Code-实现
在实现insert 和 deleMax之前， 我们先定义两个队列操作，swim 和 sink（上浮和下沉），他们是我们实现队列的关键。

* sink 下沉操作，将队列比拟成一个树，pos的两个子节点的权值比pos位置的权值大的话， 就要和那个最大的子节点进行交换，直到pos的值到达合适的位置。
```
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
```

* swim 上浮操作， 同样将队列比你成一个树， pos的父节点要是比pos的权值小的话，pos就要上升，直到pos的值到达合适的位置。
 ```
 void MaxPQ::swim(int pos) {
    int k = pos;
    while(k > 1 && array[k] > array[k/2]) {
        exch(k, k/2);
        k = k/2;
    }
}

```


* insert 操作，将要插入的节点放入数组尾端，让后上浮到合适的位置即可。
```
void MaxPQ::insert(int value) {
    array[++size] = value;
    swim(size);
}

```


* deleMax操作，将返回头节点（因为上浮操作可知，头节点的值最大），然后把尾节点放入头部，再下沉。

```
int MaxPQ::deleMax() {
    int res = array[1];
    exch(1, size--);
    array[size+1] = 0;
    sink(1);
    return res;
}
```



