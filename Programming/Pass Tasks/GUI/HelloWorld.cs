using static SplashKitSDK.SplashKit;
using static System.Convert;



const int SCREENWIDTH = 800;
const int SCREENHEIGHT = 600;
const int BOTTOMGAP = 50;

int houseSize, roofOverhang;
double wallX, wallY;
string usrInput;

OpenWindow("House", SCREENWIDTH, SCREENHEIGHT);



WriteLine("What do you want the size of the house to be: ");
usrInput = ReadLine();
houseSize = ToInt16(usrInput);

wallX = (SCREENWIDTH - houseSize) / 2;
wallY = (SCREENHEIGHT - BOTTOMGAP - houseSize);
FillEllipse(ColorBrightGreen(),0,400,SCREENWIDTH,400);

FillRectangle(ColorBrown(),wallX,wallY,houseSize,houseSize);

RefreshScreen();




Delay(5000);