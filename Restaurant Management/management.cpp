#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Menuitem {
private:
    int itemId;
    string name;
    double price;
    string category;

public:
    Menuitem(int Id, string itemName, double itemPrice, string itemCategory) {
        itemId = Id;
        name = itemName;
        price = itemPrice;
        category = itemCategory;
    }

    void display() const {
        cout << "Item Id: " << itemId << " | " << name << " | Price: " << price << endl;
    }

    int getitemId() const
    
    {
         return itemId; 
        
        }
    double getPrice() const 
    
    {
        
        return price; }
    string getCategory() const { return category; }
    string getName() const { return name; }
};

struct OrderedItem {
    Menuitem item;
    int quantity;
};

class Restaurant {
private:
    vector<Menuitem> menu;
    vector<OrderedItem> order;
    string paymentStatus = "Pending";

public:
    void addMenuitem(int Id, const string &name, double price, const string &category) {
        menu.push_back(Menuitem(Id, name, price, category));
    }

    void displayCategory(const string &cat) const {
        cout << "\n " << cat << "\n" << endl;
        for (const auto &item : menu) {
            if (item.getCategory() == cat) {
                item.display();
            }
        }
    }

    void takeOrder() {
        int catChoice;
        while (true) {
            cout << "Choose a category to order from:" << endl;
            cout << "1. Beverage\n2. Starter\n3. Main Course\n4. Dessert\n5. Remove Item\n0. Finish Order" << endl;
            cin >> catChoice;

            if (catChoice == 0) break;

            string chosenCategory;
            if (catChoice == 1) chosenCategory = "Beverage";
            else if (catChoice == 2) chosenCategory = "Starter";
            else if (catChoice == 3) chosenCategory = "Main Course";
            else if (catChoice == 4) chosenCategory = "Dessert";
            else if (catChoice == 5) {
                removeItem();
                continue;
            } else {
                cout << "Invalid choice try again." << endl;
                continue;
            }

            displayCategory(chosenCategory);

            cout << "Enter item IDs from " << chosenCategory 
                 << " (0 to go back to categories): " << endl;

            int itemId;
            while (true) {
                cout << "Item ID: ";
                cin >> itemId;

                if (itemId == 0) break;

                bool found = false;
                for (const auto &item : menu) {
                    if (item.getitemId() == itemId && item.getCategory() == chosenCategory) {
                        int quantity;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        order.push_back({item, quantity});
                        cout << "Added " << quantity << " x " << item.getName() << " to order." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Invalid item ID for this category." << endl;
                }
            }
        }

        printBill();
    }

    void removeItem() {
        if (order.empty()) {
            cout << "No items in order to remove." << endl;
            return;
        }

        cout << " Current Order " << endl;
        for (size_t i = 0; i < order.size(); i++) {
            cout << i + 1 << ". " << order[i].item.getName()
                 << " x " << order[i].quantity
                 << " | Price: " << order[i].item.getPrice() * order[i].quantity << endl;
        }

        int choice;
        cout << "Enter item number to remove (0 to cancel): ";
        cin >> choice;

        if (choice > 0 && choice <= (int)order.size()) {
            cout << "Removed " << order[choice - 1].item.getName() << " from order." << endl;
            order.erase(order.begin() + (choice - 1));
        }
    }

    void printBill() {
        string customerName, phone;
        int tableNo;

        cout << "Enter your name: ";
        cin >> ws;
        getline(cin, customerName);

        cout << "Enter your phone number: ";
        getline(cin, phone);

        cout << "Enter table number (0 if takeaway/delivery): ";
        cin >> tableNo;

        double subtotal = 0;
        cout << "\n=========================================" << endl;
        cout << "          IPPR Paradise Restaurant     " << endl;
        cout << "=========================================" << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Phone: " << phone << endl;
        if (tableNo == 0)
            cout << "Order Type: Takeaway/Delivery" << endl;
        else
            cout << "Table No: " << tableNo << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Items Ordered:" << endl;

        for (const auto &ord : order) {
            double itemTotal = ord.item.getPrice() * ord.quantity;
            cout << ord.item.getName() << " x " << ord.quantity 
                 << " = " << itemTotal << endl;
            subtotal += itemTotal;
        }

        cout << "-----------------------------------------" << endl;
        cout << "Subtotal: " << subtotal << endl;

        double discount = 0;
        if (subtotal > 500) {
            discount = subtotal * 0.10;
            cout << "Discount (10%): -" << discount << endl;
        }

        double afterDiscount = subtotal - discount;
        double gst = afterDiscount * 0.05;
        cout << "GST (5%): +" << gst << endl;

        double total = afterDiscount + gst;
        cout << "-----------------------------------------" << endl;
        cout << "TOTAL BILL: " << total << endl;

    
        cout << "\nChoose Payment Method:" << endl;
        cout << "1. Cash" << endl;
        cout << "2. Card" << endl;
        cout << "3. UPI" << endl;
        cout << "Enter choice: ";
        int payChoice;
        cin >> payChoice;

        switch (payChoice) {
            case 1:
                cout << "Cash Payment selected." << endl;
                cout << "Please pay Rs. " << total << " at the counter." << endl;
                paymentStatus = "Paid (Cash)";
                break;
            case 2: {
                cout << "Card Payment selected." << endl;
                string cardNo;
                cout << "Enter last 4 digits of your Card: ";
                cin >> cardNo;
                cout << "Processing Card Payment..." << endl;
                cout << "Payment Successful!" << endl;
                paymentStatus = "Paid (Card)";
                break;
            }
            case 3: {
                cout << "UPI Payment selected." << endl;
                string upiId;
                cout << "Enter your UPI ID: ";
                cin >> upiId;
                cout << "Processing UPI Payment..." << endl;
                cout << "Payment Successful!" << endl;
                paymentStatus = "Paid UPI";
                break;
            }
            default:
                cout << "Invalid choice! Defaulting to Cash Payment." << endl;
                cout << "Please pay Rs. " << total << " at the counter." << endl;
                paymentStatus = "Paid Cash";
        }

        cout << "-----------------------------------------" << endl;
        cout << "Payment Status: " << paymentStatus << endl;
        cout << "=========================================" << endl;
        cout << "   Thank you for dining with us! :)   " << endl;
        cout << "=========================================" << endl;
    }
};

int main() {
    Restaurant restaurant;

    // Adding menu items
    restaurant.addMenuitem(1, "Tea", 30, "Beverage");
    restaurant.addMenuitem(2, "Masala Tea", 50, "Beverage");
    restaurant.addMenuitem(3, "Hot Coffee", 50, "Beverage");
    restaurant.addMenuitem(4, "Cold Coffee", 70, "Beverage");
    restaurant.addMenuitem(5, "Green Tea", 60, "Beverage");
    restaurant.addMenuitem(6, "Fresh Lime Soda", 70, "Beverage");
    restaurant.addMenuitem(7, "Chocolate Shake", 90, "Beverage");
    restaurant.addMenuitem(8, "Chocolate Mousse Cold", 120, "Beverage");
    restaurant.addMenuitem(9, "Mojito", 120, "Beverage");
    restaurant.addMenuitem(10, "Champagne", 360, "Beverage");

    restaurant.addMenuitem(11, "Burger", 55, "Starter");
    restaurant.addMenuitem(12, "Paneer Tikka", 140, "Starter");
    restaurant.addMenuitem(13, "Chinese Sizzler", 240, "Starter");
    restaurant.addMenuitem(14, "Veg Manchurian", 120, "Starter");
    restaurant.addMenuitem(15, "Garlic Bread", 90, "Starter");
    restaurant.addMenuitem(16, "Paneer Tikka Pizza", 250, "Starter");

    restaurant.addMenuitem(17, "Tacos", 150, "Main Course");
    restaurant.addMenuitem(18, "Quesadillas", 200, "Main Course");
    restaurant.addMenuitem(19, "Burrito Bowl", 220, "Main Course");
    restaurant.addMenuitem(20, "Enchiladas", 240, "Main Course");
    restaurant.addMenuitem(21, "Nachos with Cheese", 180, "Main Course");
    restaurant.addMenuitem(22, "Paella", 350, "Main Course");
    restaurant.addMenuitem(23, "Spanish Omelette", 180, "Main Course");
    restaurant.addMenuitem(24, "Patatas Bravas", 140, "Main Course");
    restaurant.addMenuitem(25, "Churros with Chocolate", 160, "Main Course");
    restaurant.addMenuitem(26, "Gazpacho Soup", 130, "Main Course");
    restaurant.addMenuitem(27, "Spaghetti Carbonara", 270, "Main Course");
    restaurant.addMenuitem(28, "Margherita Pizza", 250, "Main Course");
    restaurant.addMenuitem(29, "Lasagna", 300, "Main Course");
    restaurant.addMenuitem(30, "Pasta Alfredo", 260, "Main Course");
    restaurant.addMenuitem(31, "Risotto", 280, "Main Course");
    restaurant.addMenuitem(32, "Dal Fry", 120, "Main Course");
    restaurant.addMenuitem(33, "Dal Makhni", 130, "Main Course");
    restaurant.addMenuitem(34, "Paneer Masala", 150, "Main Course");
    restaurant.addMenuitem(35, "Chicken Curry", 220, "Main Course");
    restaurant.addMenuitem(36, "Veg Thali", 210, "Main Course");
    restaurant.addMenuitem(37, "Non-Veg Thali", 250, "Main Course");
    restaurant.addMenuitem(38, "Biryani (Veg)", 200, "Main Course");
    restaurant.addMenuitem(39, "Biryani (Chicken)", 260, "Main Course");

    restaurant.addMenuitem(40, "Gulab Jamun (2 pcs)", 60, "Dessert");
    restaurant.addMenuitem(41, "Rasmalai (2 pcs)", 70, "Dessert");
    restaurant.addMenuitem(42, "Ice Cream", 60, "Dessert");
    restaurant.addMenuitem(43, "Chocolate Brownie", 90, "Dessert");

    cout << "=========================================" << endl;
    cout << "   Welcome to IPPR Paradise Restaurant" << endl;
    cout << "=========================================" << endl;
    cout << " Where taste meets tradition " << endl;
    cout << "Serving you the finest Mexican, Spanish," << endl;
    cout << "Italian and Indian cuisines with love." << endl;
    cout << "--------------------------------------" << endl;
    cout << "Press ENTER to start ordering..." << endl;

    cin.ignore();
    restaurant.takeOrder();

    return 0;
}
