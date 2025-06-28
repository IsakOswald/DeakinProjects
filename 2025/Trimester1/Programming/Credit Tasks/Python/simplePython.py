# Constant for points per goal
POINTS_PER_GOAL = 6

# Function to get valid integer input from the user
def get_int_input(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Please enter a valid integer.")

# Function to calculate total points
def calculate_points(goals, behinds):
    return (goals * POINTS_PER_GOAL) + behinds

# Function to print team stats
def print_stats(team1_name, team2_name, team1_goals, team2_goals, team1_behinds, team2_behinds):
    print("\n<STATS>")
    print(f"{team1_name} - Goals: {team1_goals}, Behinds: {team1_behinds}")
    print(f"{team2_name} - Goals: {team2_goals}, Behinds: {team2_behinds}")

# Function to calculate winner (should ONLY determine winner)
def calculate_winner(team1_name, team2_name, team1_total_points, team2_total_points):
    if team1_total_points > team2_total_points:
        print(f"\n{team1_name} wins!")
    elif team1_total_points < team2_total_points:
        print(f"\n{team2_name} wins!")
    else:
        print("\nIt's a tie!")

# Main program logic
def main():
    print("Welcome to the AFL calculator.\n")
    
    # Get team details
    team1_name = input("Enter Team 1 name: ")
    team1_goals = get_int_input(f"Enter {team1_name}'s goals: ")
    team1_behinds = get_int_input(f"Enter {team1_name}'s behinds: ")

    team2_name = input("Enter Team 2 name: ")
    team2_goals = get_int_input(f"Enter {team2_name}'s goals: ")
    team2_behinds = get_int_input(f"Enter {team2_name}'s behinds: ")

    # Main menu loop
    while True:
        print("\nMENU:")
        print("1. Update Team 1 goals")
        print("2. Update Team 1 behinds")
        print("3. Update Team 2 goals")
        print("4. Update Team 2 behinds")
        print("5. Print stats")
        print("6. Calculate winner")
        print("7. Quit")

        choice = get_int_input("What would you like to do? (Enter 1-7): ")

        if choice == 1:
            team1_goals = get_int_input(f"Enter new goals for {team1_name}: ")
        elif choice == 2:
            team1_behinds = get_int_input(f"Enter new behinds for {team1_name}: ")
        elif choice == 3:
            team2_goals = get_int_input(f"Enter new goals for {team2_name}: ")
        elif choice == 4:
            team2_behinds = get_int_input(f"Enter new behinds for {team2_name}: ")
        elif choice == 5:
            print_stats(team1_name, team2_name, team1_goals, team2_goals, team1_behinds, team2_behinds)
        elif choice == 6:
            team1_total_points = calculate_points(team1_goals, team1_behinds)
            team2_total_points = calculate_points(team2_goals, team2_behinds)
            calculate_winner(team1_name, team2_name, team1_total_points, team2_total_points)
        elif choice == 7:
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 7.")

# Start the program
if __name__ == "__main__":
    main()