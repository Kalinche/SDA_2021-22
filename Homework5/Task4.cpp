#include <iostream>

using namespace std;

struct Node {
	long data;
	struct Node* next;
};

void Append(Node** head, long data)
{
	Node* newNode = new Node();

	newNode->data = data;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	Node* current = *head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = newNode;
	return;
}
void DeleteFirst(Node** head)
{
	Node* temp;
	temp = *head;

	if (*head != NULL)
	{
		*head = temp->next;
		delete temp;
	}
}

void DeleteNode(Node** head, long pos)
{
	if (*head == NULL)
		return;

	Node* current = *head;

	if (pos == 0)
	{
		DeleteFirst(head);
		return;
	}

	Node* previous = NULL;

	for (int i = 0; i < pos; i++)
	{
		if (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		else
			return;
	}
	previous->next = current->next;
	delete current;

}

void Input(Node** head, const long& players)
{
	long hunger = -1;
	for (int i = 0; i < players; i++)
	{
		cin >> hunger;
		Append(head, hunger);
	}
}

long CountDays(Node** head, long& players)
{
	if (*head == NULL)
		return 0;

	bool hasElimination = 0;
	long days = 0;

	do {

		hasElimination = 0;
		Node* current = *head;
		int i = 1;

		while (current != NULL && current->next != NULL)
		{
			if (current->data < current->next->data)
			{
				current = current->next->next;
				DeleteNode(head, i);
				players--;
				hasElimination = 1;
			}
			else
				current = current->next;
			i++;
		}

		if (hasElimination == 1)
			days++;
	} while (hasElimination != 0);
}

int main() {
	long players;
	cin >> players;

	Node* head = NULL;

	Input(&head, players);

	cout << CountDays(&head, players);


	system("pause");
	return 0;
}