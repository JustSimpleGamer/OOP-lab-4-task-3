#include "Header.h"

using namespace std;

//c++ singleton
	//SOLID
	//Design pattern Strategy
	//Design pattern Factory
	//Design pattern Singleton
	//Design patterr adapter
	//Design pattern decorator
	//Design pattern bridge

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream stream("ConsoleOutput.txt");
	MyStreambuf streambuf(stream.rdbuf(), cout.rdbuf());
	cout.rdbuf(&streambuf);
	stream.close();

	system("mode con cols=125 lines=53");
	MoveCenter();

	Client client;
	Administator admin;
	Product* products = new Product[5];

	Client::Credit_card credit_card;
	Client::Credit_card* index_of_credit_card = &credit_card; //покажчик на екземпляр класу

	read_data(credit_card);
	read_data(products);

	main_script(client, *index_of_credit_card, products, admin, stream);

	save_data(credit_card);
	save_data(products);
	delete[] products;

	return 0;
}

