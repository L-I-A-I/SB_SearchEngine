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
	static int getIndexInterval();
	static std::vector<std::string> getDocumentsAddresses();
	static std::vector<std::string> getRequests();
	static void putAnswers(std::vector<std::vector<std::pair<size_t, float>>> answers);
	static size_t getResponsesLimit();
};