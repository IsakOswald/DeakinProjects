using SplashKitSDK;
using static SplashKitSDK.SplashKit;

namespace lightSim
{
     public class Program
     {
          //Create a new static instance of light
          private static readonly Light _light = new Light();

          //Our Program entry point.
          public static void Main()
          {
               RunGame();

          }


          //A private function. Limits it to being used only inside the Program class.
          private static void RunGame()
          {
               OpenWindow("Light Switch", 800, 800);

               while (!QuitRequested())
               {
                    ProcessEvents();
                    _light.DrawLight();
                    _light.CheckMouseClick();
                    RefreshScreen(60);

               }
          }
     }
}

namespace lightSim
{
     class Light
     {

          //Make sure that the bitmap image cannot be changed after creation. Make sure that its private (our Program class cant access it directly)
          private readonly Bitmap _lightOnImage;
          private readonly Bitmap _lightOffImage;
          private bool _isOn;
          private readonly int _lightX = 400;
          private readonly int _lightY = 400;

          //A constructor, make sure its public so we can use it in our Program class.
          public Light()
          {
               _lightOnImage = LoadBitmap("Light On", "/Users/isakoswald/Desktop/2025/SIT102/C3/ScreenShots/lightOn.png");
               _lightOffImage = LoadBitmap("Light Off", "/Users/isakoswald/Desktop/2025/SIT102/C3/ScreenShots/lightOff.png");
               _isOn = false;
          }

          //This can be private as we are calling it only within the Light class.
          private void FlickSwitch()
          {
               _isOn = !_isOn;
          }

          //This has to be public. Draws the image on the screen
          public void DrawLight()
          {
               if (_isOn)
               {
                    ClearScreen(ColorAntiqueWhite());
                    DrawBitmap(_lightOnImage, _lightX, _lightY);
               }

               if (!_isOn)
               {
                    ClearScreen(ColorBlack());
                    DrawBitmap(_lightOffImage, _lightX, _lightY);
               }
          }

          //This has to be public as we use it in our Program Class.
          public void CheckMouseClick()
          {
               Point2D mousePos = MousePosition();

               if ((MouseClicked(MouseButton.LeftButton)) && (mousePos.X > 400 && mousePos.X < 550) && (mousePos.Y > 425 && mousePos.Y < 600))
               {
                    FlickSwitch();
                    DrawLight();

               }
          }
     }
}