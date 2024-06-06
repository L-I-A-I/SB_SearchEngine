#include "gtest/gtest.h"
#include "ConverterJSON.h"
#include "InvertedIndex.h"
#include "SearchServer.h"

TEST(sample_test_case, sample_test)
{
	ConverterJSON converter;
	EXPECT_EQ(5, converter.getResponsesLimit());
}
TEST(TestCaseInvertedIndex, TestBasic)
{
	std::ofstream ofs("Documents/File001.txt");
	ofs << "london is the london  capital of great britain   london  ";
	ofs.close();
	std::vector<std::string> docs{ "Documents/File001.txt" };
	InvertedIndex idx(docs);
	

	EXPECT_EQ(3, idx.getWordCount("london")[0].second);
}
TEST(TestCaseSearchServer, TestSimple)
{
	const std::vector<std::string> docs{
		"Documents/file001.txt",
		"Documents/file002.txt",
		"Documents/file003.txt",
		"Documents/file004.txt"
	};
	const std::vector<std::string> docsTexts = {
		"milk milk milk milk water water water",
		"milk water water",
		"milk milk milk milk milk water water water water water",
		"americano cappuccino"
	};

	std::ofstream ofs;
	for (size_t i = 0; i < docs.size() && i < docsTexts.size(); ++i)
	{
		ofs.open(docs[i]);
		ofs << docsTexts[i];
		ofs.close();
	}

	const std::vector<std::string> request = { "milk water", "sugar" };
	const std::vector<std::vector<std::pair<size_t, float>>> expected = { {{2, 1}, {0, 0.7}, {1, 0.3}},	{} };

	SearchServer srv(docs);
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
	const std::vector<std::string> docs{
		"Documents/file001.txt",
		"Documents/file002.txt",
		"Documents/file003.txt",
		"Documents/file004.txt",
		"Documents/file005.txt",
		"Documents/file006.txt",
		"Documents/file007.txt",
		"Documents/file008.txt",
		"Documents/file009.txt",
		"Documents/file010.txt",
		"Documents/file011.txt",
		"Documents/file012.txt",
		"Documents/file013.txt",
		"Documents/file014.txt",
		"Documents/file015.txt",
		"Documents/file016.txt",
		"Documents/file017.txt",
		"Documents/file018.txt",
		"Documents/file019.txt",
		"Documents/file020.txt",
		"Documents/file021.txt",
		"Documents/file022.txt"
	};
	const std::vector<std::string> docsTexts = {
		"london is the london  capital of great britain   london  ",
		"paris is the capital of france",
		"berlin is the capital of germany",
		"rome is the capital of italy",
		"madrid is the capital of spain",
		"lisboa is the capital of portugal",
		"bern is the capital of switzerland",
		"moscow is the capital of russia",
		"kiev is the capital of ukraine",
		"minsk is the capital of belarus",
		"astana is the capital of kazakhstan",
		"beijing is the capital of china",
		"tokyo is the capital of japan",
		"bangkok is the capital of thailand",
		"welcome to moscow the capital of russia the third rome",
		"amsterdam is the capital of netherlands",
		"helsinki is the capital of finland",
		"oslo is the capital of norway",
		"stockholm is the capital of sweden",
		"riga is the capital of latvia",
		"tallinn is the capital of estonia",
		"warsaw is the capital of poland"
	};

	std::ofstream ofs;
	for (size_t i = 0; i < docs.size() && i < docsTexts.size(); ++i)
	{
		ofs.open(docs[i]);
		ofs << docsTexts[i];
		ofs.close();
	}

	const std::vector<std::string> request = { "moscow is the capital of russia" };
	const std::vector<std::vector<std::pair<size_t, float>>> expected = { {{7, 1}, {14, 1}, {0, 0.666666687}, {1, 0.666666687},	{2, 0.666666687}} };
	SearchServer srv(docs);
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

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}