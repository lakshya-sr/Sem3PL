#include <iostream>

using namespace std;

int num_orders = 0;

class Data{
	public:
		int id;
		int quantity;
		string customer_name;
		string item_name;
		
		Data(){
			id = num_orders++;
		}
		
		Data(int id){
			this->id = id;
		}
		
		void display(){
			cout << "ID: " << id << 
				    ", Item: " << item_name << 
					", Quantity: " << quantity << 
					", Customer name: " << customer_name << endl;
		}
};

class Node{
	public:
		Data data;
		Node *next;
	
	Node(){
		next = NULL;
	}
};

class SLL{
	public:
		Node *head, *tail;
	
	SLL(){
		head = NULL;
		tail = NULL;
	}
	
	Node *add_at_end(){
		Node *new_node = new Node();
		if(tail == NULL){
			head = new_node;
			tail = new_node;
		}
		else{
			tail->next = new_node;
			tail = new_node;
		}
		return new_node;
	}
	
	Data remove_from_start(){
		Node *to_remove = head;
		if(head == NULL){
			cout << "List empty" << endl;
			return Data(-1);
		}
		else if(head->next == NULL){
			head = NULL;
			tail = NULL;
		}
		else{
			head = head->next;
		}
		Data data = to_remove->data;
		delete to_remove;
		return data;
	}
	
	void display(){
		Node *current = head;
		cout << "-------" << endl;
		while(current){
			current->data.display();
			current = current->next;
		}
		cout << "-------" << endl;
	}
};

class Restaurant{
	public:
		SLL orders;
		
	void take_order(){
		Data *order = &(orders.add_at_end()->data);
		cout << "Enter item name: "; cin >> order->item_name;
		cout << "Enter quantity: "; cin >> order->quantity;
		cout << "Enter customer name: "; cin >> order->customer_name;
	}
	
	void process_order(){
		Data order = orders.remove_from_start();
		if(order.id == -1){
			cout << "No orders" << endl;
		}
		else{
			cout << "Order " << order.id << ", quantity " << order.quantity << " processed" << endl;
		}
	}
};


int main(){
	Restaurant r;
	bool running = true;
	while(running){
		int choice;
		cout << "1. Place order\n";
		cout << "2. Process order\n";
		cout << "3. Display orders\n";
		cout << "4. Exit\n";
		cout << "Enter choice: "; cin >> choice;
		
		switch(choice){
			case 1:
				r.take_order();
				break;
			case 2:
				r.process_order();
				break;
			case 3:
				r.orders.display();
				break;
			case 4:
				running = false;
				break;
			default:
				cout << "Invalid choice\n";
		}
	}
	
	return 0;
}
