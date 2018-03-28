#include <iostream>
using namespace std;

// 计算范围内有多少个属于范围的值
int countRange(const int* numbers, int length, int start, int end){
    if (numbers == nullptr)
        return 0;
    int count = 0;
    for(int i=0; i<length; i++){
        if(numbers[i]>=start && numbers[i]<=end)
            ++count;   
    }
    return count;
}

//在一个长度为n+1的数组里所有的数字都在1~n范围内，数组中至少有一个数字是重复的。
//请找出数组中任意一个重复的数字，但不能修改输入数组
int getDuplication(const int*numbers, int length){
    // 验证输入条件
    if(numbers==nullptr||length<0) return -1;

    int start = 1;        //最小
    int end = length-1;   //最大
    while(end>=start){
        int middle = ((end-start)>>2)+start; //防止值移除；中间值
        
        // 在start-middle这个数值段有count个数
        int count = countRange(numbers, length, start, middle);
        // 如果范围缩小至不能再缩小了，看是不是有重复值
        if(end == start){
            if(count>1)
                return start;
            else
                break;
        }
        // 重复数在左区间
        if(count > (middle-start+1))
            end = middle;
        // 重复数在右区间
        else
            start = middle+1;
    }
    //没有重复值
    return -1;
}

int main(){
    int numbers[] = {1,2,2,3,4,5};
    int result = getDuplication(numbers, 6);
    cout<<result;
}

