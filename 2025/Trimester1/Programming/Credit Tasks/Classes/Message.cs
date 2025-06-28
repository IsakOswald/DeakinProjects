using static SplashKitSDK.SplashKit;

//Create a namespace so we do not run into conflicts in our other class.
namespace message
{
     //This is static, we want all instances of Program to have the same Main() function.
     static class Program
     {
          static void Main()
          {

               //Create a new instance of our message class. This can also be done with new();
               Message myMessage = new Message("Hello World from a class!");
               myMessage.PrintMessage();
               myMessage.GreetName();


          }
     }
}

//Use the same namespace for clarity.
namespace message
{
     class Message
     {
          //Private variable. Make sure it can only be modified within the class.
          private readonly string _Message;

          //Constructor
          public Message(string message)
          {
               _Message = message;
          }

          //Public PrintMessage() function. Is public so it can be accessed elsewhere.
          public void PrintMessage()
          {
               WriteLine(_Message);
          }

          //A function to ask for a name and greet them.
          public void GreetName()
          {
               string name;
               Write("Enter you name! ");
               name = ReadLine();

               WriteLine("Hello,  " + name + "!");

          }

     }
}