from sys import stdin,stdout
from collections import Counter
from math import ceil,floor
from bisect import bisect_left 
from bisect import bisect_right
import math
 
def ai(): return list(map(int, stdin.readline().split()))
def ei(): return map(int, stdin.readline().split())
def ip(): return  int(stdin.readline().strip())
def op(*args): return stdout.write(str(ans) + '\n')

def solve():
	s = input()
	A_count,B_count = 0,0
	ans = 0
	for i in range(len(s)):
		if s[i] == 'A':
			A_count += 1
		elif s[i] == 'B' and A_count>0:
			ans += 2
			A_count -= 1
		elif s[i] == "B":
			B_count += 1
	if B_count % 2:
		B_count = 0
	print(len(s)-(B_count+ans))


n = ip()
for _ in range(n):
	solve()