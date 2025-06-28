#include "includes.hpp"

bool isInteger(String str)
{
    if (str.length() == 0) return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isDigit(str.charAt(i))) return false;
    }
    return true;
}

void clear_terminal() { Serial.println("\033[2J\033[H"); }