/*  TRIES ASSIGNMENT
A file, companies.dat, contains a list of company names on each line. 
Company names may have multiple words in the name. Sometimes, a company might have multiple names associated with it. 
The first name is the primary name, and the remainder are synonyms. 
In this case, the company names will be separated by a tab on the same line. 
(Create a sample version of this file for your testing. The final file used for grading is not published.)
Write a program that can read a news article from standard input. 
Keep reading until you get a line in the article that consists entirely of a period symbol (.).
Identify each company name in the article, and display each company name on the screen, one line at a time. 
Always display the primary name of the company identified, not the synonym you found in the text.
On the same line, display the "relevance" of the company name hit. 
Relevance is defined as frequency of the company name appearing in the article divided by the number of words in the article." 
For example, Microsoft in "Microsoft released new products today." should result in a relevance of 1/5, or 20%. 
If two names for the same company match, they count as matches for the same one company. Display the relevance in percentage. 
You should ignore the following words in the article (but not the company name) when considering relevance: a, an, the, and, or, but
Complete this assignment twice: Once by searching the text for each company name, and once by traversing a trie of company names based on the content of the article. 
Submit two files, mainsearch.cpp and maintrie.cpp.
You must normalize the company names for the search. 
Punctuation and other symbols should not impact the search. 
So the appearance of Microsoft Corporation, Inc. in the companies.dat file should match with Microsoft Corporation Inc in the article. 
However, the search must be case sensitive. */



#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<algorithm>
#include<fstream>
#include<map>

using namespace std;

string Article_;

class myTries
{
public:
	class  trieNode
	{
	public:
		string stringVal;
		trieNode* nextNode[256];
	}*trieRoot{};

	void put(string searchKey, string val)
	{
		trieRoot = put(trieRoot, searchKey, val, 0);
	}

	trieNode* put(trieNode* theNode, string searchKey, string val, int d)
	{
		if (theNode == NULL)
			theNode = new trieNode();
		if (d == searchKey.length())
		{
			theNode->stringVal = val;
			return theNode;
		}
		char theChar = searchKey[d];
		theNode->nextNode[theChar] = put(theNode->nextNode[theChar], searchKey, val, d + 1);
		return theNode;
	}

	bool contains(string searchKey)
	{
		return (get(searchKey) != "");
	}

	string get(string searchKey)
	{
		trieNode* x = get(trieRoot, searchKey, 0);
		if (x == NULL)
			return "";
		return x->stringVal;
	}

	trieNode* get(trieNode* x, string searchKey, int d)
	{
		if (x == NULL)
			return NULL;
		if (d == searchKey.length())
			return x;
		char c = searchKey[d];
		return get(x->nextNode[c], searchKey, d + 1);
	}
};

string removePunctuation(string theString)	//  remove punctuation characters from string
{
	theString.erase(remove_if(theString.begin(), theString.end(), ispunct), theString.end());
	return theString;
}

vector<string> parseString(string theString, string delimiter) //  insert words into vector
{
	vector<string> allWords;
	size_t pos = 0;
	string token;
	while ((pos = theString.find(delimiter)) != string::npos)
	{
		token = theString.substr(0, pos);
		allWords.push_back(token);
		theString.erase(0, pos + delimiter.length());
	}
	allWords.push_back(theString);
	return allWords;
}

int countWordsInArticle()	// counting total words except a, an, the, and, or, but
{
	string line;
	vector<string> articleWords;
	int wordCount = 0;
	string theString, Article;
	cout << "Type (or paste) the article: ";
	do {
		getline(cin, theString);
		Article_ = Article_ + theString + " ";
	} while (theString != ".");
	string theWord;
	Article = Article_;
	articleWords = parseString(removePunctuation(Article), " ");
	for (int i = 0; i < articleWords.size(); i++)
	{
		theWord = articleWords[i];
		transform(theWord.begin(), theWord.end(), theWord.begin(), tolower);
		if (theWord != "a" && theWord != "an" && theWord != "the" && theWord != "and" && theWord != "or" && theWord != "but" && theWord != "") {
			wordCount++;
		}
	}
	return wordCount;
}

map<string, int> storeCompanyNames;		//store names of all companies

void createCompaniesTrie(myTries &companyTrie)
{
	vector<string> allWords;
	string primaryName;
	ifstream companiesFile("companies.dat");
	if (companiesFile.fail())
	{
		cout << "Could not open file." << endl;
	}
	else {
		string theLine;
		//		string theWord;
		while (getline(companiesFile, theLine))
		{
			allWords = parseString(theLine, "\t");
			for (int i = 0; i < allWords.size(); i++)
			{
				if (i == 0)
				{
					primaryName = allWords[i];
					storeCompanyNames[primaryName] = 0;
				}
				companyTrie.put(removePunctuation(allWords[i]), primaryName);
			}
		}
	}
}

void searchCompany(vector<string> parsedLine, myTries &companyTries)
{
	if (parsedLine.size() == 0)
		return;
	string theStrings = "";
	string primaryName;
	for (int i = 0; i < parsedLine.size(); i++)
	{
		if (i == 0)
			theStrings = theStrings + parsedLine[i];
		else
			theStrings = theStrings + " " + parsedLine[i];
		if (companyTries.contains(theStrings))
		{
			primaryName = companyTries.get(theStrings);
			storeCompanyNames[primaryName] = storeCompanyNames[primaryName] + 1;
			for (int j = i; j < parsedLine.size(); j++)
			{
				theStrings = theStrings + " " + parsedLine[j + 1];
				if (!companyTries.contains(theStrings))
				{
					i = j;
					break;
				}
			}
		}
	}
	parsedLine.erase(parsedLine.begin());
	searchCompany(parsedLine, companyTries);
}

void searchArticle(myTries &companyTries)	// Reading article and searching name of company
{
	searchCompany(parseString(removePunctuation(Article_), " "), companyTries);
}

int main()
{
	myTries companytries;
	int totalWords = countWordsInArticle();
	createCompaniesTrie(companytries);
	cout << "Total number of words in article: " << totalWords << endl;
	searchArticle(companytries);
	for (auto it = storeCompanyNames.begin(); it != storeCompanyNames.end(); ++it)
	{
		if (it->first != "")
			cout << it->first << ", Relevance " << ((float)it->second / (float)totalWords) * 100 << "%\n";
	}
	return 0;
}