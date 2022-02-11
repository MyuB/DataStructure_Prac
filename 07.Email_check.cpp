//
// Created by Jay on 2022-02-11.
//

#include <bits/stdc++.h>
#include <openssl/md5.h>
#define endl '\n'
using namespace std;

class BloomFilter {
	int nHashes;
	vector<bool> bits;

	static constexpr int hashSize = 128 / 8;
	unsigned char hashValue[hashSize];

public:
	BloomFilter(int size, int hashes) : bits(size), nHashes(hashes) {
		if (nHashes > hashSize) throw("too many hashes");
		if (size > 255) throw("bloom filter should be less than 255");
	}

	void hash(const string& key) {
		MD5(reinterpret_cast<const unsigned char*>(key.data()), key.length(), hashValue);
	}

	void add(const string& key) {
		hash(key);
		for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++) bits[*it % bits.size()] = true;

		cout << "블룸 필터에 추가: " << key << endl;
	}

	bool mayContain(const string& key) {
		hash(key);
		for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++) {
			if (!bits[*it % bits.size()]) {
				cout << key << " : 사용할 수 있는 이메일" << endl;
				return false;
			}
		}
		cout << key << " : 이미 사용중 입니다." << endl;
		return true;
	}
};

int main()
{
	BloomFilter bloom(128, 5);

	bloom.add("abc@gilbut.com");
	bloom.add("xyz@gilbut.com");

	bloom.mayContain("abc");
	bloom.mayContain("xyz@gilbut.com");
	bloom.mayContain("xyz");

	bloom.add("abcd@gilbut.com");
	bloom.add("ab@gilbut.com");

	bloom.mayContain("abcd");
	bloom.mayContain("ab@gilbut.com");
}