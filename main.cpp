#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string BOOKS_FILE = "books.bin";
struct Book
{
	static const int BUFFER_SIZE = 20;
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};
enum SortBy
{
	Id,
	Title,
	Author
};
void add(Book newBook, int position = 0)
{
	ofstream file;
	file.open(BOOKS_FILE, iostream::binary | iostream::ate | iostream::in);
	if (position != 0)
		file.seekp(position * sizeof(Book));
	file.write(reinterpret_cast<char*>(&newBook), sizeof(Book));
	file.close();
}
void sort(Book * data,int size, SortBy sortBy)
{
	Book temp;
	switch (sortBy)
	{
	case Id:
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (data[j].Id > data[j + 1].Id)
				{
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
		break;
	}
	case Title:
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				int current = 0;
				while ((data[j].Title)[current] == (data[j + 1].Title)[current])
					++current;
				if ((data[j].Title)[current] > (data[j + 1].Title)[current])
				{
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
		break;
	}
	case Author:
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				int current = 0;
				while ((data[j].Author)[current] == (data[j + 1].Author)[current])
					++current;
				if ((data[j].Author)[current] > (data[j + 1].Author)[current])
				{
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
		break;
	}
	}
	
}
int search(Book* data, int size, char value[] )
{
	sort(data, size, Title);
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int middle = (left + right) / 2;
		if (strcmp(data[middle].Title, value) == 0)
		{
			return middle;
		}
		else if (strcmp(data[middle].Title, value) > 0)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	cerr << "not found";

}
void printBook(Book book)
{
	cout << "Author: " << book.Author << endl << "Title: " << book.Title << endl;
	cout << "Id: " << book.Id << endl << "Price: " << book.Price << endl << "Quantity: " << book.Quantity << endl << endl;
}
void printStatistics(Book data[], int size)
{
	int TotalQuantity = 0;
	float TotalPrice = 0;
	for (int i = 0; i < size; ++i)
	{
		TotalQuantity = TotalQuantity + data[i].Quantity;
		TotalPrice = TotalPrice + data[i].Price;
	}
	cout << "Quantity of all books : " << TotalQuantity << " Price of all books : " << TotalPrice << endl << endl;
}
int main()
{
	int FileSize;
	int DataSize;
	int choice;
	ifstream bookFile;
	bookFile.open(BOOKS_FILE, iostream::binary);
	if (!bookFile.is_open())
	{
		cerr << BOOKS_FILE << " did not open\n";
		return 1;
	}
	bookFile.seekg(0, iostream::end);
	FileSize = bookFile.tellg();
	DataSize = FileSize / sizeof(Book);
	Book* ptrData = new Book[DataSize];
	bookFile.seekg(0);
	bookFile.read(reinterpret_cast<char*>(ptrData), sizeof(Book) * DataSize);
	bookFile.close();
	cout << "Hello!" << endl << "Choose action: " << endl;
	cout << "1 - Add a book\n2 - Edit a book\n3 - Book search\n4 - List of books\n5 - Statistics" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{Book newBook;
	cout << "Id : ";
	cin >> newBook.Id;
	cout << "Title : ";
	cin >> newBook.Title;
	cout << "Author : ";
	cin >> newBook.Author;
	cout << "Price : ";
	cin >> newBook.Price;
	cout << "Quantity : ";
	cin >> newBook.Quantity;
	add(newBook);
	break; }
	case 2:
	{
		int id;
		cout << "Id : ";
		cin >> id;
		cout << endl;
		Book newBook;
		cout << "Id : ";
		cin >> newBook.Id;
		cout << "Title : ";
		cin >> newBook.Title;
		cout << "Author : ";
		cin >> newBook.Author;
		cout << "Price : ";
		cin >> newBook.Price;
		cout << "Quantity : ";
		cin >> newBook.Quantity;
		add(newBook, id - 1);
		break;
	}
	case 3:
	{
		char searchString[20];
		cout << "Title : ";
		cin >> searchString;
		cout << endl;
		printBook(ptrData[search(ptrData, DataSize, searchString)]);
		break;
	}
	case 4:
	{
		sort(ptrData, DataSize, Author);
		for (int i = 0; i < DataSize; ++i)
			printBook(ptrData[i]);
		break;
	}
	case 5:
		printStatistics(ptrData, DataSize);
		break;
	default:
		cerr << "invalid choice\n";
		return 1;
	}

	
}