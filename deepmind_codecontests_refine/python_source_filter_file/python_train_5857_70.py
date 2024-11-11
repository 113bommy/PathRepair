from sys import stdin
input = lambda: stdin.readline().rstrip("\r\n")
from collections import deque as que
inin = lambda: int(input())
inar = lambda: list(map(int,input().split()))

Testcase=inin()
for _ in range(Testcase):
	n,k=inar()
	if n>=k:
		ans=k*(k+1)//2
	else:
		ans=n*(n-1)//2+1
	print(ans)