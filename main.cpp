// Chapter 19, Programming Challenge 12: Inventory Bin Queue
#include <iostream>
#include "InvItem.h"
#include "InvStack.h"
#include "InvQue.h"
#include "InvTree.h"
using namespace std;

int main()
{
	InvStack<InventoryItem> stack;	// create stack
	InvQue<InventoryItem> queue;	// create queue
	InvTree<InventoryItem> tree;	// create tree
	InventoryItem item;				// create inventory item object
	

	int choice;						// Menu choice
	long serial;					// Serial number
	string mDate;					// Manufacture date
	int structChoice;               // 1 = stack, 2 = queue, 3 = tree
	cout << "Choose the data structure to use (1 for stack, 2 for queue, 3 for tree): ";
	cin >> structChoice;
	while (structChoice < 1 || structChoice > 3)
	{
		cout << "Please enter 1 for stack, 2 for queue, or 3 for tree: ";
		cin >> structChoice;
	}
	do
	{
		// Display the menu.
		cout << "\n------ Inventory Menu --------\n\n";
		cout << "1.  Enter a part into the inventory.\n";
		cout << "2.  Take a part from the inventory.\n";
		cout << "3.  Display inventory.\n";
		cout << "4.  Quit.\n\n";
		cout << "Please make a choice (1, 2, 3, or 4):  ";
		cin >> choice;

		// Validate choice
		while (choice < 1 || choice > 4)
		{
			cout << "Please enter 1, 2, 3, or 4: ";
			cin >> choice;
		}

		// Act on the user's choice.
		switch(choice)
		{

		case 1:
			// Enter a part into inventory.
			cout << "\nYou have chosen to add an item to the inventory bin.\n\n";
			cout << "Enter the item's serial number: ";
			cin >> serial;
			item.setSerialNum(serial);
			cout << "Enter the item's manufacture date: ";
			cin >> mDate;
			item.setManufactDate(mDate);
			if (structChoice == 1)
				stack.push(item);
			else if (structChoice == 2)
				queue.enqueue(item);
			else if (structChoice == 3)
				tree.insertNode(item);
			break;

		case 2:
			// Take a part out of inventory.
			cout << "\nYou have chosen to remove an item from the inventory bin.\n\n";
			if ((structChoice == 1 && stack.isEmpty()) || (structChoice == 2 && queue.isEmpty()))
				cout << "No parts to remove.\n";
			else
			{
				if (structChoice == 1){
					stack.pop(item);
					cout << "\nThe part you removed was:\n";
					cout << "\tSerial number: " << item.getSerialNum() << endl;
					cout << "\tManufacture date: " << item.getManufactDate() << endl;
					cout << endl;
				}
				else if (structChoice == 2){
					queue.dequeue(item);
					cout << "\nThe part you removed was:\n";
					cout << "\tSerial number: " << item.getSerialNum() << endl;
					cout << "\tManufacture date: " << item.getManufactDate() << endl;
					cout << endl;
				}
				else if (structChoice == 3){
					cout << "Enter the serial number of the part to remove: ";
					cin >> serial;
					item.setSerialNum(serial);
					if (tree.searchNode(item)){
						tree.remove(item);
						cout << "\nPart with serial number " << serial << " has been removed.\n";
					}
					else{
						cout << "Item not found in inventory.\n";
					}
				}


			}
			break;
		case 3:
			// Display inventory.
			cout << "\nYou have chosen to display the inventory bin.\n\n";
			if ((structChoice == 1 && stack.isEmpty()) || (structChoice == 2 && queue.isEmpty()))
				cout << "No parts in inventory.\n";
			else
			{
				if (structChoice == 1)
					stack.display();
				else if (structChoice == 2)
					queue.display();
				else if (structChoice == 3)
					tree.displayInOrder();
			}
			break;
		case 4:
			cout << "\nGoodbye!\n\n";
			break;
		}
	} while (choice  != 4);

	return 0;
}