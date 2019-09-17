#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;

template<class ItemType>

class Page {
private:
	string name, link;
	int ID_word=0,ID_link=0;

public:
	Page() {}
	~Page() {}

	bool search_link();
    string getlink() { return link; }
	int getID_link() { return ID_link; }
	int getID_Word() { return ID_word; }

	void setName_Link(string n, string l) { name = n; link = l; }
	bool search_word(ItemType search_word);
};

template<class ItemType>
bool Page<ItemType>::search_link() {

	if (L0->isEmpty()) {
		for (int i = 0;i < 100;i++) {
			if (L0->getEntry(i).search_word(link))
				ID_link++;
		}
	}

	return 1;
}

template<class ItemType>
bool Page<ItemType>::search_word(ItemType search_word) {
	ID_word = 0;

string word;
char x;
fstream my_file("Data/"+name);
if (my_file.is_open())
{
	while (!my_file.eof())
	{
		x = my_file.get();

		while (x != ' ')
		{
			word = word + x;
			x = my_file.get();
		}

		if (search_word == word)
			ID_word++;

		word.clear();
	}
}
else {
	cout << "not found " << endl;
	my_file.close();
	return 0;
}
my_file.close();
		return 1;
}

