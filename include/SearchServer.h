#pragma once

#include "InvertedIndex.h"

#include <vector>
#include <sstream>

class SearchServer {
public:
	SearchServer(const std::vector<std::string>& docs = ConverterJSON::getDocumentsAddresses());
	std::vector<std::vector<std::pair<size_t, float>>> search(const std::vector<std::string>& queries_input = ConverterJSON::getRequests());
	void startIndexing();
private:
	InvertedIndex index;
};