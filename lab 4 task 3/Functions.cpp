#include "Header.h"

using namespace std;

ofstream *global_stream;
ifstream temp1r("temp1.txt", ios::out);
ofstream temp1w("temp1.txt", ios::out);
ifstream temp2r("temp2.txt", ios::out);
ofstream temp2w("temp2.txt", ios::out);

void main_script(Client& cl, Client::Credit_card& cd, Product* pr, Administator& adm, ofstream& stream)
{
	//Client::Credit_card::number_of_operations;
	int acess_way, way_of_operation;

	temp1r.close();
	temp1w.close();
	temp2r.close();
	temp2w.close();
	global_stream = &stream;

	global_stream->open("ConsoleOutput.txt");

	Print_in_center("<<��� ��� ������� ������� ������� \"������\">>");

	cout << endl << "������ ����� �� �볺��? (1)" << endl << "������ ����� �� �����������? (2)" << endl << "������ ����� � ����� ���������� (3)" << endl << "������ ��� �����: ";

	return_back();

	acess_way = check_way(3, 0);

	if (acess_way == 1)
	{
		cout << "ĳ������ ���� �������� ������: ";

		if (cd.get_access() == true)
		{
			cout << "ĳ���" << endl;
			if (cd.get_money_on_card() == NULL)
			{
				cout << "�����! ������� �����������" << endl;
			}
			else
			{
				cout << "ʳ������ ������ �� �������� ������: " << cd.get_money_on_card() << endl;
			}

			cout << "��������� ���: " << cd.get_credit_limit() << endl;
			cout << "������: " << cd.get_credit() << endl;
			cout << "ʳ������ ���������� ��������: " << cd.get_number_of_operations() << endl << endl;

			cout << "������ �������� ������� (1), ��������� ����� �� ���� ������ (2), ����������� ������ (3) �� ��������� ������� (4)?" << endl;
			cout << "������ �����: ";

			way_of_operation = check_way(4, 0);

			if (way_of_operation == 1)
			{
				cl.pay_for_the_order(cd, pr);
			}

			if (way_of_operation == 2)
			{
				cl.make_payment_on_other_card(cd);
			}

			if (way_of_operation == 3)
			{
				cl.block_credit_card(cd);
			}

			if (way_of_operation == 4)
			{
				cl.annul_money(cd);
			}
		}
		else
		{
			cout << "�����������" << endl;
		}
	}

	if (acess_way == 2)
	{
		cout << "������ �������������� ������ �볺��� (1), ������ ���� ������� �� ������ (2), ������ ������ ������ (3) �� ������ ���� � ������ (4)?" << endl << endl;
		cout << "������ �����: ";

		return_back();

		way_of_operation = check_way(4, 0);

		if (way_of_operation == 1)
		{
			adm.initialize_card(cd);
		}
		if (way_of_operation == 2)
		{
			adm.block_credit_card(cd);
		}
		if (way_of_operation == 3)
		{
			adm.initiliaze_products(pr);
		}
		if (way_of_operation == 4)
		{
			adm.change_product(pr);
		}
	}

	if (acess_way == 3)
	{
		cout << "³�������� ���������� ����� � ����, ���� ������ ��������� �������� �������� �����, � ��� ���� �������� ������� ������� �� N ��������, ���� ���� ���� ������ ���������� (1)?" << endl << endl;
		cout << "³�������� ���� � �������������� ������ (2) ��� (3)" << endl << endl;
		cout << "³�������� �����, �� ������� ��'��� ����� Credit_card (4)" << endl << endl;
		cout << "³������� ���������� ����� ��\'���� ����� �����, ���� ���� �������� ������� ��\'���, ����������� �� ����� ��������� (5)?" << endl << endl;
		cout << "������ �����: ";

		return_back();

		way_of_operation = check_way(5, 0);

		if (way_of_operation == 1)
		{
			addtional_method();
		}
		if (way_of_operation == 2)
		{
			addtional_method(cd, 1);
		}
		if (way_of_operation == 3)
		{
			addtional_method(&cd, 1.0);
		}
		if (way_of_operation == 4)
		{
			Client::Credit_card temp = *new Client::Credit_card;
			temp = addtional_method(cd);
			//delete temp;
		}
		if (way_of_operation == 5)
		{
			Additional_Class_123 add(0, 1, 2, 3);
		}
	}
	//delete streambuf;f
	return_to_start(cl, cd, pr, adm, stream);
}

