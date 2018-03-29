#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int m_nKey; //值
    ListNode* m_pNext; //指向下一个节点的指针 
};

//逆向打印链表
//两种思路：1. 使用栈
//        2. 递归，控制输出的地方
void printListReversingly_Iteratively(ListNode* pHead){
    stack<ListNode*> nodes; //栈

    ListNode* pNode = pHead;
    while(pNode!=nullptr){ //注意，这里已经顺带解决了特殊值输入的问题
        nodes.push(pNode);
        pNode = pNode -> m_pNext;
    }

    while(!nodes.empty()){
        //这段代码用来输出（需要先返回，后删除）
        pNode = nodes.top(); //返回栈顶但不删除元素
        printf("%d\t",pNode->m_nKey);
        nodes.pop(); //从栈顶弹出一个成员
    }
}


// 递归方式
void printListReversingly_Recursively(ListNode* pHead) {

    // 注意这里是if条件。。
    if(pHead!=nullptr){
        // printf("测试：%d\t", pHead -> m_nKey);
        // printf("下一个%d\t", pHead -> m_pNext);
        if(pHead->m_pNext!=nullptr){
            printListReversingly_Recursively(pHead->m_pNext);
        }
        printf("%d\t", pHead -> m_nKey);
    }
}


int main(){
    // 构建链表
    ListNode * head = new ListNode();
    head -> m_nKey = 1;
    head -> m_pNext = nullptr;

    ListNode * next = new ListNode();
    next -> m_nKey = 5;
    next -> m_pNext = nullptr; 

    head -> m_pNext = next;

    
    printListReversingly_Iteratively(head);
    printListReversingly_Recursively(head);
}