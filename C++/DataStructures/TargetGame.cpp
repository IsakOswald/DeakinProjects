#include "splashkit.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int MAX_TARGET_X = 800;
const int MAX_TARGET_Y = 300;
const int MAX_GOAL = 13;
const int MIN_GOAL = 4;


// Create a struct for each circle
struct target_data
{

    double x_pos;
    double y_pos;
    double radius;
};

// Keep track of the game, such as target score and how many hits the user has got.
struct game_data
{
    target_data target;
    int hits;
    int goal;
};

// Declare our functions here {Described }
void draw_target(target_data x);
target_data initialize_target(double x, double y, double r);
target_data random_target();
bool mouse_over_target(target_data target);
game_data create_new_game();

int main()
{
    open_window("Reaction Timer", SCREEN_WIDTH, SCREEN_HEIGHT);

    string choice;
    do
    {
        game_data new_game = create_new_game(); // Create a new game
        bool quit = false;                      // Determine if game should end

        // Main game loop
        while (!quit)
        {
            process_events();
            clear_screen(COLOR_WHITE);
            draw_target(new_game.target);

            // Check if player clicks the target
            if (mouse_clicked(LEFT_BUTTON) && mouse_over_target(new_game.target))
            {
                new_game.target = random_target();
                new_game.hits++;
                write_line("Hits: " + std::to_string(new_game.hits) + " | Goal: " + std::to_string(new_game.goal));
            }

            // Check if the player wins
            if (new_game.hits >= new_game.goal)
            {
                write_line("YOU WIN!");
                clear_screen();
                quit = true;
            }

            refresh_screen(60);
        }

        // Ask if the player wants to play again
        write_line("Do you want to play again? [y/n]");
        choice = read_line();

    } while (choice == "y" || choice == "Y"); // Restart only if the user enters "y" or "Y"
}

// Create a target with function
target_data initialize_target(double x, double y, double r)
{
    target_data new_target;
    new_target.x_pos = x;
    new_target.y_pos = y;
    new_target.radius = r;

    return new_target;
}

// Draw the target on the screen
void draw_target(target_data target)
{
    fill_circle(color_swinburne_red(), target.x_pos, target.y_pos, target.radius);
}

// Create a random target on the screen
target_data random_target()
{
    target_data rnd_target = initialize_target(rnd(0, MAX_TARGET_X), rnd(0, MAX_TARGET_Y), rnd(5, 250));
    return rnd_target;
}

// Check if mouse is over target circle
bool mouse_over_target(target_data target)
{
    return point_in_circle(mouse_x(), mouse_y(), target.x_pos, target.y_pos, target.radius);
}

// Function to create a new instance of the game.
game_data create_new_game()
{
    game_data game1;
    game1.target = random_target();
    game1.goal = rnd(MIN_GOAL, MAX_GOAL);
    game1.hits = 0;

    return game1;
}
