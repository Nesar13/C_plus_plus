// reading from input file and
// writing as is to an output file
/*
#include <iostream> // this line for standard I/O
#include <fstream> // this line for file I/O
using namespace std;
int main()
{
	ofstream outfile("myoutput.dat"); // for file output
	ifstream infile("myinput.dat"); // for file input
	if (infile.fail())
	{
		cout << "Input file \"myinput.dat\" opening failed" << endl;
		return 1;
	}
	char symbol;
	infile.get(symbol); // read the next character into symbol 
	while ( !infile.eof() )
	{
		outfile << symbol;
		infile.get(symbol);
	}
	infile.close(); // closes the input file
	outfile.close(); // closes the output file
	return 0;
} // end of main 