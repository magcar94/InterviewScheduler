#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>




std::vector<std::string> ParseLine(std::string line)
{
	std::istringstream sline (line);
	std::vector<std::string> cell;
	char c;
	std::string s;
	while (sline >> s)
	{
		cell.push_back(s);
	}

	return cell;
}

std::vector<std::vector<std::string>> ReadInterviewList(std::string path)
{
	std::ifstream InterviewList(path);
	std::vector<std::vector< std::string>> RetInterviewList;
	while (InterviewList)
	{
		std::string line;
		while (std::getline(InterviewList, line))
		{
			std::vector<std::string> row = ParseLine(line);
			RetInterviewList.push_back(row);
		}
	}
	return RetInterviewList;
}

void PrintList(std::vector<std::vector<std::string>> List)
{
	for (int i = 0; i < List.size(); i++) {
		for (int j = 0; j < List[i].size(); j++) {
			std::cout << List[i][j];
		}
		std::cout << "\n";
	}
}

int main()
{
	auto IntervList = ReadInterviewList("D:/Git/InterviewScheduler/IntSched/InterviewList.txt");
	PrintList(IntervList);
}