void Client::pay_for_the_order(Credit_card& cd, Product* pr) //����� ������ ���������� (������ ������) �볺���� �� ��������� ������
{
	int type1, type2;

	pr->print(pr);

	cout << "������ ����� ������, ���� �� ������ ��������" << endl << "������ �����: ";

	type1 = check_way(5, 1);

	/*global_stream->close();
	cout << endl;
	global_stream->open("ConsoleOutput.txt", ios::app);*/

	type1 -= 1;

	if (cd.get_money_on_card() == NULL)
	{
		cout << "������ � ������� ���������. ��������� ������: � ������ (2)" << endl << "������ ��� ������: ";
		type2 = check_way(1, 0);
	}
	else
	{
		cout << "������ � ������� (1) �� � ������ (2)?" << endl << "������ ��� ������: ";
		type2 = check_way(2, 0);
	}

	if (type2 == 0)
	{
		return;
	}

	if (type2 == 1)
	{
		if (cd.get_money_on_card() < pr[type1].get_price())
		{
			cout << "�������! �� ������ ������� �� ��������� ������ ��� ������. �������� �� ���� ���������" << endl;
		}
		else
		{
			cd.change_money_on_card(pr[type1].get_price());
			cd.change_number_of_operations(1);

			show_results_of_operation(cd, pr[type1].get_price(), 1);
		}
		return;
	}

	if (type2 == 2)
	{
		if (!(cd.get_credit() > cd.get_credit_limit()))
		{
			if (cd.get_credit() + pr[type1].get_price() > cd.get_credit_limit())
			{
				cout << "������������! ��� ��������� ������ ���������� �� �������� ������ ������� ���� ������ ��������, �� �������� �� ����������� ���������� ����." << endl << endl;
				cout << "���-���� ����������? ��� (1) ͳ (2)" << endl << "������ �����: ";

				type2 = check_way(2, 0);
				if (type2 == 1)
				{
					cd.change_credit(pr[type1].get_price());
					cd.change_number_of_operations(1);

					show_results_of_operation(cd, pr[type1].get_price(), 1.0);
				}
				if (type2 == 2)
				{
					cout << "�������� �� ���� ���������";
				}
			}
			else
			{
				cd.change_credit(pr[type1].get_price());
				cd.change_number_of_operations(1);

				show_results_of_operation(cd, pr[type1].get_price(), 1.0);
			}
		}
		else
		{
			cout << "������������! ����������� �������!" << endl << endl;
			cout << "���-���� ����������? ��� (1) ͳ (2)" << endl << "������ �����: ";

			type2 = check_way(2, 0);

			if (type2 == 1)
			{
				cd.change_credit(pr[type1].get_price());
				cd.change_number_of_operations(1);

				show_results_of_operation(cd, pr[type1].get_price(), 1.0);
			}
			if (type2 == 2)
			{
				cout << "�������� �� ���� ���������";
			}
		}

		return;
	}
}

