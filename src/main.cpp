#include "Basket.h"

int main()
{

	Shop myShop;
	std::string command;
	int count;
	
	while (true)
	{
		try
		{
			myShop.fill_products(command, count);
			break;
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	while (command != "Exit" && command != "exit")
	{
		std::cout << "Enter the command: ";
		std::cin >> command;

		if (command == "Add" || command == "add")
		{
			try
			{
				myShop.add_product(command, count);
			}
			catch (const std::exception& ex)
			{
				std::cerr << ex.what() << std::endl;
			}
		}
		else if (command == "Remove" || command == "remove")
		{
			try
			{
				myShop.remove_product(command, count);
			}
			catch (const std::exception& ex)
			{
				std::cerr << ex.what() << std::endl;
			}
		}
		else std::cerr << "Error! Incorrect input command. Try again. " << std::endl;
	}
}