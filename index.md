# 优先队列的实现
## Thinking-基本思想
优先队列是一个数据结构，数据进入队列，并且按照权值的大/小顺序出队

## API-调用
* void insert(int val);  //用于插入数据
* int deleMax();         //用于删除数据，此处是按照最大的数据返回！
* int getSize();         //获取队列大小

## Code-实现
在实现insert 和 deleMax之前， 我们先定义两个队列操作，swim 和 sink（上浮和下沉），他们是我们实现队列的关键。
`void MaxPQ::sink(int pos) {
    int k = pos;
    while(k*2 <= size) {
        int j = k*2;
        if (j<size && array[j] < array[j+1])j++;
        if (array[j] < array[k])break;
        exch(k, j);
        k = k*2;
    }
}`
