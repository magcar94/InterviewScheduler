#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> ParseLine(std::string line)
{
	std::istringstream ss (line);
	std::vector<std::string> cell;
	char c;
	std::string token;
	while (std::getline(ss, token, ','))
	{
		cell.push_back(token);
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

void Print2DStringList(std::vector<std::vector<std::string>> List)
{
	for (int i = 0; i < List.size(); i++) {
		std:: cout << "[";
		for (int j = 0; j < List[i].size(); j++) {
			std::cout << "("<< List[i][j] <<")"<< " ";
		}
		std::cout << "]" << "\n";
	}
}
void PrintStringList(std::vector<std::string> List)
{
	for (auto row : List) 
	{
		std::cout << "[";
			std::cout << row << " ";
		std::cout << "]" << "\n";
	}
}

void FillEmployers(std::vector<std::vector<std::string>> InputList, std::vector < std::string > & EmployerList)
{
	for (int i = 0; i < InputList.size(); i++) {
		std::cout << "[";
		for (int j = 0; j < InputList[i].size(); j++) {
			std::cout << "(" << InputList[i][j] << ")" << " ";

			if (j == 0)
			{
				EmployerList.push_back(InputList[i][j]);
			}
		}
		std::cout << "]" << "\n";
	}
}


int main()
{
	auto IntervList = ReadInterviewList("D:/Git/InterviewScheduler/IntSched/InterviewList.txt");
	std::vector<std::string> EmployerList;
	FillEmployers(IntervList, EmployerList);
	Print2DStringList(IntervList);
	PrintStringList(EmployerList);
}
