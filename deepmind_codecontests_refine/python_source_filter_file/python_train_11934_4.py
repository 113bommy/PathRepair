
import sys
from math import gcd 
# def gcd (a,b):
# 	if b== 0:
# 		return a
# 	return gcd(b,a%b)

n = int(input())
a = list(map(int,input().split()))
if 1 in a:
	print(n- a.count(1))
	exit()
count = sys.maxsize
for i in range(n):

	tmp = a[i]
	for j in range(i+1,n):
		t =gcd(tmp,a[j])
		if t == 1:
			count = min(count,n + j-i -1)
if count != sys.maxsize:
	print(count)
else:
	print(-1)

