n = int(input())
a = list(map(int, input().split()))
mx = -2e9
mn = 2e9
for i in range(0, n):
	mx = max(mx, a[i])
	mn = min(mn, a[i])
cntmx = 0
cntmn = 0
for i in range(0, n):
	if a[i] == mx:
		cntmx+=1
	elif a[i] == mn:
		cntmn+=1
if mx-mn < 2:
	print(n)
	ans = ""
	for i in range(0, n):
		ans += str(a[i]) + " "
	print(ans)
else:
	cntmid = n-cntmx-cntmn
	c1 = min(cntmx, cntmn)
	c2 = cntmid//2*2
	if n-c1*2 <= n-c2:
		pmx = 0
		pmn = 0
		ans = ""
		for i in range(0, n):
			if a[i] == mx and pmx < c1:
				pmx+=1
				a[i]-=1
			elif a[i] == mn and pmn < c1:
				pmn+=1
				a[i]+=1
			ans += str(a[i]) + " "
		print(n-c1*2)
		print(ans)
	else:
		pmid = 0
		ans = ""
		for i in range(0, n):
			if a[i] == mn+1 and pmid < c2//2:
				a[i]+=1
				pmid+=1
			elif a[i] == mn+1 and pmid < c2:
				a[i]-=1
				pmid+=1
			ans += str(a[i]) + " "
		print(n-c2*2)
		print(ans)