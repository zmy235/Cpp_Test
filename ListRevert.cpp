#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class ListNode
{
public:
	int value;
	ListNode* next;
	ListNode(int v)
	{
		value=v;
		next=NULL;
	}
};

void show(ListNode* head)
{
	while(head)
	{
		cout<<head->value<<"\t";
		head=head->next;
	}
}

ListNode* build(int n)
{
	ListNode* temp = new ListNode(0);
	ListNode* head = temp;
	while(n-->0)
	{
		cin>>head->value;
		if(n!=0)head->next= new ListNode(0);
		head=head->next;
	}
	return temp;
}

void reverse(ListNode* head)
{
	ListNode* temp = new ListNode(0);
	ListNode* current = head->next;
	if(head) temp->next=head;
	while(current)
	{
		head->next = current->next;
		current->next = temp->next;
		temp->next = current;
		current=head->next;
	}
	show(temp->next);
}

int main()
{
	ListNode* head=build(5);
	show(head);
	cout<<endl;
	reverse(head);
	return 0;
}
