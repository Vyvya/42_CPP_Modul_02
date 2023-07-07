/*
when to use copy constructor:
-whenever we need to create a new object based on the alreaady existing object
-when a compiler creating a temporary object=invoke copy constructor, pssing by value object to a function, like printBook
-when you returning the object by value, compiler will create a temporary object

parametireised constructor for the class
	create the object based on the parameters

<<as soon as you are working with pointers, you have to have a 
custom copy constructor

<<copy constructor is in public
has the same name
return void
receives 1 parameter of the same class

custom destructor whenever you are working with pointers
~delete[Rates;
Rates = nullptr;]*/

#include <iostream>
using namespace std;

class Book {

	public:
		string titleB;
		string authorB;
		float* rates; //array of floats dynamically allocated
		int ratesCounter;

	Book( string title, string author ) {

		titleB = title;
		authorB = author;

		ratesCounter = 2;
		rates = new float[ratesCounter];
		rates[0] = 5;
		rates[1] = 4;
	}
	Book( const Book& original ) { //passing by value, compiler copyes the object and passes it to the copy costructor

		titleB = original.titleB;
		authorB = original.authorB;
		ratesCounter = original.ratesCounter;

		rates = new float[ratesCounter];
		for( int i = 0; i < ratesCounter; i++ ) {
			rates[i] = original.rates[i];
		}
	}
	~Book() {

		delete[]rates;
		rates = nullptr;
	}
};

void printBook( Book book ) {

	std::cout << "Title: " << book.titleB << std::endl;
	std::cout << "Author: " << book.authorB << std::endl;
	
	float sum = 0;
	for( int i = 0; i < book.ratesCounter; i++ ) {
			sum += book.rates[i];
	}
	std::cout << "Avr. fates: " << sum/book.ratesCounter << std::endl;

}

int main() {

	Book book1("Millionaire Fastlane", "M. J . DeMarco");
	Book book2("C++ Lamba Story", "Bartek F.");

	Book book3( book1 ); //invoking copy constructor
	// Book book3=book1; //invoking copy constructor
	// book3=book2; //invoking assignement operation
	printBook( book1 );
	printBook( book2 );
	printBook( book3 );

	// std::cin.get();

}