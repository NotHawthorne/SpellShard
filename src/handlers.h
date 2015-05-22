#ifndef HANDLERS_H
#define HANDLERS_H

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

std::string H_MSG_LOGIN_RESPONSE(std::string data)
{
	std::vector<std::string> strs = split(data, ',');
	if (strs[0]=="Success") { return "success"; std::cout << "success"; } else { return "failure"; std::cout << "failure"; }
}
std::vector<std::string> H_MSG_CHARACTER_LIST(std::string data)
{
	std::vector<std::string> strs = split(data, ',');
	std::vector<std::string> r_list;
	std::vector<std::string>::iterator it;
	for (it = strs.begin(); it != strs.end(); ++it )
	{
		r_list.push_back(*it);
	}
	return r_list;
}
#endif