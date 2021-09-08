# 优先队列习题

## LeetCode 239-滑动窗口最大值

给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

* 示例

```
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

```

### 思路

先定义一个优先队列， 队列的值的类型是pair<int, int>

pair第一个存放的是值的大小，第二个存放的是值的位置， 再创建一个vector<int>存放结果

定义一个指针pos便利nums数组，如果pos - pq.top().first > k 就弹出pq顶部,保证了最大值在[pos-k, pos]中。

### 题解

#### Java版本

```java
public int[] maxSlidingWindow(int[] nums, int k) {
    int[] max_value = new int[nums.length - k + 1];
    Deque<Integer> deque = new LinkedList<Integer>();// first到last存的是从大到小的nums的index排列

    for (int i = 0; i < k; i++) {
        while (!deque.isEmpty() && nums[i] >= nums[deque.peekLast()]) {
            deque.pollLast();
        }
        deque.offerLast(i);
    }

    max_value[0] = nums[deque.peekFirst()];

    for (int i = k; i < nums.length; i++) {
        while (!deque.isEmpty() && nums[i] >= nums[deque.peekLast()]) {
            deque.pollLast();
        }

        deque.offerLast(i);

        while (deque.peekFirst() < i - k + 1) {// 当最大值不在窗口中，弹出，i-k+1 is the left side index of the window
            deque.pollFirst();
        }

        max_value[i - k + 1] = nums[deque.peekFirst()];
    }

    return max_value;
}
```
