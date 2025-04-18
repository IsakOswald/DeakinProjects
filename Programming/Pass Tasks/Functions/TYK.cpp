#include "splashkit.h"

/*
- Create a function to calculate score
- Create a function to caluclate the winner based on these scores
- Procedure to calulcuate convert to int, string, or double
- Print menu
- Split menu

*/

int const POINTS_PER_GOAL = 6;


void split_menu()
{
    write_line("---------------------------");
}

string read_string(string prompt)
{
    write(prompt);

    return read_line();

}

int read_int(string prompt)
{
    string input = read_string(prompt);
    
    while ( ! is_integer(input))
    {
        write_line("Enter a valid number! ");
        input = read_line();

    }


    return std::stoi(input);

}


int read_double(string prompt)
{
    string input = read_string(prompt);
    
    while ( ! is_double(input))
    {
        write_line("Enter a valid number! ");
        input = read_line();

    }


    return std::stod(input);

}

void print_stats(string team1_name, string team2_name, int team1_goals, int team2_goals, int team1_behinds, int team2_behinds)
{
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

int menu(string team1_name, string team2_name)
{
    split_menu();
    write_line("MENU");
    write_line("1. Update " + team1_name + " goals:");
    write_line("2. Update " + team1_name + " behinds:");
    write_line("3. Update " + team2_name + " goals:");
    write_line("4. Update " + team2_name + " goals:");
    write_line("5. Print Stats");
    write_line("6. Caclulate winner");
    write_line("7. QUIT");
    int choice = read_int("What would you like to do?: ");

    split_menu();
    return choice;

    

}

void calculate_winner(string team1_name, string team2_name, int team1_total_points, int team2_total_points)
{
    if (team1_total_points > team2_total_points)
    {
        write_line(team1_name + " is winning!");
    }

    else if (team1_total_points < team2_total_points)
    {
        write_line(team2_name + " is winning!");
    }
    else
    {
        write_line("Its a tie!");
    }

    }


int calculate_points(int goals, int behinds)
{
    return (goals * POINTS_PER_GOAL) + behinds;


}


int main()
{
    int team1_goals, team2_goals, team1_behinds, team2_behinds, team1_total_points, team2_total_points,choice;
    string team1_name, team2_name;
    bool quit = false;

    write_line("Welcome to the AFL calculator.");
    split_menu();
    write_line("<ENTER DETAILS>");
    split_menu();
    team1_name = read_string("Enter team one name: ");
    team1_goals = read_int("Enter team one goals: ");
    team1_behinds = read_int("Enter team one behinds: ");
    split_menu();
    team2_name = read_string("Enter team two name: ");
    team2_goals = read_int("Enter team two goals: ");
    team2_behinds = read_int("Enter team two behinds: ");

    team1_total_points = calculate_points(team1_goals, team1_behinds);
    team2_total_points = calculate_points(team2_goals, team2_behinds);
    split_menu();

 

   do
   {
    switch(menu(team1_name, team2_name))
    {
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
        quit = true;
        break;

    }
   } while (quit != true);
   







   



    return 0;
}