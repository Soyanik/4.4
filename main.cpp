#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class TBook {
private:
    string Name;
    string Author;
    int Count;
public:
    void setName(string name) {
        Name = name;
    }
    void setAuthor(string author) {
        Author = author;
    }
    void setCount(int count) {
        Count = count;
    }
    string getName() const { 
        return Name;
    }
    string getAuthor() const { 
        return Author;
    }
    int getCount() const { 
        return Count;
    }
};

bool compareByAuthor(const TBook& book1, const TBook& book2) { 
    return book1.getAuthor() < book2.getAuthor();
}

int main() {
    TBook books[5];

    ifstream fin("data.txt");
    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        string name, author, count_str;

        getline(fin, name);
        getline(fin, author);
        getline(fin, count_str);
        int count = stoi(count_str);

        books[i].setName(name);
        books[i].setAuthor(author);
        books[i].setCount(count);
    }
    fin.close();

    sort(books, books + 5, compareByAuthor);
    for (int i = 0; i < 5; i++) {
        cout << "Name: " << books[i].getName() << endl;
        cout << "Author: " << books[i].getAuthor() << endl;
        cout << "Count: " << books[i].getCount() << endl;
    }

    return 0;
}
