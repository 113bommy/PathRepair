#!/usr/bin/python3

n = int(input())
s = input()
print(len([1 for i in range(n, len(s)) if len(set(list(s[i - 3:i]))) == 1]))
