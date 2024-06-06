#pragma once

#include "ConverterJSON.h"

#include <vector>
#include <thread>
#include <mutex>

class InvertedIndex
{
public:
	InvertedIndex(const std::vector<std::string>& docs = ConverterJSON::getDocumentsAddresses());

	void updateDocumentBase(const std::vector<std::string>& docs = ConverterJSON::getDocumentsAddresses());
	std::vector<std::pair<size_t, size_t>> getWordCount(const std::string& word);
	bool isBusy;

private:
	std::map<std::string, std::vector<std::pair<size_t, size_t>>> freqDictionary;
};