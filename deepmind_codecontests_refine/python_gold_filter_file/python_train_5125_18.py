# from math import ceil
for i in range(int(input())):
	n, d = map(int,input().split())
	a = list(map(int,input().split()))


	j = 1
	ans = 0
	while d>0 and j < n:

		if d > a[j]*j:
			ans += a[j];
			d -= a[j]*j;
		else:
			ans += d//j
			break
		j+=1
	print(ans+a[0])
