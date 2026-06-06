#pragma once

#include <cctype>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>

// class bigint {

// 	private:
// 		std::string num;
// 	public:
// 		bigint(size_t n) : num(std::to_string(n)) {}
// 		bigint() : num("0") {}
// 		bigint(const bigint& oth) : num(oth.num) {}
// 		bigint(const std::string& n) 
// 		{
// 			if(n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit) || (n.size() > 1 && n[0] == '0')) 
// 			{
// 				std::cout << "Invalid number" << std::endl;
// 				num = "0";
// 			}
// 			else
// 			{
// 				num = n;
// 			}
// 		}
// 		friend std::ostream& operator<<(std::ostream& os, const bigint& b)
// 		{
// 			return os << b.num;
// 		}
// 		std::string add_str(const std::string& s1, const std::string& s2) const
// 		{
// 			std::string res;
// 			int z = 0 , carry = 0, i = s1.size() - 1, j = s2.size() - 1;
// 			while(i >= 0 || j >= 0 || carry)
// 			{
// 				int sum = (i >= 0 ? s1[i--] - '0' : 0) + (j >= 0 ? s2[j--] - '0' : 0) + carry;
// 				res.push_back(sum % 10 + '0');
// 				carry = sum / 10;
// 			}
// 			std::reverse(res.begin(), res.end());
// 			for(z = 0; z < res.length() && res[z] == '0'; z++);
// 			res = res.substr(z, res.length());
// 			return res;
// 		}


// 		bigint operator+(const bigint& oth) const
// 		{
// 			return add_str(num, oth.num);
// 		}

// 		bigint& operator+=(const bigint& oth)
// 		{
// 			num = add_str(num, oth.num);
// 			return *this;
// 		}

// 		bigint& operator++()
// 		{
// 			return *this += bigint(1);
// 		}
// 		bigint operator++(int)
// 		{
// 			bigint tmp(*this);
// 			++(*this);
// 			return tmp;
// 		}

// 		bigint operator<<(size_t shift) const
// 		{
// 			return bigint(num + std::string(shift, '0'));
// 		}

// 		bigint& operator<<=(size_t shift)
// 		{
// 			num += std::string(shift, '0');
// 			return *this;
// 		}

// 		bigint& operator>>=(const bigint& b)
// 		{
// 			if(bigint(num.size()) <= b) // see if fixed
// 				num = "0";
// 			else {
// 				bigint i(0);
// 				while (i < b) {
// 					num = num.substr(0, num.size() - 1);
// 					++i;
// 				}
// 			}
// 			return *this;
// 		}

// 		bool operator<(const bigint& oth) const
// 		{
// 			if(num.size() < oth.num.size())
// 				return 1;
// 			else if(num.size() > oth.num.size())
// 				return 0;
// 			return num < oth.num;
// 		}

// 		bool operator>(const bigint& oth) const
// 		{
// 			return oth < *this;
// 		}

// 		bool operator==(const bigint& oth) const
// 		{
// 			return num == oth.num;
// 		}

// 		bool operator!=(const bigint& oth) const
// 		{
// 			return num != oth.num;
// 		}

// 		bool operator<=(const bigint& oth) const
// 		{
// 			return !(*this > oth);
// 		}

// 		bool operator>=(const bigint& oth) const
// 		{
// 			return !(*this < oth);
// 		}

// 		//extra
// 		bigint operator-(const bigint& oth) const
// 		{
// 			(void)oth;
// 			return bigint();
// 		}
// };


class bigint {

	private:
		std::string num;
	public:
		bigint(size_t n) : num(std::to_string(n)) {}
		bigint() : num("0") {}
		bigint(const bigint& oth) : num(oth.num) {}
		bigint(const std::string& n)
		{
			if(n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit) || n.size() > 0 && n[0] == '0')
			{
				std::cout << "invalid number" <<  std::endl;
				num = "0";
			}
			else {
				num = n;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const bigint& n)
		{
			return os << n.num;
		}

		std::string add_str(const std::string& s1, const std::string& s2) const 
		{
			std::string res;
			int z = 0, carry = 0, i = s1.size() - 1, j = s2.size() - 1;
			while (i >= 0 || j >= 0 || carry) {
				int sum = (i >= 0 ? s1[i--] - '0' : 0) + (j >= 0 ? s2[j--] - '0' : 0);
				res.push_back(sum % 10 + '0');
				carry = sum / 10;
			}
			std::reverse(res.begin(), res.end());
			for(z = 0; z < res.size() && res[z] == '0'; z++);
			res = res.substr(z, res.size());
			return res;
		}

		bigint operator+(const bigint& oth) const
		{
			return bigint(add_str(num, oth.num));
		}

		bigint& operator+=(const bigint& oth)
		{
			num = add_str(num, oth.num);
			return *this;
		}

		bigint& operator++()
		{
			return *this += bigint(1);
		}

		bigint operator++(int)
		{
			bigint tmp(*this);
			++(*this);
			return tmp;
		}

		bigint operator<<(size_t shift) const
		{
			return bigint(num + std::string(shift, '0'));
		}

		bigint& operator<<=(size_t shift)
		{
			num += std::string(shift, '0');
			return *this;
		}
		bigint& operator>>=(const bigint& b)
		{
			if(bigint(num.size()) <= b)
				num = "0";
			else {
				bigint i(0);
				while (i < b) {
					num = num.substr(0, num.size() - 1);
					++i;
				}
			}
			return *this;
		}

		bool operator<(const bigint& oth) const
		{
			if (num.size() < oth.num.size())
				return 1;
			else if (num.size() > oth.num.size())
				return 0;
			return num < oth.num;
		}

		bool operator>(const bigint& oth) const
		{
			return oth < *this;
		}

		bool operator==(const bigint& oth) const
		{
			return num == oth.num;
		}
		
		bool operator!=(const bigint& oth) const
		{
			return num!=oth.num;
		}

		bool operator<=(const bigint& oth) const
		{
			return !(*this > oth);
		}

		bool operator>=(const bigint& oth) const
		{
			return !(*this < oth);
		}

		bigint operator-(const bigint& oth) const
		{
			(void)oth;
			return bigint();
		}
};

/*
a = 42
b = 21
c = 0
d = 1337
e = 1337
a+b 63
c+=a 42
b = 21
++b 22
b++ 22
(b << 10) + 42 230000000042
d<<=4 13370000
d>>=(const bigint)2 133700
a = 42
d = 133700
d < a 0
d > a 1
d == a 0
d != a 1
d <= a 0
d >= a 1
0
*/