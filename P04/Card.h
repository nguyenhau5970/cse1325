#ifndef __Card_H
#define __Card_H
#include <string>

class Card
{
	private:
   	  std::string question;
      std::string answer;
	public:
   	  void Card(string aQuestion, string aAnswer)
      {
          answer = aAnswer;
          question=aQuestion;
          cout<<question<<endl;
      }
      
      void Attempt(string response)
   	  {
   	        std::string str;
   	        
   	        if(question=="A template encapsulating data and code that manipulates it (C++ also has struct, which is identical other than default visibility)" && response=="1")
            {
                str="Correct!"
            }
            
            if(question=="An encapsulated bundle of data and code (e.g., an instance of a program is a process; an instance of a class is an object)" && response=="2")
            {
                str="Correct!"
            }
            
            if(question=="An instance of a class containing a set of encapsulated data and associated methods" && response=="3")
            {
                str="Correct!"
            }
            
            if(question=="A class member variable" && response=="4")
            {
                str="Correct!"
            }
            
            if(question=="A special class member that creates and initializes an object from the class" && response=="5")
            {
                str="Correct!"
            }
            
            if(question=="A special class member that cleans up when an object is deleted" && response=="6")
            {
                str="Correct!"
            }
            
            if(question=="A function that manipulates data in a class" && response=="7")
            {
                str="Correct!"
            }
            
            if(question=="A derived class replacing its base class’ implementation of a method" && response=="8")
            {
                str="Correct!"
            }
            
            if(question=="A statement that introduces a name with an associated type into a scope" && response=="9")
            {
                str="Correct!"
            }
            
            if(question=="An object created to represent an error or other unusual occurrence and then propagated via special mechanisms until caught by special handling code" && response=="10")
            {
                str="Correct!"
            }
            
            else
            {
                str="X - Correct Answer was "
            }
            
            cout << str << endl;
   	 
   	  }
};

#endif

