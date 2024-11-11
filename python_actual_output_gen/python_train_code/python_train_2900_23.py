t = int(input())
ans = []
for i in range(t):
	n,x,a,b = map(int,input().split(' '))
	# print(n,x,a,b)
	r,l = max(a,b), min(a,b)
	print(l,r)
	lhg, rhg = l-1, n-r
	print(lhg,rhg)
	gap = r-l
	while(x != 0):
		if(lhg>=1):
			lhg -= 1
			x -= 1
			gap += 1
		elif(rhg>=1):
			rhg -= 1
			x -= 1
			gap += 1
		else:
			break
	# print(gap)
	ans.append(gap)
for i in range(t):
	print(ans[i])