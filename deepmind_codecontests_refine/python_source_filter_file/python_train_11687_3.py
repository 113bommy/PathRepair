import sys
import os,io
input = sys.stdin.readline
# input_all = sys.stdin.read
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# input_all = io.BytesIO(os.read(0,os.fstat(0).st_size)).read
def read_int():
	return map(int, input().split())
def read_list():
	return list(map(int, input().split()))
def print_list(l):
	print(' '.join(map(str,l)))
# import heapq as hq
# import bisect as bs
# from collections import deque as dq
# from collections import defaultdict as dc 
# import math

# f = open('test.py')
# input = f.readline
# input_all = f.read


N = int(input())
for _ in range(N):
	n, k, l = read_list()
	d = read_list()
	if max(d)<l:
		print('No')
	else:
		dic = {}
		for i in set(d):
			if i+k<=l:
				dic[i] = (1<<(2*k+1))-1
			else:
				dic[i] = ((1<<((l-i)*2+1))-1)<<(i+k-l)
		# print(dic)
		flag = True
		now = dic[d[0]]
		tt = (1<<(2*k+1))-1
		for i in range(1,n):
			if now==0:
				flag = False
				break
			tmp = dic[d[i]]
			if tmp==tt:
				now = tt
			elif now==tt:
				now = tmp
			else:
				now = (now>>1) & tmp
		if flag and now>0:
			print('Yes')
		else:
			print('No')