from sys import *
from math import *
from sys import stdin,stdout
from collections import *

int_arr = lambda : list(map(int,stdin.readline().strip().split()))
str_arr = lambda :list(map(str,stdin.readline().split()))
get_str = lambda : map(str,stdin.readline().strip().split())
get_int = lambda: map(int,stdin.readline().strip().split())
get_float = lambda : map(float,stdin.readline().strip().split())
#input = lambda : stdin.readline()


mod = 1000000007
setrecursionlimit(1000)

def ans(n,m,lst):
	min = float('inf')
	max = float('inf')
	flag = 1
	for i in lst:
		if '*' in i:
			fr = i.index('*')
			bk = i[::-1].index('*')
			if fr < min:
				min = fr
			if bk < max:
				max = bk
		if i.count('*') and flag:
			start = lst.index(i)
			flag = 0
	s = ''
	ls = lst[::-1]
	for i in lst:
		if i.count('*'):
			end = n - lst.index(i)
			break
	max = m - (max + 1)
	for i in range(len(lst)):
		if i >= start and i <= end:
			s = lst[i][min:max+1]
			print(s)


#for _ in range(int(input())):
lst = []
n,m = get_int()
for _ in range(n):
	s = str(input())
	lst.append(s)
ans(n,m,lst)
