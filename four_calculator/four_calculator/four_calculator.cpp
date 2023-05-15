// four_calculator.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<string>
using namespace std;
float cal(string n) {
    float num[100];
    char cha[100];
    float t = 0;
    int count_num=0, count_cha=0;
    for (int i = 0; i < n.size(); i++) {
        
        switch (n[i])
        {case '+':
            num[count_num] = t;
            cha[count_cha] = '+';
            count_num++;
            count_cha++;
            t = 0;
            break;
        case '-':
            num[count_num] = t;
            cha[count_cha] = '-';
            count_num++;
            count_cha++;
            t = 0;
            break;
        case '*':
            num[count_num] = t;
            cha[count_cha] = '*';
            count_num++;
            count_cha++;
            t = 0;
            break;
        case '/':
            num[count_num] = t;
            cha[count_cha] = '/';
            count_num++;
            count_cha++;
            t = 0;
            break;
        default:
            t = t * 10 + (n[i] - '0');
            break;
        }
        

    }
    if (t != 0) {
        num[count_num] = t;
        count_num++;
    }
    float temp = 0;
    bool k = false;
    int index=-1;
    for (int i = 0; i < count_cha; i++) {
        if (cha[i] == '*' && k == false) {
            
            temp = num[i] * num[i + 1];
            index = i;
            k = true;
            //num[i + 1] = temp;
        }
        else if (cha[i] == '/' && k == false) {
            temp = num[i] / num[i + 1];
            index = i;
            k = true;
            //num[i + 1] = temp;
        }
        else if (cha[i] == '*' && k == true) {
            temp = temp * num[i + 1];
        }
        else if (cha[i] == '/' && k == true) {
            temp = temp / num[i + 1];
        }
        else if((cha[i]=='+'||cha[i]=='-')&&k==true) {
            k = false;
            
        }
        if (index != -1) {
            num[index] = temp;
        }
        
        
    }
    temp = num[0];
    for (int i = 0; i < count_cha; i++) {
        if (cha[i] == '+') {
            temp =temp+num[i + 1];
            
        }
        else if (cha[i] == '-') {
            temp = temp - num[i + 1];
            
        }
    }
    return temp;
}
int main()
{
    string str;
    cin >> str;
    string str1;

    cout<<cal(str);
    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
