# -*- coding: utf-8 -*-

from sys import stdin, stdout

n, k = [int(x) for x in stdin.readline().rstrip().split()]
t = stdin.readline()



for i in range(n):
    if t[0:i] == t[n-i:n]:
        s = t[0:n-i]    
    

print(s*(k-1) + t)