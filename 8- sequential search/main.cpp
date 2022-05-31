#include <iostream>

using namespace std;

int SequentialSearch(int target,int size, int arr[5]){
    for(int i = 0; i < size; i++){
        if (target == arr[i]){
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[5] = {0 ,1, 2, 3, 4};
    cout << SequentialSearch(1, 5, arr);

    return 0;
}
