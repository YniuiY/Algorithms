#include "MyHeap.h"
using namespace std;

MyHeap::MyHeap(int N):N_(N),M(0)
{
    nums.push_back(0);  // 数组的第0个位置空置
}

MyHeap::MyHeap():N_(0),M(0)
{
    nums.push_back(0);  // 数组的第0个位置空置
}

MyHeap::~MyHeap(){}

/**
 * 在数组末尾插入的数字，上浮到正确位置
  */
void MyHeap::swim(int k)
{
    // cout<<"swim :"<<k<<endl;
    while(k > 1)
    {
        // cout<<"k: "<<k<<endl;
        if(nums[k] > nums[k/2])
        {
            swap(k, k/2);
            k = k/2;
        }
        else
        {
            break;
        }
    }
    // cout<<"swim over\n";
}

/**
 * 删除根节点后，将最下层的最右一个节点放到根节点位置，
 * 使用sink函数下沉到正确的位置。
 * 思路是：让根节点和两个子节点中最大的一个比较，如果根节点小于子节点则swap。
  */
void MyHeap::sink(int k)
{
    while(2 * k <= N_)
    {
        int j = 2 * k;
        if(nums[2 * k] < nums[2 * k + 1])
        {
            j++;
        }
        if(nums[k] < nums[j])
        {
            swap(k, j);
        }
        k = j;
    }
}

void MyHeap::swap(int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void MyHeap::insert(int value)
{
    // cout<<"insert value: "<<value<<endl;
    nums.push_back(value);
    N_++;
    M++;
    swim(N_);
}

/**
 * delMax还有问题--2022.04.08
 */
int MyHeap::delMax()
{
    // cout<<"delMax\n";
    int ret = nums[1];
    nums[1] = nums[N_];
    nums.pop_back();
    N_--;
    sink(1);
    return ret;
}

void MyHeap::sort()
{
    // cout<<"M: "<<M<<endl;
    for(int i = 0; i < M; i++)
    {
        stk.push(delMax());
    }
    
    // cout<<"\n========================= \n";
    // int size = stk.size();
    // while(size-- > 0)
    // {
    //     cout<<stk.top()<<endl;
    //     stk.pop();
    // }
    // cout<<"==========================\n";
}

void MyHeap::show()
{
    cout<<"======== Heap Show ===========\n";
    for(auto a : nums)
    {
        cout<<a<<endl;
    }
    cout<<"======== Over ============\n";
}

bool MyHeap::isSorted()
{
    for(int i = 0; i < M; i++)
    {

    }
    return false;
}