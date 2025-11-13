/*a modified version of: https://github.com/farhana786/Data-Structure-Programs/blob/main/HuffmanCoding*/
#include<fstream> 
#include<iomanip>
#include <iostream>
#include<queue> //for priority_queue
#include <string>
#include<unordered_map>
#include<map> //implemented using a red-black tree (another "application" of binary trees)
#include<vector> 

const int CHAR_COL_WIDTH = 10;
const int HUFFCODE_COL_WIDTH = 15;
const int FREQ_COL_WIDTH = 10;

using namespace std;

unordered_map<char, int> freqMap; //GLOBAL var! - anticipating use in `main`



struct Node
{
	char ch;
	int freq;
	Node* left;
	Node* right;


	void printNode()
	{
		cout << setw(CHAR_COL_WIDTH) << ch
			<< setw(FREQ_COL_WIDTH) << freq << "\t";
		if (left == nullptr)
		{
			cout << left << endl;
		}

		else
		{
			cout << left->ch << endl;
		}

		if (right == nullptr)
		{
			cout << right << endl;
		}

		else
		{
			cout << right->ch << endl;
		}
	}
};

/*an interesting alternative to a constructor used by GitHub link*/
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node;

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

/*LESS frequently occurring chars have higher priority(minHeap) (and longer Huffman codes)*/
struct orderByFrequency
{
	bool operator()(Node* l, Node* r)
	{
		return (l->freq) > (r->freq);
	}
};

/*a recursive function
@param -> huffCodeMap passed by ref - so modified in main
*/
void traverseHuffTreeAndEncode(Node* root, string str, unordered_map<char, string>& huffmanCodeMap)
{
	if (root == nullptr)
	{
		return; //base case returns nothing
	}

	if (!root->left && !root->right) //AKA: isLeaf//	
	{
		huffmanCodeMap[root->ch] = str;
	}

	traverseHuffTreeAndEncode(root->left, str + "0", huffmanCodeMap); //0 for left (arbitary)
	traverseHuffTreeAndEncode(root->right, str + "1", huffmanCodeMap);
}

priority_queue<Node*, vector<Node*>, orderByFrequency> makePriorityQueue(const string& inputString)
{

	for (char ch : inputString)
	{
		freqMap[ch]++;
	}

	//begin "heapify"-type algorithm
	priority_queue<Node*, vector<Node*>, orderByFrequency> pq;

	//makes (leaf) node of all char, frequency pairs in the map
	for (auto& pair : freqMap)
	{
		Node* leaf = getNode(pair.first, pair.second, nullptr, nullptr);
		pq.push(leaf); //NOTE: push will use `orderByFrequency`
	}

	return pq;
}

/*passed BY VALUE (copy made) - so no modification to original*/
void printPQ(std::priority_queue<Node*, vector<Node*>, orderByFrequency> pq)
{
	cout << "Char\tFreq\tleftChild\t\t\tRightChild\n";
	while (!pq.empty())
	{
		pq.top()->printNode();
		pq.pop();
	}
}

/*@param pq -> passed by value*/
Node* makeHuffTree(std::priority_queue<Node*, vector<Node*>, orderByFrequency> pq)
{
	int parentCount = 0;
	while (pq.size() > 1)
	{
		//get first two lowest frequency nodes (pop priority queue twice) 
		Node* first = pq.top();
		pq.pop();
		Node* second = pq.top();
		pq.pop();

		parentCount++;
		//const int ASCII_VALUE_OF_0 = 48;
		//make parent of first and second with freq = first.freq + second.freq
		Node* parent = getNode('\0' + parentCount,
			first->freq + second->freq,
			first,
			second);

		pq.push(parent);
	}

	return pq.top();
}

std::string storeFileContentsAsString(const std::string& filename)
{
	std::string fileContents; 

	std::ifstream fin(filename); 

	if (!fin) throw std::runtime_error("file not found");

	std::string tempLine; 
	while (std::getline(fin, tempLine))
	{
		fileContents.append(tempLine);
	}
	
	return fileContents; 
}

int main()
{

	try
	{

		//string text = "this is an example of a huffman tree";
		//string text = storeFileContentsAsString("firstTextFile.txt");
		//string text = storeFileContentsAsString("secondTextFile.txt");
		string text = storeFileContentsAsString("main.cpp");
		//string text = "all your base are belong to us";
		cout << "Original string: " << endl;
		cout << text << endl;

		//string text = "aaabbbbbbb";
		auto pq = makePriorityQueue(text);

		//printPQ(pq); 

		//cout << "\n\nAfter pushing parent into pq: " << endl; 
		//printPQ(pq); 

		cout << "\n\nHuff tree made ...\n";
		Node* huffTreeRoot = makeHuffTree(pq);
		//cout << huffTreeRoot->ch << "\t" << huffTreeRoot->freq << endl;

		unordered_map <char, string> huffmanCodeMap;
		traverseHuffTreeAndEncode(huffTreeRoot, "", huffmanCodeMap);

		cout << left
			<< setw(CHAR_COL_WIDTH) << "Char"
			<< setw(HUFFCODE_COL_WIDTH) << "HuffmanCode"
			<< setw(FREQ_COL_WIDTH) << "Freq\n";
		cout << "=================================\n";

		int totalBitsForEncoded = 0;
		for (auto& pair : huffmanCodeMap)
		{
			cout << left
				<< setw(CHAR_COL_WIDTH) << pair.first
				<< setw(HUFFCODE_COL_WIDTH) << pair.second
				<< setw(FREQ_COL_WIDTH) << freqMap.at(pair.first) << endl;

			totalBitsForEncoded += pair.second.size() * freqMap.at(pair.first);

			//cout << freqMap.at(pair.first) << endl; 
		}

		double uncompressedBitsRequired = 8 * text.size();

		cout << "\n\nBits required for original (assuming fixed-length, ASCII encoding - 8 bits per char): "
			<< uncompressedBitsRequired << endl;
		cout << "Bits for ENCODED: " << totalBitsForEncoded << endl;

		double compressionRatio = totalBitsForEncoded / uncompressedBitsRequired;
		double compressionPercent = 100 * (1 - compressionRatio);
		cout << "Compression percent (1 - compressionRatio)* 100: " << compressionPercent << endl;
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}