#include <iostream>
#include <cstring>

using namespace std;

// Structure to represent additional information about a book
struct BookInfo {
    string author;
    int publicationYear;
   
};

// Structure to represent a book
struct Book {
    string title;
    BookInfo info;
    Book* next; // Pointer to the next book in the linked list
};

class Library {
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS]; // Array to store books
    int bookCount; // Number of books currently in the library

public:
    Library() : bookCount(0) {}

    // Function to insert a new book into the library
    void insertBook(string title, string author, int publicationYear) {
        if (bookCount < MAX_BOOKS) {
            // Add the book to the array
            Book newBook;
            newBook.title = title;
            newBook.info.author = author;
            newBook.info.publicationYear = publicationYear;
            newBook.next = nullptr;

            books[bookCount] = newBook;
            bookCount++;
            cout << "Book inserted successfully." << endl;
        }
        else {
            cout << "Library is full. Cannot insert more books." << endl;
        }
    }

    // Function to display all books in the library
    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books in the library." << endl;
            return;
        }

        cout << "Books in the library:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].info.author << endl;
            cout << "Publication Year: " << books[i].info.publicationYear << endl;
            cout << "----------------------" << endl;
        }
    }

    // Function to search for a book by title
    void searchBook(string title) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].title == title) {
                cout << "Book found:" << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].info.author << endl;
                cout << "Publication Year: " << books[i].info.publicationYear << endl;
                return;
            }
        }

        cout << "Book not found." << endl;
    }

    // Function to search for a book by author
    void searchBookByAuthor(string author) {
        cout << "Books by author " << author << ":" << endl;
        bool found = false;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].info.author == author) {
                cout << "Title: " << books[i].title << endl;
                cout << "Publication Year: " << books[i].info.publicationYear << endl;
                cout << "----------------------" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No books by author " << author << " found." << endl;
        }
    }

    // Function to delete a book by title
    void deleteBook(string title) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].title == title) {
                // Move all subsequent books one position back in the array
                for (int j = i; j < bookCount - 1; ++j) {
                    books[j] = books[j + 1];
                }

                bookCount--;
                cout << "Book deleted successfully." << endl;
                return;
            }
        }

        cout << "Book not found. Cannot delete." << endl;
    }
};

int main() {
    Library library;

    // Inserting books
    library.insertBook("Book1", "Author1", 2020);
    library.insertBook("Book2", "Author2", 2019);
    library.insertBook("Book3", "Author1", 2021);
    library.insertBook("Book4", "Author3", 2022);

    // Displaying books
    library.displayBooks();

    // Searching for a book
    library.searchBook("Book2");

    // Searching for books by author
    library.searchBookByAuthor("Author1");

    // Deleting a book
    library.deleteBook("Book2");

    // Displaying books after deletion
    library.displayBooks();

    return 0;
}
