#include "SearchServer.h"

SearchServer::SearchServer(const std::vector<std::string>& docs) : index{docs}{}

std::vector<std::vector<std::pair<size_t, float>>> SearchServer::search(const std::vector<std::string>& reqs)
{
	std::vector<std::vector<std::pair<size_t, float>>> answer;

	for (size_t i = 0; i < reqs.size(); ++i)
	{
		answer.emplace_back(std::vector<std::pair<size_t, float>>{});

		std::map<size_t, size_t> docsScores;
		std::stringstream req;
		req<< reqs[i];
		std::string word;

		while (req >> word)
		{
			auto wordCount = index.getWordCount(word);

			for (size_t j = 0; j < wordCount.size(); ++j)
			{
				docsScores[wordCount[j].first] += wordCount[j].second;
			}
		}

		if (!docsScores.empty())
		{
			for (auto& docScore : docsScores)
			{
				answer[i].emplace_back(docScore);
			}

			std::sort(answer[i].begin(), answer[i].end(), [](std::pair<size_t, float> a, std::pair<size_t, float> b)
			{
				return a.second > b.second;
			});

			size_t respLimit = ConverterJSON::getResponsesLimit();
			if (answer[i].size() > respLimit)
			{
				answer[i].resize(respLimit);
			}

			size_t div = answer[i][0].second;
			for (size_t j = 0; j < answer[i].size(); ++j)
			{
				answer[i][j].second /= div;
			}
		}		
	}

    return answer;
}

bool SearchServer::startIndexing()
{
	if (index.isBusy)
	{
		std::cout << "\nAnother indexing is in progress\n";
		return false;
	}
	else
	{
		index.updateDocumentBase();
		return true;
	}
}