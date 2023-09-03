#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <algorithm>
#include <bitset>

class Solution {
public:
	// set
	static bool one(const std::string& str) {
		std::set<char> myset;
		for (char i : str) myset.insert(i);
		return str.size() == myset.size();
	}

	// hash
	static bool two(const std::string& str) {
		std::unordered_map<char, int> umap;
		for (char i : str) {
			if (umap.count(i)) return false;
			umap[i] = 1;
		}
		return true;
	}

	// brute force
	static bool three(const std::string& str) {
		for (size_t i = 0; i < str.size()-1; ++i) {
			for (size_t j = i + 1; j < str.size(); ++j) {
				if (str[i] == str[j]) return false;
			}
		}
		return true;
	}

	// sort (introsort)
	static bool four(std::string str) {
		std::sort(str.begin(), str.end());
		for (size_t i = 0; i < str.size() - 1; ++i) {
			if (str[i] == str[i + 1]) return false;
		}
		return true;
	}

	// bit vector
	static bool five(const std::string& str) {
		int end = static_cast<int>('z');
		int start = static_cast<int>('A');

		std::vector<bool> bitvec(end - start + 1, 0);

		for (const char& letter : str) {
			int ind = end - static_cast<int>(letter);
			if (bitvec[ind]) return false;
			else bitvec[ind] = true;
		}
		return true;
	}
};

int main() {
	std::string mystr = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

	auto start = std::chrono::high_resolution_clock::now();

	std::cout << "one " << Solution::one(mystr) << std::endl; 
	std::cout << "two " << Solution::two(mystr) << std::endl; 
	std::cout << "three " << Solution::three(mystr) << std::endl; 
	std::cout << "four " << Solution::four(mystr) << std::endl;
	std::cout << "five " << Solution::five(mystr) << std::endl;

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << std::endl << "execution time = " << duration.count() << " microseconds" << std::endl;

	return 0;
}

// with threads
//int main() {
//	std::string mystr = "abcd";
//	bool one = false, two = false, three = false;
//
//	auto start = std::chrono::high_resolution_clock::now();
//
//	std::thread t1([&one, &mystr]() {one = Solution::one(mystr);});
//	std::thread t2([&two, &mystr]() {two = Solution::one(mystr);});
//	std::thread t3([&three, &mystr]() {three = Solution::one(mystr);});
//
//	t1.join(); t2.join(); t3.join();
//
//	auto stop = std::chrono::high_resolution_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//
//	std::cout << "one " << one << std::endl;
//	std::cout << "two " << two << std::endl;
//	std::cout << "three " << three << std::endl;
//
//	std::cout << std::endl << "execution time = " << duration.count() << " microseconds" << std::endl;
//
//	return 0;
//}
