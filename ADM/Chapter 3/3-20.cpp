#include<iostream>

using namespace std;

struct Node {
Node(const int data) : m_data(data), next(NULL) {}
int m_data;
Node* next;
};

Node* create_list(const int size) {
	
	if (size == 0)
		return NULL;

	Node *head = new Node(1);
	Node* tmp = head;

	for(int i = 2; i <= size; ++i) {
		tmp->next = new Node(i);
		tmp = tmp->next;
	}
	
	return head;
}
		
int find_mid(Node* head) { 

	if(head == NULL)
		return -1;

	Node *slow = head, *fast = head;
	
	while(fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow->m_data;
}
int main() {

	const int size1=10,size2=1,size3=2,size4=3,size5=4;
	Node* head1 = create_list(size1);
	Node* head2 = create_list(size2);
	Node* head3 = create_list(size3);
	Node* head4 = create_list(size4);
	Node* head5 = create_list(size5);
	
	cout << "Size of list: " << size1 << ", Mid of list is: " << find_mid(head1) << endl;
	cout << "Size of list: " << size2 << ", Mid of list is: " << find_mid(head2) << endl;
	cout << "Size of list: " << size3 << ", Mid of list is: " << find_mid(head3) << endl;
	cout << "Size of list: " << size4 << ", Mid of list is: " << find_mid(head4) << endl;
	cout << "Size of list: " << size5 << ", Mid of list is: " << find_mid(head5) << endl;
	
	return 0;
	
}