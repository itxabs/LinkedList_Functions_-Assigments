#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* pre;
	Node(int val) {
		data = val;
		next = NULL;
		pre = NULL;
	}
};
class SinglyLinked
{
public:
	Node* head;
	SinglyLinked()
	{
		head = NULL;
	}

	//Add 1st for singly linked list
	void add1st(int value)
	{
		Node* newnode = new Node(value);
		newnode->next = head;
		head = newnode;
	}
	//Add last for singly linked list
	void addend(int value)
	{
		Node* newnode = new Node(value);

		if (head == NULL)
		{
			head = newnode;
			return;
		}

		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
	// Delete 1st for singly linked list
	void delete1st() {
		if (head == NULL)
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		delete(temp);
	}
	// Delete last for singly linked list
	void deleteEnd()
	{
		if (head == NULL)
		{
			return;
		}
		Node* second_L_node = head;
		while (second_L_node->next->next != NULL)
		{
			second_L_node = second_L_node->next;
		}
		Node* temp = second_L_node->next;
		second_L_node->next = NULL;
		delete temp;

	}
	// insertAt for singly linked list
	void insertAt(int val, int pos) {

		if (pos == 1 || head == NULL) {
			add1st(val);  // Assuming there is a function named add1st
			return;
		}
		Node* newnode = new Node(val);
		Node* temp = head;
		int cur_pos = 0;
		while (cur_pos != pos - 1) {
			temp = temp->next;
			cur_pos++;
		}
		// Now temp points to the node at position pos - 1
		newnode->next = temp->next;
		temp->next = newnode;
	}
	// Reverse for singly linked list
	void reverseLL()
	{
		Node* curptr = head;
		Node* preptr = NULL;
		while (curptr != NULL)
		{
			Node* nextptr = curptr->next;
			curptr->next = preptr;
			preptr = curptr;
			curptr = nextptr;
		}
		//when this loop end,preptr pointing to  the new head;
		head = preptr;
	}
	// display for singly linked list
	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << " NULL\n";
	}
	// maximum for singly linked list
	int max()
	{
		if (head == NULL)
		{
			cout << "No Element in List" << endl;
		}
		else
		{
			Node* temp = head;
			int max = temp->data;
			while (temp != NULL)
			{
				if (temp->data > max)
				{
					max = temp->data;
				}
				temp = temp->next;

			}

			return max;
		}
	}
	// search for singly linked list
	int search(int value)
	{
		if (head == NULL)
		{
			cout << "List is Empty" << endl;
		}
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == value)
				cout << "Founded" << endl;
			else
				cout << "Not Found" << endl;

