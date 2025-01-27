#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct product
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
void admin_menu(product *&products, int &size, int &capacity, int *sh_wallet);
void customer_menu();
void public_menu(product *&products, int &size, int &capacity, int *sh_wallet);
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
         << "game-console-monitor-headset\n"
         << "category: ";
    cin >> products[size].category;
    cout << "name: ";
    cin >> products[size].name;
    cout << "price: ";
    cin >> products[size].price;
    cout << "inventory: ";
    cin >> products[size].inventory;

    size++;
}
void remove_product(product *&products, int &size, int &capacity)
{
    system("cls");
    cout << "please enter the name of the product you want to remove?" << endl;
    string a;
    cin >> a;
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (a == products[i].name)
        {
            cout << "your product has been founded!" << endl
                 << i + 1 << "." << products[i].name << endl
                 << "the product inventory is: " << products[i].inventory << endl
                 << "do you want to remove all of it?\n1.yes\n2.no" << endl;
            int b;
            cin >> b;
            if (b == 1)
            {
                products[i].inventory = 0;
            }
            else
            {
                cout << "please enter your considered number between (1 to " << products[i].inventory - 1 << ")" << endl;
                int c;
                cin >> c;
                products[i].inventory = products[i].inventory - c;
            }
            c++;
        }
    }
    if (c == 0)
    {
        cout << "not found a game to remove with that name! \nplease try again\n";
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
            cout << "your product has been founded!\n";
            //          << i + 1 << "." << products[i].name << endl
            //          << "category:" << products[i].category << endl
            //          << "price:" << products[i].price << endl
            //          << "inventory:" << products[i].inventory << endl;
            cout << left << setw(16) << "|category" << left << setw(16) << "|name" << left << setw(16) << "|price" << left << setw(16) << "|inventory" << "|" << endl;
            cout << "|" << left << setw(15) << products[i].category << "|" << left << setw(15) << products[i].name << "|" << left << setw(15) << products[i].price << "|" << left << setw(15) << products[i].inventory << "|" << endl;
            b++;
        }
    }
    if (b == 0)
    {
        cout << "no products found!" << endl;
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
    system("cls");
    for (int i = 0; i < size; i++)
    {
        cout << "product: " << products[i].name << endl
             << "inventory: " << products[i].inventory << endl;
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
    // for(int i=0;i<size;i++){
    //     cout<<i+1<<"."
    //         << products[i].category<<endl;
    // }
    cout << left << setw(16) << "|category" << left << setw(16) << "|name" << left << setw(16) << "|price" << left << setw(16) << "|inventory" << "|" << endl;

    for (int i = 0; i < size; i++)
    {
        if (products[i].inventory != 0)
        {
            cout << "|" << left << setw(15) << products[i].category << "|" << left << setw(15) << products[i].name << "|" << left << setw(15) << products[i].price << "|" << left << setw(15) << products[i].inventory << "|" << endl;
        }
    }
}
void admin_menu(product *&products, int &size, int &capacity, int *sh_wallet)
{
    // system("cls");
    cout << "1.Add a product" << endl
         << "2.Remove a product" << endl
         << "3.Find a product by searching the name" << endl
         << "4.Total value of products" << endl
         << "5.Charging shops wallet " << endl
         << "6.Shops balance" << endl
         << "7.Products inventory" << endl
         << "8.Show info of the all products" << endl
         << "9.Back to the main menu" << endl
         << "Whitch one do you want to do?" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        add_product(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 2:
    {
        remove_product(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 3:
    {
        find_product(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 4:
    {
        total_value(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 5:
    {
        charge_shop_wallet(sh_wallet);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 6:
    {
        shop_wallet(sh_wallet);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 7:
    {
        product_inventory(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 8:
    {
        show_products(products, size, capacity);
        admin_menu(products, size, capacity, sh_wallet);
        break;
    }
    case 9:
        public_menu(products, size, capacity, sh_wallet);
        break;
    default:
    {
    }
    }
}
void customer_menu()
{
    // system("cls");
    cout << "1.products inventory" << endl
         << "2.find a product" << endl
         << "3.top up wallet" << endl
         << "4.balance of money" << endl
         << "5.shopping cart" << endl
         << "6.Buy a product" << endl
         << "7.show products by category" << endl;
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
    {
        cout << "1" << endl
             << "11";
        break;
    }
    case 2:
    {
        cout << "2";
        break;
    }
    case 3:
    {
    }
    case 4:
    {
    }
    case 5:
    {
    }
    case 6:
    {
    }
    case 7:
    {
    }
    case 8:

    {
    }
    default:
    {
    }
    }
}
void public_menu(product *&products, int &size, int &capacity, int *sh_wallet)
{
    int a;
    cout << "Do you want to login as a" << endl
         << "1.Admin" << endl
         << "2.Customer" << endl;
    cin >> a;
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
            cout << "Welcome to the shop management" << endl;
            admin_menu(products, size, capacity, sh_wallet);
        }
        else
        {
            public_menu(products, size, capacity, sh_wallet);
        }
        break;
    }
    case 2:
    {
        cout << "Welcome to the shop";
        customer_menu();
        break;
    }
    default:
    {
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
    system("cls");
    public_menu(products, size, capacity, sh_wallet);
    delete[] products;
}
