
using static SplashKitSDK.SplashKit;
using static System.Convert;

int doorNum;

WriteLine("Welcome, Do you want to play [y/n] ");
char answer = ToChar(ReadLine());
if (answer == 'n' || answer == 'N')
{
    WriteLine("Exiting.");
}
else 
{
    do
    {
        WriteLine("Pick a door. 1, 2, or 3");
        doorNum = ToInt16(ReadLine());
        switch(doorNum)
        {
            case 1:
                WriteLine("You Lost!");
                break;
            case 2:
                WriteLine("You Lost!");
                break;
            case 3:
                WriteLine("You Won!");
                break;



        }


    }while (doorNum != 3);


}














