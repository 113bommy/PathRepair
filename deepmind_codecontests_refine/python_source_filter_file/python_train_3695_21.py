
import collections
import math 
# 011011
#
def sortBy(a):
	return a[0]
def gcd(a,b): 
	if (b == 0): 
		return a
	return gcd(b, a%b)
def solve(lst):
	zeros = 0
	for i in lst:
		if i == '0': zeros+=1
	return zeros % (len(lst)-zeros)
k = int(input())
print(solve(input()))
# for i in range(k):
# 	k = int(input())
# 	lst = list(map(int,input().split()))
# 	p=solve(lst)
# 	print(' '.join(p))