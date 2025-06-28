#include "splashkit.h"

using std::stoi;
using std::to_string;

int main()
{
    const int NUM_COIN_TYPES = 6;

    const int TWO_DOLLARS = 200;
    const int ONE_DOLLAR = 100;
    const int FIFTY_CENTS = 50;
    const int TWENTY_CENTS = 20;
    const int TEN_CENTS = 10;
    const int FIVE_CENTS = 5;

    string again = ""; // used to check if the user want to run again
    string line;
    int to_give;
    int coin_value;
    string coin_text;

    do
    {
        write("Cost of item in cents: ");
        line = read_line();
        while (!is_integer(line))
        {
            write_line("Please enter a whole number.");
            write("Cost of item in cents: ");
            line = read_line();
        }
        int cost_of_item = stoi(line);

        write("Payment in cents: ");
        line = read_line();
        while (!is_integer(line))
        {
            write_line("Please enter a whole number.");
            write("Payment in cents: ");
            line = read_line();
        }

        int amount_paid = stoi(line);

        int change_value = amount_paid - cost_of_item;

        if (change_value < 0)
        {
            write_line("Not enough money was paid.");
            write("Run again: ");
            again = read_line();
            continue;
        }

        write_line("Change to give " + to_string(change_value));

        write("Change: ");

        for (int i = 0; i < NUM_COIN_TYPES; i++)
        {
            switch (i)
            {
            case 0:
                coin_value = TWO_DOLLARS;
                coin_text = "$2, ";
                break;
            case 1:
                coin_value = ONE_DOLLAR;
                coin_text = "$1, ";
                break;
            case 2:
                coin_value = FIFTY_CENTS;
                coin_text = "50c, ";
                break;
            case 3:
                coin_value = TWENTY_CENTS;
                coin_text = "20c, ";
                break;
            case 4:
                coin_value = TEN_CENTS;
                coin_text = "10c, ";
                break;
            case 5:
                coin_value = FIVE_CENTS;
                coin_text = "5c";
                break;
            default:
                coin_value = 0;
                coin_text = "ERROR";
                break;
            }

            // Give Change
            to_give = change_value / coin_value;
            change_value = change_value - to_give * coin_value;
            write(to_string(to_give) + " x " + coin_text);
        }

        write_line();
        write("Run again: ");
        again = read_line();
    } while (again != "n" && again != "N");
}