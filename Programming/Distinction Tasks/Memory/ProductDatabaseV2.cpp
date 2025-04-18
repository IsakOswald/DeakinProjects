#include "splashkit.h"
#include <iostream> // For dynamic memory management

/*
TODO
Create a function to add new products
Create a function to get a valid integer input
Create a function to get a valid double input
Create a function to read string
Create a function to print the number of products out
Create a function to remove a product from the product_data struct
Create a function to split terminal output nicely
Create a function to update a existing product
Create a function to give user options when modifiying a product (name, quantity, etc)
Create a function to Sell a product
Create a function to print products which are low on stock
Create a function to calculate the on-hand value
Create a function to print the status of the shop
Create a function to print the main menu and return the input needed for the switch statement
*/

// Create a struct which holds each product's data.
struct product_data
{
    string name;
    double cost;
    double sales_price;
    int inventory;
};

// Create a store struct
struct shop_data
{
    product_data *products; // Pointer to a dynamic array of products
    int current_product_num;
    int capacity; // Current capacity of the dynamic array
    double total_sales_value;
    double total_profit;
};

// Functions *******************************
void add_new_product(shop_data &shop);
int get_valid_integer(string prompt);
double get_valid_double(string prompt);
string read_string(string prompt);
void print_products(const shop_data &shop);
void remove_product(shop_data &shop);
void print_splitter();
void update_product(shop_data &shop);
void update_menu();
void sell_product(shop_data &shop);
void low_stock_products(shop_data &shop);
void on_hand_value(const shop_data &shop);
void print_status(shop_data &shop);
int menu();
void resize_products(shop_data &shop);

//*****************************************

int main()
{
    shop_data shop;
    shop.products = new product_data[2]; // Start with a small capacity
    shop.current_product_num = 0;
    shop.capacity = 2;
    shop.total_sales_value = 0;
    shop.total_profit = 0;

    int choice;
    do
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            add_new_product(shop);
            break;
        case 2:
            remove_product(shop);
            break;
        case 3:
            update_product(shop);
            break;
        case 4:
            sell_product(shop);
            break;
        case 5:
            print_status(shop);
            break;
        case 6:
            write_line("Quitting!");
            break;
        default:
            write_line("Not a valid entry!");
            break;
        }
    } while (choice != 6);

    // Free the dynamically allocated memory
    delete[] shop.products;

    return 0;
}

// Resize the dynamic array when needed
void resize_products(shop_data &shop)
{
    // Double the capacity
    int new_capacity = shop.capacity * 2;
    product_data *new_products = new product_data[new_capacity];

    // Copy existing products to the new array
    for (int i = 0; i < shop.current_product_num; i++)
    {
        new_products[i] = shop.products[i];
    }

    // Delete the old array and update the pointer
    delete[] shop.products;
    shop.products = new_products;
    shop.capacity = new_capacity;
}

// Allow the user to add a new product to the shop
void add_new_product(shop_data &shop)
{
    print_splitter();

    // Resize the array if it's full
    if (shop.current_product_num >= shop.capacity)
    {
        resize_products(shop);
    }

    product_data new_product;
    new_product.name = read_string("Enter product name: ");
    new_product.cost = get_valid_double("Enter the cost of the item: ");
    new_product.sales_price = get_valid_double("Enter the sales price of the product: ");
    new_product.inventory = get_valid_integer("Enter inventory amount: ");

    // Add the new product to the array
    shop.products[shop.current_product_num] = new_product;
    shop.current_product_num++;

    write_line("");
    write_line("You successfully added " + new_product.name + " to the shop");
    write_line("This product was added as product No. " + std::to_string(shop.current_product_num) + "\n");
}

// Remove a product from the list
void remove_product(shop_data &shop)
{
    print_splitter();

    bool found = false;
    string to_remove = to_lowercase(read_string("What do you want to remove?: "));

    // Iterate through the list of products.
    for (int i = 0; i < shop.current_product_num; i++)
    {
        // Search for the name of the product and compare it to the user input.
        if (to_lowercase(shop.products[i].name) == to_remove)
        {
            // Shift all elements after the removed product to the left
            for (int j = i; j < shop.current_product_num - 1; j++)
            {
                shop.products[j] = shop.products[j + 1];
            }

            found = true;
            shop.current_product_num--;

            write_line(shop.products[i].name + " was removed! \n");
            print_products(shop);

            break;
        }
    }

    // If there was no product that matched the user input, output that it was not found.
    if (!found)
    {
        write("The product was not in the list! \n");
    }
}