void Client::make_payment_on_other_card(Credit_card& cd)
{
	string card_number;

	cout << "������ ����� ������ �� ��� �� ������ ��������� ����� (16 ����): ";
	cin >> card_number;

	global_stream->close();

	if (card_number.size() < 16)
	{
		do
		{
			try_again();

			cout << "����-�����, ������ ��������� ����� ������." << endl << endl << "������ ����� ������: ";

			restart_cin();

			cin >> card_number;
		} while (card_number.size() != 16);
	}
	
	ConsoleOutput_open();
	ConsoleOutput_write(card_number);
	cout << endl;

	int type;

	if (cd.get_money_on_card() == NULL)
	{
		cout << "������ � ������� ���������. ��������� ������: � ������ (2)" << endl << endl << "������ ��� ������: ";
		type = check_way(1, 0);
	}
	else
	{
		cout << "������ � ������� (1) �� � ������ (2)?" << endl << endl << "������ ��� ������: ";
		type = check_way(2, 0);
	}


	int price;

	cout << "������ ������� ������, ��� �� ������ ��������� �� ������: " << endl;
	cout << "������ ����: ";
	price = check_int_corectness(1);
	cout << endl;

	if (type == 1)
	{
		if (cd.get_money_on_card() < price)
		{
			cout << "�������! �� ������ ������� �� ��������� ������ ��� ������. �������� �� ���� ���������" << endl;
		}
		else
		{
			cd.change_money_on_card(price);
			cd.change_number_of_operations(1);

			show_results_of_operation(cd, price, 1);
		}
		return;
	}

	if (type == 2)
	{
		if (!(cd.get_credit() > cd.get_credit_limit()))
		{
			if (cd.get_credit() + price > cd.get_credit_limit())
			{
				cout << "������������! ��� ��������� ������ ���������� �� �������� ������ ������� ���� ������ ��������, �� �������� �� ����������� ���������� ����." << endl << endl;
				cout << "���-���� ����������? ��� (1) ͳ (2)" << endl << "������ �����: ";

				type = check_way(2, 0);
				if (type == 1)
				{
					cd.change_credit(price);
					cd.change_number_of_operations(1);

					show_results_of_operation(cd, price, 1.0);
				}
				if (type == 2)
				{
					cout << "�������� �� ���� ���������";
				}
			}
			else
			{
				cd.change_credit(price);

				show_results_of_operation(cd, price, 1.0);
			}
		}
		else
		{
			cout << "������������! ����������� �������!" << endl << endl;
			cout << "���-���� ����������? ��� (1) ͳ (2)" << endl << "������ �����: ";

			type = check_way(2, 0);

			if (type == 1)
			{
				cd.change_credit(price);
				cd.change_number_of_operations(1);

				show_results_of_operation(cd, price, 1.0);
			}
			if (type == 2)
			{
				cout << "�������� �� ���� ���������";
			}
		}

		return;
	}
}

void Client::block_credit_card(Credit_card& cd)
{
	int way;

	cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
	cout << "������ �����: ";

	way = check_way(2, 0);

	if (way == 1)
	{
		cd.change_access(false);

		cout << "������ ���� ������ �����������!" << endl;

		return;
	}

	cout << "���� ������ �볺��� ��������� ��� ���" << endl << endl;
}

void Client::annul_money(Credit_card& cd)
{
	cout << "������ ��������� �������? " << "��� (1) ͳ (2)" << endl << endl;
	cout << "������ �����: ";

	int way = check_way(2, 0);

	if (way == 1)
	{
		cd.set_money_on_card(NULL);

		cout << "��� ������� ���� ������ ����������!" << endl;
	}

	if (way == 2)
	{
		cout << "���� ������� ��������� ��� ���" << endl << endl;
	}

	return;
}

void Client::show_results_of_operation(Credit_card& cd, double price, int type)
{
	//cout << endl;
	cout << "�������� ������� ������!" << endl << endl << "� ������ ������� ���� ����� " << price << " �������" << endl;
	cout << "ʳ������ ������ �� �������: " << cd.get_money_on_card() << " �������" << endl;
	cout << "�������� ������� ������: " << cd.get_credit() << " �������" << endl << endl;
}

void Client::show_results_of_operation(Credit_card& cd, double price, double type)
{
	//cout << endl;
	cout << "�������� ������� ������!" << endl << endl << "�� ������ ������� ���� ������ " << price << " �������" << endl;
	cout << "ʳ������ ������ �� �������: " << cd.get_money_on_card() << " �������" << endl;
	cout << "�������� ������� ������: " << cd.get_credit() << " �������" << endl << endl;
}

