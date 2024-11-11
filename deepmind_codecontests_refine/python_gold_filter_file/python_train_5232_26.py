import sys
input = sys.stdin.readline

for nt in range(int(input())):
	n = int(input())
	a = list(map(int,input().split()))
	b = sorted(a)
	l = {}
	for i in range(n):
		l[b[i]] = i
	if a==b:
		print (0)
		continue
	dp = [0]*(n+1)
	for i in range(n):
		dp[l[a[i]]] = 1+dp[l[a[i]]-1]
	print (n-max(dp))

