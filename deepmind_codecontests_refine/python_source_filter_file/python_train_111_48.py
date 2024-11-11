from math import ceil
n = int(input())
l = list(map(int,input().split()))
k = ceil((2*sum(l))/n)
if k>max(l):
	print(k)
else:
	print(max(l))