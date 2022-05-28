#include "SubStringSearch.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

SubStringSearch::SubStringSearch(){}

SubStringSearch::~SubStringSearch(){}

int SubStringSearch::search(string s, string pattern)
{
    int matchNumber = 0;
    for(int i = s.length()-1; i >= pattern.length()-1; i--)
    {
        string sub = s.substr(i-pattern.length()+1, pattern.length());
        // cout<<sub<<endl;
        if(sub.compare(pattern) == 0)
        {
            matchNumber++;
        }
    }
    return matchNumber;
}



/* ***************************************************************************************** */
/* Rabin-Krap指纹字符串匹配算法 */
/* ***************************************************************************************** */
RabinKarp::RabinKarp(string pat):pattern(pat)
{
    M = pat.length();
    cout<<"pat lenght:"<<M<<endl;
    Q = longRandomPrime();
    patHash = hash(pat, M);
    for(int i = 1; i <= M-1; i++)
    {
        RM = (RM * R) % Q;  //RM = R^(M-1)
    }
    cout<<"RM: "<<RM<<endl;
}

RabinKarp::~RabinKarp(){}

unsigned long long RabinKarp::hash(string s, int m)
{
    unsigned long long ret = 0;
    for(int i = 0; i < m; i++)
    {
        ret = (ret*R + s.at(i)) % Q;
        // cout<<"ret:"<<ret<<endl;
    }
    return ret;
}

int RabinKarp::search(string s)
{
    int matchNumber = 0;
    int N = s.length();
    unsigned long long txtHash = 0;
    txtHash = hash(s, M);
    if(txtHash == patHash)
    {
        if(check(s.substr(0, M)))
        {
            matchNumber++;
            cout<<"match in index: 0\t substring:"<<s.substr(0, M)<<endl;
        }
    }

    for(int i = M; i < N; i++)
    {
        /**
         * 除Q取余两次降低冲突概率,额外加一个Q保证计算结果总是正数
         */
        txtHash = (txtHash + Q - RM * s.at(i-M) % Q) % Q; //减去最大的一个数;
        txtHash = (txtHash * R + s.at(i)) % Q;            //加上最后一个数字;
        // cout<<"txtHash:"<<txtHash<<"\tpatHash:"<<patHash<<endl;
        if(txtHash == patHash)
        {
            if(check(s.substr(i-M+1, M)))
            {
                matchNumber++;
                cout<<"match in index: "<<i-M+1<<"\t substring:"<<s.substr(i-M+1, M)<<endl;
            }
        }
    }
    return matchNumber;
}

unsigned long long RabinKarp::longRandomPrime()
{
    long long ret = 0;
    unsigned long long max = (long long)pow(10, 20);
    unsigned long long min = (long long)pow(10, 20) - pow(10, 19);
    srand((unsigned)time(NULL));
    while (1)
    {
        ret = (rand()%(max-min)) + min;
        if(judgePrime(ret))
        {       
            break;
        }
    }
    cout<<"Q is: "<<abs(ret)<<endl;
    return abs(ret);
}

bool RabinKarp::check(string s)
{
    return true;        //拉斯维加斯算法
}

bool RabinKarp::judgePrime(int p)
{
    int j;
    for(j = 2; j < sqrt(p); j++)
    {
        if(p%j == 0)
            break;
    }
    if(j > sqrt(p))
        return true;
    else
        return false;
}