Client::~Client()
{
	cout << "��'��� ����� \"Client\" ��� ���������" << endl;
}

bool Client::Credit_card::get_access()
{
	return this->access;
}

void Client::Credit_card::change_access(bool state)
{
	this->access = state;
}

string Client::Credit_card::get_card_number()
{
	return this->card_number;
}

void Client::Credit_card::set_card_number(string card_number)
{
	this->card_number = card_number;
}

double Client::Credit_card::get_money_on_card()
{
	return this->money_on_card;
}

void Client::Credit_card::set_money_on_card(double money)
{
	this->money_on_card = money;
}

void Client::Credit_card::change_money_on_card(double money)
{
	this->money_on_card = this->money_on_card - money;
}

unsigned int Client::Credit_card::get_credit_limit()
{
	return this->credit_limit;
}

void Client::Credit_card::set_credit_limit(int credit_limit)
{
	this->credit_limit = credit_limit;
}

double Client::Credit_card::get_credit()
{
	return this->credit;
}

void Client::Credit_card::set_credit(double credit)
{
	this->credit = credit;
}

void Client::Credit_card::change_credit(double price)
{
	this->credit += price;
}

int Client::Credit_card::get_number_of_operations()
{
	return number_of_operations;
}

void Client::Credit_card::change_number_of_operations(int size)
{
	this->number_of_operations += size;
}

void Client::Credit_card::set_card_attributes(bool access, string card_number, double money_on_card, unsigned int credit_limit, double credit, int number_of_operations)
{
	this->access = access;
	this->card_number = card_number;
	this->money_on_card = money_on_card;
	this->credit_limit = credit_limit;
	this->credit = credit;
	this->number_of_operations = number_of_operations;
}

Client::Credit_card::Credit_card(bool access, string card_number, double money_on_card, unsigned int credit_limit, double credit, int number_of_operations)
{
	this->access = access;
	this->card_number = card_number;
	this->money_on_card = money_on_card;
	this->credit_limit = credit_limit;
	this->credit = credit;
	this->number_of_operations = number_of_operations;
}

Client::Credit_card::Credit_card()
{
	this->access = false;
	this->card_number = "";
	this->money_on_card = 0;
	this->credit_limit = 0;
	this->credit = 0;
	this->number_of_operations = 0;
}

Client::Credit_card::Credit_card(const Credit_card& cd)
{
	this->access = cd.access;
	this->card_number = cd.card_number;
	this->money_on_card = cd.money_on_card;
	this->credit_limit = cd.credit_limit;
	this->credit = cd.credit;
}

Client::Credit_card::~Credit_card()
{
	cout << "��'��� ����� \"Credit_card\" ��� ���������" << endl;
}

void Administator::initialize_card(Client::Credit_card& cd)
{
	string card_number;
	unsigned int credit_limit;
	double money_on_card, credit;
	int number_of_operations;

	cout << "������ ����� ����� �볺���: ";
	cin >> card_number;
	ConsoleOutput_write(card_number);
	//cd.set_card_number(*card_number);

	cout << endl << "������ ������� ������ �� ������ �볺���: ";
	money_on_card = check_int_corectness(1);
	//cin >> money_on_card;
	//cd.set_money_on_card(money);

	cout << "������ ��������� ��� �� ������ �볺���: ";
	credit_limit = check_int_corectness(1);
	//cin >> credit_limit;
	//cd.set_credit_limit(credit_limit);

	cout << "������ ��������� ������� ������� �볺���: ";
	credit = check_int_corectness(0);
	//cin >> credit;
	//cd.set_credit(credit);

	cout << "������ ��������� ������� ���������� ��������: ";
	number_of_operations = check_int_corectness(1);
	//cin >> number_of_operations;
	//cd.set_credit(number_of_operations);
	//cd.change_access(true);

	Client::Credit_card temp(true, card_number, money_on_card, credit_limit, credit, number_of_operations);

	cd = temp;

	cout << endl;

	return;
}

