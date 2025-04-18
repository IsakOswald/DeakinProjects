using SplashKitSDK;
using System.Diagnostics;
using static SplashKitSDK.SplashKit;
using static System.Convert;

const int WINX = 800, WINY = 600;
int radius = 50;



OpenWindow("TYK2", WINX, WINY);
ClearScreen();
RefreshScreen();




while (!QuitRequested())
{
    

    
    if(KeyDown(KeyCode.CKey))
    {
        ClearScreen(RandomColor());
        RefreshScreen(7);
    }


    if(KeyDown(KeyCode.SKey))
    {
        radius = 10;
    }
    
    if(KeyDown(KeyCode.MKey))
    {
        radius = 50;
    }

    if(KeyDown(KeyCode.LKey))
    {
        radius = 100;
    }

    if(MouseDown(MouseButton.LeftButton))
    {
        FillCircle(RandomColor(), MouseX(),MouseY(),radius);
        RefreshScreen(6);
    }






    
    


    ProcessEvents();
}




