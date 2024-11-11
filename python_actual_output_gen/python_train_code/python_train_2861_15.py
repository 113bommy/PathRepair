# -*- coding: utf-8 -*-

from sys import stdin, stdout

n, k = [int(x) for x in stdin.readline().rstrip().split()]
t = stdin.readline()



for i in range(int(n/2)+1):
    if t[0:i] == t[n-i:n]:
        s = t[0:n-i]    
    

print(s*(k-1) + t)