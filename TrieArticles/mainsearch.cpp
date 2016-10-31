
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>


using namespace std;

struct Company {
	string name;
	int count;
};

struct CompanyAlias {
	string company;
	string alias;
};

vector<Company> Companies;
vector<CompanyAlias> CompanyAliases;
int readcompanies();

int readArticle();


int readcompanies()
{
	FILE *companyFile;
	errno_t err;
	err = fopen_s(&companyFile, "companies.dat", "r");

	if (err != 0) { cout << "The company file was not opened.\n"; return 0; }

	char theChar;				// character from file
	string theString;			// string built from characters
	bool companymode = true;	// are we building a company string or an alias string?
	string modeswitch = "no";	// if we hit EOF, tab, or newline, we will switch mode from building string to adding to vector
	string currentCompany;		// the current company, if we are in alias mode (companymode == false)
	do
	{
		theChar = fgetc(companyFile);
		if (theChar == EOF) { modeswitch = "EOF"; }
		if (theChar == '\t') { modeswitch = "tab"; }
		if (theChar == '\n') { modeswitch = "newline"; }
		if ((theChar >= 'a' && theChar <= 'z') || (theChar >= 'A' && theChar <= 'Z') || (theChar >= '0' && theChar <= '9') || theChar == ' ') { theString = theString + theChar; }

		if (modeswitch != "no") {
			if (companymode) {
				currentCompany = theString;
				Company newComp;
				newComp.name = currentCompany;
				newComp.count = 0;
				Companies.push_back(newComp);
			}
			else {	// alias mode
				CompanyAlias newAlias;
				newAlias.company = currentCompany;
				newAlias.alias = theString;
				CompanyAliases.push_back(newAlias);
			}
			if (modeswitch == "EOF") { break; }
			else if (modeswitch == "tab") { companymode = false; }
			else if (modeswitch == "newline") { companymode = true; }

			theString = "";		// clear the string
			modeswitch = "no";	// clear the mode
		}

	} while (true);

	fclose(companyFile);

	return 0;
}

int readArticle() {
	string theString, Article;
	cout << "Type (or paste) the article: ";
	do {
		getline(cin, theString);
		Article = Article + theString + " ";
	} while (theString != ".");
	//cout << Article;

	int totalWords = 0;
	string theChar = "";
	string theWord;
	int found = 0;
	theString = "";

	// strip out punctuation and special characters...
	for (int i = 0; i < Article.length(); i++) {
		theChar = Article.substr(i, 1);
		if ((theChar >= "a" && theChar <= "z") || (theChar >= "A" && theChar <= "Z") || (theChar >= "0" && theChar <= "9") || theChar == " ") { theString = theString + theChar; }
		if (theChar == "\n" || theChar == "\t") {
			theString = theString + " ";
		}
	}

	// count companies found (and remove from string)...
	for (int j = 0; j < Companies.size(); j++) {
		do {
			found = theString.find(Companies[j].name);
			//cout << "Searching for " << Companies[j].name << "\n";
			if (found != -1) {
				Companies[j].count++;
				totalWords++;
				theString.erase(found, Companies[j].name.length());
				//cout << "Found " << Companies[j].name << " at " << found << "\n";
			}
		} while (found != -1);
	}

	// count aliases found (and remove from string)...
	for (int j = 0; j < CompanyAliases.size(); j++) {
		do {
			found = theString.find(CompanyAliases[j].alias);
			//cout << "Searching for " << Companies[j].name << "\n";
			if (found != -1) {
				for (int k = 0; k < Companies.size(); k++) {
					if (Companies[k].name == CompanyAliases[j].company) { Companies[k].count++; totalWords++; }
				}
				theString.erase(found, CompanyAliases[j].alias.length());
				//cout << "Found " << Companies[j].name << " at " << found << "\n";
			}
		} while (found != -1);
	}

	// count remaining words...
	theWord = "";
	string lowStr;
	for (int i = 0; i < theString.length(); i++) {
		theChar = theString.substr(i, 1);
		if ((theChar >= "a" && theChar <= "z") || (theChar >= "A" && theChar <= "Z") || (theChar >= "0" && theChar <= "9")) { theWord += theChar; }
		else {
			transform(theWord.begin(), theWord.end(), theWord.begin(), ::tolower);
			if (theWord != "a" && theWord != "an" && theWord != "the" && theWord != "and" && theWord != "or" && theWord != "but" && theWord != "") {
				totalWords++;
			}
			theWord = "";
		}
	}
	for (int i = 0; i < Companies.size(); i++) {
		if (Companies[i].count > 0) {
			cout << Companies[i].name << ", Relevance: " << (Companies[i].count / (double)totalWords * 100) << "%\n";
		}
	}

	return 0;
}