#include"Header.h"
#include"LinkedList.h"
#include"PrecondViolatedExcept.h"
#include"ArrayQueue.h"
template<class ItemType>

const int a = 100;

LinkedList<Page<string>>* L0 = new LinkedList<Page<string>>();
LinkedList<string>* L1 = new LinkedList<string>();
LinkedList<string>* L2 = new LinkedList<string>();
Page<string> my_Page;

list<int> myIntList;
list<int> myIntList2;


int main() {

	string line, search;

	int number_Pages = 0, num = 0, v = 0;

	fstream my_file("Data/names.txt");
	//this function creat name's page in linkedlist L1	
	if (my_file.is_open())
	{
		number_Pages = 0;
		while (getline(my_file, line))
		{
			L1->insert(number_Pages, line);
			//cout << L1->getEntry(number_Pages) << endl;
			number_Pages++;
		}

		my_file.close();

	}

	//this function creat link's page in linkedlist L2	
	my_file.open("Data/links.txt");
	if (my_file.is_open())
	{
		number_Pages = 0;
		while (getline(my_file, line))
		{
			L2->insert(number_Pages, line);
			//cout << L2->getEntry(number_Pages++) << endl;
		}

		my_file.close();
	}


	//this function creat pages in linkedlist
	for (number_Pages = 0;number_Pages < L1->getLength();number_Pages++) {

		my_file.open(L1->getEntry(number_Pages));
		my_Page.setName_Link(L1->getEntry(number_Pages), L2->getEntry(number_Pages));
		L0->insert(number_Pages, my_Page);
		//cout << "link:" << L0->getEntry(number_Pages).getID_link() << endl;
		//cout << "ID :" << L0->getEntry(number_Pages).getID_Word() << endl;
	}

	cout << "Enter search word" << endl;
	cin >> search;



	for (int i = 0;i < L0->getLength();i++) {
		L0->getEntry(i).search_link();
		L0->getEntry(i).search_word(search);
		cout << "link:"<< L0->getEntry(i).getID_link()<<endl;
		cout << "ID :"<<L0->getEntry(i).getID_Word() << endl;

	}

	/*
	for (int i = 0;i < number_Pages - 1;i++) {

		if (L0->getEntry(i).getID_Word() > 0) {
			if (L0->getEntry(i).getID_Word() > L0->getEntry(i + 1).getID_Word())
			{
				myIntList.push_front(i);
			}
			else
				myIntList.push_back(number_Pages);
		}
	}

	for (std::list<int>::iterator it = myIntList.begin(); it != myIntList.end() &&
		L0->getEntry(*it).getID_link() > 0; ++it) {

		if (L0->getEntry(*it).getID_link() > 0) 
			if (L0->getEntry(*it).getID_link() > L0->getEntry(*it + 1).getID_link())
				myIntList2.push_front(*it);
			else
				myIntList2.push_back(*it);
		}
	myIntList2.push_back(number_Pages);
	
		for (std::list<int>::iterator it = myIntList2.begin(); it != myIntList2.end(); ++it)
			cout << L0->getEntry(*it).getlink() << endl;
		
		*/


	cin >> v;
	return 0;

}