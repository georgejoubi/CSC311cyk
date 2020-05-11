#pragma once
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
private:
	T* p;
	int rows, cols;
public:
	Matrix(int n, int m) :rows(n), cols(m) {
		/* more efficient to create
			a 1-d array that represents 
			a 2-d matrix
			*/
		p = new T[n*m]();
	}
	T* operator[](int i) {
		return &p[i*cols];
	}
	int getRows() {
		return rows;
	}
	int getCols() {
		return cols;
	}
};

/* return the union of two sets
   we cannot call it union since
   it is a c++ keyword. Union
   doesn't look good either
   */
template <typename T>
set<T>& merge(set<T>& ls, set<T>& rs) {
	std::set<T> s;
	std::set_union(ls.begin(), ls.end(), rs.begin(), rs.end(), std::inserter(s, s.begin()));
	return s;
}

/* returns the cartesian 
	product of two sets
	*/
template <typename T>
set<T> cartesian(set<T>& s1, set<T>& s2) {

	set<T> result;

	for (std::set<T>::iterator it1 = s1.begin(); it1 != s1.end(); it1++) {
		for (std::set<T>::iteratorvit2 = s2.begin(); it2 != s2.end(); it2++) {
			string current = *it1 + *it2;
			result.insert(current);
		}
	}

	return result;

}
