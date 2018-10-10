#pragma once
class IsLess {
public:
	template<class T>
	static bool compare(const T& a, const T& b) { return a < b; }	//checks if values passed in are less than one an other
};
