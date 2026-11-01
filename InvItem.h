// Specification file for the InvItem class
#ifndef INVITEM_H
#define INVITEM_H
#include <string>
using namespace std;

class InventoryItem
{
private:
	long serialNum;			// Serial number
	string manufactDate;	// Manufacture date
	int lotNum;				// Lot number

public:
	// Default constructor
	InventoryItem()
		{ serialNum = 0; manufactDate = ""; lotNum = 0; }

	// Constructor
	InventoryItem(long s, string m, int lot)
		{ serialNum = s; manufactDate = m; lotNum = lot; }

	void setSerialNum(long s)
		{ serialNum = s; }

	void setManufactDate(string m)
		{ manufactDate = m; }

	void setLotNum(int lot)
		{ lotNum = lot; }

	long getSerialNum() const
		{ return serialNum; }

	string getManufactDate()
		{ return manufactDate; }

	int getLotNum() const
		{ return lotNum; }

	// Overload the < operator
    bool operator<(const InventoryItem& other) const {
        return serialNum < other.serialNum; // Compare based on serial number
    }

    // Optional: Overload the == operator for equality checks
    bool operator==(const InventoryItem& other) const {
        return serialNum == other.serialNum; // Compare based on serial number
    }

	// Overload the > operator
    bool operator>(const InventoryItem& other) const {
        return serialNum > other.serialNum; // Compare based on serial number
    }

	// Overload the << operator
	// A friend function can access the private and protected members of the class. 
	// This is necessary for the << operator because it often needs to access the internal state 
	// (like serialNum and manufactureDate) of the class to output meaningful information.
    friend std::ostream& operator<<(std::ostream& os, const InventoryItem& item) {
        os << "Serial Number: " << item.serialNum << ", Manufacture Date: " << item.manufactDate;
        return os;
    }
};

#endif