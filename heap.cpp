#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <stack>
#include <cmath>
#define MAX 1000
#define EE 2.71828182846
#define PI 3.14159265359
#define ERROR -123
using namespace std;

int X[MAX], n;
//���ɼ��赱X[i+1, i+2, ... n]Ϊ��ʱ��ͨ��Push_down������X[i,...,n]��Ϊ��

//��������Ϊ��ʱ����Ӹ��ڵ㣬���¶ѡ�
void Push_down(int X[], int k, int n)
{
    if (2*k+1>n) return;
    if (2*k==n)
    {
        if (X[k]>=X[2*k]) return;
        swap(X[k], X[2*k]);
        return;
    }
    if (X[2*k]>X[2*k+1])
    {
        if (X[k]>=X[2*k]) return;
        swap(X[k], X[2*k]);
        Push_down(X, 2*k, n);
    }
    else
    {
        if (X[k]>=X[2*k+1]) return;
        swap(X[k], X[2*k+1]);
        Push_down(X, 2*k+1, n);
    }
}
//��X[]�����ѣ���Χ1~n��O(n)
void Build_heap(int X[], int n)
{
    for (int i=n/2+1; i>=1; i--)
        Push_down(X, i, n);
}

//������ O(nlogn)
void Heap_sort(int X[], int n)
{
    Build_heap(X, n);
    for (int i=n; i>0; i--)
    {
        Push_down(X, 1, i);
        swap(X[1], X[i]);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &X[i]);
    }
    Heap_sort(X, n);
    //Build_heap(X, n);
    for (int i=1; i<=n; i++)
    {
        printf("%d ", X[i]);
    }
    return 0;
}