			temp = temp->next;
		}
		return 0;

	}
	// countNodes for singly linked list
	int countNodes()
	{
		Node* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	//average for singly linked list
	int average()
	{
		Node* temp = head;
		int sum = 0;
		while (temp != NULL)
		{
			sum = sum + temp->data;
			temp = temp->next;
		}
		return sum / countNodes();//coutNodes is function which count the number of nodes
	}
	// detectLoop  for singly linked list
	bool detectLoop() {
		if (head == NULL)
		{
			return false;
		}
		Node* slow = head;
		Node* fast = head;
		while (slow && fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
	// paindrome
	bool Palindrome()
	{
		//1. find middle of LL
		Node* slow = head;
		Node* fast = head;
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		} //now slow is pointing to middle element

		//2. break LL into middle
		Node* curr = slow->next;
		Node* pre = slow;
		slow->next = NULL;

		//3. To reverse 2nd half LL
		while (curr != NULL)
		{
			Node* nextnode = curr->next;
			curr->next = pre;
			pre = curr;
			curr = nextnode;
		}

		//4. Compare two parts of linked list
		Node* head1 = head;
		Node* head2 = pre;
		while (head2 != NULL)
		{
			if (head1->data != head2->data)
			{
				return false;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
		return true;
	}

};

class Doubly {
public:
	Node* head;
	Node* end;
	Doubly() {
		head = NULL;
		end = NULL;
	}
	~Doubly() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void Display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " <> ";
			temp = temp->next;
		}cout << endl;
	}
	// Add 1st for 2bly linked list
	void Add1st(int val)
	{
		Node* newnode = new Node(val);
		if (head == NULL)
		{
			head = newnode;
			end = newnode;
			return;
		}
		newnode->next = head;
		head->pre = newnode;
		head = newnode;
		return;
	}
	// Add End for 2bly linked list
	void AddEnd(int val)
	{

		Node* newnode = new Node(val);
		if (end == NULL)
		{
			head = newnode;
			end = newnode;
			return;
		}
		end->next = newnode;
		newnode->pre = end;
		end = newnode;
		return;
	}
	// Delete 1st for 2bly linked list
	void delete1st()
	{
		if (head == NULL)
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head == NULL)
		{
			end = NULL;
		}
		else {
			head->pre = NULL;
		}
		delete temp;
	}
	// Delete end for 2bly linked list
	void deleteEnd()
	{
		if (head == NULL)
		{
			return;
		}
		Node* temp = end;
		end = end->pre;
		if (end == NULL)
		{
			head = NULL;
		}
		else {
			end->next = NULL;
		}

		delete temp;
		return;
	}
	// insert At for 2bly linked list
	void InsertAt(int val, int pos)
	{
		if (pos == 1 || head == NULL)
		{
			Add1st(val);
		}
		Node* temp = head;
		int count = 1;
		while (count < (pos - 1))
		{
			temp = temp->next;
			count++;
		}
		//temp will pointing the node (k-1)th pos;
		Node* newnode = new Node(val);
		newnode->next = temp->next;
		temp->next = newnode;
		newnode->pre = temp;
		newnode->next->pre = newnode;
		return;
	}
	// Reverse for 2bly linked list
	void ReverseDll() {
		Node* currptr = head;
		Node* temp = NULL;

		while (currptr != NULL) {

			temp = currptr->pre;
			currptr->pre = currptr->next;
			currptr->next = temp;

			currptr = currptr->pre;
		}
		if (temp != NULL) {
			head = temp->pre;
		}
	}
	int max()
	{
		if (!head)
		{
			return 0;
		}
		else {
			Node* temp = head;
			int max = head->data;
			while (temp != NULL)
			{
				if (temp->data > max)
				{
					max = temp->data;
				}
				temp = temp->next;

			}
			return max;
		}
	}
	//funtion which search the element and return the element.
	int search(int value)
	{
		if (head == NULL)
		{
			cout << "Doubly List is Empty" << endl;
		}
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == value)
				cout << "Founded" << endl;
			else
				cout << "Not Founded" << endl;

			temp = temp->next;
		}
		return 0;
	}
	int countNodes()
	{
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			Node* temp = head;
			int count = 0;
			while (temp != NULL)
			{
				count++;
				temp = temp->next;
			}
			return count;
		}
	}
	//funtion which find the average pof the data in the nodes of linkedlist.
	int average()
	{
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			Node* temp = head;
			int sum = 0;
			while (temp != NULL)
			{
				sum = sum + temp->data;
				temp = temp->next;
			}

			return sum / countNodes();//coutNodes is function which count the number of nodes
		}
	}
	bool detectLoop() {
		Node* slow = head;
		Node* fast = head;
		while (slow && fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
};
//Circlar 1ingly LL
class Cir1lyLL
{
private:
	Node* head;
public:

	Cir1lyLL()
	{
		head = NULL;
	}

	void display()
	{
		if (!head) {
			return;
		}
		// the do-while loop is chosen to ensure that the loop body is executed at least once, 
		Node* temp = head;
		do {
			cout << temp->data << "->";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}
	// Add1st for circular 1ingly linked list
	void Add1st(int value)
	{
		Node* newnode = new Node(value);
		if (head == NULL)
		{
			head = newnode;
			newnode->next = head;
			return;
		}
		Node* end = head;
		while (end->next != head)
		{
			end = end->next;
		}
		end->next = newnode;
		newnode->next = head;
		head = newnode;
	}
	// AddEnd for circular 1ingly linked list
	void AddEnd(int value)
	{

		Node* newnode = new Node(value);
		if (head == NULL)
		{
			head = newnode;
			newnode->next = head;// circular linked list
			return;
		}
		Node* tail = head;
		while (tail->next != head)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		newnode->next = head;
	}
	// delete1st for circular 1ingly linked list
	void  delete1st()
	{
		if (head == NULL)
		{
			return;
		}
		Node* temp = head;
		Node* tail = head;
		while (tail->next != head)
		{
			tail = tail->next;
		}
		head = head->next;
		tail->next = head;
		delete temp;
	}
	// deleteEnd for circular 1ingly linked list
	void  deleteEnd()
	{
		if (head == NULL)
		{
			return;
		}

		Node* tail = head;
		while (tail->next->next != head)
		{
			tail = tail->next;
		}
		Node* temp = tail->next;// to be delete 
		tail->next = head;
		delete temp;
	}
	// InsertAt for circular 1ingly linked list
	void insertAT(int val, int pos)
	{
		Node* newnode = new Node(val);
		Node* temp = head;
		int cur_pos = 0;
		while (cur_pos != pos - 1) {
			temp = temp->next;
			cur_pos++;
		}
		// Now temp points to the node at position pos - 1
		newnode->next = temp->next;
		temp->next = newnode;
	}
	// Reverse for circular 1ingly linked list
	void Reverse()
	{
		if (head == NULL || head->next == head) {
			return;
		}

		Node* curptr = head;
		Node* preptr = NULL;
		Node* nextptr = NULL;

		do {
			nextptr = curptr->next;  // Save the next node
			curptr->next = preptr;   // Reverse the link
			preptr = curptr;         // Move one step forward in the reversed list
			curptr = nextptr;        // Move one step forward in the original list
		} while (curptr != NULL && curptr != head);
		head = preptr;
	}
	//Search
	void search(int value)
	{
		Node* temp = head;
		do
		{
			if (temp->data == value)
			{
				cout << "Found" << endl;
				return;
			}

			temp = temp->next;
		} while (temp != head);
		cout << "Not Found" << endl;
	}
	//function which count the nodes which are presend in the linkedlist
	int countNodes()
	{
		if (!head) {
			return 0;
		}
		Node* temp = head;
		int count = 0;

		do
		{
			count++;
			temp = temp->next;
		} while (temp != head);
		return count;
	}
	int max()
	{
		if (!head)
		{
			return 0;
		}
		else {
			Node* temp = head;
			int max = head->data;
			do
			{
				if (temp->data > max)
				{
					max = temp->data;
				}
				temp = temp->next;

			} while (temp != head);
			return max;
		}
	}
	int average()
	{
		if (!head) {

			return 0;

		}
		Node* temp = head;
		int sum = 0;
		do
		{
			sum = sum + temp->data;
			temp = temp->next;
		} while (temp != head);
		return sum / countNodes(); //coutNodes is function which count the number of nodes
	}
	bool detectLoop() {
		Node* slow = head;
		Node* fast = head;
		while (slow && fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
};

class CircularDoublyLinkedList {
private:
	Node* head;

public:
	CircularDoublyLinkedList() {
		head = NULL;
	}
	// Add1st for circular 2bly linked list
	void Add1st(int value)
	{
		Node* newnode = new Node(value);
		if (head == NULL)
		{
			head = newnode;
			head->next = head;
			head->pre = head;
			return;
		}
		Node* end = head->pre;  // The last node in the list
		end->next = newnode;
		newnode->pre = end;
		newnode->next = head;
		head->pre = newnode;
		head = newnode;
	}
	// AddEnd for circular 2bly linked list
	void AddEnd(int value)
	{
		Node* newnode = new Node(value);
		if (head == NULL)
		{
			head = newnode;
			head->next = head; // circular linked list
			head->pre = head; // doubly linked list
			return;
		}
		Node* tail = head->pre; // The last node in the list
		tail->next = newnode;
		newnode->pre = tail;
		newnode->next = head;
		head->pre = newnode;
	}
	//  delete1st for circular 2bly linked list
	void delete1st()
	{
		if (head == NULL)
		{
			return;
		}

		Node* temp = head;
		Node* tail = head->pre; // The last node in the list

		if (head->next == head) // Only one node in the list
		{
			delete head;
			head = NULL;
		}
		else
		{
			head = head->next;
			head->pre = tail;
			tail->next = head;
			delete temp;
		}
	}
	//deleteEnd for circular 2bly linked list
	void deleteEnd()
	{
		if (head == NULL)
		{
			return;
		}

		Node* tail = head->pre; // The last node in the list

		if (head->next == head) // Only one node in the list
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node* temp = tail;
			tail->pre->next = head;
			head->pre = tail->pre;
			delete temp;
		}
	}
	//insertAT for circular 2bly linked list
	void insertAT(int val, int pos)
	{
		Node* newnode = new Node(val);

		if (pos == 0) // Insert at the beginning
		{
			if (head == NULL)
			{
				head = newnode;
				head->next = head;
				head->pre = head;
			}
			else
			{
				newnode->next = head;
				newnode->pre = head->pre;
				head->pre->next = newnode;
				head->pre = newnode;
				head = newnode;
			}
		}
		else
		{
			Node* temp = head;
			for (int cur_pos = 0; cur_pos < pos - 1; ++cur_pos)
			{
				temp = temp->next;
			}
			// Now temp points to the node at position pos - 1

			newnode->next = temp->next;
			newnode->pre = temp;
			temp->next->pre = newnode;
			temp->next = newnode;
		}
	}
	//Reverse for circular 2bly linked list
	void Reverse()
	{
		if (head == NULL || head->next == head) {
			return;
		}

		Node* curptr = head;
		Node* preptr = NULL;
		Node* nextptr = NULL;

		do {
			nextptr = curptr->next;  // Save the next node
			curptr->next = preptr;   // Reverse the next pointer
			curptr->pre = nextptr;  // Reverse the prev pointer
			preptr = curptr;         // Move one step forward in the reversed list
			curptr = nextptr;        // Move one step forward in the original list
		} while (curptr != NULL && curptr != head);

		head = preptr;  // Update the head to the new start of the reversed list
	}


	void display()
	{
		if (!head) {
			return;
		}
		// the do-while loop is chosen to ensure that the loop body is executed at least once, 
		Node* temp = head;
		do {
			cout << temp->data << "\t";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}
	bool detectLoop() {
		Node* slow = head;
		Node* fast = head;
		while (slow && fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}
		return false;
	}
	int max()
	{
		if (!head)
		{
			return 0;
		}
		else {
			Node* temp = head;
			int max = head->data;
			do
			{
				if (temp->data > max)
				{
					max = temp->data;
				}
				temp = temp->pre;

			} while (temp != head);
			return max;
		}
	}
	int countNodes()
	{
		if (!head) {
			return 0;
		}
		Node* temp = head;
		int count = 0;

		do
		{
			count++;
			temp = temp->next;
		} while (temp != head);
		return count;
	}
	//Search
	void search(int value)
	{
		Node* temp = head;
		do
		{
			if (temp->data == value)
			{
				cout << "Found" << endl;
				return;
			}

			temp = temp->next;
		} while (temp != head);
		cout << "Not Found" << endl;
	}
	int average()
	{
		if (!head) {

			return 0;

		}
		Node* temp = head;
		int sum = 0;
		do
		{
			sum = sum + temp->data;
			temp = temp->next;
		} while (temp != head);
		return sum / countNodes(); //coutNodes is function which count the number of nodes
	}
};
int main()
{
	SinglyLinked obj;
	Doubly Ob;
	Cir1lyLL obJ;
	CircularDoublyLinkedList objj;

	int ch;

	cout << "      ************" << endl;
	cout << "       \t\tAssignment DS&A (A4)" << endl;
	cout << "      ************" << endl;
outerInvalid:
	cout << "\n\n {Here we have four types of Linkedist for performed to you!} " << endl;
	cout << "\n1- Singly LL" << endl;
	cout << "2- Doubly LL" << endl;
	cout << "3- Circular Singly LL" << endl;
	cout << "4- Circular Doubly LL" << endl;
	cout << "5- Exit" << endl;
	cout << "\n\nPlease enter What you want to perform ?\n";
	cin >> ch;
	if (!cin.good())
	{
		cin.clear();
		cin.ignore();
	}

	system("cls");
	switch (ch)
	{
	case 1://outer case 1
	{	a:
		cout << "Singly LL '[data|next]'\n";
		cout << "\nFollowing are the SinglyClassLL Functions " << endl;
		cout << "\n1- add1st" << endl;
		cout << "\n2- addEnd" << endl;
		cout << "\n3- delete1st" << endl;
		cout << "\n4- deleteEnd" << endl;
		cout << "\n5- insertAt" << endl;
		cout << "\n6- Reverse " << endl;
		cout << "\n7- Max" << endl;
		cout << "\n8- Search" << endl;
		cout << "\n9- CountNode" << endl;
		cout << "\n10- Detect" << endl;
		cout << "\n11- Average" << endl;
		cout << "\n12- Palindrome" << endl;
		cout << "\n00- Back" << endl;
		cout << "\nPlease enter your choice: ";
		int n = 0;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		switch (n)
		{
		case 00:
			{
			system("cls");
			goto outerInvalid;
			}
		case 1://inner case 1
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		above:
			cin >> x;
			if (cin.good())
			{

				obj.add1st(x);
				obj.display();
				cout << "TimeComplexity: o(1)\n";
				system("pause");
				system("cls");
				goto a;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto above;
			}

		}
		case 2://inner case 2
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		case2Above:
			cin >> x;
			if (cin.good())
			{
				obj.addend(x);
				obj.display();
				cout << "TimeComplexity: o(n)\n";
				system("pause");
				system("cls");
				goto a;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "Please Enter in Interger" << endl;
				goto case2Above;
			}

		}
		case 3://inner case 3
		{

			obj.delete1st();
			system("cls");
			cout << "First node Deleted" << endl << endl;
			obj.display();
			cout << "TimeComplexity: o(1)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		case 4://inner case 4
		{
			obj.deleteEnd();
			system("cls");
			cout << "Last Node is Deleted" << endl << endl;
			obj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		case 5://inner case 5
		{
			int z, pos = -1;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		case3Above:
			cin >> z;
			if (cin.good())
			{
				cout << "Enter the position" << endl;
			case3innerAbove:
				cin >> pos;
				if (cin.good() && pos > 0)
				{
					obj.insertAt(z, pos);
					obj.display();
					cout << "TimeComplexity: o(n)\n";
					system("pause");
					system("cls");
					goto a;
				}
				else
				{
					cin.clear();
					cin.ignore();
					cout << "Please Enter the position in Integer & Grater then 0" << endl;
					goto case3innerAbove;
				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto case3Above;
			}

			break;
		}
		case 6://inner case 6
		{
			obj.reverseLL();
			system("cls");
			cout << "Your linklist is reversed." << endl;
			obj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		case 7://inner case 7
		{
			system("cls");
			cout << "The Maximuim number in the linklist is : " << obj.max() << endl;
			obj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		case 8://innner case 8
		{
			int a;
			system("cls");
			cout << "Enter the Number you want are looking for: " << endl;
		case8Above:
			cin >> a;
			if (cin.good())
			{
				obj.search(a);
				system("pause");
				cout << "TimeComplexity: o(n)\n";
				system("cls");
				goto a;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto case8Above;
			}

		}
		case 9://innner case 9
		{
			system("cls");
			cout << "The Number of Nodes in the linke list is : " << obj.countNodes() << endl;
			obj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		case 10://inner case 10
		{
			system("cls");
			cout << obj.detectLoop() << endl;
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		case 11://innner case 11
		{
			system("cls");
			cout << "The average of current linkelist is : " << obj.average() << endl;
			obj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		case 12://inner case 12
		{
			system("cls");
			cout << obj.Palindrome();
			obj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto a;
			break;
		}
		default://iner default
		{
			system("cls");
			cout << "You Enter wrong input" << endl << endl;
			goto a;
			break;
		}

		}

		break;//outer break
	}

	case 2://outer 2
	{
	b:
		cout << "Doubly LL '[Pre|data|next]'\n" << endl;
		cout << "Following are the DoublyLL Functions " << endl << endl;
		cout << "1- add1st" << endl;
		cout << "\n2- addEnd" << endl;
		cout << "\n3- delete1st" << endl;
		cout << "\n4- deleteEnd" << endl;
		cout << "\n5- insertAt" << endl;
		cout << "\n6- Reverse " << endl;
		cout << "\n7- Max" << endl;
		cout << "\n8- Search" << endl;
		cout << "\n9- CountNode" << endl;
		cout << "\n10- Detect Loop" << endl;
		cout << "\n11- Average" << endl << endl;
		cout << "\n00- Back" << endl;

		cout << "\nPlease enter your choice: ";
		int n;

		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		switch (n)
		{
		case 00:
		{
			system("cls");
			goto outerInvalid;
		}
		case 1://inner case 1
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		Obcase1Above:
			cin >> x;
			if (cin.good())
			{


				Ob.Add1st(x);
				Ob.Display();
				cout << "TimeComplexity: o(1)\n";
				system("pause");
				system("cls");
				goto b;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto Obcase1Above;

			}
		}

		case 2://inner case 2
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		Obcase2Above:
			cin >> x;
			if (cin.good())
			{
				Ob.AddEnd(x);
				Ob.Display();
				cout << "TimeComplexity: o(1)\n";
				system("pause");
				system("cls");
				goto b;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto Obcase2Above;

			}
		}
		case 3://inner case 3
		{
			Ob.delete1st();
			system("cls");
			cout << "First node Deleted" << endl << endl;
			Ob.Display();
			cout << "TimeComplexity: o(1)\n";
			system("pause");
			system("cls");
			goto b;
			break;
		}
		case 4://inner case 4
		{
			Ob.deleteEnd();
			system("cls");
			cout << "Last node Deleted" << endl << endl;
			Ob.Display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto b;
			break;
		}
		case 5://inner case 5
		{
			int z, pos = -1;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		Obcase5Above:
			cin >> z;
			if (cin.good())
			{

				cout << "Enter the position" << endl;
			Obcase5innerAbove:
				cin >> pos;
				if (cin.good())
				{
					Ob.InsertAt(z, pos);
					Ob.Display();
					cout << "TimeComplexity: o(n)\n";
					system("pause");
					system("cls");
					goto b;
					break;
				}
				else
				{
					cin.clear();
					cin.ignore();
					system("cls");
					cout << "Please Enter the position in Integer & Grater then 0" << endl;
					goto Obcase5innerAbove;

				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto Obcase5Above;

			}
		}
		case 6://inner case 6
		{
			Ob.ReverseDll();
			system("cls");
			cout << "Your linklist is reversed." << endl;
			Ob.Display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto b;
			break;
		}
		case 7://inner case 7
		{
			system("cls");
			cout << "The Maximuim number in the linklist is : " << Ob.max() << endl;
			Ob.Display();
			cout << "TimeComplexity: o(1)\n";
			system("pause");
			system("cls");
			goto b;
			break;
		}
		case 8://inner case 8
		{
			int a;
			system("cls");
			cout << "Enter the Number you want are looking for: " << endl;
		Obcase8Above:
			cin >> a;
			if (cin.good())
			{
				Ob.search(a);
				system("pause");
				cout << "TimeComplexity: o(n)\n";
				system("cls");
				goto b;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto Obcase8Above;
			}
		}
		case 9://inner case 9
		{
			system("cls");
			cout << "The Number of Nodes in the Doubly linked list is : " << Ob.countNodes() << endl;
			Ob.Display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto b;
			break;
		}
		case 10://inner case 10
		{
			system("cls");
			cout << Ob.detectLoop() << endl;
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto b;
			break;
		}
		case 11://inner case 11
		{
			system("cls");
			cout << "The average of current linkelist is : " << Ob.average() << endl;
			Ob.Display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto b;
			break;
		}
		default://inner default
		{
			system("cls");
			cout << "You Enter wrong input" << endl << endl;
			goto b;
			break;
		}


		}
		break;//outer break
	}
	case 3://outer case 3
	{
	c:
		cout << " Cir 1ingly LL '[EndNode<-[head|data|next]->1stNode]'\n";
		cout << "\nFollowing are the Circlar 1ingly LL Functions " << endl;
		cout << "\n1- add1st" << endl;
		cout << "\n2- addEnd" << endl;
		cout << "\n3- delete1st" << endl;
		cout << "\n4- deleteEnd" << endl;
		cout << "\n5- insertAt" << endl;
		cout << "\n6- Reverse " << endl;
		cout << "\n7- Max" << endl;
		cout << "\n8- Search" << endl;
		cout << "\n9- CountNode" << endl;
		cout << "\n10- Detect" << endl;
		cout << "\n11- Average" << endl;
		cout << "\n00- Back" << endl;

		cout << "\nPlease enter your choice: ";
		int m;
		cin >> m;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		switch (m)
		{

		case 00:
		{
			system("cls");
			goto outerInvalid;
		}
		case 1://inner case 1
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		obJcase1Above:
			cin >> x;
			if (cin.good())
			{
				obJ.Add1st(x);
				obJ.display();
				cout << "TimeComplexity: o(1)\n";
				system("pause");
				system("cls");
				goto c;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto obJcase1Above;
			}
		}
		case 2://inner case 2
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		obJcase2Above:
			cin >> x;
			if (cin.good())
			{
				obJ.AddEnd(x);
				obJ.display();
				cout << "TimeComplexity: o(n)\n";
				system("pause");
				system("cls");
				goto c;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto obJcase2Above;
			}
		}
		case 3://inner case 3
		{
			obJ.delete1st();
			system("cls");
			cout << "Circular singly First node Deleted" << endl << endl;
			obJ.display();
			cout << "TimeComplexity: o(1)\n";
			system("pause");
			system("cls");
			goto c;
			break;
		}
		case 4://inner case 4
		{
			obJ.deleteEnd();
			system("cls");
			cout << "Circular singly Last node Deleted" << endl << endl;
			obJ.display();
			cout << "TimeComplexity: o(1)\n";
			system("pause");
			system("cls");
			goto c;
			break;
		}
		case 5://inner case 5
		{
			int z, pos = -1;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		obJcase5Above:
			cin >> z;
			if (cin.good())
			{


				cout << "Enter the position" << endl;
			obJcase5innerAbove:
				cin >> pos;
				if (cin.good())
				{
					obJ.insertAT(z, pos);
					obJ.display();
					cout << "TimeComplexity: o(n)\n";
					system("pause");
					system("cls");
					goto c;
					break;
				}
				else
				{
					cin.clear();
					cin.ignore();
					system("cls");
					cout << "Please Enter the position in Integer & Grater then 0" << endl;
					goto obJcase5innerAbove;
				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto obJcase5Above;
			}
		}
		case 6://inner case 6
		{
			obJ.Reverse();
			system("cls");
			cout << "Your linklist is reversed." << endl;
			obJ.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto c;
			break;
		}
		case 7://inner case 7
		{
			system("cls");
			cout << "The Maximuim number in the linklist is : " << obJ.max() << endl;
			obJ.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto c;
			break;
		}
		case 8://inner case 8
		{
			int a;
			system("cls");
			cout << "Enter the Number you want are looking for: " << endl;
		obJcase8Above:
			cin >> a;
			if (cin.good())
			{
				obJ.search(a);
				system("pause");
				cout << "TimeComplexity: o(n)\n";
				system("cls");
				goto c;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto obJcase8Above;
			}
		}
		case 9://inner case 9
		{
			system("cls");
			cout << "The Number of Nodes in the Doubly linked list is : " << obJ.countNodes() << endl;
			obJ.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto c;
			break;
		}
		case 10://inner case 10
		{
			system("cls");
			cout << obJ.detectLoop() << endl;
			system("pause");
			cout << "TimeComplexity: o(n)\n";
			system("cls");
			goto c;
			break;
		}
		case 11://inner case 11
		{
			system("cls");
			cout << "The average of current linkelist is : " << obJ.average() << endl;
			obJ.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto c;
			break;
		}
		default://inner default
		{
			system("cls");
			cout << "You Enter wrong input" << endl << endl;
			goto c;
			break;
		}


		}
		break;//outer break
	}
	case 4://outer case 4
	{
	d:
		cout << "ClassCir2Bly LL 'EndNode<-[Pre|data|next]->1stNode'\n";
		cout << "\nFollowing are the Circular DoublyLL Functions " << endl;
		cout << "\n1- add1st";
		cout << "\n2- addEnd";
		cout << "\n3- delete1st";
		cout << "\n4- deleteEnd" << endl;
		cout << "\n5- insertAt" << endl;
		cout << "\n6- Reverse " << endl;
		cout << "\n7- Max" << endl;
		cout << "\n8- Search" << endl;
		cout << "\n9- CountNode" << endl;
		cout << "\n10- Detect Loop" << endl;
		cout << "\n11- Average" << endl;
		cout << "\n00- Back" << endl;

		cout << "\nPlease enter your choice: ";
		int n;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		switch (n)
		{
		case 00:
		{
			system("cls");
			goto outerInvalid;
		}
		case 1://innner 1
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		objjcase1Above:
			cin >> x;
			if (cin.good())
			{
				objj.Add1st(x);
				objj.display();
				cout << "TimeComplexity: o(1)\n";
				system("pause");
				system("cls");
				goto d;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto objjcase1Above;
			}
		}
		case 2://inner case 2
		{
			int x;
			system("cls");
			cout << "Enter the value you want to add : " << endl;
		objjcase2Above:
			cin >> x;
			if (cin.good())
			{
				objj.AddEnd(x);
				objj.display();
				cout << "TimeComplexity: o(n)\n";
				system("pause");
				system("cls");
				goto d;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto objjcase2Above;
			}
		}
		case 3://inner case 3
		{
			objj.delete1st();
			system("cls");
			cout << "Circular Doubly First node Deleted" << endl << endl;
			objj.display();
			cout << "TimeComplexity: o(1)\n";
			system("pause");
			system("cls");
			goto d;
			break;
		}
		case 4://inner case 4
		{
			objj.deleteEnd();
			system("cls");
			cout << "Circular Doubly First node Deleted" << endl << endl;
			objj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto d;
			break;
		}
		case 5://inner case 5
		{
			int z, pos = -1;
			cout << "Enter the value you want to add : " << endl;
		objjcase5Above:
			cin >> z;
			if (cin.good())
			{


				cout << "Enter the position" << endl;
			objjcase5innerAbove:
				cin >> pos;
				if (cin.good())
				{



					objj.insertAT(z, pos);
					objj.display();
					cout << "TimeComplexity: o(n)\n";
					system("pause");
					system("cls");
					goto d;
					break;
				}
				else
				{
					cin.clear();
					cin.ignore();
					system("cls");
					cout << "Please Enter the position in Integer & Grater then 0" << endl;
					goto objjcase5innerAbove;

				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto objjcase5Above;

			}
		}
		case 6://inner case 6
		{
			objj.Reverse();
			system("cls");
			cout << "Your linklist is reversed." << endl;
			objj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto d;
			break;
		}
		case 7://inner case 7
		{
			system("cls");
			cout << "The Maximuim number in the linklist is : " << objj.max() << endl;
			objj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto d;
			break;
		}
		case 8://inner case 8
		{
			int a;
			system("cls");
			cout << "Enter the Number you want are looking for: " << endl;
		objjcase8Above:
			cin >> a;
			if (cin.good())
			{
				objj.search(a);
				system("pause");
				cout << "TimeComplexity: o(n)\n";
				system("cls");
				goto d;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();
				system("cls");
				cout << "Please Enter in Interger" << endl;
				goto objjcase8Above;
			}
		}
		case 9://inner case 9
		{
			system("cls");
			cout << "The Number of Nodes in the Doubly linked list is : " << objj.countNodes() << endl;
			objj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto d;
			break;
		}
		case 10://inner case 10
		{
			system("cls");
			cout << objj.detectLoop() << endl;
			system("pause");
			cout << "TimeComplexity: o(n)\n";
			system("cls");
			goto d;
			break;
		}
		case 11://inner case 11
		{
			system("cls");
			cout << "The average of current linkelist is : " << objj.average() << endl;
			objj.display();
			cout << "TimeComplexity: o(n)\n";
			system("pause");
			system("cls");
			goto d;
			break;
		}
		default://inner default
		{
			system("cls");
			cout << "You Enter wrong input" << endl << endl;
			goto d;
			break;
		}


		}
		break;//outer break
	}

	case 5://outer case 5
	{
		system("pause");
		Ob.~Doubly();
		exit(0);
		break;
	}
	default://outer default
	{
		cout << "\nPlease enter a valid choice!" << endl;
		goto outerInvalid;
		break;
	}
	}
	return 0;
}