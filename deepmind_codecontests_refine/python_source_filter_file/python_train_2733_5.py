# f = open('test.py')
# def input():
# 	return f.readline().replace('\n','')

# import heapq
# import bisect
# from collections import deque
from collections import defaultdict
def read_list():
	return list(map(int,input().split(' ')))
def print_list(l):
	print(' '.join(map(str,l)))

n = int(input())
nums = read_list()
res = []
dic = defaultdict(list)
a = list(set(nums))
for i in range(n):
	dic[nums[i]].append(i)
for k in a:
	for i in dic[k]:
		for j in range(n-1,i,-1):
			if nums[j]<nums[i]:
				res.append('%d %d'%(i+1,j+1))
print(len(res))
for s in res:
	print(s)





	
