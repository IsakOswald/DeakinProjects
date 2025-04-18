#include "menu_template.hpp"

#define RESET_COLOR "\033[0m"
#define GREEN_TEXT "\033[32m"
#define BLUE_TEXT "\033[34m"
#define YELLOW_TEXT "\033[33m"
#define CYAN_TEXT "\033[36m"
#define RED_TEXT "\033[31m"

void main_menu()
{
  
    Serial.print("\033[2J\033[H");

    Serial.println(RED_TEXT "+---------------------------+");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[1] " GREEN_TEXT "Turn LED On          " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[2] " GREEN_TEXT "Turn LED Off         " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[3] " GREEN_TEXT "Blink LED            " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[4] " GREEN_TEXT "Manual Lock          " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[5] " GREEN_TEXT "Manual Unlock        " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[6] " GREEN_TEXT "Read Temp            " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[7] " GREEN_TEXT "Read Humidity        " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[8] " GREEN_TEXT "Read Sound Levels    " RED_TEXT "|");
    Serial.println(RED_TEXT "| " YELLOW_TEXT "[9] " GREEN_TEXT "Read Window State    " RED_TEXT "|");
    Serial.println(RED_TEXT "+---------------------------+");

    Serial.println("Press '99' to exit/disable security");
    Serial.print(BLUE_TEXT "> " RESET_COLOR);
}