#ifndef Huffman_Huffman_h
#define Huffman_Huffman_h
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>



struct node {
public:
	struct node *left;
	struct node *right;
	std::string prefix = "";
	char symbol;
	int frequency;

	node() {}

	node(int f) {

		frequency = f;
		symbol = '\0';
	}
};



struct cmpnode {
	bool operator()(const node *left, const node *right) { return left->frequency > right->frequency; }
};


struct HuffmanTree {

	int bitLength = 0;
	std::string prefix = "";
	node *leaf;
	node *root;
	std::priority_queue<node*, std::vector<node*>, cmpnode> forest;

};



class HuffmanCoding {

public:
	// constructor
	HuffmanCoding();

	// read file will read in the infile.dat and remove all spaces/punctuation/special characters.
	

	std::string readFile();

	// counts the occurences of each symbol (character) in the file and
	// returns a map (frequency table) with that information.
	// in addition it outputs this frequency table to outfile.dat

	std::map<char, int> countFrequency(std::string &f);




	void createNodeHeap(std::map<char, int> &m);



	node* mergeNodes();

	

	void generateCodes(node *leaf, std::string pre = "");

	// Write the total bit length of the encoded message to outfile.dat

	void writeBitLength();

	// file content prior to being cleaned

	std::string fileContent;

	// file content without punctuation/spaces/special characters

	std::string cleanedFileContent;

	// frequency Table

	std::map<char, int> frequencyTable;



	HuffmanTree huffmanTree;

private:
	
	std::ifstream inputFile;
	std::ofstream outputFile;

};


#endif
