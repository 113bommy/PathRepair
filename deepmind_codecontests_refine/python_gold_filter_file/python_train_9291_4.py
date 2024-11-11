# f = open('test.py')
# def input():
# 	return f.readline().replace('\n','')

# import heapq
# import bisect
# from collections import deque
# from collections import defaultdict
def read_list():
	return list(map(int,input().strip().split(' ')))
def print_list(l):
	print(''.join(map(str,l)))


N = int(input())

for _ in range(N):
	n,k= read_list()
	if k%n==0:
		print(0)
	else:
		print(2)
	s,r = k//n,k%n
	for t in range(n):
		dp = [0]*n
		mm = s 
		if t<r:
			mm+=1
		for i in range(mm):
			dp[(t+i)%n] = 1
		print_list(dp)

