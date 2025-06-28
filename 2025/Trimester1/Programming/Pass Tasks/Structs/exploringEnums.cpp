#include "splashkit.h"

//Here we are declaring out functions (seen below)
string read_string(string prompt);
int read_integer(string prompt);


int MAX_DAYS = 7
//ENUMS based on the day of the week, MON = 0, TUES = 1, WED = 2.....
enum day
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,

    NUM_DAYS = 7
    

};


//Converts enum to a string which is the day
string to_string(day x)
{
  switch(x)
  {
    case 1:
    return "Mon";
    break;

    case 2:
    return "Tues";
    break;

    case 3:
    return "Wed";
    break;

    case 4:
    return "Fri";
    break;

    case 5:
    return "Sat";
    break;

    case 6:
    return "Sun";
    break;



  }  
}

string display_day(int x )
{
  for (int i = 0; i < MAX_DAYS; i++)
  {
    
  }




}


int main()
{

    // Enum variable declaration
    day today;

    // Assigning a value to the enum variable
    today = WEDNESDAY;

    // Print the value of today
    write_line("Today is day number " + std::to_string(today));


    return 0;
}


string read_string(string prompt)
{
  write(prompt);
  return read_line();
}

int read_integer(string prompt)
{
  string line = read_string(prompt);
  while (!is_integer(line))
  {
    write_line("Please enter a whole number.");
    line = read_string(prompt);
  }
  return stoi(line);
}
