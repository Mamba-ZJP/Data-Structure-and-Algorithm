#include<iostream>
#include<map>
#include<string>

using namespace std;
struct trieNode {
	bool isWord;
	map<char,trieNode*> Next;  //根本不用考虑初始化问题，NULL不NULL的，因为初始化一个TrieNode时，map里是空的
	trieNode():isWord(false){} //当建树的时候，插入（索引）关键字时，回对值初始化。
};

class Trie {
public:
	Trie() {root = new trieNode;}
	void insert(string word);
	bool search(string word);
	bool startsWith(string prefix);
	bool remove(string word);
private:
	trieNode* root;
};

bool Trie::remove(string word) {
	trieNode* multi_child_Node = root,* cur = root;
	int multi_child_Node_Index = -1;
	for (int i = 0; i < word.size(); ++i) {
		if (cur->Next.find(word[i]) == cur->Next.end()) //if the word doesen't exsit, cannot remove
			return false;   //find函数如果找不到，返回尾后迭代器，否则返回指向元素的迭代器
		else {
			cur = cur->Next[word[i]];
			if (cur->Next.size() > 1) { //如果有多余1个的子结点 就更新 多孩子索引的下标 和 node 
				multi_child_Node = cur;
				multi_child_Node_Index = i;
			}
		}
	}
	
	if (multi_child_Node_Index == word.size() - 1) {//如果最后一个结点无论有没有孩子 都不能删 能做的只是改标记
		if (!cur->isWord) return false;
		else
			cur->isWord = false;
		return true;
	}
	else if (multi_child_Node_Index == -1) { //其实2、3两种情况可以统一，只不过因为下标初始值是-1
		root->Next.erase(word[0]);//erase返回删除元素的后面一个迭代器
		return true;
	}                     
	else if (multi_child_Node_Index != word.size() - 1) {
		multi_child_Node->Next.erase(word[multi_child_Node_Index] + 1);
		return true;
	}
	return false;
}

bool Trie::startsWith(string word) {
	trieNode* cur = root;
	for (int i = 0; i < word.size(); ++i) {
		if (cur->Next.find(word[i]) == cur->Next.end())
			return false;
		cur = cur->Next[word[i]];
	}
	return true;
}

bool Trie::search(string word) {
	trieNode* cur = root;
	for (int i = 0; i < word.size(); ++i) {
		if (cur->Next.find(word[i]) == cur->Next.end())
			return false;
		cur = cur->Next[word[i]];
	}
	return cur->isWord;
}

void Trie::insert(string word) {
	trieNode* cur = root;
	for (int i = 0; i < word.size(); ++i) {
		if (cur->Next.find(word[i]) == cur->Next.end()) {
			cur->Next[word[i]] = new trieNode; //当建树的时候，插入（索引）关键字时，会对值初始化。
		}                 //索引就直接插入了
		cur = cur->Next[word[i]];
	}
	if (!cur->isWord)
		cur->isWord = true;
}


int main(void) {
	Trie* tree = new Trie;
	tree->insert("apple");
	if (tree->startsWith("app"))
		cout << "1" << ends;
	tree->remove("apple");
	if (!tree->search("apple"))
		cout << "1" << ends;
	return 0;
}
