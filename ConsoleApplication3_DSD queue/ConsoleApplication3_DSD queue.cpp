//динамическая структура данных очередь принцып первый поступил и первый же вышел
#include <iostream>
using namespace std;
class Data {
private:
	int x;
	Data* pred;
public:
	Data() {
		x = 0;
		pred = NULL;
	}
	void show() {
		cout << "x = " << x << endl;
	}
	void input() {
		cout << "Input x";
		cin >> x;
	}
	Data* get_pred() {
		return pred;
	}
	void set_pred(Data* e) {
		pred = e;
	}
};


class Queue
{
private:
	Data* head;
	Data* tail;
public:
	Queue() :head(NULL), tail(NULL) {}
	void add()
	{
		Data* t = new Data;
		t->input();
		if (head == NULL)
		{
			head = t;
			tail = t;
		}
		else
		{
			head->set_pred(t);
			head = t;
		}
	}
	void show_all()
	{
		Data* temp = tail;
		while (temp != NULL)
		{
			temp->show();
			temp = temp->get_pred();
		}
	}
	void delete_elements()
	{
		if (head == NULL)
			return;
		Data* temp = tail;
		tail = tail->get_pred();
		delete temp;
		if (tail == NULL)
			head = NULL;
	}
};
	int main()
	{
		Queue my_q;
		my_q.add();
		my_q.add();
		my_q.add();
		my_q.show_all();
		my_q.delete_elements();
		my_q.show_all();

	}
