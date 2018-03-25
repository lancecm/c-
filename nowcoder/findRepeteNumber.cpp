#include <iostream>
using namespace std;

// 在一个长度为n的数组中的所有数字都在0~n-1的范围内，数组中有些数字是重复的，但不知道有几个数字是重复的。请找出数组中任意一个重复的数字。
bool duplicate(int numbers[], int length, int* duplication) {
    // 保证题目条件
    if(numbers == nullptr || length <=0) 
        return false;
    for(int i=0; i<length; i++){
        if(numbers[i]<0 || numbers[i]>length-1)
            return false;
    }

    for(int i=0; i<length; i++){
        while(numbers[i]!=i){
            // 该数字（m）在i处和m处出现过, 则表示重复了，返回该数字
            if(numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }
            //排序; 把该数字交换到它对应的下标位置，即交换numbers[numbers[i]]和numbers[i]
            int temp = numbers[i];      //temp = numbers[i] 
            numbers[i] = numbers[temp]; //numbers[i] = numbers[numbers[i]]
            numbers[temp] = temp;       //numbers[numbers[i]] = temp
        }
    }

    return false;

}

//简易测试
int main(){
    int duplication;
    int numbers[] = {2,3,4,1,3,1,55,55};
    int length = length(numbers);
    bool j = duplicate(numbers, length, &duplication);
    cout<<j<<" "<<duplication;
    return 0;
}


