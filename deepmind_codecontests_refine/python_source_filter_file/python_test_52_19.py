
from math import log2
M=10**9+7
for _ in range(int(input())):
	n,k=map(int, input().split())
	ans=0
	while k>1:
		ans=(ans+n**(int(log2(k))))%M
		k-=2**(int(log2(k)))
	print(ans)
