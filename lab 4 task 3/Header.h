#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Product
{
public:
	void set_product(string name, double price);
	double get_price();
	string get_product_name();
	void print(Product* pr);

	Product(string name, double price);
	Product();
	~Product();
private:
	string name;
	double price;
};

class Client
{
public:
	class Credit_card
	{
	public:
		bool get_access();
		void change_access(bool state);

		string get_card_number();
		void set_card_number(string card_number);

		double get_money_on_card();
		void set_money_on_card(double money);
		void change_money_on_card(double money);

		unsigned int get_credit_limit();
		void set_credit_limit(int credit_limit);

		double get_credit();
		void set_credit(double credit);
		void change_credit(double money);

		int get_number_of_operations();
		void change_number_of_operations(int size);

		void set_card_attributes(bool access, string card_number, double money_on_card, unsigned int credit_limit, double credit, int number_of_operations);

		Credit_card();
		Credit_card(bool access, string card_number, double money_on_card, unsigned int credit_limit, double credit, int number_of_operations);

		Credit_card(const Credit_card& cd);

		~Credit_card();

		//static int number_of_operations; //знайти рішення для того, щоб воно працювало
	private:
		bool access;
		string card_number;
		double money_on_card;
		unsigned int credit_limit;
		double credit;
		int number_of_operations;

		//початкове констатне значення
		//посилання
	};
	void pay_for_the_order(Credit_card& cd, Product* pr);
	void make_payment_on_other_card(Credit_card& cd);
	void block_credit_card(Credit_card& cd);
	void annul_money(Credit_card& cd);
	void show_results_of_operation(Credit_card& cd, double price, int type); //Перевантажений метод
	void show_results_of_operation(Credit_card& cd, double price, double type); //Перевантажений метод

	~Client();
};

//int Client::Credit_card::number_of_operations;

class Administator
{
public:
	void block_credit_card(Client::Credit_card& cd);
	void initialize_card(Client::Credit_card& cd);
	void initiliaze_products(Product* pr);
	void change_product(Product* pr);

	~Administator();
};
void main_script(Client&, Client::Credit_card&, Product*, Administator&, ofstream&);

void return_to_start(Client&, Client::Credit_card&, Product*, Administator&, ofstream&);
void restart_cin();

int check_way(int way, int number);
int check_int_corectness(int);

void save_data(Product* pr);
void read_data(Product* pr);

void save_data(Client::Credit_card& cd);
void read_data(Client::Credit_card& cd);

void static addtional_method();
void static addtional_method(Client::Credit_card& cd, int);
void static addtional_method(Client::Credit_card* cd, double);
Client::Credit_card addtional_method(Client::Credit_card& cd);

void MoveWindow(int posx, int posy);
void MoveCenter();

void Print_in_center(const string& s);

void return_back(int type);

void return_back();

void try_again();

class MyStreambuf :public streambuf
{
public:
	MyStreambuf(streambuf* _firstBuf, streambuf* _secondBuf) :firstBuf(_firstBuf), secondBuf(_secondBuf) {}
	streamsize xsputn(const char_type* s, streamsize n)
	{
		firstBuf->sputn(s, n);
		secondBuf->sputn(s, n);
		return n;
	}

	int overflow(int_type c)
	{
		firstBuf->sputc(c);
		secondBuf->sputc(c);
		return c;
	}

	~MyStreambuf();

private:
	streambuf* firstBuf;
	streambuf* secondBuf;
};

void ConsoleOutput_open();
void ConsoleOutput_clear();
void ConsoleOutput_write(string string_line);

void temp1w_open();
void temp1r_open();
void temp1_clear();

void temp2w_open();
void temp2r_open();
void temp2_clear();

class Additional_Class_With_Private_Imitation : private Product
{
public:
	Additional_Class_With_Private_Imitation(string name, double price, int add1, float add2, double add3);
private:
	int add1;
	float add2;
	double add3;
};

class Additional_Class_1
{
public:
	Additional_Class_1(int add);
	~Additional_Class_1();

	int get_add()
	{
		return this->add;
	}
private:
	int add;
};

class Additional_Class_2
{
public:
	Additional_Class_2(int add);
	~Additional_Class_2();

	int get_add()
	{
		return this->add;
	}
private:
	int add;
};

class Additional_Class_3
{
public:
	Additional_Class_3(int add);
	~Additional_Class_3();

	int get_add()
	{
		return this->add;
	}
private:
	int add;
};

class Additional_Class_123 : public Additional_Class_1, public Additional_Class_2, public Additional_Class_3
{
public:
	Additional_Class_123(int add, int add1, int add2, int add3);
	~Additional_Class_123();

	using Add1 = Additional_Class_1;
	using Additional_Class_3::get_add;

	void print()
	{
		cout << Add1::get_add() << Additional_Class_2::get_add() << get_add();
	}
private:
	int add, add1, add2, add3;
};