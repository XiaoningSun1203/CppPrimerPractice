#include <utility>

#include <iostream>
#include <vector>
using namespace std;

/**
 * heapify递归（三个节点中找出最大值，并对被改节点之下的节点重新heapify）
 * @param nums 每次传入的nums都比上一次少一个节点.
 * @param fath 是tree中某个节点的数组下标，意味着对index为父节点的三个节点做heapify.
 * @param heapSize  是传入的那个tree的大小.
 */
    void maxHeapify(vector<int>& nums, int fath, int heapSize) {
        // 为什么没准备递归出口？
        if(fath >= heapSize)
                {
                    return;
                }
        int left = fath * 2 + 1;//左孩子在树中的位置
        int right = fath * 2 + 2;
        int largest = fath;// 先假设三个节点中父节点数值最大
        // 先判断是否下标left和right出界（<heapSize）再比较大小
        if (left < heapSize && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < heapSize && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != fath) {
            swap(nums[fath], nums[largest]);
            maxHeapify(nums, largest, heapSize);
            // 由于swap会改变左或右孩子节点的值，于是被改节点可能不满足最大堆要求了，
            //需要在被改节点之下的节点重新heapify。
        }
    }

/**
 * 把数组改成最大堆
 */
    void buildMaxHeap(vector<int>& nums, int heapSize) {
        //从倒数第二层开始，往上每一个节点做heapify递归
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(nums, i, heapSize);
        }
    }

/**
 * 用 heap sort 最大堆搜索 来求第k大的值
 */
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize); // 第一大元素已出现，nums[0]
        // 第k大元素下标是nums.size() - k
        // for内执行完第一次，出现第二大元素，放在nums【0】，执行第二次出现第三大元素
        // 所以lastNode >= nums.size() - k + 1，是为了少执行一次
        // （溢出原因）这里nums.size()不能用heapSize代替，因为heapsize一直在变
        for (int lastNode = nums.size() - 1; lastNode >= nums.size() - k + 1; --lastNode) {
            // 提取最大值，方法：把最后一个节点值与顶点值（最大值）做交换
            swap(nums[0], nums[lastNode]);
            // 最后一个节点值已满足“目前最大值”要求，砍断
            --heapSize;
            // 每次固定好“目前最大值”后，把改过顶点的树重新做成最大堆
            maxHeapify(nums, 0, heapSize);

        }
        return nums[0];
    }
