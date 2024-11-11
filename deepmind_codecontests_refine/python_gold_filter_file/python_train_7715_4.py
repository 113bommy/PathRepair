#!/usr/bin/python3
from collections import Counter

def readint():
    return int(input())


def readline():
    return [int(c) for c in input().split()]


def update(pos, mv, d):
    if mv == 'U':
        pos[1] += d
    elif mv == 'D':
        pos[1] -= d
    elif mv == 'L':
        pos[0] -= d
    elif mv == 'R':
        pos[0] += d


def can(u, v, length):
    d = abs(u[0] - v[0]) + abs(u[1] - v[1])
    if d % 2 != length % 2:
        return False
    return length >= d


def ok(length, n, x, y, s):
    pos = [0, 0]
    for i in range(length, n):
        update(pos, s[i], 1)

    l, r = 0, length
    while True:
        if can(pos, [x, y], length):
            return True
        if r == n:
            break
        update(pos, s[l], 1)
        l += 1
        update(pos, s[r], -1)
        r += 1

    return False


def main():
    n = readint()
    s = input()
    x, y = readline()

    if not ok(n, n, x, y, s):
        print(-1)
        return

    l, r = -1, n
    while r - l > 1:
        mid = (l + r) // 2
        if ok(mid, n, x, y, s):
            r = mid
        else:
            l = mid
            
    print(r)

    


if __name__ == '__main__':
    main()


"""
#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 9;

string s;
int n;
int x, y;

void upd(pair<int, int> &pos, char mv, int d){
	if(mv == 'U')
		pos.second += d;
	if(mv == 'D')
		pos.second -= d;
	if(mv == 'L')
		pos.first -= d;
	if(mv == 'R')
		pos.first += d;
}

bool can(pair<int, int> u, pair<int, int> v, int len){
	int d = abs(u.first - v.first) + abs(u.second - v.second);
	if(d % 2 != len % 2) return false;
	return len >= d;
}

bool ok(int len){
	pair<int, int> pos = make_pair(0, 0);
	for(int i = len; i < n; ++i)
		upd(pos, s[i], 1);

	int l = 0, r = len;
	while(true){
		if(can(pos, make_pair(x, y), len))
			return true;
		
		if(r == n) break;
		upd(pos, s[l++], 1);
		upd(pos, s[r++], -1);		
	}
	
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	cin >> n;
	cin >> s;
	cin >> x >> y;
	
	if(!ok(n)){
		puts("-1");
		return 0;
	}
	
	int l = -1, r = n;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid;
	}
	
	cout << r << endl;
    return 0;
}
"""
