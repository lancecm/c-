#include <iostream>
using namespace std;

// 在一个二维数组中，每一行窦从左到右递增排列，每一列从上到下递增排列。
// 完成算法：输入二维数组和一个整数，判断数组中是否含有该整数。
bool Find(int* matrix, int rows, int columns, int number){
    bool found = false;
    // 检查合规
    if(matrix==nullptr||rows<=0||columns<=0){
        cout << "输入有误！" << endl;
    }
    else{
        for(int i=0, j=columns-1; i>=0 &&j<=columns-1;){
            int current = matrix[i*columns+j];
            cout<<"查找值：" << current <<endl;
            // 如果相等
           if( current == number){
               found = true;
               break;
           }
           // 如果当前值比查找值大
           if( current > number) --j;
           if( current < number) ++i;
        }
    }
    return found;
}

int main(){
    int matrix[] = {1,2,8,9,
                    2,4,9,12,
                    4,7,10,13,
                    6,8,11,15};
    bool result = Find(matrix,4,4,6);
    cout <<"结果为 "<< result<<endl;

    // int* matrix2 = NULL;
    bool result2 = Find(matrix,0,0,0);
    cout <<"结果为 "<< result2<<endl;


}