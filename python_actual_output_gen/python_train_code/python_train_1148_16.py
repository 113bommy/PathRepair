#! /usr/bin/python3

t = int(input())

for tt in range(t):
	n,k = map(int, input().split())
	a = list(map(int, input().split()))
	m = max(a[0], n+1-a[k-1])
	for i in range(2,k):
		m = max(m, (a[i]-a[i-1]+1)//2)
	print(m)



