#ifndef __Deck_H
#define __Deck_H

class Deck
{
	private:
  	  vector<string> _cards;
  	  vector<string> _options;
  	  int _next_card;
	public:
   	  add_card(string question, string answer);
   	  add_false(string falseAnswer);
   	  friend std::ostream& operator<<(std::ostream& ost, const Deck& d);
   	  vector<string> options;
   	  deal(string Card)
   	  {
   	      
   	  }

};

#endif
