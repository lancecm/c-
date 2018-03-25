#include <iostream>

using namespace std;
class CMyString{
    public:
        CMyString(char* pData = nullptr);
        CMyString(const CMyString& str);
        ~CMyString(void);
    
    private:
        char* m_pData;
    
    //赋值运算符
    //1. 返回值的生命类型为该类型的引用
    //2. 传入的参数的类型声明为常量引用
    //3. 释放自身已有内存（否则会出现内存泄露）
    //4. 判断传入参数和当前实例是不是同一个实例，如果是直接返回
    CMyString& operator =(const CMyString &str){
        if(this== &str)
            return *this;
        
        //释放内存
        delete[] m_pData;
        m_pData = nullptr;
        
        m_pData = new char[strlen(str.m_pData)+1];
        strcpy(m_pData, str.m_pData);
        return *this;
    }

};