////
//// Created by Jay on 2022-02-11.
////
//
//#include <bits/stdc++.h>
//#define endl '\n'
//using namespace std;
//
//class URLService {
//public:
//	using ActualURL = string;
//	using TinyURL = string;
//private:
//	unordered_map<TinyURL, ActualURL> data;
//public:
//	pair<bool, ActualURL> lookup(const TinyURL& url) const {
//		auto it = data.find(url);
//		if (it == data.end())
//			return {false, string()};
//		else
//			return {true, it->second};
//	}
//
//	bool registerURL(const ActualURL& actualUrl, const TinyURL& tinyURL) {
//		auto found = lookup(tinyURL).first;
//		if (found) return false;
//		data[tinyURL] = actualUrl;
//		return true;
//	}
//
//	bool deregisterURL(const TinyURL& tinyURL) {
//		auto found = lookup(tinyURL).first;
//		if (found) {
//			data.erase(tinyURL);
//			return true;
//		}
//		return false;
//	}
//
//	void printURLs() const {
//		for (const auto& d : data)
//			cout << d.first << " -> " << d.second << endl;
//		cout << endl;
//	}
//};
//
//int main() {
//	URLService service;
//
//	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002245", "https://py_dojang"))
//	{
//		cout << "https://py_dojang 등록" << endl;
//	}
//	else
//	{
//		cout << "https://py_dojang 등록 실패" << endl;
//	}
//
//	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN001484", "https://c_dojang"))
//	{
//		cout << "https://c_dojang 등록" << endl;
//	}
//	else
//	{
//		cout << "https://c_dojang 등록 실패" << endl;
//	}
//
//	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002402", "https://opencv4"))
//	{
//		cout << "https://opencv4 등록" << endl;
//	}
//	else
//	{
//		cout << "https://opencv4 등록 실패" << endl;
//	}
//
//	auto pythonBook = service.lookup("https://py_dojang");
//	if (pythonBook.first)
//	{
//		cout << "https://py_dojang 원본 URL: " << pythonBook.second << endl;
//	}
//	else
//	{
//		cout << "https://py_dojang 원본 URL을 찾을 수 없습니다." << endl;
//	}
//
//	auto cppBook = service.lookup("https://cpp_dojang");
//	if (cppBook.first)
//	{
//		cout << "https://cpp_dojang 원본 URL: " << cppBook.second << endl;
//	}
//	else
//	{
//		cout << "https://cpp_dojang 원본 URL을 찾을 수 없습니다." << endl;
//	}
//
//	if (service.deregisterURL("https://c_dojang"))
//	{
//		cout << "c_dojang 책 URL 등록 해제" << endl;
//	}
//	else
//	{
//		cout << "c_dojang 책 URL 등록 해제 실패" << endl;
//	}
//
//	auto findQtBook = service.lookup("https://c_dojang");
//	if (findQtBook.first)
//	{
//		cout << "https://c_dojang 원본 URL: " << findQtBook.second << endl;
//	}
//	else
//	{
//		cout << "https://c_dojang 원본 URL을 찾을 수 없습니다." << endl;
//	}
//
//	cout << "등록된 URL 리스트:" << endl;
//	service.printURLs();
//
//	return 0;
//}