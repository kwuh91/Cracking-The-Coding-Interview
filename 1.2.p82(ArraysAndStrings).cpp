#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
	// hash 
	// time O(n) space O(n)
	static bool one(const std::string& str1, const std::string& str2) {
		size_t n = str1.size(), m = str2.size();
		if (n != m) return false;
		std::unordered_map<char, size_t> umap1; std::unordered_map<char, size_t> umap2;
		size_t i = 0;
		while (i < n) {
			umap1.count(str1[i]) ? umap1[str1[i]]++ : umap1[str1[i]] = 1;
			umap2.count(str2[i]) ? umap2[str2[i]]++ : umap2[str2[i]] = 1;

			i++;
		}

		for (const char& letter : str1) {
			if (umap1.count(letter) && umap2.count(letter)) {
				if (umap1[letter] != umap2[letter]) return false;
			}
			else if (umap1.count(letter)) return false;
			else if (umap2.count(letter)) return false;
		}

		return true;
	}

	// sort 
	// time O(n log n) space O(1)
	static bool two(std::string str1, std::string str2) {
		size_t n = str1.size(), m = str2.size();
		if (n != m) return false;
		std::sort(str1.begin(), str1.end()); std::sort(str2.begin(), str2.end());
		return str1 == str2;
	}
};

int main() {
	std::string str1 = "qweAZSXDCFVrqqtyquiop"; std::string str2 = "poiquytreqFVDCSXAZqwq";
	std::cout << "one = " << Solution::one(str2, str1) << std::endl;
	std::cout << "two = " << Solution::two(str2, str1) << std::endl;
	return 0;
}
