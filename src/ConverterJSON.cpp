#include "ConverterJSON.h"

bool ConverterJSON::checkConfig()
{
	std::ifstream file("config.json");
	if (file.is_open())
	{
		json jConf;
		file >> jConf;
		file.close();

		if (jConf.find("config") != jConf.end() && jConf.find("files") != jConf.end())
		{
			if (jConf["config"].find("index_interval") != jConf["config"].end() &&
				jConf["config"].find("max_responses") != jConf["config"].end() &&
				jConf["config"].find("name") != jConf["config"].end() &&
				jConf["config"].find("version") != jConf["config"].end() &&
				jConf["config"].find("index_interval") != jConf["config"].end())
			{
				if (jConf["config"]["index_interval"].is_number_integer() &&
					jConf["config"]["max_responses"].is_number_integer() &&
					jConf["config"]["index_interval"].is_number_integer() &&
					jConf["config"]["name"].is_string() &&
					jConf["config"]["version"].is_string())
				{
					return true;
				}
				else
				{
					std::cerr << "Config properties broken\n";
					
					return false;
				}
			}
			else
			{
				std::cerr << "Config properties not found\n";
				return false;
			}
		}
		else
		{
			std::cerr << "Config file is broken\n";
			return false;
		}
	}
	else
	{
		std::cerr << "Config file not found\n";
		return false;
	}
}

int ConverterJSON::getIndexInterval()
{
	std::ifstream file("config.json");
	json jInt;
	file >> jInt;
	file.close();
	return jInt["config"]["index_interval"];
}

std::vector<std::string> ConverterJSON::getDocumentsAddresses()
{
	std::ifstream file("config.json");
	json jDocs;
	file >> jDocs;
	file.close();
	std::vector<std::string> docs;

	for (auto& doc : jDocs["files"]) {
		docs.emplace_back(doc);
	}

	return docs;
}

size_t ConverterJSON::getResponsesLimit()
{
	std::ifstream file("config.json");
	json jRespLim;
	file >> jRespLim;
	file.close();

	return 	jRespLim["config"]["max_responses"];
}

std::vector<std::string> ConverterJSON::getRequests()
{
	std::ifstream file("requests.json");
	json jReqs;
	file >> jReqs;
	file.close();
	std::vector<std::string> reqs;

	for (auto& req : jReqs["requests"]) {
		reqs.emplace_back(req);
	}

	return reqs;
}

void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<size_t, float>>> answers)
{
	json jAns;
	for (size_t i = 0; i < answers.size(); ++i)
	{
		if (answers[i].empty())
		{
			jAns["request" + std::to_string(i)] += {{"result", false}};
		}
		else
		{
			jAns["request" + std::to_string(i)] += {{"result", true}};

			if (answers[i].size() > 1)
			{
				json jRel;
				for (size_t j = 0; j < answers[i].size(); ++j)
				{

					jRel["relevance"] += { {"docid", answers[i][j].first}, { "rank", answers[i][j].second } };
				}
				jAns["request" + std::to_string(i)] += jRel;
			}
			else
			{
				jAns["request" + std::to_string(i)] += { {"docid", answers[i][0].first}, { "rank", answers[i][0].second } };
			}
			
			
			
		}

		
	}
	
	std::ofstream file("answers.json");
	file << jAns;
	file.close();
}
