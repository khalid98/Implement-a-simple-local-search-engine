#pragma once
#include <stdexcept>
#include <string>
using namespace std;
class PrecondViolatedExcept : public logic_error
{
public:
	PrecondViolatedExcept(const string& message = "");
}; // end PrecondViolatedExcep