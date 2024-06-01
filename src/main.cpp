#include "ConverterJSON.h"
#include "SearchServer.h"
//#include "gtest/gtest.h"

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
	/*
	testing::InitGoogleTest(&argc, argv);

	std::cout << RUN_ALL_TESTS() << "\n";
	*/
	
	if (ConverterJSON::checkConfig()) {
		SearchServer server;
		std::string command;

		std::thread indexing([&server]() {
			while (true)
			{
				std::this_thread::sleep_for(std::chrono::seconds(ConverterJSON::getIndexInterval()));
				server.startIndexing();
			}
		});
		indexing.detach();

		while (input(command))
		{
			if (command == "put") ConverterJSON::putAnswers(server.search());
		}
	}
}

/*
TEST(sample_test_case, sample_test)
{
	ConverterJSON converter;
	EXPECT_EQ(5, converter.getResponsesLimit());
}
TEST(TestCaseInvertedIndex, TestBasic)
{
	InvertedIndex idx;

	EXPECT_EQ(9, idx.getWordCount("minsk")[0].first);
}
TEST(TestCaseSearchServer, TestSimple)
{
	const std::vector<std::string> docs = {
	"milk milk milk milk water water water",
	"milk water water",
	"milk milk milk milk milk water water water water water",
	"americano cappuccino"
	};
	const std::vector<std::string> request = { "milk water", "sugar" };
	const std::vector<std::vector<std::pair<int, float>>> expected = { {{2, 1}, {0, 0.7}, {1, 0.3}},	{} };
	SearchServer srv;
	auto result = srv.search(request);
	bool exp{ true };
	bool res{ true };
	if (result.size() == expected.size())
	{
		for (size_t i = 0; i < result.size(); i++)
		{
			for (size_t j = 0; j < result[i].size(); ++j)
			{
				if (result[i][j].first != expected[i][j].first || result[i][j].second != expected[i][j].second || (result.empty() && expected.empty()))
				{
					res = false;
				}
			}
		}
	}
	else
	{
		res = false;
	}

	ASSERT_EQ(res, exp);
}
TEST(TestCaseSearchServer, TestTop5)
{
	const std::vector<std::string> request = { "moscow is the capital of russia" };
	const std::vector<std::vector<std::pair<int, float>>> expected = { {{7, 1}, {14, 1}, {0, 0.666666687}, {1, 0.666666687},	{2, 0.666666687}} };
	SearchServer srv;
	auto result = srv.search(request);
	bool exp{ true };
	bool res{ true };
	if (result.size() == expected.size())
	{
		for (size_t i = 0; i < result.size(); i++)
		{
			for (size_t j = 0; j < result[i].size(); ++j)
			{
				if (result[i][j].first != expected[i][j].first || result[i][j].second != expected[i][j].second)
				{
					res = false;
				}
			}
		}
	}
	else
	{
		res = false;
	}

	ASSERT_EQ(res, exp);
}
*/