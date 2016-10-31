#include <iostream>
#include <fstream>
using namespace std;
void count_word();
void output_table(int &, int &, int &);
void count_word()
{
	
/*ofstream infile("C://Users//Class2017//Documents//Visual Studio 2015//Projects//CS570//Lab2_Take2//infile.txt");
	infile.open("infile.txt");
	infile << "Writing this to file. \n";
	infile.close(); } */

	ifstream infile("C://Users//Class2017//Documents//Visual Studio 2015//Projects//CS570//Lab2_Take2//infile.txt");
	int n = 0;
	int OneLetterWord = 0;
	int TwoLetterWord = 0;
	int ThreeOrMore = 0;

	char letter;

	while (!infile.eof() || infile >> ws) //loops until end of file has been reached, >> is extracting the whitespaces
	{
		infile.get(letter);
		if (letter != ' ')
			n++;

		if (letter == ' ' || infile.eof()) 
		{
			if (n == 1)
			{
				OneLetterWord++;
			}
			else if (n == 2)
			{
				TwoLetterWord++;
			}
			else if (n >= 3)
			{
				ThreeOrMore++;
			}

			n = 0;
		}

	}
	output_table(OneLetterWord, TwoLetterWord, ThreeOrMore);
	infile.close();
}
void output_table(int &OneLetterWord, int &TwoLetterWord, int &ThreeOrMore)
{
	ofstream outfile("C://Users//Class2017//Documents//Visual Studio 2015//Projects//CS570//Lab2_Take2//outfile.txt");
	outfile << "The number of one letter words is: " << OneLetterWord << endl;
	outfile << "The number of two letter words is: " << TwoLetterWord << endl;
	outfile << "The number of three of more letter words is: " << ThreeOrMore << endl;
	outfile.close();
}

int main() {
	ifstream infile("C://Users//Class2017//Documents//Visual Studio 2015//Projects//CS570//Lab2_Take2//infile.txt");
	
	if (infile.fail()) {
		cout << "Input file \"infile.txt\" opening failed" << endl;
		return 1;
	}
	count_word();
	infile.close();
	return 0;
}
