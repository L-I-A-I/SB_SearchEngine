#include "ConverterJSON.h"
#include "SearchServer.h"

bool input(std::string& command)
{
	std::cout << "Enter Command: ";
	std::cin >> command;

	if (command != "exit")
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main(int argc, char* argv[])
{	
	if (ConverterJSON::checkConfig())
	{
		SearchServer server;
		std::string command;

		std::thread indexing([&server]()
		{
			while (true)
			{
				std::this_thread::sleep_for(std::chrono::seconds(ConverterJSON::getIndexInterval()));
				server.startIndexing();
			}
		});
		indexing.detach();

		while (input(command))
		{
			if (command == "put")
			{
				if(ConverterJSON::putAnswers(server.search()))
					std::cout << "\nPut is complete\n";
				else 
					std::cout << "\nPut is NOT complete\n";
			}
			else if (command == "index")
			{
				if(server.startIndexing())
					std::cout << "\nManual indexing is complete\n";
				else
					std::cout << "\nManual indexing is NOT complete\n";
			}
			else std::cout << "Wrong command\n";
		}
	}

	std::cout << "\n" << "EXITING";
	std::cin.get();
}