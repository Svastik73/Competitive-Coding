//https://codeforces.com/contest/1858/problem/C

/*
n==6
No ::{1,5} {2,4} {3,6}  3 pairs
GCD::  1     2     3    3 distinct

n==7
No ::{1,5} {2,4} {3,6} {7}
GCD:: 1      2     3    1 3 distinct
  */
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int cur = 0;
        for (int i = 1; i <= n; i += 2) {
            for (int j = i; j <= n; j *= 2) {
                a[cur++] = j;
            }
        }
        for (int i = 0; i<n; ++i) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
