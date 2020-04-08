# Implementation of the CYK algorithm

1. In utilities.h implement the fucntions
   ```c++
      set<T> merge(set<T>& s1,set<T>& s2);
      set<T> cartesian(set<T>& s1,set<T>& s2);
   ```
   The first one returns the union of s1 and s2.
   The second one returns the cartesian product s1xs2
   
1. In main.cpp implement
    ```c++
       set<string> search(string s)
       set<string> search(set<string> ss);
    ```
  The first one  returns a set of symbols that can generate symbol s
  obviously according to the production rules. The second one
  does the same **but for all** symbols in the input set
  
1. After you have thouroughly tested the above functions
   implement
   ```c++
    void  solve(Matrix<set<string>> &m,string input);
   ```
