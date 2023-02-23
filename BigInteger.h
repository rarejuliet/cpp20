#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <string>
#define MAX_STRING_NUM_LENGTH 10000 // for strings

//using namespace std;
//-------------------------------------------------------------
class BigInteger
{
private:
	std::string number;
	bool sign;

public:
	/**
		 @brief BigInteger object constructor initializes zero
	**/
	BigInteger();
	/**
		@brief BigInteger object constructor
		@param s - A string containing an integer.
	**/
	BigInteger(std::string s); // "string" constructor
	/**
		@brief BigInteger object constructor
		@param num  - A string containing an integer.
		@param sign - true if num is negative, else false
	**/
	BigInteger(std::string num, bool sign); // "string" constructor
	 /**
	     @brief BigInteger int constructor
	     @param n - 
	 **/
	BigInteger(long long n); //  constructor
	void setNumber(std::string s);
	const std::string& getNumber(); // retrieves the number
	void setSign(bool s);
	const bool& getSign();
	BigInteger absolute(); // returns the absolute value
	void operator = (BigInteger b);
	bool operator == (BigInteger b);
	bool operator != (BigInteger b);
	bool operator > (BigInteger b);
	bool operator < (BigInteger b);
	bool operator >= (BigInteger b);
	bool operator <= (BigInteger b);
	BigInteger& operator ++(); // prefix
	BigInteger  operator ++(int); // postfix
	BigInteger& operator --(); // prefix
	BigInteger  operator --(int); // postfix
	BigInteger operator + (BigInteger b);
	BigInteger operator - (BigInteger b);
	BigInteger operator * (BigInteger b);
	BigInteger operator / (BigInteger b);
	BigInteger operator % (BigInteger b);
	BigInteger& operator += (BigInteger b);
	BigInteger& operator -= (BigInteger b);
	BigInteger& operator *= (BigInteger b);
	BigInteger& operator /= (BigInteger b);
	BigInteger& operator %= (BigInteger b);
	BigInteger& operator [] (int n);
	BigInteger operator -(); // unary minus sign
	operator std::string(); // for conversion from BigInteger to string
private:
	bool equals(BigInteger n1, BigInteger n2);
	bool less(BigInteger n1, BigInteger n2);
	bool greater(BigInteger n1, BigInteger n2);
	std::string add(std::string number1, std::string number2);
	std::string subtract(std::string number1, std::string number2) const;
	std::string multiply(std::string n1, std::string n2);
	std::pair<std::string, long long> divide(std::string n, long long den) const;
	std::string toString(long long n);
	long long toInt(std::string s);
};
#endif