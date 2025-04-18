using static SplashKitSDK.SplashKit;
using static System.Convert;


//Create varibles in global scope.
double total = 0, min = 0, max = 0, average = 0;
int count = 0;
string answer, line;






do
{
    //Create a local varible in scope.
    double value;
    
    //Prompt for a value
    Write("Enter a value: ");
    line = ReadLine();

    //Handle Errors
    while (! IsDouble(line))
    {
        Write("Enter a valid value: ");
        line = ReadLine();
    }

    value = ToDouble(line);

   
    
    //Increase Count
    count ++;
    WriteLine($"Count: {count}");

    //Increase total with the current value
    total += value;
    WriteLine($"Total: {total}");

    //Check min
    if (value < min || count == 1)
    {
        min = value;
    }
    WriteLine($"Min: {min}");

    //Check max
    if (count == 1 || value > max)
    {
        max = value;
    }
    WriteLine($"Max: {max}");
  

    //Calculate avg
    average = total / count;
    WriteLine($"Average: {average}");

    WriteLine();

    Write("Go again? [y/n]: ");
    answer = ReadLine();

    //Handle exiting.
    while((answer != "n" && answer != "N") && (answer != "y" && answer != "Y"))
    {
        Write("Not a valid entry. Go again? [y/n]:");
        answer = ReadLine();
    }


    


    


}while(answer != "n" && answer != "N");

