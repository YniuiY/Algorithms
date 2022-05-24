#ifndef QUICKSORT_H_
#define QUICKSORT_H_

/* 
    快速排序算法：
        1、从数组中找出任意一个数tmp，最理想情况下这个数是数组中元素的中值；
        2、从数组的左右两端开始遍历；
        3、左边遇到大于等于tmp的停下，右边遇到小于tmp的停下，交换左右着两个数，
            直到左右下标交错或相等，将tmp赋值给这个下标；
        4、这时左边的数组都小于tmp，右边的数组都大于tmp;然后分为左右两个数组再次重复上述步骤（递归）
        5、直到数组大小等于1时，排序完成。

        时间复杂度:
        最理想：O(n * log(n))
        最差:  O(n^2)

        空间复杂度：
            O(n * log(n))
 */

#include <iostream>
using namespace std;

// template<typename Type>
class QuickSort
{
private:
    /* data */
    void swap(int *&array,int i, int j)
    {
        cout<<"swap beg: "<<array[i]<<" "<<array[j]<<endl;
        // cout<<"swap()"<<endl;
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        cout<<"swap end: "<<array[i]<<" "<<array[j]<<endl;
    }
public:
    QuickSort(){}
    ~QuickSort(){}

    void sort(int* array, int beg, int end)
    {
        cout<<"beg: "<<beg<<" end: "<<end<<endl;
        if(beg < end)
        {
            int tmp = array[beg];
            int i = beg + 1;
            int j = end;
            while (i < j)
            {
                while(i < j && array[j] > tmp)
                {
                    j--;
                }
                while(i < j && array[i] <= tmp)
                {
                    i++;
                }
                if(i != j)
                {
                    swap(array, i, j);
                }
            }
            //结束上面的循环时 i >= j，因为中间的两个while循环条件都是i<j才进行，当i>=j时就跳出循环了。
            cout<<"i: "<<i<<endl;
            cout<<"j: "<<j<<endl;
            swap(array, i, beg);

            sort(array, beg, i - 1);
            sort(array, j + 1, end);

        }

        cout<<"QSort end"<<endl;
    }
};


#endif