void Administator::block_credit_card(Client::Credit_card& cd)
{
	//read_data(cd);

	int type;
	if (cd.get_access() == true)
	{
		cout << "���� ������: ��������" << endl << "������������ �������: ";

		if (cd.get_credit() > cd.get_credit_limit())
		{
			cout << "���" << endl << "����������� ������� ������ " << (cd.get_credit() - cd.get_credit_limit()) << " �������" << endl << endl;
		}
		else
		{
			cout << "ͳ" << endl << endl;
		}

		cout << "������ ����������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cd.change_access(false);

			cout << "������ ���� ������ �����������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
		return;
	}
	if (cd.get_access() == false)
	{
		cout << "���� ������: �����������" << endl << endl << "������ �������� ������? " << "��� (1) ͳ (2)" << endl;
		cout << "������ �����: ";

		type = check_way(2, 0);

		if (type == 1)
		{
			cd.change_access(true);

			cout << "������ ���� ������ ���������!" << endl << endl;

			return;
		}

		cout << "���� ������ �볺��� ��������� ��� ���" << endl;
	}
}

void addtional_method() //���������� �����
{
	cout << "������ ������� �������� � �����: ";
	int size = check_int_corectness(1);

	int* array = new int[size];

	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << (array[i] = rand() % 100);
		cout << " ";
	}
	cout << "]" << endl << endl;

	bool swapped;
	for (int i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}

	cout << "³����������� �����" << endl << endl;

	cout << "[ ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
		cout << " ";
	}
	cout << "]" << endl << endl;

	delete[] array;

	return;
}

Administator::~Administator()
{
	cout << "��'��� ����� \"Administator\" ��� ���������" << endl;
}

void save_data(Client::Credit_card& cd)
{
	ofstream file("files/Client.txt");

	//file.write((char*)&cd, sizeof(Client::Credit_card));

	file << cd.get_access() << endl << cd.get_card_number() << endl << cd.get_money_on_card() << endl << cd.get_credit_limit() << endl << cd.get_credit() << endl << cd.get_number_of_operations();

	file.close();
}

void read_data(Client::Credit_card& cd)
{
	bool access;
	string card_number;
	double money_on_card;
	unsigned int credit_limit;
	double credit;
	int number_of_operations;

	ifstream file("files/Client.txt");

	//file.read(<char*>(&cd), sizeof(Client::Credit_card));

	file >> access >> card_number >> money_on_card >> credit_limit >> credit >> number_of_operations;

	cd.set_card_attributes(access, card_number, money_on_card, credit_limit, credit, number_of_operations);

	file.close();
}

void save_data(Product* pr)
{
	ofstream file("files/Products.txt");

	for (int i = 0; i < 5; i++)
	{
		//file.write((char*)&pr[i], sizeof(Product));
		file << pr[i].get_product_name() << endl << pr[i].get_price() << endl;
	}

	file.close();
}

void read_data(Product* pr)
{
	string name;
	double price;

	ifstream file("files/Products.txt");
	for (int i = 0; i < 5; i++)
	{
		//file.read((char*)&pr[i], sizeof(Product));
		file >> name >> price;
		pr[i].set_product(name, price);
	}
	file.close();
}

void ConsoleOutput_open()
{
	global_stream->open("ConsoleOutput.txt", ios::app);
}

void ConsoleOutput_clear()
{
	global_stream->open("ConsoleOutput.txt", ios::out);
	global_stream->close();
}

void ConsoleOutput_write(string string_line)
{
	cout << string_line;
	global_stream->close();
	return_back();
}

void temp1w_open()
{
	temp1w.open("temp1.txt", ios::app);
}

void temp1r_open()
{
	temp1r.open("temp1.txt");
}

void temp1_clear()
{
	temp1w.open("temp1.txt", ios::out);
	temp1w.close();
}

