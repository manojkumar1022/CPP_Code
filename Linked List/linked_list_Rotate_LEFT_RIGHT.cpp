#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int val;
	Node* next;
	Node(int val)
	{
		this->val = val;
		next = NULL;
	}
};

Node* left_rotate(Node* head, int k)  //TC = O(n),  SC = O(1)
{
	if (head == NULL)
		return head;

	Node* temp = head;
	int n = 1;
	while (temp->next)
	{
		temp = temp->next;
		n++;
	}
	k = k % n;
	if (k == 0)
		return head;
	temp->next = head;

	Node* p = head;
	for (int i = 0; i < k - 1; i++)
		p = p->next;

	head = p->next;
	p->next = NULL;
	return head;

}

Node* right_rotate(Node* head, int k)    //TC = O(n),  SC = O(1)
{
	if (head == NULL)
		return head;

	Node* temp = head;
	int n = 1;
	while (temp->next)
	{
		temp = temp->next;
		n++;
	}
	k = k % n;
	if (k == 0)
		return head;
	temp->next = head;
	Node *p = head;
	for (int i = 0; i < (n - k - 1); i++)
	{
		p = p->next;
	}
	head = p->next;
	p->next = NULL;
	return head;
}


void printLL(Node* temp)
{

	while (temp)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	int val;
	cin >> val;
	Node* head = new Node(val);
	Node* tail = head;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> val;
		tail->next = new Node(val);
		tail = tail->next;
	}

	//head = left_rotate(head, k);
	head = right_rotate(head, k);
	printLL(head);
}