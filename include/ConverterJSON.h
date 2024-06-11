#pragma once

#include <fstream>
#include <vector>
#include <map>
#include <iostream>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

class ConverterJSON
{
public:

	static bool checkConfig();
	static size_t getIndexInterval();
	static std::vector<std::string> getDocumentsAddresses();
	static std::vector<std::string> getRequests();
	static bool putAnswers(std::vector<std::vector<std::pair<size_t, float>>> answers);
	static size_t getResponsesLimit();
};