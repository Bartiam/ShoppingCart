#include "Basket.h"

// Реализация метода заполнение склада товарами;
void Shop::fill_products(std::string& article, int& count)
{
	while (true)
	{
		std::cout << "Enter the article of the product: " << std::endl;
		std::cin >> article;
		if (article == "Stop" || article == "stop") break;
		std::cout << "Enter the product quantity: ";
		std::cin >> count;

		// Бросает исключение в случае если количество добавляемого товара меньше 0;
		if (count < 0) throw std::invalid_argument("invalid_argument\nThe number of products cannot be less than 0. Try again.");
		// Добавляет товар в список товаров магазина;
		else products.emplace(article, count);

		std::cout << "To stop filling the warehouse, enter \"stop\". " << std::endl;
	}
}

// Релизация метода добавления товара в корзину;
void Shop::add_product(std::string& article, int& count)
{
	// Переменная для проверки имеется ли такой товар в магазине;
	bool isTrue = true;
	// Проверка есть ли товары в магазине;
	if (products.empty()) throw std::runtime_error("runtime_error!\nThe store's warehouse is empty.");

	// Проверки перед добавлением товара в коризну;
	while (true)
	{
		// Вывод списка товаров;
		std::cout << "You can add products from the list: " << std::endl;
		for (const auto& product : products)
			std::cout << "Article: " << product.first << "\tCount: " << product.second << std::endl;

		std::cout << "Enter the article of the product: " << std::endl;
		std::cin >> article;
		if (article == "Stop" || article == "stop") break;
		std::cout << "Enter the product quantity: ";
		std::cin >> count;

		// Проверка на введённое количество товаров;
		if (count < 0) throw std::invalid_argument("invalid_argument!\nThe number of products cannot be less than 0. ");
		for (auto it = products.begin(); it != products.end(); ++it)
		{
			if (it->first == article) // Поиск товара на складе;
			{
				if (it->second < count) // Сравнение введённого количества товара и доступного товара в магазине;
					throw std::invalid_argument("invalid_argument!\nThere is no such quantity of goods in the store.");
				
				if (it->second > count) it->second -= count;
				else products.erase(it);

				// Добавление товара в корзину;
				basket.emplace(article, count);
				isTrue = true;
				std::cout << "If you have added all the necessary products, enter \"stop\"." << std::endl;
				break;
			}
			else isTrue = false;
		}
		// Бросает исключение если такого товара нет на складе;
		if (!isTrue) throw std::invalid_argument("invalid_argument!\nThere is no such product in the store. ");
	}
}
// Реализация метода удаления товара из корзины;
void Shop::remove_product(std::string& article, int& count)
{
	bool isTrue = true;
	// Проверка есть ли товары в корзине;
	if (basket.empty()) throw std::runtime_error("runtime_error!\nThe basket is empty.");

	// Проверки перед удалением товара из коризны;
	while (true)
	{
		// Вывод списка товаров;
		std::cout << "You can only delete what is in the basket. Here is the list: " << std::endl;
		for (const auto& product : basket)
			std::cout << "Article: " << product.first << "\tCount: " << product.second << std::endl;

		std::cout << "Enter the article of the product: " << std::endl;
		std::cin >> article;
		if (article == "Stop" || article == "stop") break;
		std::cout << "Enter the product quantity: ";

		// Проверка на введённое количество товаров;
		if (count < 0) throw std::invalid_argument("invalid_argument!\nThe number of products cannot be less than 0. ");

		for (auto it = basket.begin(); it != basket.end(); ++it)
		{
			if (it->first == article) // Поиск товара в корзине;
			{
				if (it->second < count) // Сравнение введённого количества товара и доступного товара в корзине;
					throw std::invalid_argument("invalid_argument!\nThere are not so many items in the basket.");

				// Удаление товара из корзины;
				if (it->second > count) it->second -= count;
				else basket.erase(it);
				isTrue = true;
				std::cout << "If you deleted everything you wanted, enter \"stop\"." << std::endl;
				break;
			}
			else isTrue = false;
		}
		// Бросает исключение если такого товара нет в корзине;
		if (!isTrue) throw std::invalid_argument("invalid_argument!\nThis product is not in the basket. ");
	}
}
