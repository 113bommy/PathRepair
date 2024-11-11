import sys
import math as mt
input=sys.stdin.buffer.readline
I=lambda:list(map(int,input().split()))
for tc in range(1):
	n,m=I()
	a=I()
	b=I()
	arr=[[a[i]&b[j] for j in range(m)] for i in range(n)]
	arr.sort(key=lambda ar:min(ar),reverse=True)
	print(arr)
	ans=0
	for j in arr:
		ans=min([i|ans for i in j])
	print(ans)