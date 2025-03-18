#include "splashkit.h"

/*

TODO:

- Create a function to calculate score
- Create a function to caluclate the winner based on these scores
- Procedure to calulcuate convert to int, string, or double
- Print menu
- Split menu

*/

//Const global varible. Is how many points per goal.
int const POINTS_PER_GOAL = 6;

//Create a function to split the terminal with '-'. This is just for astetic purposes.
void split_menu()
{
    write_line("---------------------------");
}

//A function to give the user a prompt, and read the string based of the input.
string read_string(string prompt)
{
    write(prompt);

    return read_line();

}

//A function similar to read_string(), however since it returns a integer, we need a loop to check for valid input.
int read_int(string prompt)
{
    //read user input based on our read_string() function we made
    string input = read_string(prompt);
    
    //validate input
    while ( ! is_integer(input))
    {
        write_line("Enter a valid number! ");
        input = read_line();

    }

    // return the integer if valid input.
    return std::stoi(input);

}

// A function the same as read_int() however returns a double instead. 
int read_double(string prompt)
{
    //read user input based on our read_string() function we made
    string input = read_string(prompt);
    
    //checking user input
    while ( ! is_double(input))
    {
        write_line("Enter a valid number! ");
        input = read_line();

    }

    // return the double if valid input.
    return std::stod(input);

}

//Pass all team goals, points, and name into print stats. This then outputs all of these stats in the terminal.
void print_stats(string team1_name, string team2_name, int team1_goals, int team2_goals, int team1_behinds, int team2_behinds)
{
    //Print the stats
    write_line("<STATS>");
    split_menu();
    write_line("Team one name: " + team1_name);
    write_line("Team one goals: " + std::to_string(team1_goals));
    write_line("Team one behinds: " + std::to_string(team1_behinds));
    split_menu();
    write_line("Team two name: " + team2_name);
    write_line("Team two goals:" + std::to_string(team2_goals));
    write_line("Team two behinds: " + std::to_string(team2_behinds));
    split_menu();
}

//Create a menu to print to the terminal. A switch will then be implemented based on input here.
int menu(string team1_name, string team2_name)
{
    //Use split menu command from before.
    split_menu();
    write_line("MENU");
    //Prompt what the user would like to do.
    write_line("1. Update " + team1_name + " goals:");
    write_line("2. Update " + team1_name + " behinds:");
    write_line("3. Update " + team2_name + " goals:");
    write_line("4. Update " + team2_name + " goals:");
    write_line("5. Print Stats");
    write_line("6. Caclulate winner");
    write_line("7. QUIT");
    //Read this coice with our read_int() function, and return it.
    int choice = read_int("What would you like to do?: ");

    split_menu();
    //Return the user choice if its valid (by our read_int() function)
    return choice;

    

}


//A function to calculate the winner based on the points of each team
void calculate_winner(string team1_name, string team2_name, int team1_total_points, int team2_total_points)
{
    //if team one points is greater than team two, team one wins
    if (team1_total_points > team2_total_points)
    {
        write_line(team1_name + " is winning!");
    }
    //if team two points is greater than team one, team two wins
    else if (team1_total_points < team2_total_points)
    {
        write_line(team2_name + " is winning!");
    }
    //If its a tie, print it is a tie.
    else
    {
        write_line("Its a tie!");
    }

    }

//Calculate the points based on our global points_per_goal varible. (points * 6)
int calculate_points(int goals, int behinds)
{
    return (goals * POINTS_PER_GOAL) + behinds;


}


int main()
{
    //declare out varibles here
    int team1_goals, team2_goals, team1_behinds, team2_behinds, team1_total_points, team2_total_points,choice;
    string team1_name, team2_name;
    bool quit = false;
    //------------------------

    //Create the start of the program, a welcome message.
    write_line("Welcome to the AFL calculator.");
    split_menu();
    write_line("<ENTER DETAILS>");
    split_menu();
    //read input using our functions that validate input
    team1_name = read_string("Enter team one name: ");
    team1_goals = read_int("Enter team one goals: ");
    team1_behinds = read_int("Enter team one behinds: ");
    split_menu(); // split the menu for astetic purposes.
    //grab more input using our functions
    team2_name = read_string("Enter team two name: ");
    team2_goals = read_int("Enter team two goals: ");
    team2_behinds = read_int("Enter team two behinds: ");
    //get more input yet again using our functions, update total points for both teams.
    team1_total_points = calculate_points(team1_goals, team1_behinds);
    team2_total_points = calculate_points(team2_goals, team2_behinds);
    split_menu();

 
    //repete this code if the user does not want to quit.
   do
   {
    //Use a switch statement based on the return value of our menu() function.
    switch(menu(team1_name, team2_name))
    {
        //Update accordingly.
        case 1:
        team1_goals = read_int("New Goals: ");
        break;
        case 2:
        team1_behinds = read_int("New Behinds: ");
        break;
        case 3:
        team2_goals = read_int("New Goals: ");
        break;
        case 4:
        team2_behinds = read_int("New Behinds: ");
        break;
        case 5:
        print_stats(team1_name, team2_name, team1_goals, team2_goals, team1_behinds, team2_behinds);
        break;
        case 6:
        team1_total_points = calculate_points(team1_goals, team1_behinds);
        team2_total_points = calculate_points(team2_goals, team2_behinds);
        calculate_winner(team1_name, team2_name, team1_total_points, team2_total_points);
        break;
        break;
        case 7:
        //If user input is 7, update quit to true. The user wants to quit.
        quit = true;
        break;

    }
   } while (quit != true); //Quit the program as user requestied. We break out of this loop here.
   







   



    return 0;
}