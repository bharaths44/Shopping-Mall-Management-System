#include <iostream>

#include <vector>

#include <string>

using namespace std;

class Product {
    public: string name;
    double price;

    Product(string n, double p): name(n),
    price(p) {}
};

class ShoppingCart {
    public: vector < Product > items;

    double total_price() const {
        double total = 0.0;
        for (const auto & item: items) {
            total += item.price;
        }
        return total;
    }

    void add_item(const Product & item) {
        items.push_back(item);
    }

    void remove_item(int index) {
        items.erase(items.begin() + index);
    }

    void clear() {
        items.clear();
    }

    void print() const {
        cout << "^^^^^^^^^^  Shopping Cart  ^^^^^^^^^^^" << endl;
        if (items.empty()) {
            cout << "Empty" << endl;
        } else {
            for (int i = 0; i < items.size(); i++) {
                cout <<"\t" <<i + 1 << ". " << items[i].name << " - $" << items[i].price << endl;
            }
            cout << " * Total: $ " << total_price() <<"*"<<endl;

        }
        cout<< "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }
};

class Customer {
    public: string name;
    ShoppingCart cart;

    Customer(string n): name(n) {}

    void print() const {
        cout << "*************************************" <<endl;
        cout <<"\t"<< "Customer Name: " << name << endl;
        cart.print();
        cout << "*************************************" <<endl;
    }
};

class Shop {
    public: string name;
    vector < Product > products;

    Shop(string n): name(n) {}

    void add_product(const Product & product) {
        products.push_back(product);
    }

    void print_products() const {
        cout << "Products Available at " << name << ":" << endl;
        for (int i = 0; i < products.size(); i++) {
            cout <<"\t"<< i + 1 << ". " << products[i].name << " - $" << products[i].price << endl;
        }
    }