void temp2w_open()
{
	temp2w.open("temp2.txt", ios::app);
}

void temp2r_open()
{
	temp2r.open("temp2.txt");
}

void temp2_clear()
{
	temp2w.open("temp2.txt", ios::out);
	temp2w.close();
}

Product::Product(string name, double price)
{
	this->name = name;
	this->price = price;
}

Product::Product()
{}

Product::~Product()
{
	cout << "��'��� ����� \"Product\" ��� ���������" << endl;
}

int check_way(int way, int sub_way)
{
	//temp2w.close();
	return_back();
	global_stream->close();

	int type = 0;

	if (!(cin >> type))
	{
		//ConsoleOutput_try_again("����-�����, ������ �������� ��������");
		do
		{
			try_again();

			cout << endl << "����-�����, ������ �������� ��������" << endl << "������ �����: ";

			restart_cin();
			
		} while (!(cin >> type));
		//return_back(type);
	}

	if (type == 0)
	{
		return 0;
	}

	if (way == 1)
	{
		if (type != 2)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "������ � ������� ���������. ��������� ������: � ������ (2)" << endl << endl << "������ ��� ������: ";

				restart_cin();
				cin >> type;
			} while (type != 2);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 2)
	{
		if (type != 1 && type != 2)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "����-�����, ������ �������� �����" << endl << "������ �����: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 3)
	{
		if (type != 1 && type != 2 && type != 3)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "����-�����, ������ �������� �����" << endl << "������ �����: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 4)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "����-�����, ������ �������� �����" << endl << "������ �����: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 5 && sub_way == 0)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5)
		{
			cout << endl;
			do
			{
				try_again();

				cout << "����-�����, ������ �������� �����" << endl << "������ �����: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4 && type != 5);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	if (way == 5 && sub_way == 1)
	{
		if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5)
		{
			cout << endl;
			do
			{
				try_again();

				cout << endl << "������ �� ����� ������� �� ����. ����-�����, ������ �������� �����" << endl << "������ �����: ";

				restart_cin();
				cin >> type;

			} while (type != 1 && type != 2 && type != 3 && type != 4 && type != 5);
			cout << endl;
		}
		return_back(type);
		cout << endl;
	}

	//temp2w_open();

	return type;
}

void try_again()
{
	bool end = false, first_endl = false;
	string line1;

	temp2_clear();

	temp1w.open("temp1.txt", ios::in);
	temp2w_open();
	temp2w << temp1w.rdbuf() << endl << endl;
	temp2w.close();
	temp1w.close();

	system("cls");

	temp2r_open();
	while (end == false)
	{
		if (!getline(temp2r, line1))
		{
			end = true;
		}
		else
		{
			if (first_endl == false)
			{
				first_endl = true;
				cout << line1;
			}
			else
			{
				cout << endl << line1;
			}
		}
	}
	temp2r.close();
}

int check_int_corectness(int type)
{
	global_stream->close();

	int variable;

	if (!(cin >> variable))
	{
		do
		{
			try_again();

			cout << "����-�����, ������ �������� �����" << endl << "������ �����: ";
			
			restart_cin();
		} while (!(cin >> variable));
	}

	if (type == 1)
	{
		if (variable < 0)
		{
			do
			{
				try_again();

				cout << "����-�����, ������ �������� �����" << endl << "������ �����: ";

				restart_cin();
			} while (!(cin >> variable) || variable < 0);
		}
	}

	return_back(variable);
	return variable;
}

void return_to_start(Client& cl, Client::Credit_card& cd, Product* pr, Administator& adm, ofstream& stream)
{
	int type;

	//restart_cin();

	cout << "������ ����������� �� �������?" << endl << "��� (1) ͳ (2)" << endl << endl;
	cout << "������ �����: ";

	type = check_way(2, 0);
	if (type == 0)
	{
		return;
	}

	if (type == 1)
	{
		global_stream->close();
		global_stream->clear();

		temp1_clear();

		system("cls");
		main_script(cl, cd, pr, adm, stream);
	}
	if (type == 2)
	{
		system("cls");
		cout << "������ �������� ���� ��������" << endl << endl;
	}
}

