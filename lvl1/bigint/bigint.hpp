#pragma once

#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>

class bigint {

	private:
		std::string num;
	public:
		bigint(size_t n) : num(std::to_string(n)) {}
		bigint() : num("0") {}
		bigint(const bigint& oth) : num(oth.num) {}
		bigint(const std::string& n)
		{
			if(n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit) || (n.size() > 1 && n[0] == '0'))
			{
				std::cout << "invalid num" << std::endl;
				num = "0";
			}
			else {
				num = n;
			}
		}
		friend std::ostream& operator<<(std::ostream& os, const bigint& oth)
		{
			return os << oth.num;
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
		bigint operator<<(size_t shft) const 
		{
			return bigint(num + std::string(shft, '0'));
		}
		bigint& operator<<=(size_t shft)
		{
			num = num + std::string(shft, '0');
			return *this;
		}
		bigint& operator>>=(const bigint& oth)
		{
			if(bigint(num.size()) <= oth)
				num = "0";
			else {
				bigint i(0);
				while (i < oth) {
					num = num.substr(0, num.size() - 1);
					++i;
				}
			}
			return *this;
		}

		bool operator<(const bigint& oth) const
		{
			if(num.size() < oth.num.size())
				return 1;
			else if(num.size() > oth.num.size())
				return 0;
			return num < oth.num;
		}
		bool operator>(const bigint& oth) const
		{
			return oth < *this;
		}
		bool operator!=(const bigint& oth) const
		{
			return num != oth.num;
		}
		bool operator==(const bigint& oth) const
		{
			return num == oth.num;
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
// #pragma once

// #include <cctype>
// #include <cstddef>
// #include <iostream>
// #include <ostream>
// #include <string>
// #include <algorithm>


// class bigint {

// 	private:
// 		std::string num;
// 	public:
// 		bigint(size_t n) : num(std::to_string(n)) {}
// 		bigint() : num("0") {}
// 		bigint(const bigint& oth) : num(oth.num) {}
// 		bigint(const std::string& n) {
// 			if(n.empty() || !std::all_of(n.begin(), n.end(), ::isdigit) || (n.size() > 1 && n[0] == '0'))
// 			{
// 				std::cout << "invalid arg" << std::endl;
// 				num = "0";
// 			}
// 			else {
// 				num = n;
// 			}
// 		}

// 		friend std::ostream& operator<<(std::ostream& os, const bigint& n)
// 		{
// 			return os << n.num;
// 		}
// 		std::string add_str(const std::string& s1, const std::string& s2) const
// 		{
// 			std::string res;
// 			int carry = 0, z = 0, i = s1.size() - 1, j = s2.size() - 1;
// 			while (i >= 0 || j >= 0 || carry) {
// 				int sum = (i >= 0 ? s1[i--] - '0': 0) + (j >= 0 ? s2[j--] - '0': 0);
// 				res.push_back(sum % 10 + '0');
// 				carry = sum / 10;
// 			}
// 			std::reverse(res.begin(), res.end());
// 			for(z = 0; z <= res.size() && res[z] == '0'; z++);
// 			res = res.substr(z, res.size());
// 			return res;
// 		}

// 		bigint operator+(const bigint& oth) const 
// 		{
// 			return bigint(add_str(num, oth.num));
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
// 		bigint operator<<(size_t shft) const
// 		{
// 			return bigint(num + std::string(shft, '0'));
// 		}
// 		bigint& operator<<=(size_t shft)
// 		{
// 			num = num + std::string(shft, '0');
// 			return *this;
// 		}
// 		bigint& operator>>=(const bigint& oth)
// 		{
// 			if(bigint(num.size()) <= oth)
// 				num = "0";
// 			else {
// 				bigint i(0);
// 				while (i < oth) {
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
// 		bigint operator-(const bigint& oth) const
// 		{
// 			(void)oth;
// 			return bigint();
// 		}
// };