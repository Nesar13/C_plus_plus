/* "I pledge my honor that I have abdied by the Stevens Honor System."
Author: Nesar Ahmed
Date: 4/20/2016
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <iterator>
#include "Huffman.h"

using namespace std;


HuffmanCoding::HuffmanCoding() {};

string HuffmanCoding::readFile() {

	inputFile.open("infile.dat");
	string str;
	string temp;

	while (getline(inputFile, str)) {

		fileContent += str;
	}



	remove_copy_if(fileContent.begin(), fileContent.end(),
		back_inserter(temp), //Store output
		ptr_fun<int, int>(&ispunct)
		);

	// remove spaces
	remove_copy(temp.begin(), temp.end(), back_inserter(cleanedFileContent), ' ');

	return cleanedFileContent;
}


map<char, int> HuffmanCoding::countFrequency(string &f) {

	for (auto itr = f.begin(); itr != f.end(); ++itr) {

		if (frequencyTable.count(*itr)) {

			int freq = frequencyTable.at(*itr);
			freq += 1;
			frequencyTable.at(*itr) = freq;
		}
		frequencyTable.insert(pair<char, int>(*itr, 1));
	}

	outputFile.open("outfile.dat");
	for (auto itr = frequencyTable.begin(); itr != frequencyTable.end(); ++itr) {

		outputFile << "Character: " << itr->first << " Frequency: " << itr->second << "\n";

	}

	outputFile.close();

	return frequencyTable;

}

void HuffmanCoding::createNodeHeap(std::map<char, int> &m) {


	for (auto itr = m.begin(); itr != m.end(); ++itr) {

		huffmanTree.leaf = new node;
		huffmanTree.leaf->symbol = itr->first;
		huffmanTree.leaf->frequency = itr->second;
		huffmanTree.forest.push(huffmanTree.leaf);
	}
}


node* HuffmanCoding::mergeNodes() {

	while (huffmanTree.forest.size() > 1) {

		node *least = huffmanTree.forest.top();
		huffmanTree.forest.pop();
		node *secondLeast = huffmanTree.forest.top();
		huffmanTree.forest.pop();

		node *newNode = new node(least->frequency + secondLeast->frequency);

		newNode->left = least;
		newNode->right = secondLeast;
		huffmanTree.forest.push(newNode);
		mergeNodes();
	}


	return huffmanTree.forest.top();
}

bool isLeaf(node *leaf) {

	if (leaf->symbol != '\0') {
		return true;
	}
	else {
		return false;
	}
}



void HuffmanCoding::generateCodes(node* leaf, string pre) {


	if (isLeaf(leaf)) {
		leaf->prefix = pre;
		//        cout << "Leaf Found: " << leaf->symbol << " - " << leaf->prefix << endl;
		outputFile.open("outfile.dat", fstream::app);
		outputFile << "CHAR: " << leaf->symbol << " HUFFMAN ENCODING: " << leaf->prefix << endl;
		outputFile.close();
		huffmanTree.bitLength = huffmanTree.bitLength + leaf->prefix.size() * leaf->frequency;
	}
	if (leaf->left != NULL) {
		pre += "0";//append to string
		generateCodes(leaf->left, pre);
		pre.pop_back();
	}
	if (leaf->right != NULL) {
		pre += "1";//append to string
		generateCodes(leaf->right, pre);
		pre.pop_back();
	}
}


void HuffmanCoding::writeBitLength() {

	outputFile.open("outfile.dat", fstream::app);
	outputFile << "Length of coded message (in bits): " << huffmanTree.bitLength << endl;
	outputFile.close();

}





/*Write a program that takes any input text and produces both a frequency table and the corresponding Huffman code.

Take approximately 360 words from any English document as your input text.Ignore all blanks, all punctuation marks, all special symbols.Create an input file with this input text.
Construct the frequency table according to the input text read from the file, in the form :

symbol	frequency
A	.
.	.
.	.
m	.
.	.
.	.
7	.
Then, using the Huffman algorithm, construct the optimal prefix binary code for the table.
Design your program to read the input from the input file "infile.dat".Your program must produce the output, in the file "outfile.dat", consisting of

the frequency table for the source text,
the Huffman code for each letter and digit in the source code, and
the length of the coded message in terms of number of bits. */
