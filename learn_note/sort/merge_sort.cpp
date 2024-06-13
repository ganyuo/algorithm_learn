/**
 ************************************
 * @file     : merge_sort.cpp
 * @author   : ganyuo
 * @date     : 2024-06-03
 ************************************
 * @brief :
 *     归并排序的实现
 */

#include <stdio.h>

template <typename SORT_DATA_TYPE>
void merge_sort(SORT_DATA_TYPE array_[], int size_)
{
    if(size_ <= 1)
    {
        return;
    }
    int middle = size_ / 2;
    merge_sort(array_, middle);
    merge_sort(array_ + middle, size_ - middle);
    merge_data(array_, middle, size_);
}

int main()
{
    int array[] = {34, 82, 12, 65, 8, 72, 49, 28, 60};
    int a_len = sizeof(array) / sizeof(int);

    merge_sort(array, a_len);
    for(int i = 0; i < a_len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
