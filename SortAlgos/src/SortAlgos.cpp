#include <SortAlgos.h>
using namespace std;

SortAlgos::SortAlgos(int N):N_(N)
{
    std::default_random_engine randomEngine;
    
    for(int i = 0; i < N; i++)
    {
        nums.push_back(randomEngine());
        temp.push_back(0);
    }

    // show();
}

SortAlgos::SortAlgos(int N, int M):N_(N),M_(M)
{
    std::default_random_engine randomEngine;
    
    for(int i = 0; i < N; i++)
    {
        nums.push_back(randomEngine());
        temp.push_back(0);
    }

    
}

SortAlgos::~SortAlgos(){}

// 选择排序
void SortAlgos::checkSort()
{
    int minPos;
    for(int i = 0; i < N_; i++)
    {
        minPos = i;
        for(int j = i + 1; j < N_; j++)
        {
            if(nums[minPos] > nums[j])
            {
                swap(minPos,j);
            }
        }
    }
}

// 插入排序
void SortAlgos::insertSort(int left, int right)
{
    int N = right - left + 1;
    if(N <= 1) return;
    // cout<<"insertSort "<<"left: "<<left<<"\t right: "<<right<<endl;
    for(int i = left + 1; i < left + N; i++)
    {
        for(int j = i; j >= left; j--)
        {
            if(nums[j] < nums[j-1])
            {
                swap(j,j-1);
            }
        }
    }

    // show();
}

/**
 * 归并和快排都是分治思想的产物，
 * 区别在于归并每次都是等分数组，并将两个数组归并成有序的数组
 * 快排是根据中间值的大小切分数组。并且当所有切分的数组内有序时，整个大数组都将有序。
 */

//快速排序 
void SortAlgos::quickSort(int startPos, int endPos)
{
    // cout<<"quickSort: "<<"startPos:"<<startPos<<"\t endPos:"<<endPos<<endl;
    // if(startPos >= endPos - M_)
    if(endPos < startPos +  M_)
    {
        // cout<<"mergSort\n";
        // mergeSort(startPos, endPos);
        insertSort(startPos, endPos);
        return;
    }
    int bPos = startPos + 1;
    int ePos = endPos;
    int midValue = nums[startPos];

    while(true)
    {
        while(nums[bPos] < midValue && bPos != endPos)
        {
            bPos++;
        }
        while(nums[ePos] > midValue && ePos != startPos)
        {
            ePos--;
        }
        if(bPos >= ePos)
        {
            break;
        }

        swap(bPos, ePos);
    }

    // 结束上面的循环时 bPos >= ePos，即ePos可能在bPos的左边 或指向相同的位置。
    if(ePos != startPos)
    {
        // 在这个工程中，startPos是数组最左边的数字，结束时应该和bPos/ePos中最左边的那个交换
        // 这样才能满足左侧的数字都小于midValue，右侧数字都大于midValue
        swap(ePos, startPos);
    }
    quickSort(startPos, ePos - 1);
    quickSort(ePos + 1, endPos);

}

void SortAlgos::quick3WaySorty(int lo, int hi)
{
    int le = lo, ri = hi;
    int i = lo + 1;
    int v = nums[lo];

    while(i <= ri)
    {
        if(nums[i] < v)
        {
            swap(le++, i++); //小于v的放到数组前面
        }
        else if(nums[i] > v)
        {
            swap(i, ri--); //大于v的放到数组后面
        }
        else
        {
            i++;        //等于v的就留在数组中间
        }
    }

    /* 递归的切分数组，分成小数组再切分，长度2，3的小数组会有序，最后合并成有序的大数组 */
    sort(lo, le-1);
    sort(ri+1, hi);
}

// 归并排序
void SortAlgos::mergeSort(int left, int right)
{
    // cout<<"mergSort\n";
    if(left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    // cout<<"mid: "<<mid<<"\t left:"<<left<<"\t right: "<<right<<endl;
    /**
     * 递归的拆分数组，直到数组只有一个元素return
     * 从有两个元素的数组开始merge。
     * 最后一次执行merge前可以得到两个本身有序的数组。
     * 再将两个数组中的元素区分根据相对大小填入目标数组就可以得到整体有序数组。
     *  */ 
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void SortAlgos::merge(int left, int mid, int right)
{
    // cout<<"left: "<<left<<"\t right: "<<right<<endl; 
    for(int i = left; i <= right; i++)
    {
        temp[i] = nums[i];
    }

    int x = left, y = mid+1;

    for(int k = left; k <= right; k++)
    {
        if(x > mid)
        {
            nums[k] = temp[y++];//左边的都小于右边的，则直接将右半边拷贝到目标数组
        }
        else if(y > right)
        {
            nums[k] = temp[x++];//右边的都大于左边的，则直接将左半边拷贝到目标数组
        }
        else if(temp[x] < temp[y])
        {
            nums[k] = temp[x++];// 左右两边的数组哪个小哪个先进目标数组
        }
        else
        {
            nums[k] = temp[y++];
        }

    }
}

bool SortAlgos::isSorted()
{
    cout<<"\nis Sorted?\n\n";
    bool ret = true;
    for(int i = 0; i < N_ - 1; i++)
    {
        // cout<<nums[i]<<", "<<endl;
        if(nums[i] > nums[i+1])
        {
            ret = false;
        }
    }
    // show();
    return ret;
}

void SortAlgos::swap(int pos1, int pos2)
{
    // cout<<"Swap pos1:"<<pos1<< "  pos2:"<<pos2<<endl;
    // cout<<"Swap "<<nums[pos1]<<" "<<nums[pos2]<<endl;
    int tmp = nums[pos1];
    nums[pos1] = nums[pos2];
    nums[pos2] = tmp;
}

void SortAlgos::show()
{
    cout<<endl;
    for(auto a: nums)
    {
        std::cout<<a<<endl;
    }
    cout<<endl;
}