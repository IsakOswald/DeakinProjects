//! Start of header file
#pragma once

//* Our libs and headers for the project.
#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "splashkit.h"

// A function which allows us to get a double based on the prompt
double get_double(std::string prompt)
{
    std::string input;

    write(prompt);
    input = read_line();

    while (!is_double(input))
    {
        write_line("Please enter a valid number!");
        input = read_line();
    }

    return std::stod(input);
}

// A function which allows us to get a double based on the prompt
int get_int(std::string prompt)
{
    std::string input;

    write(prompt);
    input = read_line();

    while (!is_integer(input))
    {
        write_line("Please enter a valid number!");
        input = read_line();
    }

    return std::stoi(input);
}

// A function for nicely formatted terminal output
void print_splitter() { write_line("*********************"); }

//! End of header file

// Include our header we made.
// #include "helper.h" Uncomment this later if needed. I have pasted the header in here for readibility (for tutor)

// Forward declarations.
class User;
class Travel;
class Transport;

// Our functions we will be using in main
void run_program();
void print_menu();

class Location
{
   public:
    std::string name;
    std::string description;

    // The default constructor
    Location()
    {
        name = "Not set.";
        description = "Not set.";
    }

    // A function to add a new location to the existing array.
    void add_location()
    {
        print_splitter();
        write("Enter the location name: ");
        std::string input = read_line();
        name = input;

        write("Enter the description of " + name + ": ");
        input = read_line();
        description = input;
    }
};

// The user class, this holds all relevant user data.
class User
{
    // Some private variables we dont want to be accessed outside of the class.
   private:
    std::string usr_name;
    std::string password;
    Location* current_location;
    double balance;

   public:
    // A constructor for the class
    User()
    {
        usr_name = "No name set yet!";
        balance = 0;
        current_location = nullptr;
    }

    // A function that gets the users initial name and balance
    void set_initial()
    {
        print_splitter();

        write("Enter your name: ");
        usr_name = read_line();

        std::cout << '\n';

        balance = get_double("Enter your initial balance: ");
    }

    void set_home_address(Location* current_location) { this->current_location = current_location; }

    // A function to print the users name and current balance
    void print_attributes()
    {
        print_splitter();

        write_line("Username -> " + usr_name);
        write_line("Current Balance -> " + std::to_string(balance));
    }

    // Print the current location of the user
    void print_current_location()
    {
        // Make sure that they do have a current location set.
        if (current_location == nullptr)
        {
            write_line("Error: Current location is not set!");
        }
        else
        {
            write_line("You are currently at " + current_location->name);
        }
    }

    // A function to top up the users balance
    void top_up_balance()
    {
        print_splitter();
        double topup;

        get_double("Enter the amount you want to top up: ");

        balance += topup;
    }

    // A getter for the balance
    double get_balance() const { return balance; }

    // Deduct the balance. Will be used when traveling.
    void deduct_balance(double amount) { balance -= amount; }
};

class Transport
{
   public:
    double cost;
    std::string name;
    std::string description;
    double speed;

    // Transport default constructor.
    Transport()
    {
        name = "Unknown";
        speed = 0;
        cost = 0;
        description = "Unknown";
    }

    // A constructor
    Transport(std::string name, double speed, double cost, std::string description)
    {
        this->name = name;
        this->speed = speed;
        this->cost = cost;
        this->description = description;
    }
};

class Travel
{
   private:
    Transport methods[5];
    int destinations_options;
    int destinations_capacity;

   public:
    Location* destinations;
    // A constructor
    Travel()
    {
        destinations = nullptr;
        destinations_options = 0;
        destinations_capacity = 0;

        // Set the transport methods.
        methods[0] = Transport("Tram", 60, 3, "Safe option. You arrived at your destination pretty fast!");
        methods[1] = Transport("Walking", 5, 0, "Maybe not the best option if you are walking far. You were late to your destination!");
        methods[2] = Transport("Bike", 15, 0, "Good choice. You almost crashed though.");
        methods[3] = Transport("Bus", 45, 3.75, "Great! You missed the bus and had to walk.");
        methods[4] = Transport("Train", 150, 5, "The fastest of them all, has limited accessibility though.");
    }

    // A function to print the available travel methods.
    void print_travel_methods()
    {
        print_splitter();
        write_line("The Methods available are shown below.");

        // Loop through the travel methods array
        for (int i = 0; i < 5; i++)
        {
            write_line("Name: " + methods[i].name);
            write_line("Cost: " + std::to_string(methods[i].cost));
        }
    }

    // A function to create the array dynamically
    void create_dynamic_array()
    {
        print_splitter();
        write_line("We have created the first location called My Home for you!");
        destinations_options = get_int("How many destinations would you like to create?: ");
        // Give the user some room to add new destinations
        destinations_capacity = (destinations_options * 2);

        // Dynamically created.
        destinations = new Location[destinations_capacity];

        // Automatically set up the home location
        destinations_options = 1;
        destinations[0].name = "My home";
        destinations[0].description = "Where I live";

        populate_destination();
    }

    // A function to fill the array
    void populate_destination()
    {
        print_splitter();
        std::string input;

        // Loop through based on the size of the array.
        for (int i = destinations_options; i <= destinations_capacity / 2; i++)
        {
            write("Enter the name of location " + std::to_string(i + 1) + ": ");
            input = read_line();
            destinations[i].name = input;

            write("Enter a description for location " + std::to_string(i + 1) + " please: ");
            input = read_line();
            destinations[i].description = input;

            destinations_options++;

            write('\n');
        }
    }

