#include "splashkit.h"
int main()
{
    const int PLAYER_RADIUS = 50;
    const int PLAYER_SPEED = 3;

    int player_X = 640;

    open_window("Converting to Cpp!", 800, 600);

    while(!quit_requested())
    {
        clear_screen(color_white());
        fill_circle(color_turquoise(), player_X, 360, PLAYER_RADIUS);
        
        refresh_screen(60);
        process_events();


        if ( key_down(RIGHT_KEY) )
        {
            player_X += PLAYER_SPEED;
        }
    
        if ( key_down(LEFT_KEY) )
        {
            player_X -= PLAYER_SPEED;
        }

        


    }


    return 0;
}


//using SplashKitSDK;
//using static SplashKitSDK.SplashKit;

//const int PLAYER_RADIUS = 50;
//const int PLAYER_SPEED = 3;

//int playerX = 640;

//OpenWindow("Circle Moving", 1280, 720);

//while( ! QuitRequested() )
//{
//   ClearScreen(ColorWhite());
//    FillCircle(ColorTurquoise(), playerX, 360, PLAYER_RADIUS);
//    RefreshScreen(60);

//    ProcessEvents();

//   if ( KeyDown(KeyCode.RightKey) )
//    {
//        playerX += PLAYER_SPEED;
//   }
//
//    if ( KeyDown(KeyCode.LeftKey) )
//    {
//        playerX -= PLAYER_SPEED;
//    }
//}