#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int alocNum = 0;

struct trie_node {
	char v;
	int flag = 0; // 0:root 1:normal node 2:end node
	map<char,trie_node*> nodes;
	int aloc;

	trie_node(const char _v, const int _flag) : v(_v), flag(_flag) {
		aloc = alocNum++;
	}
};

trie_node *head;

void make_trie(trie_node *temp, const string& str, int I) {
	if(0 == temp->flag) {
		if(temp->nodes.find(str[I]) != temp->nodes.end()) {
			make_trie(temp->nodes[str[I]], str, I + 1);
		} else {
			temp->nodes.insert(make_pair(str[I], new trie_node(str[I], 1)));
			make_trie(temp->nodes[str[I]], str, I + 1);
		}
	}

	if(1 == temp->flag || 2 == temp->flag) {
		if(I == str.size()) {
			temp->flag = 2;
			return;
		} else {
			if(temp->nodes.find(str[I]) != temp->nodes.end()) {
				make_trie(temp->nodes[str[I]], str, I + 1);
			} else {
				temp->nodes.insert(make_pair(str[I], new trie_node(str[I], 1)));
				make_trie(temp->nodes[str[I]], str, I + 1);
			}
		}
	}
}


int main() {
	string str = "aabab";
	head = new trie_node('#',0);
	for(int i = 0; i < str.size(); i++) {
		make_trie(head, str.substr(i, str.size() - i), 0);
	}

	

}


