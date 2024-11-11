for nt in range(int(input())):
	n, k = map(int,input().split())
	a = list(map(int,input().split()))
	ans = -10**18
	for i in range(n-1, max(-1, n-200), -1):
		for j in range(i+1, n):
			ans = max(ans, (i+1)*(j+1) - k*(a[i]|a[j]))
	print (ans)