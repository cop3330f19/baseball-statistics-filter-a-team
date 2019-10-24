#ifndef STRING_HELPER
#define STRING_HELPER

#include <string>
#include <sstream>
#include <vector>

class StringHelper{
	
	public:
		/**************************************************************
		 *                             parse                          *
		 *                                                            *
		 * Passed   : 2 arguments: a string, a character that is the  *
		 *            delimiter                                       *
		 * Purpose  : Split a given string by its delimiter           *
		 * Returns  : String vector                                   *
		 **************************************************************/
		static std::vector<std::string> parse(std::string , char );

		/**************************************************************
		 *                           toUpper                          *
		 *                                                            *
		 * Passed   : 1 argument: a string                            *
		 * Purpose  : Convert a string to all upper case              *
		 * Returns  : String                                          *
		 **************************************************************/
		static std::string toUpper(const std::string );

		/**************************************************************
		 *                          toString                          *
		 *                                                            *
		 * Passed   : 1 argument: a native  type value or a ADT       *
		 *				with an output stream overload                *
		 * Purpose  : Convert a non-string value to a string          *
		 * Returns  : String                                          *
		 **************************************************************/
		template<typename T>
		static std::string toString(const T& value)
		{
			std::ostringstream oss;
			oss << value;
			return oss.str();
		}

};
#endif