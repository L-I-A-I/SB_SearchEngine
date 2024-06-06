#include "InvertedIndex.h"

InvertedIndex::InvertedIndex(const std::vector<std::string>& docs)
{
	updateDocumentBase(docs);
}


void InvertedIndex::updateDocumentBase(const std::vector<std::string>& docs)
{
	isBusy = true;
	freqDictionary.clear();

	std::mutex dictMute, idMute;
	size_t docId{ 0 };
	std::vector<std::thread> cores;

	for (size_t i = 0; i < std::thread::hardware_concurrency() && i < docs.size(); ++i)
	{
		cores.emplace_back(std::thread([&]() {
			while (docId < docs.size())
			{
				idMute.lock();
				size_t tempId{ docId };
				++docId;
				idMute.unlock();

				std::ifstream file(docs[tempId]);

				if (file.is_open())
				{
					std::map<std::string, size_t> wordsCount;
					std::string word;

					while (file >> word)
					{
						wordsCount[word] += 1;
					}
					file.close();
					for (auto& wc : wordsCount)
					{
						dictMute.lock();
						freqDictionary[wc.first].emplace_back(tempId, wc.second);
						dictMute.unlock();
					}
				}
				else
				{
					std::cerr << "Couldn't open doc №" << i << "\n";
				}
			}})
		);
	}

	for (auto& t : cores) t.join();
	isBusy = false;
}

std::vector<std::pair<size_t, size_t>> InvertedIndex::getWordCount(const std::string& word)
{
	if (isBusy)
	{
		std::cout << "\nWaiting for indexing to finish\n";

		while (isBusy)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	if (freqDictionary.find(word) != freqDictionary.end())
	{
		return freqDictionary[word];
	} 
	else
	{
		return std::vector<std::pair<size_t, size_t>>{};
	}
}
