#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
using namespace std;
struct product
{
    string category;
    string name;
    int price;
    int inventory;
};
struct shoping_cart
{
    string category;
    string name;
    int price;
    int inventory;
};
void add_product(product *&products, int &size, int &capacity);
void remove_product(product *&products, int &size, int &capacity);
void find_product(product *&products, int &size, int &capacity);
void total_value(product *&products, int &size, int &capacity);
void charge_shop_wallet(int *wallet);
void shop_wallet(int *wallet);
void product_inventory(product *&products, int &size, int &capacity);
void show_products(product *&products, int &size, int &capacity);
void charge_c_wallt(int *wallet);
void customer_wallet(int *wallet);
void show_cart(shoping_cart *&cart, int &cart_size, int &cart_capacity);
void add_to_cart(product *&products, int &size, int &capcity, shoping_cart *&cart, int &cart_size, int &cart_capacity);
void buy_all(int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity, int *sh_wallet, product *&products, int &size, int &capacity);
void admin_menu(product *&products, int &size, int &capacity, int *sh_wallet, int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity);
void customer_menu(product *&products, int &size, int &capacity, int *sh_wallet, int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity);
void public_menu(product *&products, int &size, int &capacity, int *sh_wallet, int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity);

void add_product(product *&products, int &size, int &capacity)
{
    system("cls");
    if (size == capacity)
    {
        capacity += 1;
        product *newproducts = new product[capacity];
        for (int i = 0; i < size; i++)
        {
            newproducts[i] = products[i];
        }
        delete[] products;
        products = newproducts;
    }
    cout << "please enter the details of the product which you want to add" << endl
         << "whitch category do you want to add a product in?(enter its number)\n";
    Sleep(800);
    cout << "1.game\n2.console\n3.monitor\n4.headset\n"
         << "category: ";
    int a;
    cin >> a;
    // cin >> products[size].category;
    switch (a)
    {
    case 1:
        products[size].category = "game";
        Sleep(800);
        cout << "name: ";
        cin >> products[size].name;
        Sleep(800);
        cout << "price: ";
        cin >> products[size].price;
        if (products[size].price <= 0)
        {
            cout << "the price of product should be between larger than 1\n";
            Sleep(2000);
            cout << "price: ";
            cin >> products[size].price;
        }
        Sleep(800);
        cout << "inventory: ";
        cin >> products[size].inventory;
        if (products[size].inventory <= 0)
        {
            cout << "the inventory of product should be between larger than 1\n";
            Sleep(2000);
            cout << "inventory: ";
            cin >> products[size].inventory;
        }
        size++;
        break;
    case 2:
        products[size].category = "console";
        Sleep(800);
        cout << "name: ";
        cin >> products[size].name;

        Sleep(800);
        cout << "price: ";
        cin >> products[size].price;
        if (products[size].price <= 0)
        {
            cout << "the price of product should be between larger than 1\n";
            Sleep(2000);
            cout << "price: ";
            cin >> products[size].price;
        }
        Sleep(800);
        cout << "inventory: ";
        cin >> products[size].inventory;
        if (products[size].inventory <= 0)
        {
            cout << "the inventory of product should be between larger than 1\n";
            Sleep(2000);
            cout << "inventory: ";
            cin >> products[size].inventory;
        }
        size++;
        break;
    case 3:
        products[size].category = "monitor";
        Sleep(800);
        cout << "name: ";
        cin >> products[size].name;
        Sleep(800);
        cout << "price: ";
        cin >> products[size].price;
        if (products[size].price <= 0)
        {
            cout << "the price of product should be between larger than 1\n";
            Sleep(2000);
            cout << "price: ";
            cin >> products[size].price;
        }
        Sleep(800);
        cout << "inventory: ";
        cin >> products[size].inventory;
        if (products[size].inventory <= 0)
        {
            cout << "the inventory of product should be between larger than 1\n";
            Sleep(2000);
            cout << "inventory: ";
            cin >> products[size].inventory;
        }
        size++;
        break;
    case 4:
        products[size].category = "headset";
        Sleep(800);
        cout << "name: ";
        cin >> products[size].name;
        Sleep(800);
        cout << "price: ";
        cin >> products[size].price;
        if (products[size].price <= 0)
        {
            cout << "the price of product should be between larger than 1\n";
            Sleep(2000);
            cout << "price: ";
            cin >> products[size].price;
        }
        Sleep(800);
        cout << "inventory: ";
        cin >> products[size].inventory;
        if (products[size].inventory <= 0)
        {
            cout << "the inventory of product should be between larger than 1\n";
            Sleep(2000);
            cout << "inventory: ";
            cin >> products[size].inventory;
        }
        size++;
        break;
    default:
        system("cls");
        cout << "please enter a number(1-2-3-4)\n";
        Sleep(1500);
        break;
    }
}
void remove_product(product *&products, int &size, int &capacity)
{
    system("cls");
    Sleep(800);
    cout << "please enter the name of the product you want to remove?" << endl;
    string a;
    cin >> a;
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (a == products[i].name)
        {
            cout << "your product has been founded!" << endl;
            Sleep(800);
            cout << i + 1 << "." << products[i].name << endl;
            Sleep(800);
            cout << "the product inventory is: " << products[i].inventory << endl;
            Sleep(800);
            cout << "do you want to remove all of it?\n1.yes\n2.no" << endl;
            int b;
            cin >> b;
            if (b == 1)
            {
                products[i].inventory = 0;
                system("cls");
            }
            else if (b == 2)
            {
                cout << "please enter your considered number between (1 to " << products[i].inventory - 1 << ")" << endl;
                int c;
                cin >> c;
                if (c > 0 && c < products[i].inventory - 1)
                {
                    products[i].inventory = products[i].inventory - c;
                    system("cls");
                }
                else
                {
                    cout << "wrong input!\n";
                    cout << "please enter your considered number between (1 to " << products[i].inventory - 1 << ")" << endl;
                    int c;
                    cin >> c;
                    products[i].inventory = products[i].inventory - c;
                    system("cls");
                }
            }
            else
            {
                cout << "you entered wrong number!\n";
                Sleep(1000);
                remove_product(products, size, capacity);
            }
            c++;
        }
    }
    if (c == 0)
    {
        cout << "not found a game to remove with that name! \n";
        Sleep(1200);
        system("cls");
    }
}
void find_product(product *&products, int &size, int &capacity)
{
    system("cls");
    cout << "please enter the name of the product you want to find." << endl;
    string a;
    cin >> a;
    int b = 0;
    for (int i = 0; i < size; i++)
    {
        if (products[i].name == a)
        {
            system("cls");
            Sleep(1000);
            cout << "your product has been founded!\n";
            cout << left << setw(16) << "|category" << left << setw(16) << "|name" << left << setw(16) << "|price" << left << setw(16) << "|inventory" << "|" << endl;
            cout << "|" << left << setw(15) << products[i].category << "|" << left << setw(15) << products[i].name << "|" << left << setw(15) << products[i].price << "|" << left << setw(15) << products[i].inventory << "|" << endl;
            b++;
        }
    }
    if (b == 0)
    {
        cout << "no products found!" << endl;
        Sleep(1000);
        system("cls");
    }
}
void total_value(product *&products, int &size, int &capacity)
{
    system("cls");
    int t = 0;
    for (int i = 0; i < size; i++)
    {
        t += products[i].inventory * products[i].price;
    }
    cout << "the total value of the products of shop is: " << t << endl;
}
void charge_shop_wallet(int *wallet)
{
    system("cls");
    int a;
    cout << "how much do you want to charge?\nplease enter here: ";
    cin >> a;
    *wallet += a;
}
void shop_wallet(int *wallet)
{
    system("cls");
    cout << "shop balance: " << *wallet << endl;
}
void product_inventory(product *&products, int &size, int &capacity)
{
    int a = 0;
    for (int i = 0; i < size; i++)
    {
        if (products[i].inventory > 0)
        {
            cout << i + 1 << ".product: " << products[i].name << "| inventory: " << products[i].inventory << endl;
            a++;
        }
    }
    if (a == 0)
    {
        cout << "there is no product to show!\n";
    }
}
void show_products(product *&products, int &size, int &capacity)
{
    system("cls");
    if (size == 0)
    {
        cout << "no products available" << endl;
        return;
    }
    cout << left << setw(16) << "|category" << left << setw(16) << "|name" << left << setw(16) << "|price" << left << setw(16) << "|inventory" << "|" << endl;

    for (int i = 0; i < size; i++)
    {
        if (products[i].inventory != 0)
        {
            cout << "|" << left << setw(15) << products[i].category << "|" << left << setw(15) << products[i].name << "|" << left << setw(15) << products[i].price << "|" << left << setw(15) << products[i].inventory << "|" << endl;
        }
    }
}
void charge_c_wallt(int *wallet)
{
    system("cls");
    int a;
    cout << "how much do you want to charge?\nplease enter here: ";
    cin >> a;
    *wallet += a;
}
void customer_wallet(int *wallet)
{
    system("cls");
    cout << "your wallet balance is: " << *wallet << endl;
}
void show_cart(shoping_cart *&cart, int &cart_size, int &cart_capacity)
{
    if (cart_size == 0)
    {
        cout << "there is no products available in your shoping cart!" << endl;
        return;
    }
    cout << left << setw(16) << "|category" << left << setw(16) << "|name" << left << setw(16) << "|price" << left << setw(16) << "|inventory" << "|" << endl;

    for (int i = 0; i < cart_size; i++)
    {
        if (cart[i].inventory != 0)
        {
            cout << "|" << left << setw(15) << cart[i].category << "|" << left << setw(15) << cart[i].name << "|" << left << setw(15) << cart[i].price << "|" << left << setw(15) << cart[i].inventory << "|" << endl;
        }
    }
}
void add_to_cart(product *&products, int &size, int &capcity, shoping_cart *&cart, int &cart_size, int &cart_capacity)
{
    cout << "enter the name of the product you want to add to your shoping cart:\n";
    string name;
    cin >> name;
    for (int i = 0; i < size; i++)
    {

        if (products[i].name == name)
        {
            cout << "enter the inventory to add to the cart between: 1 to " << products[i].inventory << endl;
            int inventory;
            cin >> inventory;
            if (inventory > 0)
            {
            }
            if (cart_size == cart_capacity)
            {
                cart_capacity += 1;
                shoping_cart *new_cart = new shoping_cart[cart_capacity];
                for (int i = 0; i < cart_size; i++)
                {
                    new_cart[i] = cart[i];
                }
                delete[] cart;
                cart = new_cart;
            }
            cart[cart_size].category = products[i].category;
            cart[cart_size].name = products[i].name;
            cart[cart_size].price = products[i].price;
            cart[cart_size].inventory = inventory;
            cart_size++;
        }
    }
}
void buy_all(int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity, int *sh_wallet, product *&products, int &size, int &capacity)
{
    system("cls");
    int a = 0;
    for (int i = 0; i < cart_size; i++)
    {
        a += cart[i].inventory * cart[i].price;
    }
    // cout<<a;
    if (*cu_wallet < a)
    {
        cout << "you don't have enough money\n";
    }
    else
    {
        for (int i = 0; i < cart_size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (cart[i].name == products[j].name)
                {
                    products[i].inventory = products[i].inventory - cart[i].inventory;
                    cart[i].inventory = 0;
                }
            }
        }
        *sh_wallet += a;
        *cu_wallet = *cu_wallet - a;
    }
}
void show_by_category(product *&products, int &size, int &capacity)
{
    system("cls");
    string a;
    cout << "whitch category do you want to see its products?\n";
    cin >> a;
    int b = 0;
    cout << left << setw(16) << "|category" << left << setw(16) << "|name" << left << setw(16) << "|price" << left << setw(16) << "|inventory" << "|" << endl;
    for (int i = 0; i < size; i++)
    {
        if (a == products[i].category)
        {
            if (products[i].inventory != 0)
            {
                cout << "|" << left << setw(15) << products[i].category << "|" << left << setw(15) << products[i].name << "|" << left << setw(15) << products[i].price << "|" << left << setw(15) << products[i].inventory << "|" << endl;
            }
            b++;
        }
    }
    if (b == 0)
    {
        cout << "|" << left << setw(15) << "/:" << "|" << left << setw(15) << "/:" << "|" << left << setw(15) << "/:" << "|" << left << setw(15) << "/:" << "|" << endl;
        cout << "there is no product exist in this category!\n";
    }
}
void admin_menu(product *&products, int &size, int &capacity, int *sh_wallet, int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity)
{
    // system("cls");
    cout << "Whitch one do you want to do?" << endl;
    Sleep(1000);
    cout << "1.Add a product" << endl;
    Sleep(100);
    cout << "2.Remove a product" << endl;
    Sleep(100);
    cout << "3.Find a product by searching the name" << endl;
    Sleep(100);
    cout << "4.Total value of products" << endl;
    Sleep(100);
    cout << "5.Charging shops wallet " << endl;
    Sleep(100);
    cout << "6.Shops balance" << endl;
    Sleep(100);
    cout << "7.Products inventory" << endl;
    Sleep(100);
    cout << "8.Show info of the all products" << endl;
    Sleep(100);
    cout << "9.Back to the main menu" << endl;
    Sleep(100);

    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        add_product(products, size, capacity);
        system("cls");
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 2:
    {
        remove_product(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 3:
    {
        find_product(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 4:
    {
        total_value(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 5:
    {
        charge_shop_wallet(sh_wallet);
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 6:
    {
        shop_wallet(sh_wallet);
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 7:
    {
        system("cls");
        product_inventory(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 8:
    {
        show_products(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 9:
        public_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    default:
    {
    }
    }
}
void customer_menu(product *&products, int &size, int &capacity, int *sh_wallet, int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity)
{
    // system("cls");
    cout << "Whitch one do you want to do?" << endl;
    Sleep(1000);
    cout << "1.Products inventory" << endl;
    Sleep(100);
    cout << "2.Find a product by searching the name" << endl;
    Sleep(100);
    cout << "3.Charging wallet" << endl;
    Sleep(100);
    cout << "4.Wallet balance" << endl;
    Sleep(100);
    cout << "5.Show shopping cart" << endl;
    Sleep(100);
    cout << "6.Add a product to the shoping cart" << endl;
    Sleep(100);
    cout << "7.Buy all the products in the shoping cart" << endl;
    Sleep(100);
    cout << "8.Show products by category" << endl;
    Sleep(100);
    cout << "9.Back to main menu" << endl;
    Sleep(100);

    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        customer_wallet(cu_wallet);
        product_inventory(products, size, capacity);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 2:
    {
        find_product(products, size, capacity);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 3:
    {
        charge_c_wallt(cu_wallet);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 4:
    {
        customer_wallet(cu_wallet);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 5:
    {
        customer_wallet(cu_wallet);
        show_cart(cart, cart_size, cart_capacity);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 6:
    {
        customer_wallet(cu_wallet);
        add_to_cart(products, size, capacity, cart, cart_size, cart_capacity);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 7:
    {
        buy_all(cu_wallet, cart, cart_size, cart_capacity, sh_wallet, products, size, capacity);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 8:
    {
        show_by_category(products, size, capacity);
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    case 9:
    {
        public_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    default:
    {
    }
    }
}
void public_menu(product *&products, int &size, int &capacity, int *sh_wallet, int *cu_wallet, shoping_cart *&cart, int &cart_size, int &cart_capacity)
{
    system("cls");
    int a;
    cout << "Do you want to login as a" << endl
         << "1.Admin" << endl
         << "2.Customer" << endl;
    cin >> a;
    system("cls");
    switch (a)
    {
    case 1:
    {
        cout << "please enter password" << endl
             << ": ";
        string pass;
        cin >> pass;
        if (pass == "admin1admin")
        {
            system("cls");
            cout << "correct password!\nplease wait";
            Sleep(800);
            cout << ".";
            Sleep(800);
            cout << ".";
            Sleep(800);
            cout << ".";
            Sleep(800);
            system("cls");
            cout << "Welcome to the shop management!" << endl;
            Sleep(1500);
            system("cls");
            admin_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        }
        else
        {
            system("cls");
            cout << "wrong password!\n";
            Sleep(1000);
            public_menu(products, size, capacity, sh_wallet, sh_wallet, cart, cart_size, cart_capacity);
        }
        break;
    }
    case 2:
    {
        cout << "please wait";
        Sleep(800);
        cout << ".";
        Sleep(800);
        cout << ".";
        Sleep(800);
        cout << ".";
        Sleep(800);
        system("cls");
        cout << "Welcome to the shop!\n";
        Sleep(1500);
        system("cls");
        customer_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    default:
    {
        cout << "enter a number (1 or 2)!\n";
        Sleep(1500);
        public_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
        break;
    }
    }
}
int main()
{
    int size = 0;
    int capacity = 2;
    product *products = new product[capacity];
    int s_wallet = 0;
    int *sh_wallet = &s_wallet;
    int c_wallet = 1000;
    int *cu_wallet = &c_wallet;
    int cart_size = 0;
    int cart_capacity = 2;
    shoping_cart *cart = new shoping_cart[cart_capacity];
    system("cls");
    public_menu(products, size, capacity, sh_wallet, cu_wallet, cart, cart_size, cart_capacity);
    delete[] products;
    delete[] cart;
}