from math import ceil

from collections import deque

n,k = map(int,input().split())
ans = []
ans = deque(ans)
ans = []

r = n%(2*k+1)
if r == 0:
	r = 2*k+1
if n >= 2*k+1:
	if r >= k+1:
		# print("--")
		# ans.append(r)
		r = r - k
		for i in range(r,n+1,2*k+1):
			ans.append(i)
	else:
		# ans.append(2*k-r)
		# print(r)
		for i in range(r,n-k,2*k+1):
			ans.append(i)
		ans.append(n)
	print(len(ans))
	print(*ans)
else:
	print(1)
	print(n//2)