    Product get_product(int index) const {
        return products[index];
    }
};

int main() {
    // Create some sample products
    Product p1("Milk", 40);Product p2("Bread", 35);Product p3("Eggs", 6.00);Product p4("Sugar", 70);

    Product p5("Shirt", 3000);

    Product p6("Lipstick", 800);Product p7("Eyeliner", 200);Product p8("Highlighter", 500);Product p9("Contour", 600);Product p10("Compact", 800);

    Product p11("Bat",4000);Product p12("Ball",1000);Product p13("Badminton Racket",1300);Product p14("Boot",3000);Product p15("Jersey",1800);

    Product p16("Top",2800);Product p17("Skirt",2400);Product p18("Shirt",2300);Product p19("Jeans",2500);

    // Create some sample shops and add products to them
    Shop s1("Elite - Grocery");
    s1.add_product(p1);
    s1.add_product(p2);
    s1.add_product(p3);
    s1.add_product(p4);

    Shop s2("WestSide - Clothing");
    s2.add_product(p5);
    s2.add_product(p16);
    s2.add_product(p17);
    s2.add_product(p18);
    s2.add_product(p19);

    Shop s3("Tac - Cosmetics");
    s3.add_product(p7);
    s3.add_product(p8);
    s3.add_product(p9);
    s3.add_product(p10);
    s3.add_product(p6);

    Shop s4("Cosmos - Sports");
    s4.add_product(p11);
    s4.add_product(p12);
    s4.add_product(p13);
    s4.add_product(p14);
    s4.add_product(p15);

    // Create a sample customer
    Customer c1("Alice");

    int option = 0;

    do {
          cout<<R"(
*********************************************************************
---------------------------------------------------------------------
*********************************************************************
   _____ _                       _               __  __       _ _
  / ____| |                     (_)             |  \/  |     | | |
 | (___ | |__   ___  _ __  _ __  _ _ __   __ _  | \  / | __ _| | |
  \___ \| '_ \ / _ \| '_ \| '_ \| | '_ \ / _` | | |\/| |/ _` | | |
  ____) | | | | (_) | |_) | |_) | | | | | (_| | | |  | | (_| | | |
 |_____/|_| |_|\___/| .__/| .__/|_|_| |_|\__, | |_|  |_|\__,_|_|_|
                    | |   | |             __/ |
                    |_|   |_|            |___/

*********************************************************************
---------------------------------------------------------------------
*********************************************************************

===========================     MENU    =============================

-------------------------   1. Browse Shops  ------------------------
-------------------------   2. View Cart     ------------------------
-------------------------   3. Checkout      ------------------------
-------------------------   4. Quit          ------------------------

======================================================================


)";
        cout << "Choose an option : ";
        cin >> option;

        if (option == 1) {
            // Browse Shops
            int shop_index = 0;
            while(1) {
               cout<<R"(
============================== SHOPS =================================

---------------------- 1. Elite - Grocery     ------------------------
---------------------- 2. WestSide - Clothing ------------------------
---------------------- 3. Tac - Cosmetics     ------------------------
---------------------- 4. Cosmos - Sports     ------------------------
---------------------- 5. Back                ------------------------

======================================================================
)";
                cout << "Choose a shop : ";
                cin >> shop_index;

                if (shop_index == 1) {
                    cout<<R"(
-----------------------------------------------------------------------------
 _____ _     _  _____  _____        _____ ____  ____  ____  _____ ____ ___  _
/  __// \   / \/__ __\/  __/       /  __//  __\/  _ \/   _\/  __//  __\\  \//
|  \  | |   | |  / \  |  \ _____   | |  _|  \/|| / \||  /  |  \  |  \/| \  /
|  /_ | |_/\| |  | |  |  /_\____\  | |_//|    /| \_/||  \_ |  /_ |    / / /
\____\\____/\_/  \_/  \____\       \____\\_/\_\\____/\____/\____\\_/\_\/_/

-----------------------------------------------------------------------------
)";
                    s1.print_products();

                    int product_index = 0;
                    do {
                        cout << "Choose a product (0 to go back): ";
                        cin >> product_index;
                        if (product_index > 0 && product_index <= s1.products.size()) {
                            // Add product to cart
                            c1.cart.add_item(s1.get_product(product_index - 1));
                            cout << s1.get_product(product_index - 1).name << " added to cart." << endl;
                        }
                    } while (product_index != 0);
                }
                  else if (shop_index == 2) {
                      cout<<R"(
---------------------------------------------------------------------------------------------------------

 _    _  ____  ___  ____  ___  ____  ____  ____            ___  __    _____  ____  _   _  ____  _  _  ___
( \/\/ )( ___)/ __)(_  _)/ __)(_  _)(  _ \( ___)   ___    / __)(  )  (  _  )(_  _)( )_( )(_  _)( \( )/ __)
 )    (  )__) \__ \  )(  \__ \ _)(_  )(_) ))__)   (___)  ( (__  )(__  )(_)(   )(   ) _ (  _)(_  )  (( (_-.
(__/\__)(____)(___/ (__) (___/(____)(____/(____)          \___)(____)(_____) (__) (_) (_)(____)(_)\_)\___/

---------------------------------------------------------------------------------------------------------
         )";
                    s2.print_products();

                    int product_index = 0;
                    do {
                        cout << "Choose a product (0 to go back): ";
                        cin >> product_index;
                        if (product_index > 0 && product_index <= s2.products.size()) {
                            // Add product to cart
                            c1.cart.add_item(s2.get_product(product_index - 1));
                            cout << s2.get_product(product_index - 1).name << " added to cart." << endl;
                        }
                    } while (product_index != 0);
                }

                else if (shop_index == 3) {
                    cout<<R"(

----------------------------------------------------------------------------------------------------
 ______   ____     __                    __   ___    _____ ___ ___    ___  ______  ____    __  _____
|      | /    |   /  ]                  /  ] /   \  / ___/|   |   |  /  _]|      ||    |  /  ]/ ___/
|      ||  o  |  /  /      _____       /  / |     |(   \_ | _   _ | /  [_ |      | |  |  /  /(   \_
|_|  |_||     | /  /      |     |     /  /  |  O  | \__  ||  \_/  ||    _]|_|  |_| |  | /  /  \__  |
  |  |  |  _  |/   \_     |_____|    /   \_ |     | /  \ ||   |   ||   [_   |  |   |  |/   \_ /  \ |
  |  |  |  |  |\     |               \     ||     | \    ||   |   ||     |  |  |   |  |\     |\    |
  |__|  |__|__| \____|                \____| \___/   \___||___|___||_____|  |__|  |____|\____| \___|

----------------------------------------------------------------------------------------------------
)";
                    s3.print_products();

                    int product_index = 0;
                    do {
                        cout << "Choose a product (0 to go back): ";
                        cin >> product_index;
                        if (product_index > 0 && product_index <= s3.products.size()) {
                            // Add product to cart
                            c1.cart.add_item(s3.get_product(product_index - 1));
                            cout << s3.get_product(product_index - 1).name << " added to cart." << endl;
                        }
                    } while (product_index != 0);
                }

                    else if (shop_index == 4) {
                    cout<<R"(
-------------------------------------------------------------------------------------------------------------
_________                                                      _________                         __
\_   ___ \   ____   ______  _____    ____   ______            /   _____/______    ____ _______ _/  |_  ______
/    \  \/  /  _ \ /  ___/ /     \  /  _ \ /  ___/   ______   \_____  \ \____ \  /  _ \\_  __ \\   __\/  ___/
\     \____(  <_> )\___ \ |  Y Y  \(  <_> )\___ \   /_____/   /        \|  |_> >(  <_> )|  | \/ |  |  \___ \
 \______  / \____//____  >|__|_|  / \____//____  >           /_______  /|   __/  \____/ |__|    |__| /____  >
        \/             \/       \/             \/                    \/ |__|                              \/

-------------------------------------------------------------------------------------------------------------
)";
                    s4.print_products();

                    int product_index = 0;
                    do {
                        cout << "Choose a product (0 to go back): ";
                        cin >> product_index;
                        if (product_index > 0 && product_index <= s4.products.size()) {
                            // Add product to cart
                            c1.cart.add_item(s4.get_product(product_index - 1));
                            cout << s4.get_product(product_index - 1).name << " added to cart." << endl;
                        }
                    } while (product_index != 0);


                }
                else if (shop_index == 5) {
                    // Go back
                    break;
                } else {
                    cout << "Invalid option." << endl;
                }
            }
        }
            else if (option == 2) {
                // View Cart
                c1.print();
                int cart_option = 0;
                do {
                    cout<<R"(
============================== CART =================================

-----------------------   1. Remove Item   --------------------------
-----------------------   2. Clear Cart    --------------------------
-----------------------   3. View Cart     --------------------------
-----------------------   4. Back          --------------------------

======================================================================
)";
                    cout << "Choose an option: ";
                    cin >> cart_option;
                    if (cart_option == 1) {
                        int item_index = 0;
                        c1.cart.print();
                        cout << "Choose an item to remove (0 to go back): ";
                        cin >> item_index;
                        if (item_index > 0 && item_index <= c1.cart.items.size()) {
                            c1.cart.remove_item(item_index - 1);
                            cout << "Item removed from cart." << endl;
                        }
                    } else if (cart_option == 2) {
                        c1.cart.clear();
                        cout << "Cart cleared." << endl;
                    } else if(cart_option == 3) {
                        c1.print();
                    }else if (cart_option != 4) {
                        cout << "Invalid option." << endl;
                    }
                } while (cart_option != 4);
            } else if (option == 3) {
                // Checkout
                if (c1.cart.items.empty()) {
                    cout << "Your cart is empty." << endl;
                } else {
                    cout << "Total: $" << c1.cart.total_price() << endl;
                    c1.cart.clear();
                    cout << "Thank you for shopping!" << endl;
                }
            } else if (option != 4) {
                cout << "Invalid option." << endl;
            }
        }while (option != 4);
    return 0;
}
