// Challenge 3: Book Manager
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Book {
public:
    string title, author, id;
    int pages;
    bool borrowed;

    Book(string t, string a, int p, string number, bool isBorrowed)
        : title(t), author(a), id(number), pages(p), borrowed(isBorrowed) {}

    void display() const {
        cout << "ID: " << id << " | " << title << " by " << author
             << " | " << pages << " pages | "
             << (borrowed ? "Borrowed" : "Available") << '\n';
    }
};

vector<Book> loadBooks(const string& filename) {
    ifstream input(filename);
    vector<Book> books;
    if (!input) {
        cerr << "Cannot open " << filename << "\n";
        return books;
    }
    string line;
    while (getline(input, line)) {
        if (line.empty()) continue;
        string title, author, pagesText, id, borrowedText;
        stringstream row(line);
        if (!getline(row, title, ',') || !getline(row, author, ',') ||
            !getline(row, pagesText, ',') || !getline(row, id, ',') ||
            !getline(row, borrowedText)) {
            cerr << "Skipping invalid book row: " << line << '\n';
            continue;
        }
        try {
            size_t consumed = 0;
            int pages = stoi(pagesText, &consumed);
            if (consumed != pagesText.size() || pages < 0 ||
                (borrowedText != "true" && borrowedText != "false")) {
                cerr << "Skipping invalid book row: " << line << '\n';
                continue;
            }
            books.emplace_back(title, author, pages, id, borrowedText == "true");
        } catch (const exception&) {
            cerr << "Skipping invalid book row: " << line << '\n';
        }
    }
    return books;
}

bool saveBooks(const string& filename, const vector<Book>& books) {
    ofstream output(filename);
    if (!output) return false;
    for (const Book& book : books)
        output << book.title << ',' << book.author << ',' << book.pages << ','
               << book.id << ',' << (book.borrowed ? "true" : "false") << '\n';
    return static_cast<bool>(output);
}

Book* findBook(vector<Book>& books, const string& id) {
    for (Book& book : books) if (book.id == id) return &book;
    return nullptr;
}

int main() {
    const string filename = "bookData.txt";
    vector<Book> books = loadBooks(filename);
    if (books.empty()) return 1;
    while (true) {
        cout << "\n=== Library Book Manager ===\n"
             << "1. View all books\n2. View book by ID\n"
             << "3. Borrow book\n4. Return book\n5. Quit\nChoose: ";
        int choice;
        if (!(cin >> choice)) {
            if (cin.eof()) break;
            cout << "Enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice == 5) break;
        if (choice == 1) {
            for (const Book& book : books) book.display();
        } else if (choice >= 2 && choice <= 4) {
            string id;
            cout << "Enter book ID (e.g. 001): ";
            cin >> id;
            Book* book = findBook(books, id);
            if (!book) {
                cout << "No book found with that ID.\n";
                continue;
            }
            if (choice == 2) book->display();
            else {
                bool shouldBorrow = (choice == 3);
                if (book->borrowed == shouldBorrow) {
                    cout << (shouldBorrow ? "Already borrowed.\n" : "Already available.\n");
                } else {
                    book->borrowed = shouldBorrow;
                    if (saveBooks(filename, books))
                        cout << (shouldBorrow ? "Book borrowed.\n" : "Book returned.\n");
                    else {
                        book->borrowed = !shouldBorrow;
                        cerr << "Could not save changes to " << filename << "\n";
                    }
                }
            }
        } else cout << "Enter a number from 1 to 5.\n";
    }
    return 0;
}
