#include <iostream>
#include <string>

class Solution {
public:
	static char* one(char* str, int size) {
		char* res = new char[size*2];
		int ind = 0;
		for (int i = 0; i < size; ++i) {
			if (str[i] != ' ') {
				res[ind] = str[i];
				ind++;
			}
			else {
				res[ind] = '%'; 
				res[ind + 1] = '2'; 
				#pragma warning(suppress: 6386)
				res[ind + 2] = '0';
				ind += 3;
			}
		}
		return res;
	}
};

int main() {
	char str[18] = "Mr John Smith    ";
	char *res = Solution::one(str, 13);
	for (size_t i = 0; i < 26; ++i) {
		std::cout << res[i];
	}
	delete[] res;
	return 0;
}