void restart_cin()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

void Administator::initiliaze_products(Product* pr) //����� ������ � ������� ��'����
{
	string name;
	int price;
	for (int i = 0; i < 5; i++)
	{
		restart_cin();

		cout << "������ ����� " << i + 1 << "-�� ������: ";
		getline(cin, name);
		ConsoleOutput_write(name);

		cout << endl << "������ ���� " << i + 1 << "-�� ������: ";
		price = check_int_corectness(1);

		pr[i].set_product(name, price);
		cout << endl;
	}

	return;
}

void Administator::change_product(Product* pr) //����� ������ � ��c���� ��'����
{
	pr->print(pr);

	cout << "������ ����� ������, ���� �� ������ ������: " << endl;
	cout << "������ �����: ";

	int type = check_way(5, 1);

	string name;
	int price;

	restart_cin();

	cout << "������ ���� ����� " << type << "-�� ������: ";
	getline(cin, name);
	ConsoleOutput_write(name);

	cout << endl << "������ ���� ���� " << type << "-�� ������: ";
	price = check_int_corectness(1);

	pr[type - 1].set_product(name, price);

	cout << type << "-�� ����� ��� ������ �������!" << endl << endl;
}

void Product::set_product(string name, double price)
{
	this->name = name;
	this->price = price;
}

double Product::get_price()
{
	return this->price;
}

string Product::get_product_name()
{
	return this->name;
}

void Product::print(Product* pr)
{
	size_t length = 0;

	for (int i = 0; i < 5; i++)
	{
		if ((pr[i].name).length() > length)
		{
			length = (pr[i].name).length();
		}
	}

	cout << "������ ������:" << endl;

	cout << setw(3) << left << "N" << setw(length + 3) << "�����" << "ֳ��" << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << setw(3) << i + 1 << setw(length + 3) << pr[i].name << pr[i].price << endl << endl;
	}
}

void addtional_method(Client::Credit_card& cd, int a)
{
	//�������� ���� ����������
	cout << "��������� \"������ ���������\": " << cd.get_money_on_card() + cd.get_credit_limit() + cd.get_credit() + cd.get_number_of_operations() << endl << endl;
}

void addtional_method(Client::Credit_card* cd, double a)
{
	//�������� ���� ����������
	cout << "��������� \"������ ���������\": " << cd->get_money_on_card() + cd->get_credit_limit() + cd->get_credit() + cd->get_number_of_operations() << endl << endl;
	//������� ��� �������� ��ﳿ?
}

Client::Credit_card addtional_method(Client::Credit_card& cd)
{
	cout << "��������� \"������ ���������\": " << cd.get_money_on_card() + cd.get_credit_limit() + cd.get_credit() + cd.get_number_of_operations() << endl << endl;
	return cd;
}

void MoveWindow(int posx, int posy)
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void MoveCenter()
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posx, posy;
	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2;
	posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;

	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void Print_in_center(const string& s)
{
	int width_field = 120;
	string v(width_field, ' ');
	string v1;

	int l_word = s.size();
	int l_field = v.size();
	int step = (l_field - l_word) / 2;

	for (int i = 0; i < l_word; i++) {
		v1.push_back(s[i]);
	}
	copy(v1.begin(), v1.end(), v.begin() + step);
	for (auto x : v) {
		cout << x;
	}
	cout << endl;
}

MyStreambuf::~MyStreambuf()
{
	cout << "��'��� ����� \"MyStreambuf\" ��� ���������";

	restart_cin();

	global_stream->close();
	//temp2w.close();

	cin.get();
}

