#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "utilities.h"
/* GENERAL NOTES:
   1. the insert operation on sets is safe
	  it does not insert an element that
	  is already in the set
   2. If you have a c++17 conformant compiler
	  you don't have to implement the merge
	  function, you can use the set.merge(...)
   3. Test the smaller functions first
	  before attempting to implement solve
   4. Try designing solve on a piece of paper
	  before coding
*/
using namespace std;
vector<pair<string, string>> productions;

/* given a symbol  "symbol"
	returns a set of all symbols
	that can produce it
	*/
set<string> search(string symbol) {
	set<string> result;
	for (std::vector<int>::iterator it = productions.begin(); it != productions.end(); ++it) {
		if (*it.second == symbol) {
			result.insert(*it.first);
		}
	}
	return result;
}


/* generalization of the above
   returns a set of symbols that
   can produce a set of symbols
   */
set<string> search(set<string> ss) {
	set<string> result;
	for (std::set<int>::iterator it = ss.begin(); it != ss.end(); ++it) {
		set<string> current = search(*it);
		result = merge(result, current);
	}
	return result;
}

/* this is the heart of
   the CYK algorithm
   it takes an argument a matrix m
   and string imput and "fills"
   the solution
   */
void solve(Matrix<set<string>>& m, string input) {

	int n = input.length();

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			
			string target = input.substr(i, i + j + 1);
			set<string> ss;
			
			if (target.length() == 1) {
				m[i][j] = search(target);
			} else {

				for (int x = 1; x < target.length() - 1; x++) {
					string left = target.substr(0, x);
					string right = target.substr(x, target.length());
					ss.merge(ss,cartesian(m[i][j-x]))
				}

			}
		}
	}

}

int main() {
	cout << "input a string\n";
	string input;
	cin >> input;
	/* Assumes that the starting
		symbol is "S"
		*/
	Matrix<set<string>> table(input.length(), input.length());
	std::ifstream file;
	/* read the cfg from file "cfg.txt"
	   if the grammar is CNF*/
	file.open("cfg.txt");
	int np;
	std::string pr;
	std::string left, right;
	/* read the file and save the productions
		in a vector of pairs. For example
		S->AB is saved as pair("S","AB");
		*/
	while (file >> pr) {
		if (pr.length() > 5) {
			std::cout << "not cnf\n";
			abort();
		}
		int itr = pr.find("->");
		if (itr != 1) {
			std::cout << "more than one symbol on left\n";
			abort();
		}
		left = pr.substr(0, 1);
		right = pr.substr(itr + 2, 2);
		pair<string, string> p(left, right);
		productions.push_back(p);
	}
	solve(table, input);
	file.close();
	/* the startig symbol is assumed
		to be S
		*/
	int j = input.length() - 1;
	if (table[0][j].find("S") != table[0][j].end()) {
		std::cout << "belongs to language\n";
	}
	else
		std::cout << "does not belong to language\n";

}
