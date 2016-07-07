#include "TextBoxDisplay.hpp"
using namespace std;

TextBoxDisplay :: TextBoxDisplay(){}

void TextBoxDisplay :: draw() const
{
  cout << "|"; repeatString("_",60); cout << "|" << endl;
  cout << "|,"; repeatString("-", 58); cout << ",|" << endl;
  cout << "||"; repeatString(" ", 58); cout << "||" << endl;
  cout << "||"; repeatString(" ", 58); cout << "||" << endl;
  cout << "||"; repeatString(" ", 58); cout << "||" << endl;
  cout << "||"; repeatString(" ", 58); cout << "||" << endl;
  cout << "||"; repeatString("_", 58); cout << "||" << endl;
  cout << "'"; repeatString("-", 60); cout << "'" << endl;
}