    // Print the users list of locations
    void print_destinations()
    {
        print_splitter();
        write_line("Your destinations are: ");
        // Loop through all the locations
        for (int i = 0; i < destinations_options; i++)
        {
            write_line(std::to_string(i + 1) + ": " + destinations[i].name);
        }
    }

    // A function to add a destination to the array
    void add_destination()
    {
        if (destinations_options >= destinations_capacity)
        {
            write_line("Cannot add more destinations. The array is full.");
            return;
        }

        write("Enter the name of the new destination: ");
        std::string input = read_line();
        destinations[destinations_options].name = input;

        write("Enter a description for the new destination: ");
        input = read_line();
        destinations[destinations_options].description = input;

        destinations_options++;
        write_line("New destination added successfully!");
    }

    void remove_destination()
    {
        // Check if there are any destinations to begin with
        if (destinations_options == 0)
        {
            write_line("No destinations to remove.");
            return;
        }

        write("Enter the name of the destination to remove: ");
        std::string name_to_remove = read_line();

        // Find the destination to remove
        int index_to_remove = -1;
        for (int i = 0; i < destinations_options; i++)
        {
            if (destinations[i].name == name_to_remove)
            {
                index_to_remove = i;
                break;
            }
        }
        // Check if the index exists
        if (index_to_remove == -1)
        {
            write_line("Destination not found.");
            return;
        }

        // Shift all destinations to the left to fill the gap
        for (int i = index_to_remove; i < destinations_options - 1; i++)
        {
            destinations[i] = destinations[i + 1];
        }

        // Decrement the number of filled destinations
        destinations_options--;

        write_line("Destination removed successfully!");
    }

    void travel_to_location(User& user)
    {
        // Check if destinations array is initialized
        if (destinations == nullptr || destinations_options == 0)
        {
            write_line("No destinations available to travel to. Please set your destinations first.");
            return;
        }

        // Check if the user has enough balance for at least one transport method
        bool can_afford_transport = false;
        for (int i = 0; i < 5; i++)
        {
            if (user.get_balance() >= methods[i].cost)
            {
                can_afford_transport = true;
                break;
            }
        }

        // Check if the user can afford the transport
        if (!can_afford_transport)
        {
            write_line("You do not have enough balance to afford any transport method.");
            return;
        }

        // Display available destinations
        print_splitter();
        write_line("Available destinations:");
        for (int i = 0; i < destinations_options; i++)
        {
            write_line(std::to_string(i + 1) + ": " + destinations[i].name);
        }

        // Prompt the user to select a destination
        write("Enter the name of the destination you want to travel to: ");
        std::string destination_name = read_line();

        // Find the selected destination
        int destination_index = -1;
        for (int i = 0; i < destinations_options; i++)
        {
            if (destinations[i].name == destination_name)
            {
                destination_index = i;
                break;
            }
        }

        // Check if the user's destination was not found
        if (destination_index == -1)
        {
            write_line("Destination not found.");
            return;
        }

        // Display available transport methods
        print_splitter();
        write_line("Available transport methods:");
        for (int i = 0; i < 5; i++)
        {
            write_line(std::to_string(i + 1) + ": " + methods[i].name + " (Cost: " + std::to_string(methods[i].cost) + ")");
        }

        // Prompt the user to select a transport method
        int transport_choice = get_int("Enter the number of the transport method you want to use: ") - 1;

        if (transport_choice < 0 || transport_choice >= 5)
        {
            write_line("Invalid transport method selected.");
            return;
        }

        // Check if the user has enough balance for the selected transport method
        if (user.get_balance() < methods[transport_choice].cost)
        {
            write_line("You do not have enough balance to use this transport method.");
            return;
        }

        // Deduct the cost from the user's balance
        user.deduct_balance(methods[transport_choice].cost);

        // Update the user's current location
        user.set_home_address(&destinations[destination_index]);

        // Display travel details
        print_splitter();
        write_line("You traveled to " + destinations[destination_index].name + " using " + methods[transport_choice].name + ".");
        write_line("Speed: " + std::to_string(methods[transport_choice].speed) + " km/h");
        write_line("Description: " + methods[transport_choice].description);
    }
    // Deconstructor
    ~Travel() { delete[] destinations; }
};

// Main function
int main()
{
    run_program();

    return 0;
}

// Handle the main running of the program.
void run_program()
{
    User myUser;
    Travel myTravel;

    int choice;

    do
    {
        print_menu();
        choice = get_int("Enter you choice!: ");

        switch (choice)
        {
            case 0:
                write_line("Goodbye");
                break;
            case 1:
                myUser.set_initial();
                break;
            case 2:
                myUser.print_attributes();
                break;
            case 3:
                myTravel.print_travel_methods();
                break;
            case 4:
                myUser.top_up_balance();
                break;
            case 5:
                myTravel.create_dynamic_array();
                myUser.set_home_address(&myTravel.destinations[0]);
                break;
            case 6:
                myTravel.add_destination();
                break;
            case 7:
                myTravel.remove_destination();
            case 8:
                myTravel.print_destinations();
                break;
            case 9:
                myUser.print_current_location();
                break;
            case 10:
                myTravel.travel_to_location(myUser);
                break;
        }

    } while (choice != 0);
}

void print_menu()
{
    print_splitter();
    write('\n');
    write_line("1. Set your name and initial balance.");
    write_line("2. Print your account information.");
    write_line("3. Print the transport methods available.");
    write_line("4. Top up your balance.");
    write_line("5. Set your initial locations:");
    write_line("6. Add a location");
    write_line("7. Remove a location");
    write_line("8. Print your destinations.");
    write_line("9. Print my current location.");
    write_line("10. Travel");
    write_line("0. Quit");
}