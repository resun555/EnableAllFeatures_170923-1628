// EnableAllFeatures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	system("C:");
	system("cd C:\\Windows\\System32");
	system("diskpart.exe /s \"C:\\Users\\EwacEbup\\Documents\\Visual Studio 2017\\Projects\\EnableAllFeatures\\EnableAllFeatures\\diskpart.txt\"");
	system("Dism.exe /Image:I:\\ /Get-Features /Format:Table > \"C:\\Users\\EwacEbup\\Documents\\Visual Studio 2017\\Projects\\EnableAllFeatures\\EnableAllFeatures\\GetFeatures.txt\"");
	std::string path = "C:\\Users\\EwacEbup\\Documents\\Visual Studio 2017\\Projects\\EnableAllFeatures\\EnableAllFeatures\\GetFeatures.txt";
	std::ifstream *reader = new std::ifstream(path, std::ios::in);
	if (!*reader)
	{
		delete reader;
		throw new std::exception("System.FileNotFound");
	}
	List<> *rows = new List<>();
	while (!reader->eof())
	{
		std::string row;
		std::getline(*reader, row);
		try
		{
			rows->Insert(row, rows->Length() + 1);
		}
		catch (const std::exception *e)
		{
			std::cerr << e->what();
		}
	}
	reader->close();
	rows->Traversal(Filter<>);
	std::string *FeatureNames = new std::string[rows->Length()];
	rows->Traversal(Extract<>, FeatureNames);
	for (size_t i = 0; i < rows->Length(); i++)
	{
		FeatureNames[i] = "Dism.exe /Image:I:\\ /Enable-Feature /FeatureName:" + FeatureNames[i] + " /All /Source:S:\\sources\\sxs";
		char *command = new char[FeatureNames[i].length() + 1];
		strncpy_s(command, FeatureNames[i].length() + 1, FeatureNames[i].c_str(), FeatureNames[i].length());
		system(command);
		delete command;
	}
	delete FeatureNames;
	delete rows;
	delete reader;
    return 0;
}

