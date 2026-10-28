#include <iostream>

// Chapter 19, Programming Challenge 12: Inventory Bin Queue
#include <iostream>
#include "InvItem.h"
#include "InvStack.h"
#include "InvQue.h"
using namespace std;

int main()
{
	InvStack<InventoryItem> stack;	// create stack
	InvQue<InventoryItem> queue;	// create queue
	InventoryItem item;				// create inventory item object
	

	int choice;						// Menu choice
	long serial;					// Serial number
	string mDate;					// Manufacture date
	int structChoice;               // 1 = stack, 2 = queue
	cout << "Choose the data structure to use (1 for stack, 2 for queue): ";
	cin >> structChoice;
	while (structChoice < 1 || structChoice > 2)
	{
		cout << "Please enter 1 for stack or 2 for queue: ";
		cin >> structChoice;
	}
	do
	{
		// Display the menu.
		cout << "\n------ Inventory Menu --------\n\n";
		cout << "1.  Enter a part into the inventory.\n";
		cout << "2.  Take a part from the inventory.\n";
		cout << "3.  Quit.\n\n";
		cout << "Please make a choice (1, 2, or 3):  ";
		cin >> choice;

		// Validate choice
		while (choice < 1 || choice > 3)
		{
			cout << "Please enter 1, 2, or 3: ";
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
			else
				queue.enqueue(item);
			break;

		case 2:
			// Take a part out of inventory.
			cout << "\nYou have chosen to remove an item from the inventory bin.\n\n";
			if ((structChoice == 1 && stack.isEmpty()) || (structChoice == 2 && queue.isEmpty()))
				cout << "No parts to remove.\n";
			else
			{
				if (structChoice == 1)
					stack.pop(item);
				else
					queue.dequeue(item);
				cout << "\nThe part you removed was:\n";
				cout << "\tSerial number: " << item.getSerialNum() << endl;
				cout << "\tManufacture date: " << item.getManufactDate() << endl;
				cout << endl;
			}
			break;

		case 3:
			cout << "\nGoodbye!\n\n";
			break;
		}
	} while (choice  != 3);

	return 0;
}