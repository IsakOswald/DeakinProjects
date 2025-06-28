#include <iostream>
#include <stdlib.h>
#include <string.h>

using std::string;

struct text_message
{
     string text;
     string sender;

     text_message()
     {
          this->text = "";
          this->sender = "";
     }

     text_message(string sender, string text)
     {
          this->sender = sender;
          this->text = text;
     }

     void print_message()
     {
          std::cout << sender + " said: " + text << std::endl;
     }
};

int main()
{
     text_message *m1 = new text_message("Isak", "Hello, how are you?");
     text_message *m2 = new text_message("John", "Im good, what about yourself?");
     text_message *m3 = new text_message("Isak", "could be better, am trying to finish this task before I go to bed but its 1:30am already");
     text_message *m4 = new text_message("Ben", "Then just go to bed??");
     text_message m5 = text_message("The Stack", "Hi, im sending a message from the stack");
     text_message m6 = text_message("Ben", "?");
     text_message *m7 = new text_message("Ben", "Left the group chat!");

     m1->print_message();
     m2->print_message();
     m3->print_message();
     m4->print_message();
     m5.print_message();
     m6.print_message();
     m7->print_message();

     delete m1;
     delete m2;
     delete m3;
     delete m4;
     delete m7;

     return 0;
}
