#pragma once

#include "InvertedIndex.h"

#include <vector>
#include <sstream>
#include <algorithm>



class SearchServer {
public:		
	std::vector<std::vector<std::pair<size_t, float>>> search(const std::vector<std::string>& queries_input = ConverterJSON::getRequests());
	void startIndexing();
private:
	InvertedIndex index;
};