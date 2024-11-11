for _ in range(int(input())):
	r,c = map(int,input().split())
	count, mn = 0,100
	ans = 0
	for i in range(r):
		k = list(map(int,input().split()))
		for j in k:
			if j<0:
				count+=1
			mn = min(mn,abs(j))
			ans += abs(j)

	if count%2==0:
		print(ans)
	else:
		print(ans-mn)