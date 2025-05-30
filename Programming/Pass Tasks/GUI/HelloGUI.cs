﻿using static SplashKitSDK.SplashKit;

OpenWindow("My First GUI Program", 640, 480);

ClearScreen(ColorWhite());
DrawText("Hello World! - using SplashKit shapes:", ColorBlack(), 50, 50);

// H
FillRectangle(ColorRed(), 50, 100, 20, 100);
FillRectangle(ColorRed(), 70, 140, 40, 20);
FillRectangle(ColorRed(), 110, 100, 20, 100);

// E
FillRectangle(ColorOrange(), 150, 100, 20, 100);
FillRectangle(ColorOrange(), 170, 100, 40, 20);
FillRectangle(ColorOrange(), 170, 140, 20, 20);
FillRectangle(ColorOrange(), 170, 180, 40, 20);

// L
FillRectangle(ColorGold(), 230, 100, 20, 100);
FillRectangle(ColorGold(), 250, 180, 40, 20);

// L
FillRectangle(ColorGreenYellow(), 310, 100, 20, 100);
FillRectangle(ColorGreenYellow(), 330, 180, 40, 20);

// O
FillEllipse(ColorLimeGreen(), 390, 100, 80, 100);
FillEllipse(ColorWhite(), 410, 120, 40, 60);

// W
FillTriangle(ColorGreen(), 50, 250, 90, 370, 120, 250);
FillTriangle(ColorGreen(), 90, 250, 120, 370, 160, 250);
FillTriangle(ColorWhite(), 70, 250, 90, 310, 110, 250);
FillTriangle(ColorWhite(), 100, 250, 120, 310, 140, 250);
FillRectangle(ColorWhite(), 70, 350, 80, 30);

// O
FillEllipse(ColorBlue(), 170, 250, 80, 100);
FillEllipse(ColorWhite(), 190, 270, 40, 60);

// R
FillTriangle(ColorBlueViolet(), 270, 250, 270, 350, 340, 350);
FillTriangle(ColorWhite(), 252, 250, 252, 350, 320, 350);
FillEllipse(ColorBlueViolet(), 252, 250, 80, 60);
FillEllipse(ColorWhite(), 270, 270, 40, 20);
FillRectangle(ColorWhite(), 252, 250, 20, 100);
FillRectangle(ColorBlueViolet(), 270, 250, 20, 100);

// L
FillRectangle(ColorPurple(), 360, 250, 20, 100);
FillRectangle(ColorPurple(), 380, 330, 40, 20);

// D
FillEllipse(ColorMagenta(), 420, 250, 100, 100);
FillEllipse(ColorWhite(), 440, 270, 60, 60);
FillRectangle(ColorWhite(), 420, 250, 30, 100);
FillRectangle(ColorMagenta(), 450, 250, 20, 101);

// !
FillRectangle(ColorPink(), 550, 250, 20, 60);
FillCircle(ColorPink(), 560, 340, 10);

RefreshScreen();
Delay(5000);