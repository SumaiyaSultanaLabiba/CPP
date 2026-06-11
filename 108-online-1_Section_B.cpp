#include<iostream>
#include<cstring>
using namespace std;



class Book
{
private:
string title;
string author;
int ratingCount;
double avgRating;


public:
Book()
{
    this->title="Unnamed";
    this->author="Unknown";
    this->ratingCount=0;
    this->avgRating=0;
}

Book(string title, string author, int ratingCount=0, double avgRating=0)
{
    this->title=title;
    this->author=author;
    this->ratingCount=ratingCount;
    this->avgRating=avgRating;
}

void addRating(int rating)
{
    this->avgRating=((this->avgRating)*this->ratingCount+rating);
    this->ratingCount++;
    this->avgRating=this->avgRating/this->ratingCount;
}

double getAverageRating()
{
    return this->avgRating;
}

void display()
{
    cout<<"Book: "<<this->title<<" by "<<this->author<<", Average Rating: "<<this->avgRating<<endl;
}

string getTitle()
{
    return this->title;
}

string getAuthor()
{
    return this->author;
}
};


class Library
{
private:
int maxBooks;
Book* books;
int totalBooks;

public:
Library()
{
   this->maxBooks=10;
   this->totalBooks=0;
   this->books=new Book[this->maxBooks]; 
}



Library(int maxBooks)
{
   this->maxBooks=maxBooks;
   this->totalBooks=0;
   this->books=new Book[this->maxBooks]; 
}



Library(int maxBooks, Book* books, int totalBooks)
{
   this->maxBooks=maxBooks;
   this->totalBooks=totalBooks;
   this->books=new Book[this->maxBooks]; 
   for(int i=0; i<this->totalBooks; i++)
   {
    this->books[i]=books[i];
   }
}



Library(const Library& other)
{
this->maxBooks=other.maxBooks;
this->totalBooks=other.totalBooks;
this->books=new Book[this->maxBooks];
for(int i=0; i<this->totalBooks; i++)
{
    this->books[i]=other.books[i];
}
}



~Library()
{
    delete[] this->books;
}



void addBook(Book b) 
{
if(this->maxBooks==this->totalBooks)   
{
    cout<<"Library is full. Cannot add more books."<<endl;
    return;
} 
int i;    
for(i=0; i<this->totalBooks; i++)
{
    if(this->books[i].getTitle()==b.getTitle() && this->books[i].getAuthor()==b.getAuthor())
    break;
}
if(i==this->totalBooks)
{
    this->books[this->totalBooks]=b;
    this->totalBooks++;
    cout<<"Book added: "<<b.getTitle()<<" by "<<b.getAuthor()<<endl;
}
else
{
    cout<<"This book already exists; cannot put multiple copies of a book"<<endl;
}
}



void removeBook(Book  b)
{
int i;    
for(i=0; i<this->totalBooks; i++)
{
    if(this->books[i].getTitle()==b.getTitle() && this->books[i].getAuthor()==b.getAuthor())
    break;
}
if(i==this->totalBooks)
{
    cout<<"This book is not found in the library"<<endl;
}
else
{
    for(int j=i; j<this->totalBooks-1; j++)
    {
      this->books[j]=this->books[j+1];
    }
    this->totalBooks--;
    cout<<"Book removed: "<<b.getTitle()<<" by "<<b.getAuthor()<<endl;
}
}



void  rateBook(string  title,  string author, int rating)
{
for(int i=0; i<this->totalBooks; i++)
{
    if(this->books[i].getTitle()==title && this->books[i].getAuthor()==author)
    {
        this->books[i].addRating(rating);
        break;
    }
}
}



void showBooks()
{
for(int i=0; i<this->totalBooks; i++)
{
    this->books[i].display();
}
}



Book  bestRatedBook()
{
double maxRating=0;
Book bestRatedBook;
for(int i=0; i<this->totalBooks; i++)
{
    if(this->books[i].getAverageRating()>maxRating)
    {
        maxRating=this->books[i].getAverageRating();
        bestRatedBook=this->books[i];
    }
}
return bestRatedBook;
}
};





int main() { 
Library lib1(5); 
Book b1("The Great Gatsby", "F. Scott Fitzgerald"); 
Book b2("To Kill a Mockingbird", "Harper Lee"); 
Book b3("1984", "George Orwell"); 
Book b4("War and Peace", "Leo Tolstoy"); 
Book b5("The Kite Runner", "Khaled Hosseini"); 
Book b6("A Tale of Two Cities", "Charles Dickens"); 
lib1.addBook(b1); 
lib1.addBook(b2); 
lib1.addBook(b3); 
lib1.addBook(b4); 
lib1.addBook(b5); 
lib1.addBook(b6); 
lib1.rateBook("The Great Gatsby", "F. Scott Fitzgerald", 5); 
lib1.rateBook("The Great Gatsby", "F. Scott Fitzgerald", 4); 
lib1.rateBook("To Kill a Mockingbird", "Harper Lee", 5); 
lib1.rateBook("1984", "George Orwell", 4); 
lib1.rateBook("1984", "George Orwell", 5); 
lib1.rateBook("1984", "George Orwell", 5); 
lib1.rateBook("War and Peace", "Leo Tolstoy", 3); 
lib1.rateBook("War and Peace", "Leo Tolstoy", 4); 
lib1.rateBook("The Kite Runner", "Khaled Hosseini", 5); 
lib1.rateBook("The Kite Runner", "Khaled Hosseini", 4); 
lib1.rateBook("The Kite Runner", "Khaled Hosseini", 5); 
cout << "\nLibrary 1 Books and Ratings:\n"; 
lib1.showBooks(); 
cout << "\nBest Rated Book in Library 1:\n"; 
lib1.bestRatedBook().display(); 
cout << endl; 
Library lib2(lib1); 
lib2.removeBook(b2); 
lib2.addBook(b6); 
cout << "\nLibrary 2 Books and Ratings:\n"; 
lib2.showBooks(); 
cout << "\nBest Rated Book in Library 1:\n"; 
lib1.bestRatedBook().display(); 
cout << "\nBest Rated Book in Library 2:\n"; 
lib2.bestRatedBook().display(); 
return 0; 
} 