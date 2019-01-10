#include "MyParser.h"



MyParser::MyParser()
{
}


MyParser::~MyParser()
{
}

void MyParser::OnCommand(const std::string & cmdline)
{
	std::string argv("");
	std::cout << Split(cmdline, argv);
}

int MyParser::Split(const std::string & text, std::string & parts)
{


	return 100;
}
