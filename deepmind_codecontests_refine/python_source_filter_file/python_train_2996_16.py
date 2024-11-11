#!/usr/bin/env python3
import sys
input = sys.stdin.readline
from collections import defaultdict
 
def empty_list():
    return [0] * 26
 
class RollingHash():
    def __init__(self, s):
        length = len(s)
        base = 1009
        # self.mod = (1 << 61) - 1
        self.mod = 67280421310721
        self.hash = [0] * (length + 2)
        self.pow = [1] * (length + 2)
 
        for i in range(length):
            self.hash[i+1] = (self.hash[i] + s[i]) * base % self.mod
            self.pow[i+1] = self.pow[i] * base % self.mod
        self.pow[length+1] = self.pow[length] * base % self.mod 
 
    def get(self, l, r):
        t = self.hash[r] - self.hash[l] * self.pow[r-l] % self.mod
        return t % self.mod
 
ss = []
n = int(input())
for _ in range(n):
    ss.append([ord(item) for item in input().rstrip()])
ss.sort(key=lambda x: len(x), reverse=True)
 
orda = ord("a")
words = defaultdict(empty_list)
ans = 0
for s in ss:
    word_len = len(s)
    s_rev = s[::-1]
    RH = RollingHash(s_rev)
    rh = RH.get(0, word_len-1)
    ans += words[rh][s_rev[-1] - orda]
    initial = [0] * 26 
    for i, ch in enumerate(s):
        initial[ch - orda] = 1
        for j, is_initial in enumerate(initial):
            if is_initial:
                rh = RH.get(0, word_len-i-1)
                words[rh][j] += 1
print(ans)