// Allow the user to update the attributes of an existing product.
void update_product(shop_data &shop)
{
    print_splitter();

    string input = to_lowercase(read_string("What product would you like to update?: "));
    bool found = false;

    // Iterate through the list.
    for (int i = 0; i < shop.current_product_num; i++)
    {
        // Check if the input matches the name of the product.
        if (to_lowercase(shop.products[i].name) == input)
        {
            found = true;

            update_menu();

            int choice = get_valid_integer("Enter a choice: ");

            switch (choice)
            {
            case 1:
                shop.products[i].name = read_string("Enter product name: ");
                break;
            case 2:
                shop.products[i].cost = get_valid_double("Enter the cost of the item: ");
                break;
            case 3:
                shop.products[i].sales_price = get_valid_double("Enter the sales price of the product: ");
                break;
            case 4:
                shop.products[i].inventory = get_valid_integer("Enter inventory amount: ");
                break;
            case 5:
                write_line("Quitting....");
                break;
            default:
                write_line("ERROR 404. Option Not found");
            }
        }
    }

    if (!found)
    {
        write_line("Product not found!");
    }
}

// Print all the products.
void print_products(const shop_data &shop)
{
    print_splitter();

    write("You have: ");
    for (int i = 0; i < shop.current_product_num; i++)
    {
        write(shop.products[i].name + " | ");
    }

    write("in stock! \n \n");
}

// Check if a input is a integer.
int get_valid_integer(string prompt)
{
    write(prompt);
    string input = read_line();

    // Validate the user input is an integer.
    while ((!is_integer(input)) || (std::stoi(input) < 0))
    {
        write("Please enter a valid integer: ");
        input = read_line();
    }

    return std::stoi(input);
}

// Same as the get_valid_integer function however for a double input.
double get_valid_double(string prompt)
{
    write(prompt);
    string input = read_line();

    while ((!is_double(input)) || (std::stod(input) < 0))
    {
        write("Please enter a valid integer: ");
        input = read_line();
    }

    return std::stod(input);
}

// Get a string input from user.
string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

// A splitter to make the output neat.
void print_splitter()
{
    write_line("**********************");
}

// Print the options the user has to update an existing product.
void update_menu()
{
    print_splitter();

    write_line("1. Modify name");
    write_line("2. Modify cost");
    write_line("3. Modify sales price");
    write_line("4. Modify inventory");
    write_line("5. Quit");
}

// Sell a product.
void sell_product(shop_data &shop)
{
    print_splitter();
    string input = to_lowercase(read_string("What product would you like to sell?: "));
    bool found = false;
    int sell_ammount;

    // Find the product name and see if it matches an existing product.
    for (int i = 0; i < shop.current_product_num; i++)
    {
        if (to_lowercase(shop.products[i].name) == input)
        {
            found = true;
            sell_ammount = get_valid_integer("How many products would you like to sell?: ");
            // Make sure they cant sell into negative numbers
            while (sell_ammount > shop.products[i].inventory)
            {
                sell_ammount = get_valid_integer("You can't sell that many, re-enter: ");
            }
            // Subtract the items sold from the products inventory.
            shop.products[i].inventory -= sell_ammount;

            // Update the total profit based on these sales.
            shop.total_profit += (sell_ammount * shop.products[i].sales_price) - sell_ammount * shop.products[i].cost;

            // Calculate the total sales value based on tese sales.
            shop.total_sales_value += sell_ammount * shop.products[i].sales_price;
            break;
        }
    }

    // If the product is not found output it could not be found
    if (!found)
    {
        write_line("Product could not be found :(");
    }
}

// Check the ammount of all on hand products.
void on_hand_value(const shop_data &shop)
{
    double total = 0;

    for (int i = 0; i < shop.current_product_num; i++)
    {
        // Add the product to the total.
        total += shop.products[i].sales_price * shop.products[i].inventory;
    }

    write_line("The total value of your inventory is: " + std::to_string(total));
}

// Check the products low on stock.
void low_stock_products(shop_data &shop)
{
    print_splitter();

    for (int i = 0; i < shop.current_product_num; i++)
    { // Check if the products inventory is less then 10.
        if (shop.products[i].inventory < 10)
        {
            write_line(shop.products[i].name + " is low on stock!");
        }
    }
}

// Output all of the previous functions created.
void print_status(shop_data &shop)
{
    print_splitter();

    write("Products low on stock include of: ");
    low_stock_products(shop);
    write("\n");

    write_line("Total sales value is : $" + std::to_string(shop.total_sales_value));

    write_line("Total profit is: $" + std::to_string(shop.total_profit));

    write_line("Total number of products are: " + std::to_string(shop.current_product_num));

    on_hand_value(shop);
}

// Print the main menu options.
int menu()
{
    print_splitter();

    write_line("1. Add a new product");
    write_line("2. Delete a product");
    write_line("3. Update a product");
    write_line("4. Sell a product");
    write_line("5. Print status");
    write_line("6. QUIT!");

    // Return the option chosen making sure its valid.
    return get_valid_integer("What do you want to do?: ");
}