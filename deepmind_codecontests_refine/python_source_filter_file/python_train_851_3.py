n = int(input())
l = list(map(int,input().split()))
a = [[l[i], i] for i in range(n)]
a.sort()
ll = l.copy()
ll.sort()
if n < 6:
	print(a[-1][0] - a[0][0], 1)
	print(*([1] * n))
else:
	b = [ll[i] - ll[i-1] for i in range(3, n - 2)]
	#wybieramy najwieksza sume z b ale nie moge wybrac ziomow o mniej niz 2 od siebie
	dp = [[0,0] for i in range(len(b) + 5)]
	i = len(b) - 1
	dp[i] = [0, b[i]]
	while i >= 0:
		dp[i][0] = max(dp[i+1])
		dp[i][1] = max(dp[i+3]) + b[i]
		i-=1
	odp = []
	i = 0
	while True:
		if dp[i][1] == 0:
			break
		if dp[i][1] >= dp[i][0]:
			odp.append(i)
			i += 3
		else:
			i += 1
	odp = [i+3 for i in odp]
	grupy = [0] * n
	grupa = 1
	wsk = 0
	for i in range(n):
		if wsk <= len(odp)-1:
			if i == odp[wsk]:
				wsk += 1
				grupa += 1
		grupy[a[i][1]] = grupa
	print(ll[-1] - ll[0] - max(dp[0]), grupa)
	print(*grupy)