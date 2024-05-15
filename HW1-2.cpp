/*׫��һ֧����ݔ��̈́h�����ܵĳ�ʽ��
i. ݔ�빦�ܣ�ʹ����ÿݔ��һ���������㌢��������С����������뵽Linked List�У�Ȼ�ጢLinked List���c�e��ֵһһdisplay��ΞĻ�ϡ�
ii. �h�����ܣ�ʹ����ÿݔ��һ���������㌢Linked List������ͬ���ֵĹ��c�h������List�Пoԓ���֣��t��̎�����ጢLinked List���c�e��ֵһһdisplay��ΞĻ�ϡ�*/

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
