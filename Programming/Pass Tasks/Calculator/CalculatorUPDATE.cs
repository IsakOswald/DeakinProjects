using static SplashKitSDK.SplashKit;
using static System.Convert;



/* 
LIST

Create prompts.
Create varibles to hold user input
Transfer user input into type int
Calculate savings.



*/



//Get user input and save it in a string varible.
WriteLine("What are you saving for? Enter Title: ");
string savingFor = ReadLine();

WriteLine("How much do you need to save? Enter ammount in $: ");
//Read the varible and save it as a type 32bit integer.
float savingAmmount = ToInt32(ReadLine());
WriteLine("\n");


WriteLine("How long before the purchase? Enter ammount in weeks: ");
//Smae this here, make sure its a int.
int weeks = ToInt16(ReadLine());

WriteLine("How much do you already have? Enter ammount in $: ");
int currentAmmount = ToInt16(ReadLine());

WriteLine("How much can you save each week?: ");
float savingPerWeek = ToInt32(ReadLine());

//Calculate
float savingsLeft = savingAmmount - currentAmmount;
float totalWeeks = savingsLeft / savingPerWeek;

WriteLine("To save for your goal, you will need to save a total of: $" + savingsLeft);
WriteLine("Based on your current savings of $ " + savingsLeft + ", you will need to save for: " + totalWeeks
+ " weeks"
);