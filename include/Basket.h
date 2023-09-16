#pragma once
#include <iostream>
#include <string>
#include <map>

class Shop
{
private:
	// Товары в коризне;
	std::map<std::string, int> basket;
	// Товары в наличии;
	std::map<std::string, int> products;
	// Переменные для ввода информации о товаре;
public:
	// Прототип метода заполнение склада товарами;
	void fill_products(std::string& article, int& count);
	// Прототип метода добавления товара в корзину;
	void add_product(std::string& article, int& count);
	//Прототип метода удаление товара из корзины;
	void remove_product(std::string& article, int& count);
};