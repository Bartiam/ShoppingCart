#include "Basket.h"

// ���������� ������ ���������� ������ ��������;
void Shop::fill_products(std::string& article, int& count)
{
	while (true)
	{
		std::cout << "Enter the article of the product: " << std::endl;
		std::cin >> article;
		if (article == "Stop" || article == "stop") break;
		std::cout << "Enter the product quantity: ";
		std::cin >> count;

		// ������� ���������� � ������ ���� ���������� ������������ ������ ������ 0;
		if (count < 0) throw std::invalid_argument("The number of products cannot be less than 0. Try again.");
		// ��������� ����� � ������ ������� ��������;
		else products.emplace(article, count);

		std::cout << "To stop filling the warehouse, enter \"stop\". " << std::endl;
	}
}

// ��������� ������ ���������� ������ � �������;
void Shop::add_product(std::string& article, int& count)
{
	// ���������� ��� �������� ������� �� ����� ����� � ��������;
	bool isTrue = true;
	// �������� ���� �� ������ � ��������;
	if (products.empty()) throw std::runtime_error("runtime_error!\nThe store's warehouse is empty.");

	// �������� ����� ����������� ������ � �������;
	while (true)
	{
		// ����� ������ �������;
		std::cout << "You can add products from the list: " << std::endl;
		for (const auto& product : products)
			std::cout << "Article: " << product.first << "\tCount: " << product.second << std::endl;

		std::cout << "Enter the article of the product: " << std::endl;
		std::cin >> article;
		if (article == "Stop" || article == "stop") break;
		std::cout << "Enter the product quantity: ";
		std::cin >> count;

		// �������� �� �������� ���������� �������;
		if (count < 0) throw std::invalid_argument("invalid_argument!\nThe number of products cannot be less than 0. ");
		for (auto it = products.begin(); it != products.end(); ++it)
		{
			if (it->first == article) // ����� ������ �� ������;
			{
				if (it->second < count) // ��������� ��������� ���������� ������ � ���������� ������ � ��������;
					throw std::invalid_argument("invalid_argument!\nThere is no such quantity of goods in the store.");
				
				if (it->second > count) it->second -= count;
				else products.erase(it);

				// ���������� ������ � �������;
				basket.emplace(article, count);
				isTrue = true;
				std::cout << "If you have added all the necessary products, enter \"stop\"." << std::endl;
				break;
			}
			else isTrue = false;
		}
		// ������� ���������� ���� ������ ������ ��� �� ������;
		if (!isTrue) throw std::invalid_argument("invalid_argument!\nThere is no such product in the store. ");
	}
}
// ���������� ������ �������� ������ �� �������;
void Shop::remove_product(std::string& article, int& count)
{
	bool isTrue = true;
	// �������� ���� �� ������ � �������;
	if (basket.empty()) throw std::runtime_error("runtime_error!\nThe basket is empty.");

	// �������� ����� ��������� ������ �� �������;
	while (true)
	{
		// ����� ������ �������;
		std::cout << "You can only delete what is in the basket. Here is the list: " << std::endl;
		for (const auto& product : basket)
			std::cout << "Article: " << product.first << "\tCount: " << product.second << std::endl;

		std::cout << "Enter the article of the product: " << std::endl;
		std::cin >> article;
		if (article == "Stop" || article == "stop") break;
		std::cout << "Enter the product quantity: ";

		// �������� �� �������� ���������� �������;
		if (count < 0) throw std::invalid_argument("invalid_argument!\nThe number of products cannot be less than 0. ");

		for (auto it = basket.begin(); it != basket.end(); ++it)
		{
			if (it->first == article) // ����� ������ � �������;
			{
				if (it->second < count) // ��������� ��������� ���������� ������ � ���������� ������ � �������;
					throw std::invalid_argument("invalid_argument!\nThere are not so many items in the basket.");

				// �������� ������ �� �������;
				if (it->second > count) it->second -= count;
				else basket.erase(it);
				isTrue = true;
				std::cout << "If you deleted everything you wanted, enter \"stop\"." << std::endl;
				break;
			}
			else isTrue = false;
		}
		// ������� ���������� ���� ������ ������ ��� � �������;
		if (!isTrue) throw std::invalid_argument("invalid_argument!\nThis product is not in the basket. ");
	}
}