void return_back(int input)
{
	global_stream->close();
	//global_stream << input;
	//c++ singleton
	//SOLID
	//Design pattern Strategy
	//Design pattern Factory
	//Design pattern Singleton
	//Design patterr adapter
	//Design pattern decorator
	//Design pattern bridge

	//global_stream->close();

	bool end = false, first_endl = false;

	//global_stream->open("ConsoleOutput.txt", ios::app);
	//cout << endl;
	//global_stream->close();

	global_stream->open("ConsoleOutput.txt", ios::in);
	//ofstream temp1("temp.txt", ios::app);
	temp1w_open();
	temp1w << global_stream->rdbuf();
	temp1w.close();

	temp1w_open();
	temp1w << input << endl;
	temp1w.close();

	global_stream->close();

	//global_stream->open("ConsoleOutput.txt", ios::out);
	//global_stream->close();

	system("cls");

	//ifstream temp2("temp.txt");
	string line1, line2;

	temp1r_open();
	while (end == false)
	{
		if (!getline(temp1r, line1))
		{
			end = true;
		}
		else
		{
			if (first_endl == false)
			{
				first_endl = true;
				cout << line1;
			}
			else
			{
				cout << endl << line1;
			}
		}
	}
	temp1r.close();

	cout << endl;

	ConsoleOutput_clear();
	ConsoleOutput_open();
}

void return_back()
{
	global_stream->close();

	bool end = false, first_endl = false;

	//global_stream->open("ConsoleOutput.txt", ios::app);
	//cout << endl;
	//global_stream->close();

	global_stream->open("ConsoleOutput.txt", ios::in);
	//ofstream temp1("temp.txt", ios::app);
	temp1w_open();
	temp1w << global_stream->rdbuf();
	temp1w.close();
	global_stream->close();

	//global_stream->open("ConsoleOutput.txt", ios::out);
	//global_stream->close();

	system("cls");

	//ifstream temp2("temp.txt");
	string line1, line2;

	temp1r_open();
	while (end == false)
	{
		if (!getline(temp1r, line1))
		{
			end = true;
		}
		else
		{
			if (first_endl == false)
			{
				first_endl = true;
				cout << line1;
			}
			else
			{
				cout << endl << line1;
			}
		}
	}
	temp1r.close();

	//cout << endl;

	ConsoleOutput_clear();
	ConsoleOutput_open();
}


//Trash


Additional_Class_With_Private_Imitation::Additional_Class_With_Private_Imitation(string name, double price, int add1, float add2, double add3) : Product(name, price)
{

}

Additional_Class_1::Additional_Class_1(int add)
{
	this->add = add;
	cout << "��� ��������� ��\'��� ����� \"Additional_Class_1\"" << endl;
}

Additional_Class_1::~Additional_Class_1()
{
	cout << "��\'��� ����� \"Additional_Class_1\" ��� ���������" << endl << endl;
}

Additional_Class_2::Additional_Class_2(int add)
{
	this->add = add;
	cout << "��� ��������� ��\'��� ����� \"Additional_Class_2\"" << endl;
}

Additional_Class_2::~Additional_Class_2()
{
	cout << "��\'��� ����� \"Additional_Class_2\" ��� ���������" << endl;
}

Additional_Class_3::Additional_Class_3(int add)
{
	this->add = add;
	cout << "��� ��������� ��\'��� ����� \"Additional_Class_3\"" << endl;
}

Additional_Class_3::~Additional_Class_3()
{
	cout << "��\'��� ����� \"Additional_Class_3\" ��� ���������" << endl;
}

Additional_Class_123::Additional_Class_123(int add, int add1, int add2, int add3) : Additional_Class_1(add1), Additional_Class_2(add2), Additional_Class_3(add3)
{
	this->add = add;
	this->add1 = add1;
	this->add2 = add2;
	this->add3 = add3;
	cout << "��� ��������� ��\'��� ����� \"Additional_Class_123\"" << endl << endl;
}

Additional_Class_123::~Additional_Class_123()
{
	cout << "��\'��� ����� \"Additional_Class_123\" ��� ���������" << endl;
}