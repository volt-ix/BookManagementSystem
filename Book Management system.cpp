#include <iostream>
#include <string>		// to be able to use getline()
#include <string.h>
#include <cctype>
using namespace std;

class NewBook {			//new class for putting and adding books
public:

	string name;		//the attributes for the book
	string type;
	string author;
	string year;
	int price;

	void mybook(string x,string y,string z,string a,int b) {   //to quickly assign a book
		name = x;
		type = y;
		year = z;
		author = a;
		price = b;
	}

	void bookinfo() {                                      // to efficiently print out the info with less writing and less lines of code
		cout << " -"<<name<<"\n" << endl;
		cout << "    it's an " << type << " book" << endl;
		cout << "    it came out in: " << year << endl;
		cout << "    "<<author << " wrote it " << endl;
	}
	void bookprice() {
		cout << " is available for " << price << " $\n" << endl;	//to print out the price
	}
	
	
	
};

int main()
{
	NewBook book1, book2, book3, book4, book5, book6, book7, book8, book9, book10, book11, book12, book13, book14, book15, book16, book17, book18, book19, book20;
	
	//books

	book1.mybook("a short history of nearly everything", "educational", "02/04/2003", "Bill Bryson", 10);
	book2.mybook("sapiens", "educational", "2011", "Yuval Noah Harari", 12);									// books available
	book3.mybook("The 4-hour work week", "self-improvement", "2007", "Tim Ferris", 15);
	book4.mybook("atomic habits", "self-improvement", "10/16/2018", "James Clear", 13);
	book5.mybook("harry potter collection", "Novel", "2001-2009", "J.K Rowling", 35);

	NewBook arr[20] = { book1,book2,book3,book4,book5,book6, book7, book8, book9, book10, book11, book12, book13, book14, book15, book16, book17, book18, book19, book20 };

	//to be able to use the objects efficiently + its under the book1~book5 because other wise it wont take the values

	int i;


	do {

		cout << "1.check our available books here." << endl;		//print out the menu options
		cout << "2.add new book." << endl;
		cout << "3.remove old book." << endl;
		cout << "4.search for a book." << endl;
		cout << "5.check price of book." << endl;
		cout << "6.exit system" << endl;

		cin >> i;
		cin.ignore();							// if i dont use this after a cin that is before a getline function than getline wont work

		if (i > 6 || i < 1) {								//prints out that there is an error before asking the user again
			cout << "invalid input! try again." << endl;
		}

		cout << "-----------------------------------------------------------------------------" << endl;

		switch (i)
		{
		case 1:
			cout << "we currently have the following books: \n";

			for (int i = 0; i < 20; i++) {

				if (arr[i].name.empty()) {						//checks if the string name is empty, if it is than it doesnt print out bookinfo
																//and it continues the loop until it finds an object with a name
					continue;
				}
				else 
					arr[i].bookinfo();							// print bookinfo

				
			}

			cout << "\n";
			cout << "-----------------------------------------------------------------------------" << endl;

			break;

		case 2:
			cout << "to add a new book, just enter it's name, type , the author, the year and it's price" << endl;
			cout << "this is a small library so it can only hold 20 books so far, we only have 5 so don't go overboard ok?" << endl;

			for (int q = 0; q < 20; q++) {

				if (arr[q].name.empty()) {				/*if name is empty, then arr[q] / bookx doesnt have info. so fill it out user
														--->then break because we only want him to add 1 book, but if bookx has info then move on
														and store the new info into bookx+1*/
					getline(cin, arr[q].name);
					cin >> arr[q].type;
					cin.ignore();
					getline(cin, arr[q].author);
					cin >> arr[q].year;
					cin.ignore();
					cin >> arr[q].price;
					cin.ignore();

					break;
				}
				else

					continue;				// continue loop if there is a name until loop finds an object without a name(without this it wont work)
			}

			break;

		case 3:
		{
		cout << "to remove a book from this library, just type the name of the book and it will be no longer\n";
		cout << "what is the name of the book that you want to remove? (it has to be from the available books or nothing will be removed)\n";
		string somename;
		getline(cin, somename);

		for (int i = 0; i < 20; i++) {
			if (somename == arr[i].name) {			//loop checks all object names, if the name typed is in the library ---> erase the name string
				arr[i].name.erase();
			}
		}
		break;
		}
		case 4:
		{string namex;
		cout << "input the name of the book: \n\n";
		getline(cin, namex);
		cout << "\n";
		int counter = 0;
		char firstcharacter;
		for (int i = 0; i < 20; i++) {
		
			if (namex != arr[i].name) {
				continue;						//if not equal object name,continue checking until namex == object name

			}
			else if (namex == arr[i].name) {
				counter++;
				cout << "here are the results: \n";
				cout << "we found " << counter << " results \n";
				cout << arr[i].name << " is available in our library\n\n";

			}
			

		}
		break;
		}
		case 5:
		{
			string namez;
			cout << "input the name of the book: \n\n";
			getline(cin, namez);
			cout << "\n";

			for (int i = 0; i < 20; i++) {

				if (namez != arr[i].name) {

					continue;					// same as case 4, in fact copy pasted

				}
				else if (namez == arr[i].name) {
					cout << arr[i].name;
					arr[i].bookprice();
					
				}

				break;

			}
		}
		}
		} while (i != 6 || i < 0 || i > 6);				//if anything else inputed in menu, the program will ask again
		return 0;
	}
