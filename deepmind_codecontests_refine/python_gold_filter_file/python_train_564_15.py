from sys import stdin,stdout
from collections import Counter
def ai(): return list(map(int, stdin.readline().split()))
def ei(): return map(int, stdin.readline().split())
def ip(): return  int(stdin.readline().strip())
def op(ans): return stdout.write(str(ans) + '\n')
from math import ceil

s = input()
t = input()
a,b = sorted(s),sorted(t)

def substr(s,t):
	i=j=0
	while i<len(s) and j<len(t):
		if s[i]==t[j]:
			j += 1
			i += 1
		else:
			i += 1
	return j==len(t)

if substr(s,t):
	print('automaton')
elif a==b:
	print('array')
elif substr(a,b):
	print('both')
else:
	print('need tree')