t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	ans = n+n-1
	for i in range(n-2):
		if a[i]<a[i+1] and a[i+1]>a[i+2]: ans += 1
		if a[i]>a[i+1] and a[i+1]<a[i+2]: ans += 1
	for i in range(n-3):
		if a[i+1]<a[i]<a[i+3]<a[i+2]: ans += 1
		if a[i+1]<a[i+3]<=a[i]<a[i+2]: ans += 1
		if a[i+2]<a[i]<a[i+3]<a[i+1]: ans += 1
		if a[i+2]<a[i+3]<=a[i]<a[i+1]: ans += 1
	print(ans)