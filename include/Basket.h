#pragma once
#include <iostream>
#include <string>
#include <map>

class Shop
{
private:
	// ������ � �������;
	std::map<std::string, int> basket;
	// ������ � �������;
	std::map<std::string, int> products;
	// ���������� ��� ����� ���������� � ������;
public:
	// �������� ������ ���������� ������ ��������;
	void fill_products(std::string& article, int& count);
	// �������� ������ ���������� ������ � �������;
	void add_product(std::string& article, int& count);
	//�������� ������ �������� ������ �� �������;
	void remove_product(std::string& article, int& count);
};