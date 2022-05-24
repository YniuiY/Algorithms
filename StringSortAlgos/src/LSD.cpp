#include "LSD.h"

LSD::LSD(){}

LSD::~LSD(){}

void LSD::sort(vector<string> &a, int w)
{
    int N = a.size();
    cout<<"a.size: "<<N<<endl;
    vector<string> aux(N, "0");
    vector<int> count(R+1, 0);
    
    cout<<"aux size:"<<aux.size()<<endl;
    cout<<"count size: "<<count.size()<<endl;

    /**
     * 每个字符串中的元素，从右向左依次作为键，参加排序 (字符串定长)
     */
    for(int i = w-1; i >= 0; i--)
    {
        /**
         * 统计这个键出现的频率
         */
        // cout<<"statistics\n";
        for(int j = 0; j < N; j++)
        {
            count[a[j].at(i) + 1]++;
            // cout<<"a[j].at(i): "<<a[j].at(i)<<endl;
        }

        /**
         * 频率转换成索引
         */
        // cout<<"frequence to index\n";
        for(int j = 0; j < R; j++)
        {
            count[j+1] += count[j];
        }

        /**
         * 按照索引分类
         */
        // cout<<"index calssfication\n";
        for(int j = 0; j < N; j++)
        {
            // cout<<"count index:"<<count[a[j].at(i)]<<"\tj: "<<j<<endl;
            // printf("a[j].at(i): %d\t %c\n",a[j].at(i), a[j].at(i));
            aux[count[a[j].at(i)]++] = a[j];
        }

        /**
         * 回写
         */
        // cout<<"write back\n";
        for(int j = 0; j < N; j++)
        {
            a[j] = aux[j];
        }

        for(int j = 0; j < R; j++)
        {
            count[j] = 0;
        }

        // cout<<"*********************\n"<<endl;
        // for(auto c: a)
        // {
        //     cout<<c<<endl;
        // }
        // cout<<"*********************\n"<<endl;

    }
}