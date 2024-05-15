/*撰寫一支具有輸入和刪除功能的程式。
i. 輸入功能：使用者每輸入一個整數，便將它按照由小到大的順序插入到Linked List中，然後將Linked List節點裡的值一一display到螢幕上。
ii. 刪除功能：使用者每輸入一個整數，便將Linked List所有相同數字的節點刪除；若List中無該數字，則不處理。最後將Linked List節點裡的值一一display到螢幕上。*/

#include "iostream"
#include "stdio.h"
#include "stdlib.h"

using namespace std;


typedef struct Node{
    int data;
    Node* next;
};

Node* first = nullptr;

void show()
{
    Node* nnode = first;
    while (nnode != nullptr)
    {
        cout << nnode->data << " ";
        nnode = nnode->next;
    }
}

void insert(int n)
{
    Node* nnode, *pre = nullptr, *cur=first;
    nnode = new Node;
    nnode->data = n;
    nnode->next = nullptr;
    if (cur)
    {
        while (cur != nullptr)
        {
            if (cur->data >= n)
            {
                if (cur == first)
                {
                    first = nnode;
                    nnode->next = cur;
                }
                else
                {
                    pre->next = nnode;
                    nnode->next = cur;
                }
                break;
            }
            pre=cur;
            cur = cur->next;
        }
        if (!cur)
        {
            pre->next = nnode;
        }
    }
    else
    {
        first = nnode;
    }
}

void Delete(int n)
{
    Node* nnode, * pre = nullptr, * cur = first;
    while (cur != nullptr)
    {
        if (cur->data == n)
        {
            if (cur == first)
            {
                first = cur->next;
                pre = cur;
            }
            /*else if (cur->next == nullptr)
            {
                pre->next = nullptr;
            }*/
            else
            {
                pre->next = cur->next;
            }
        }
        else
        {
            pre = cur;
        }
        
        cur = cur->next;
    }
}

int main() {
    int n;
    char a;
    while (1)
    {
        cout << "Input or Delete ? ";
        cin >> a;
        if(a == 'I' || a == 'i')
        {   

            cout << "Input an integer ?";
            cin >> n;
            insert(n);
            show();
        }
        else if(a == 'D' || a == 'd')
        {
            cout << "Delete which integer?";
            cin >> n;
            Delete(n);
            show();
        }
        else
        {
            cout << "error";
        }
    }
    


}
